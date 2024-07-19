##############################################################################
# SYNOPSYS CONFIDENTIAL - This is an unpublished, confidential, and          #
# proprietary work of Synopsys, Inc., and may be subject to patent,          #
# copyright, trade secret, and other legal or contractual protection.        #
# This work may be used only pursuant to the terms and conditions of a       #
# written license agreement with Synopsys, Inc. All other use, reproduction, #
# distribution, or disclosure of this work is strictly prohibited.           #
##############################################################################

import sim
import sys
import os

# Platform variable
core_name = ""
mem_name = ""
mem_start_address = ""
top_inst_name = ""

def parse_arguments():
    global core_name
    global mem_name
    global mem_start_address
    global top_inst_name

    #if(len(sys.argv) < 4):
    #        raise StandardError("Invalid number of arguments. Should be 4")

    core_name = sys.argv[1]
    #mem_name = "/TCP/ECU/iMX8DXL/DRAM"#sys.argv[2]
    #mem_start_address = 0x80000000#int(sys.argv[3],16)
    
    mem_name = '/S32K388_System/S32K388_MCU/Memories/PFLASH/MEM'
    mem_start_address = 0x400000
    top_inst_name = "JUNK_1"#sys.argv[4]

try:
    parse_arguments()
except StandardError as detail:
    print os.path.basename(__file__) + " :", detail
    sim.print_message("Error in script")

SLAVE_ADDR_7_BIT = "0x1E"
SLAVE_ADDR_10_BIT = "0xF6FF"
SLAVE_ADDR_15_BIT = "0xFEFF"

I2C_MONITOR_Stub = []

def get_i2c_monitor_no():
    i2c_monitor_no = core_probe.find_symbol_by_name("i2c_monitor_no", 'object')
    i2c_monitor_no_mem_probe = sim.MemoryProbe(mem_name, i2c_monitor_no.size, i2c_monitor_no.start_address - mem_start_address)
    return i2c_monitor_no_mem_probe.get_value()

def get_addr_mode():
    addr_mode = core_probe.find_symbol_by_name("addr_mode", 'object')
    addr_mode_mem_probe = sim.MemoryProbe(mem_name, addr_mode.size, addr_mode.start_address - mem_start_address)
    return addr_mode_mem_probe.get_value()

def get_is_master():
    is_master = core_probe.find_symbol_by_name("is_master", 'object')
    is_master_mem_probe = sim.MemoryProbe(mem_name, is_master.size, is_master.start_address - mem_start_address)
    return is_master_mem_probe.get_value()

def get_is_high_speed():
    is_high_speed = core_probe.find_symbol_by_name("is_high_speed", 'object')
    is_high_speed_mem_probe = sim.MemoryProbe(mem_name, is_high_speed.size, is_high_speed.start_address - mem_start_address)
    return is_high_speed_mem_probe.get_value()


def config_I2C_MONITOR(observer, args):
    print("AKN: config_I2C_MONITOR Callback")

    i2c_monitor_no = 0#get_i2c_monitor_no()
    i2c_monitor_no = 0
    addr_mode = 7#get_addr_mode()
    is_master = False#get_is_master()

    print("i2c_monitor_no = ", i2c_monitor_no)
    print("addr_mode  = ", addr_mode)
    print("is_master = ", is_master)

    arg_list = []

    if is_master:
        I2C_MONITOR_Stub[i2c_monitor_no].execute_command("set_serial_clock_period", ['2'])
        arg_list.append("master_register")
    else:
        arg_list.append("slave_register")
        if addr_mode == 7:
            arg_list.append(SLAVE_ADDR_7_BIT)
        elif addr_mode == 10:
            arg_list.append(SLAVE_ADDR_10_BIT)
        elif addr_mode == 15:
            arg_list.append(SLAVE_ADDR_15_BIT)

    # print (arg_list)
    I2C_MONITOR_Stub[i2c_monitor_no].execute_command(arg_list[0], arg_list[1:])
    # print("--------------------------------------------------------------------------------------------------")


def master_send_data(observer, args):

    # $i2cMonitor master_send_data 0xA $address $data $isRestart $is15BitAddr

    print("master_send_data ..")
    i2c_monitor_no = 0#get_i2c_monitor_no()
    addr_mode = 7#get_addr_mode()
    is_high_speed = False#get_is_high_speed()

    # print("i2c_monitor_no = ", i2c_monitor_no)
    # print("addr_mode  = ", addr_mode)
    # print("is_high_speed", is_high_speed)

    arg_list = ["master_send_data"]
    data = "0x00 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x99 0xAA 0xBB 0xCC 0xDD 0xEE 0xFF"
    is_restart = "0"

    if is_high_speed:
        arg_list.append("0xA")

    if addr_mode == 7:
        arg_list.append(SLAVE_ADDR_7_BIT)
    elif addr_mode == 10:
        arg_list.append(SLAVE_ADDR_10_BIT)
    elif addr_mode == 15:
        arg_list.append(SLAVE_ADDR_15_BIT)

    arg_list.append(data)
    arg_list.append(is_restart)

    if addr_mode == 15:
        arg_list.append("15bit")

    # print (arg_list)
    I2C_MONITOR_Stub[i2c_monitor_no].execute_command(arg_list[0], arg_list[1:])


def master_receive_data(observer, args):
    i2c_monitor_no = get_i2c_monitor_no()
    addr_mode = get_addr_mode()
    is_master = get_is_master()
    is_high_speed = get_is_high_speed()

    # print("i2c_monitor_no = ", i2c_monitor_no)
    # print("addr_mode  = ", addr_mode)
    # print("is_master = ", is_master)
    # print("is_high_speed", is_high_speed)

    arg_list = ["master_receive_data"]
    is_restart = "0"

    if is_high_speed:
        arg_list.append("0xA")

    if addr_mode == 7:
        arg_list.append("0x1F")
        # arg_list.append(SLAVE_ADDR_7_BIT)
    elif addr_mode == 10:
        arg_list.append(SLAVE_ADDR_10_BIT)
    elif addr_mode == 15:
        arg_list.append(SLAVE_ADDR_15_BIT)

    arg_list.append("16") # no of bytes to rcv
    arg_list.append(is_restart)

    if addr_mode == 15:
        arg_list.append("15bit")

    # print (arg_list)
    I2C_MONITOR_Stub[i2c_monitor_no].execute_command(arg_list[0], arg_list[1:])


def slave_push_data(observer, args):
    print("Pushing data ..")
    i2c_monitor_no = 0#get_i2c_monitor_no()
    # print("i2c_monitor_no = ", i2c_monitor_no)
    arg_list = ["slave_push_data", "0xA0 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x99 0xAA 0xBB 0xCC 0xDD 0xEE 0xFF"]
    # print (arg_list)
    I2C_MONITOR_Stub[i2c_monitor_no].execute_command(arg_list[0], arg_list[1:])

try:
    # Core & Function Probing
    core_probe = sim.CoreProbe(core_name)

    config_I2C_MONITOR_symbol = core_probe.find_symbol_by_name("config_I2C_MONITOR",'function')
    core_probe.create_begin_instruction_observer(config_I2C_MONITOR, config_I2C_MONITOR_symbol.start_address)

    slave_push_data_symbol = core_probe.find_symbol_by_name("slave_push_data",'function')
    core_probe.create_begin_instruction_observer(slave_push_data, slave_push_data_symbol.start_address)

#    master_send_data_symbol = core_probe.find_symbol_by_name("master_send_data",'function')
#    core_probe.create_begin_instruction_observer(master_send_data, master_send_data_symbol.start_address)

 #   master_receive_data_symbol = core_probe.find_symbol_by_name("master_receive_data",'function')
  #  core_probe.create_begin_instruction_observer(master_receive_data, master_receive_data_symbol.start_address)

    for i2c_monitor_no in range(1): # 0..27
        #probe_name = '/%s/Stubs/I2C/I2C_MONITOR_%d' % (top_inst_name, i2c_monitor_no)
        #probe_name ="/TCP/I2C/I2CExternalBlock_2_CM4_0"
        probe_name ="/S32K388_System/I2C/I2C_IO_STUB_"+str(i2c_monitor_no)
        print(i2c_monitor_no, " probe_name = ", probe_name)
        I2C_MONITOR_Stub.append(sim.CommandProcessorProbe(probe_name))

except StandardError as detail:
    print( os.path.basename(__file__) + " :", detail)
    sim.print_message("Error in script")

sim.suspend_script()
