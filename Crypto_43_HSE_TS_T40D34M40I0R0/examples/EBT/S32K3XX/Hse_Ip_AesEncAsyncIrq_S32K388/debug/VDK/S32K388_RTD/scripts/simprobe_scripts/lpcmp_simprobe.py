#############################################################################
# Copyright 1996-2021 Synopsys, Inc.                                        #
#                                                                           #
# This Synopsys software and all associated documentation are proprietary   #
# to Synopsys, Inc. and may only be used pursuant to the terms and          #
# conditions of a written license agreement with Synopsys, Inc.             #
# All other use, reproduction, modification, or distribution of the         #
# Synopsys software or the associated documentation is strictly prohibited. #
#############################################################################
import sim
import sys
import os
import re
import sim_utils
import time

core_name = sys.argv[1]
mem_name = "S32K388_System/S32K388_MCU/Memories/TEST_MEM/m_memory"
#mem start address should be one of the memory address where variable gets created (TEST)
mem_start_address = int(0x70000000)

trigger_pin_map = {
0: 'S32K388_System/S32K388_MCU/Timer/RTC_0/p_trigg_en_out'
}



def Raise_trigger_pin_CB(observer, args):
    global trigger_pin_map
    global mem_start_address, mem_name
    sim.print_message("Raise_trigger_pin_CB")
    Pin_Index = 0 #py_Int_Src.get_value()
    Trigger_pin_path = sim.get_full_model_name(trigger_pin_map[Pin_Index])
    Trigger_pin = sim.BoolProbe(Trigger_pin_path)
    if 0 == Trigger_pin.get_value():
        #print('Asserting : ',Trgmux_pin_path)
        Trigger_pin.set_value(1)
        

def lower_trigger_pin_CB(observer, args):
    global trigger_pin_map
    global mem_start_address, mem_name
    sim.print_message("lower_trigger_pin_CB")

    Pin_Index = 0
    Trigger_pin_path = sim.get_full_model_name(trigger_pin_map[Pin_Index])
    Trigger_pin = sim.BoolProbe(Trigger_pin_path)
    Trigger_pin.set_value(0)

        
#Main method
print("****LPCMP simprobe script execution started***")

obs = []
core_probe = sim.CoreProbe(core_name)
  
trigger_probe_1 = core_probe.find_symbol_by_name('_ZN5LPCMP5LPCMP17raise_trigger_pinEv', 'function')
core_probe.create_begin_instruction_observer(Raise_trigger_pin_CB, trigger_probe_1.start_address)

trigger_probe_2 = core_probe.find_symbol_by_name('_ZN5LPCMP5LPCMP17lower_trigger_pinEv', 'function')
core_probe.create_begin_instruction_observer(lower_trigger_pin_CB, trigger_probe_2.start_address)  
    
