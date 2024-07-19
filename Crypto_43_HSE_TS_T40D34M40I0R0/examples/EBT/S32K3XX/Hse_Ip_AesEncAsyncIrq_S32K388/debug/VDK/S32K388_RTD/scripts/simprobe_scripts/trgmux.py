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

trgmux_pin_map = {
2: 'S32K388_System/S32K388_MCU/Real_time_Control/ADC_0/p_eoc_out',
3: 'S32K388_System/S32K388_MCU/Real_time_Control/ADC_1/p_eoc_out',
4: 'S32K388_System/S32K388_MCU/Real_time_Control/ADC_2/p_eoc_out',
5: 'S32K388_System/S32K388_MCU/Real_time_Control/LPCMP_0/p_COUT_out', 
6: 'S32K388_System/S32K388_MCU/Real_time_Control/LPCMP_1/p_COUT_out',
10: 'S32K388_System/S32K388_MCU/Core_Systems/eDMA3_0/p_dma_ipd_done_out_16',
11: 'S32K388_System/S32K388_MCU/Core_Systems/eDMA3_0/p_dma_ipd_done_out_17',
56: 'S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_trigger_out_0',
57: 'S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_trigger_out_1',
58: 'S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_trigger_out_2',
59: 'S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_trigger_out_3',
76: 'S32K388_System/S32K388_MCU/Communication/lpi2c_0/p_master_out_trig',
77: 'S32K388_System/S32K388_MCU/Communication/lpi2c_0/p_slave_out_trig',
78: 'S32K388_System/S32K388_MCU/Communication/lpspi_0/p_frame_out_trig',
79: 'S32K388_System/S32K388_MCU/Communication/lpspi_0/p_word_out_trig',
84: 'S32K388_System/S32K388_MCU/Communication/LPUART_0/p_trigger1_out',
85: 'S32K388_System/S32K388_MCU/Communication/LPUART_0/p_trigger2_out',
86: 'S32K388_System/S32K388_MCU/Communication/LPUART_0/p_trigger3_out',
87: 'S32K388_System/S32K388_MCU/Communication/LPUART_1/p_trigger1_out',
88: 'S32K388_System/S32K388_MCU/Communication/LPUART_1/p_trigger2_out',
89: 'S32K388_System/S32K388_MCU/Communication/LPUART_1/p_trigger3_out',
90: 'S32K388_System/S32K388_MCU/Communication/LPUART_2/p_trigger1_out',
91: 'S32K388_System/S32K388_MCU/Communication/LPUART_2/p_trigger2_out',
92: 'S32K388_System/S32K388_MCU/Communication/LPUART_2/p_trigger3_out',
93: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_0',
94: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_1',
95: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_2',
96: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_3',
97: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_4',
98: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_5',
99: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_6',
100: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_7',
101: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_8',
102: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_9',
103: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_10',
104: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_lcu_dff_out_11',
105: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_0',
106: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_1',
107: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_2',
108: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_3',
109: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_4',
110: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_5',
111: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_6',
112: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_7',
113: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_8',
114: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_9',
115: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_10',
116: 'S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_lcu_dff_out_11',
117: 'S32K388_System/S32K388_MCU/Timer/PIT_0/p_trig_out_0',
118: 'S32K388_System/S32K388_MCU/Timer/PIT_0/p_trig_out_1',
119: 'S32K388_System/S32K388_MCU/Timer/PIT_0/p_trig_out_2',
120: 'S32K388_System/S32K388_MCU/Timer/PIT_0/p_trig_out_3',
121: 'S32K388_System/S32K388_MCU/Timer/PIT_0/p_rti_trig_out',
122: 'S32K388_System/S32K388_MCU/Timer/PIT_1/p_trig_out_0',
123: 'S32K388_System/S32K388_MCU/Timer/PIT_1/p_trig_out_1',
124: 'S32K388_System/S32K388_MCU/Timer/PIT_1/p_trig_out_2',
125: 'S32K388_System/S32K388_MCU/Timer/PIT_1/p_trig_out_3',
}



def Raise_TRGMUX_pin_CB(observer, args):
    global trgmux_pin_map
    global mem_start_address, mem_name
    sim.print_message("Raise_TRGMUX_pin_CB")
    pyth_trgmux_source = core_probe.find_symbol_by_name('_ZN6TRGMUX10trgmux_pinE', 'object')
    py_Int_Src = sim.MemoryProbe(mem_name, pyth_trgmux_source.size, pyth_trgmux_source.start_address - mem_start_address)
    Pin_Index = py_Int_Src.get_value()
    print('Pin index is', Pin_Index)
    Trgmux_pin_path = sim.get_full_model_name(trgmux_pin_map[Pin_Index])
    Trgmux_pin = sim.BoolProbe(Trgmux_pin_path)
    if 0 == Trgmux_pin.get_value():
        #print('Asserting : ',Trgmux_pin_path)
        Trgmux_pin.set_value(1)
        
def Lower_TRGMUX_pin_CB(observer, args):
    global trgmux_pin_map
    sim.print_message("Lower_TRGMUX_pin_CB")
    #pyth_trgmux_source = core_probe.find_symbol_by_address(0x900b5b20, 'object')
    pyth_trgmux_source = core_probe.find_symbol_by_name("_ZN6TRGMUX10trgmux_pinE", 'object')
    py_Int_Src = sim.MemoryProbe(mem_name, pyth_trgmux_source.size, pyth_trgmux_source.start_address - mem_start_address)
    Pin_Index = py_Int_Src.get_value()
    #print('Pin index is', Pin_Index)
    Trgmux_pin_path = sim.get_full_model_name(trgmux_pin_map[Pin_Index])
    Trgmux_pin = sim.BoolProbe(Trgmux_pin_path)
    if 1 == Trgmux_pin.get_value():
        #print('Deasserting : ',Trgmux_pin_path)
        Trgmux_pin.set_value(0)

#Main method
print("****TRGMUX simprobe script execution started***")

obs = []
core_probe = sim.CoreProbe(core_name)
  
trgmux_probe_1 = core_probe.find_symbol_by_name('_ZN6TRGMUX6TRGMUX16Raise_Trgmux_PinEv', 'function')
core_probe.create_begin_instruction_observer(Raise_TRGMUX_pin_CB, trgmux_probe_1.start_address)
    
trgmux_probe_2 = core_probe.find_symbol_by_name('_ZN6TRGMUX6TRGMUX16Lower_Trgmux_PinEv', 'function')
core_probe.create_begin_instruction_observer(Lower_TRGMUX_pin_CB, trgmux_probe_2.start_address)
    
    
