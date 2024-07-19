##############################################################################
# SYNOPSYS CONFIDENTIAL - This is an unpublished, confidential, and          #
# proprietary work of Synopsys, Inc., and may be subject to patent,          #
# copyright, trade secret, and other legal or contractual protection.        #
# This work may be used only pursuant to the terms and conditions of a       #
# written license agreement with Synopsys, Inc. All other use, reproduction, #
# distribution, or disclosure of this work is strictly prohibited.           #
##############################################################################
import os
import sys
import re
import sim
import sim_utils

# Platform variable
core_name = ""
core_path = ""
mem_name = "/S32K388_System/S32K388_MCU/Memories/TEST_MEM/m_memory"
mem_start_address = int(0x70000000)
top_node = "S32K388_System"

#pass core name as argument
core_probe = sim.CoreProbe(sys.argv[1])

print("core_probe =" + str(sys.argv[1]))

write_to_variable = ""
pins = [
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_0"%top_node], # eMIOS_0
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_1"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_2"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_3"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_4"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_5"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_6"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_7"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_8"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_9"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_10"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_11"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_12"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_13"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_14"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_15"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_16"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_17"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_18"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_19"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_20"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_21"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_22"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_intr_out_23"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_0"%top_node], # eMIOS_1
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_1"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_2"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_3"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_4"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_5"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_6"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_7"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_8"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_9"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_10"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_11"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_12"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_13"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_14"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_15"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_16"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_17"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_18"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_19"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_20"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_21"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_22"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_intr_out_23"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_0"%top_node], # eMIOS_2
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_1"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_2"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_3"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_4"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_5"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_6"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_7"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_8"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_9"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_10"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_11"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_12"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_13"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_14"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_15"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_16"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_17"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_18"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_19"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_20"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_21"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_22"%top_node],
    [None, "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_intr_out_23"%top_node],
]


def set_value_of(variable_name, val, debug = False):  # API to write to C/C++ variable
    global mem_name
    global mem_start_address

    var = core_probe.find_symbol_by_name(variable_name, 'object')
    if debug == True:
        print variable_name, " ========================================= "
        print "var.start_address = ", hex(var.start_address)
        print "mem_start_address = ", hex(mem_start_address)
        print "var.size = ", var.size
        print "var.start_address - mem_start_address = ", hex(var.start_address - mem_start_address)

    var_probe = sim.MemoryProbe(
        mem_name, var.size, (var.start_address - mem_start_address))
        # mem_name, var.size, (var.start_address - mem_start_address) - 0x4)
    var_probe.set_value(val)


def get_value_of_c_code_variable(variable_name,  debug=False):# API to write to C/C++ variable
    global mem_name
    global mem_start_address
    print("mem_naem = " + str(mem_name))

    var = core_probe.find_symbol_by_name(variable_name, 'object')
    if debug == True:
        print variable_name, " ========================================= "
        print "var.start_address = ", hex(var.start_address)
        print "mem_start_address = ", hex(mem_start_address)
        print "var.size = ", var.size
        print "var.start_address - mem_start_address = ", hex(var.start_address - mem_start_address)

    var_probe = sim.MemoryProbe(mem_name, var.size, var.start_address - mem_start_address)

    if debug == True:
        print "var_probe.get_value() = ", hex(var_probe.get_value())
        print "___________________________________________________________"
    return var_probe.get_value()


#
# Description: Analyse waveform
#
first_high_time = 0
is_first_time = True
def analyse_frequency_cb(pin_probe):
    global write_to_variable
    global first_high_time
    global is_first_time

    # sim.print_message("analyse_frequency_cb+++++++++++++++")

    # Mark 1st High i.e. start of cycle
    if is_first_time == True:
        is_first_time = False
        first_high_time = sim.get_time_in_unit('ns')
        # sim.print_message( "pulse start = " + sim.get_time_in_unit('ns'))
        pin_probe.callback_on_value(1)

    # Mark 2nd High i.e. end of cycle & calculate period
    else:
        period = (sim.get_time_in_unit('ns') - first_high_time)
        # sim.print_message( "pulse end  = " + sim.get_time_in_unit('ns'))
        # sim.print_message( " int(round(period)) = " +  int(round(period)))
        # sim.print_message( "write_to_variable = " + write_to_variable)
        set_value_of(write_to_variable, int(round(period)), debug = False)

        period = 0
        is_first_time = True
        first_high_time = 0

# Description: Stop pattern on pin/signal
def start_waveform_cb(observer, args):
    global pins
    no = get_value_of_c_code_variable("pin_no",  debug=False)
    # sim.print_message("start_waveform_cb: no = " + str(no))
    print "start_waveform_cb: no = ", str(no)
   
    pins[no][0].start()
    print "___________________________________________________________"

# Description: Stop pattern on pins/signal
def stop_waveform_cb(observer, args):
    global pins
    no = get_value_of_c_code_variable("pin_no",  debug=False)
     #sim.print_message("stop_waveform_cb: no = " + str(no))
    print "stop_waveform_cb: no = ", str(no)
    pins[no][0].stop()
    print "___________________________________________________________"

# Description: Pause pattern on pins/signal
def pause_waveform_cb(observer, args):
    global pins
    no = get_value_of_c_code_variable("pin_no",  debug=False)
     #sim.print_message("pause_waveform_cb: no = " + str(no))
    print "pause_waveform_cb: no = ", str(no)
    pins[no][0].pause(0)
    print "___________________________________________________________"

#
# Description: Generate pattern on pins/signal
#
def create_waveform_cb(observer, args):
    global pins
    print('Create Waveform Callback ...')
    no = get_value_of_c_code_variable("pin_no",  debug=False)
    pulse_period = get_value_of_c_code_variable("pulse_period",  debug=False)
    pulse_high_time = get_value_of_c_code_variable("pulse_high_time",  debug=False)
    pulse_start_state = get_value_of_c_code_variable("pulse_start_state",  debug=False)
    pulse_repeat = get_value_of_c_code_variable("pulse_repeat",  debug=False)
    pulse_cnt = get_value_of_c_code_variable("pulse_cnt",  debug=False)

    sim.print_message("no = " + str(no))
    sim.print_message("pins[no] = " + str(pins[no]))
    sim.print_message("pulse_period = " + str(pulse_period))
    sim.print_message("pulse_high_time = " + str(pulse_high_time))
    sim.print_message("pulse_start_state = " + str(pulse_start_state))
    sim.print_message("pulse_repeat = " + str(pulse_repeat))
    sim.print_message("pulse_cnt = " + str(pulse_cnt))

    probe = sim.BoolProbe(pins[no][1])
    pins[no][0].update(probe, (pulse_period, 'ns'), (pulse_high_time, 'ns'), pulse_start_state, pulse_repeat, start = False)
    # sim.print_message("____________________________________________________")


def get_sys_clk_cb(observer, args):
    global eMIOS_0_sys_clk
    # sim.print_message("get_sys_clk_cb")
    eMIOS_0_sys_clk.callback_on_value_change(0)


def p_emios_gtbe_in_cb(observer, args):
    global eMIOS_0_sys_clk, top_node
    #sim.print_message("p_emios_gtbe_in_cb")
    #sim.print_message("p_emios_gtbe_in asserted")
    probe = sim.BoolProbe("/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_gtbe_in"%top_node)
    probe.set_value(1)
    probe = sim.BoolProbe("/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_gtbe_in"%top_node)
    probe.set_value(1)


def set_counter_bus_cb(observer, args):
    # sim.print_message("set_counter_bus_cb")
    global top_node
    bus_name_eMIOS_0 = [
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_counter_bus_0"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_counter_bus_1"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_counter_bus_2"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_counter_bus_3"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_counter_bus_4"%top_node,
    ]
    bus_name_eMIOS_1 = [
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_counter_bus_0"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_counter_bus_1"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_counter_bus_2"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_counter_bus_3"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_counter_bus_4"%top_node,
    ]
    bus_name_eMIOS_2 = [
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_counter_bus_0"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_counter_bus_1"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_counter_bus_2"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_counter_bus_3"%top_node,
        "/%s/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_counter_bus_4"%top_node,
    ]
    idx = get_value_of_c_code_variable("counter_bus_idx",  debug=False)
    value = get_value_of_c_code_variable("counter_bus_value",  debug=False)

    # sim.print_message("idx = " + str(idx))
    # sim.print_message("value = " + str(value))
    # sim.print_message("bus_name_eMIOS_0[idx] = " + str(bus_name_eMIOS_0[idx]))
    # sim.print_message("bus_name_eMIOS_1[idx] = " + str(bus_name_eMIOS_1[idx]))
    # sim.print_message("bus_name_eMIOS_2[idx] = " + str(bus_name_eMIOS_2[idx]))

    # eMIOS_0
    probe = sim.UintProbe( bus_name_eMIOS_0[idx] )
    probe.set_value(value)
    probe.set_clamp_value(value)

    # eMIOS_1
    probe = sim.UintProbe( bus_name_eMIOS_1[idx] )
    probe.set_value(value)
    probe.set_clamp_value(value)
    
    # eMIOS_2
    probe = sim.UintProbe( bus_name_eMIOS_2[idx] )
    probe.set_value(value)
    probe.set_clamp_value(value)
    
    # sim.print_message("____________________________________________________")




def create_function_observer(core_probe, function, callback):
    sym = core_probe.find_symbol_by_name(function, "function")
   # print("sym.start_address = " + str(sym.start_address))
    obs = core_probe.create_about_to_execute_instruction_observer(callback, sym.start_address, sym.start_address)
    return obs


#Main method
print("****eMIOS simprobe script execution started***")

for pin in pins:
    probe = sim.BoolProbe(pin[1])
    pin[0] = sim_utils.LogicWaveform(probe, (2, 'ns'), (1, 'ns'), 0, 1, start = False)
    pin[0].stop()

# attaching c++ trigger function with python callback
eMIOS0_obs = create_function_observer(core_probe, "_Z17created_waveform_v", create_waveform_cb)
eMIOS1_obs = create_function_observer(core_probe, "_Z14stop_waveform_v", stop_waveform_cb)
eMIOS2_obs = create_function_observer(core_probe, "_Z15start_waveform_v", start_waveform_cb)
eMIOS3_obs = create_function_observer(core_probe, "_Z15pause_waveform_v", pause_waveform_cb)
eMIOS4_obs = create_function_observer(core_probe, "_Z16p_emios_gtbe_in_v", p_emios_gtbe_in_cb)


