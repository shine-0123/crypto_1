#############################################################################
# Copyright 1996-2016 Synopsys, Inc.                                        #
#                                                                           #
# This Synopsys software and all associated documentation are proprietary   #
# to Synopsys, Inc. and may only be used pursuant to the terms and          #
# conditions of a written license agreement with Synopsys, Inc.             #
# All other use, reproduction, modification, or distribution of the         #
# Synopsys software or the associated documentation is strictly prohibited. #
#############################################################################
import os
import subprocess
import threading
import time
# Used for finding all the pathnames matching a specified pattern according to the rules used by the Unix shell.
import glob
import imp
Breakpoints = []
test_mem_name = '/S32K312_System/S32K312_MCU/Memories/TEST_MEM/m_memory'
test_addr_siul = 0x10000000
test_addr_idx = 0x4000000


if "VMAF_DIR" in os.environ:
    global vmaf_dir
    vmaf_dir = os.environ['VMAF_DIR']

    imp.load_source('VMAF', vmaf_dir+'/VMAF.py')
    from VMAF import *

#############################################################################
# start_failed callback
#############################################################################
def start_failed_cb(sim):
    print('Error: simulation start failed!')
    vpx.remove_all_breakpoints(False)


#############################################################################
# Create sim probe thread
#############################################################################
def create_simprobes(core_name):
    s32k_plat = "S32K312"
    core =""
    if core_name == "CM7_0":
        core ='S32K312_System.S32K312_MCU.CPU_SS.CLUSTER_0.cpu0'

    vpconfig_dir = os.path.dirname(vpx.get_current_vpconfig().get_path())
    simprobe_dir = os.path.join(vpconfig_dir, '..', 'shared', 'simprobe_scripts')


def write_iopad():
    print("write_iopad")
    iopad_num = vpx.get_node(test_mem_name+"["+str(test_addr_idx+2)+"]").get_value()
    write_val = vpx.get_node(test_mem_name+"["+str(test_addr_idx+3)+"]").get_value()
    print("IOPAD:", iopad_num, "WRITE_VAL: ", write_val)
    if (write_val == '0'):
        #if(iopad_num in iopad.keys()):
        vpx.get_node(iopad[int(iopad_num)]).send_command("override_value 0")
        vpx.get_node(iopad[int(iopad_num)]).send_command("disable_override")
    else:
        #if(iopad_num in iopad.keys()):
        vpx.get_node(iopad[int(iopad_num)]).send_command("override_value 1")
        vpx.get_node(iopad[int(iopad_num)]).send_command("disable_override")
    vpx.get_node(test_mem_name+"["+str(test_addr_idx+0)+"]").set_value(0)

def read_iopad():
    print("read_iopad")
    iopad_num = vpx.get_node(test_mem_name+"["+str(test_addr_idx+2)+"]").get_value()
    read_val = vpx.get_node(iopad[int(iopad_num)]+'/inout').get_value()
    if(int(read_val) > int(0)):
        print("setting pad %d to 1, got value %s" % (int(iopad_num),str(read_val)))
        vpx.get_node(test_mem_name+"["+str(test_addr_idx+4)+"]").set_value(1)
    else:
        print("setting pad %d to 0, got value %s" % (int(iopad_num),str(read_val)))
        vpx.get_node(test_mem_name+"["+str(test_addr_idx+4)+"]").set_value(0)
    vpx.get_node(test_mem_name+"["+str(test_addr_idx+1)+"]").set_value(0)

def create_breakpoints():
    test_mem0 = vpx.get_node(test_mem_name+"["+str(test_addr_idx+0)+"]")
    bp0 = test_mem0.create_breakpoint('after_write')
    bp0.set_callback('write_iopad()')
    Breakpoints.append(bp0)
    test_mem1 = vpx.get_node(test_mem_name+"["+str(test_addr_idx+1)+"]")
    bp1 = test_mem1.create_breakpoint('after_write')
    bp1.set_callback('read_iopad()')
    Breakpoints.append(bp1)
    test_mem2 = vpx.get_node(test_mem_name+"["+str(test_addr_idx+5)+"]")
    bp2 = test_mem2.create_breakpoint('after_write')
    bp2.set_callback('write_double_iopad()')
    Breakpoints.append(bp2)
    #10 index of memory is used
    #software will write on this memory addr which would be 10*4
    test_mem3 = vpx.get_node(test_mem_name+"["+str(test_addr_idx+10)+"]")
    bp3 = test_mem3.create_breakpoint('after_write')
    bp3.set_callback('write_double_iopad_adc()')
    Breakpoints.append(bp3)


        
#############################################################################
# connected callback
#############################################################################
def connected_cb(sim):
    global Breakpoints
    print ("Connect CB")
    print ("Setup breakpoint")
    #create_breakpoints()
    vpCfg = vpx.get_current_vpconfig()
    core_name = vpCfg.get_environment_variable('core_name')
    if core_name != "M0PLUS":
	    create_simprobes(core_name)
	    boot_init(core_name)
    #else :
        #create_hse_simprobes(core_name)
    #time.sleep(5)
    vpx.get_breakpoint(0).set_callback('initial_crunch_cb(__sim__)')


#############################################################################
# Bootup Initialization (these lines were taken from "launch_common_R52.tcl")
#############################################################################
def boot_setup(core_num, start_address):
    TEST_MEM ='/S32K312_System/S32K312_MCU/Memories/TEST_MEM'
    print("boot_setup called; core ID = %d", core_num)
    mem_addr = (0x4000000 + 0x400 + core_num)
    vpx.get_node(vpx.get_full_model_path( TEST_MEM + "/m_memory")).set_value(start_address,mem_addr)
    vpx.get_node(vpx.get_full_model_path( TEST_MEM + "/m_memory")).set_value(0x1,(mem_addr + 0x4))
    

def boot_init(core_name):
    print("boot init")
    #vpCfg = vpx.get_current_vpconfig()
    #core_name = vpCfg.get_environment_variable('core_name')
    core_ID = int(core_name[-1])
    boot_setup(core_ID, 0x00500800)
    


#############################################################################
# This method loads on 'cpuName' the symbols from the executable and sets up a breakpoint at the 'symbolName' symbol.
# E.G.: For S32S, cpuName could be 'ECU.MCU.Base.Cores.CPU_clusters.R52_0.cpu0'
#############################################################################
def setSimulatorBreakpoint(cpuName, symbolList):
    simWorkingDir = vpx.get_simulation_working_directory()
    print (simWorkingDir)

    cpu = vpx.get_core(cpuName)

    testBinaryImagePath = os.path.abspath(glob.glob(simWorkingDir + '/../../../../*.elf')[0])
    print (testBinaryImagePath)

    cpu.load_symbols([[testBinaryImagePath]])
    symbolTable = cpu.get_symboltable(testBinaryImagePath)
    for symbolName in symbolList:
        symbolNameList = symbolTable.get_symbols(symbolName)
        if (len(symbolNameList) > 0):
            symbol = symbolNameList[0]
            bp=cpu.create_breakpoint(str(symbol.startAddress))
            if symbolList[symbolName] is not None:
                bp.set_callback(symbolList[symbolName])
        else:
            print ("The %s symbol does not exist" % symbolName)

#############################################################################
# disconnected callback
#############################################################################
def disconnected_cb(sim):
    global t32_process_handle
    
    # If the T32 child process was opened
    if (t32_process_handle is not None):
        # If T32 child process is not terminated
        if (t32_process_handle.poll() is None):
            t32_process_handle.terminate()
    
#vpx.remove_all_breakpoints(False)  

#############################################################################
# 
#############################################################################
def check_MCD_debugger_connected():
    MCD_debugger_connected_to_sim = 0
    client_list = vpx.get_vpsession_clients()
    for client in client_list:
        if str(client).startswith('MCD_'):
           MCD_debugger_connected_to_sim = 1
        if str(client).startswith('TRACE32_'):
           MCD_debugger_connected_to_sim = 1
    return int(MCD_debugger_connected_to_sim)
    
#############################################################################
# 
#############################################################################
  
def auto_continue(sim):
    try:
        sim.continue_simulation()
    except:
        return

    # When not in batch mode, we explicitly auto-continue.
    try:
        sim.wait_interrupted_or_exited()
    except:
        # If we caught an exception here, it is because the wait command timed out while waiting for runfor to complete.
        print ("Error: The simulation took longer than expected and is being timed out.")

    try:
        sim.stop_simulation()
    except:
        # The auto-terminate should have already done the stop_simulation so this may error out.
        pass

def register_auto_continue():
    vpx.register_run_proc( 'auto_continue(__sim__)' )


#############################################################################
# initial_crunch callback - last connected callback
#############################################################################
def initial_crunch_cb(sim):
    global t32_process_handle
    global thread
    count = 0
    is_connected = 0
   
    register_auto_continue()
    
    t32_process_handle = subprocess.Popen(os.environ['TEST_T32_CMD'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False)
    thread = threading.Thread(target = trace32_check, args=(t32_process_handle,))
    thread.start()
    # Count is in ms
    while (count < 5000):
        time.sleep(0.010) # Poll every 10ms
        count = count + 1
        is_connected = check_MCD_debugger_connected() # int(vpx.submit_vpx_tcl_cmd('check_MCD_debugger_connected'))
        if is_connected == 1:
            print ("...debugger connected after %.2f sec.\n" % (count / 100.0))
            time.sleep(0.25) # Wait 250ms for the debugger to attach to the core (SYStem.Mode.Attach)
            break
    if is_connected == 0:
        print ('Timeout occurred for T32 connection (timeout value is: %.2f seconds).' % (count / 100.0))
        vpx.stop_simulation()

#############################################################################
# Trace32 thread to check if instance is still running
#############################################################################
def trace32_check(t32_process_handle):
    # Wait for the child process (T32) to terminate.
    t32_process_handle.wait()
    # Stop the simulation when T32 exits\
    try:
        sim_state = sim.get_simulation_state()
        if not ((sim_state == 'TERMINATED') or (sim_state == 'DISCONNECTED')):
            sim.stop_simulation()
    except:
        if not ((os.getenv('DEBUG_APP') == 'ON') or (os.getenv('TEST') == 'run')):
            sim.stop_simulation()
        pass


def test_callback():
    print ("reach the end of test")
    vpx.remove_all_breakpoints(False)
#############################################################################
# main
#############################################################################

t32_process_handle = None
thread = None

# register callbacks for required events
vpx.add_callback('start_failed', 'start_failed_cb(__sim__)')
vpx.add_callback('connected', 'connected_cb(__sim__)')
vpx.add_callback('disconnected', 'disconnected_cb(__sim__)')

if "VMAF_DIR" in os.environ:
    vpx.add_callback('connected', 'check_flag()')
