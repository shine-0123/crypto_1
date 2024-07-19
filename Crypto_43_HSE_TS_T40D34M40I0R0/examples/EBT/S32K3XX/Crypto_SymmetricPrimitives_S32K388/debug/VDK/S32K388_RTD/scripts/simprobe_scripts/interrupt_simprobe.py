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

interrupt_map = {
4: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_0',
5: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_1',
6: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_2',
7: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_3',
8: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_4',
9: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_5',
10: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_6',
11: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_7',
12: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_8',
13: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_9',
14: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_10',
15: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_11',
16: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_12',
17: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_13',
18: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_14',
19: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_15',
20: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_16',
21: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_17',
22: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_18',
23: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_19',
24: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_20',
25: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_21',
26: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_22',
27: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_23',
28: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_24',
29: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_25',
30: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_26',
31: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_27',
32: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_28',
33: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_29',
34: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_30',
35: '/Core_Systems/eDMA3_0/p_dma_ipi_int_out_31',
39: '/Timer/Stm_0/p_irq_out_0',
40: '/Timer/Stm_1/p_irq_out_1',
41: '/Timer/Stm_2/p_irq_out_2',
42: '/Timer/SWT_0/p_irq_out',
43: '/Timer/SWT_1/p_irq_out',
44: '/Timer/SWT_2/p_irq_out',
48: '/Memories/PFLASH/p_pec_intr_out',
49: '/Memories/PFLASH/p_wdog_intr_out',
50: '/Memories/PFLASH/p_xwdog_intr_out',
51: '/Reset_Boot/MC_RGM_0/ipi_int',
52: '/Modes_Power_Management/PMC_0/p_HVD_intr',
53: '/Core_Systems/SIUL2_0/p_irq_out_0__pin',
54: '/Core_Systems/SIUL2_0/p_irq_out_1__pin',
55: '/Core_Systems/SIUL2_0/p_irq_out_2__pin',
56: '/Core_Systems/SIUL2_0/p_irq_out_3__pin',
57: '/Timer/Stm_3/p_irq_out_3',
58: '/Timer/SWT_3/p_irq_out',
61: '/Real_time_Control/eMIOS_0/p_emios_intr_out_20',
62: '/Real_time_Control/eMIOS_0/p_emios_intr_out_16',
63: '/Real_time_Control/eMIOS_0/p_emios_intr_out_12',
64: '/Real_time_Control/eMIOS_0/p_emios_intr_out_8',
65: '/Real_time_Control/eMIOS_0/p_emios_intr_out_4',
66: '/Real_time_Control/eMIOS_0/p_emios_intr_out_0',
69: '/Real_time_Control/eMIOS_1/p_emios_intr_out_20',
70: '/Real_time_Control/eMIOS_1/p_emios_intr_out_16',
71: '/Real_time_Control/eMIOS_1/p_emios_intr_out_12',
72: '/Real_time_Control/eMIOS_1/p_emios_intr_out_8',
73: '/Real_time_Control/eMIOS_1/p_emios_intr_out_4',
74: '/Real_time_Control/eMIOS_1/p_emios_intr_out_0',
77: '/Real_time_Control/eMIOS_2/p_emios_intr_out_20',
78: '/Real_time_Control/eMIOS_2/p_emios_intr_out_16',
79: '/Real_time_Control/eMIOS_2/p_emios_intr_out_12',
80: '/Real_time_Control/eMIOS_2/p_emios_intr_out_8',
81: '/Real_time_Control/eMIOS_2/p_emios_intr_out_4',
82: '/Real_time_Control/eMIOS_2/p_emios_intr_out_0',
83: '/S32K388_MCU/Modes_Power_Management/WKPU_0/p_intrVct_out_0',
84: '/Safety/CMU_0/p_fhh_intr_out',
85: '/Safety/CMU_1/p_fll_intr_out',
86: '/Safety/CMU_2/p_fll_intr_out',
87: '/Real_time_Control/BCTU_0/p_ipi_int_trg_out',
92: '/Real_time_Control/LCU_0/p_int_req_out_0',
93: '/Real_time_Control/LCU_1/p_int_req_out_1',
96: '/Timer/PIT_0/p_irq_out_0',
97: '/Timer/PIT_1/p_irq_out_1',
98: '/Timer/PIT_2/p_irq_out_2',
99: '/Timer/PIT_3/p_irq_out_3',
102: '/Timer/RTC_0/p_api_irq_out',
109: '/Communication/FlexCAN_0/p_irq_boff_out',
110: '/Communication/FlexCAN_0/p_irq_out_0',
111: '/Communication/FlexCAN_0/p_irq_out_32',
112: '/Communication/FlexCAN_0/p_irq_out_64',
113: '/Communication/FlexCAN_1/p_irq_boff_out',
114: '/Communication/FlexCAN_1/p_irq_out_0',
115: '/Communication/FlexCAN_1/p_irq_out_32',
116: '/Communication/FlexCAN_2/p_irq_boff_out',
117: '/Communication/FlexCAN_2/p_irq_out_0',
118: '/Communication/FlexCAN_2/p_irq_out_32',
119: '/Communication/FlexCAN_3/p_irq_boff_out',
120: '/Communication/FlexCAN_3/p_irq_out_0',
121: '/Communication/FlexCAN_4/p_irq_boff_out',
122: '/Communication/FlexCAN_4/p_irq_out_0',
123: '/Communication/FlexCAN_5/p_irq_boff_out',
124: '/Communication/FlexCAN_5/p_irq_out_0',
125: '/Communication/FlexCAN_6/p_irq_boff_out',
126: '/Communication/FlexCAN_6/p_irq_out_0',
127: '/Communication/FlexCAN_7/p_irq_boff_out',
128: '/Communication/FlexCAN_7/p_irq_out_0',
129: '/Communication/FlexCAN_1/p_irq_out_64',
130: '/Communication/FlexCAN_2/p_irq_out_64',
131: '/Communication/FlexCAN_3/p_irq_out_32',
132: '/Communication/FlexCAN_4/p_irq_out_32',
133: '/Communication/FlexCAN_5/p_irq_out_32',
134: '/Communication/FlexCAN_6/p_irq_out_32',
135: '/Communication/FlexCAN_7/p_irq_out_32',
141: '/Communication/LPUART_0/p_tx_interrupt_out',
142: '/Communication/LPUART_1/p_rx_interrupt_out',
143: '/Communication/LPUART_2/p_tx_interrupt_out',
144: '/Communication/LPUART_3/p_rx_interrupt_out',
145: '/Communication/LPUART_4/p_tx_interrupt_out',
146: '/Communication/LPUART_5/p_rx_interrupt_out',
147: '/Communication/LPUART_6/p_tx_interrupt_out',
148: '/Communication/LPUART_7/p_rx_interrupt_out',
149: '/Communication/LPUART_8/p_tx_interrupt_out',
150: '/Communication/LPUART_9/p_rx_interrupt_out',
151: '/Communication/LPUART_10/p_tx_interrupt_out',
152: '/Communication/LPUART_11/p_rx_interrupt_out',
153: '/Communication/LPUART_12/p_tx_interrupt_out',
154: '/Communication/LPUART_13/p_rx_interrupt_out',
155: '/Communication/LPUART_14/p_tx_interrupt_out',
156: '/Communication/LPUART_15/p_rx_interrupt_out',
161: '/Communication/lpi2c_0/p_m_tdf_intr',
162: '/Communication/lpi2c_1/p_m_tdf_intr',
165: '/Communication/lpspi_0/p_tdf_intr',
166: '/Communication/lpspi_1/p_tdf_intr',
167: '/Communication/lpspi_2/p_tdf_intr',
168: '/Communication/lpspi_3/p_tdf_intr',
169: '/Communication/lpspi_4/p_tdf_intr',
170: '/Communication/lpspi_5/p_tdf_intr',
171: '/Communication/GMAC_1/sbd_intr_o',
172: '/Communication/GMAC_1/sbd_perch_tx_intr_o_0',
173: '/Communication/QuadSPI_0/p_ipi_int_tfff_out',
180: '/Real_time_Control/ADC_0/p_irq_adc_er_out',
181: '/Real_time_Control/ADC_1/p_irq_adc_er_out',
182: '/Real_time_Control/ADC_2/p_irq_adc_er_out',
183: '/Real_time_Control/LPCMP_0/p_interrupt_out_0',
184: '/Real_time_Control/LPCMP_1/p_interrupt_out_0',
185: '/Real_time_Control/LPCMP_2/p_interrupt_out_0',
224: '/Communication/GMAC_0/sbd_intr_o',
225: '/Communication/GMAC_0/sbd_perch_tx_intr_o_0',
226: '/Communication/GMAC_0/sbd_perch_rx_intr_o_0',
227: '/Communication/GMAC_0/sbd_perch_tx_intr_o_1',
228: '/Communication/GMAC_0/sbd_perch_rx_intr_o_1',
229: '/Communication/GMAC_0/sbd_perch_tx_intr_o_2',
230: '/Communication/GMAC_0/sbd_perch_rx_intr_o_2',
231: '/Communication/GMAC_0/sbd_sfty_ce_intr_o',
232: '/Communication/GMAC_0/sbd_sfty_ue_intr_o',
233: '/Communication/GMAC_1/sbd_perch_rx_intr_o_0',
234: '/Communication/GMAC_1/sbd_perch_tx_intr_o_1',
235: '/Communication/GMAC_1/sbd_perch_rx_intr_o_1',
236: '/Communication/GMAC_1/sbd_perch_tx_intr_o_2',
237: '/Communication/GMAC_1/sbd_perch_rx_intr_o_2',
238: '/Communication/GMAC_1/sbd_sfty_ce_intr_o',
239: '/Communication/GMAC_1/sbd_sfty_ue_intr_o',
}



def Raise_Interrupt_CB(observer, args):
    global interrupt_map
    global mem_start_address, mem_name
    #sim.print_message("Raise_Interrupt_CB")
    pyth_Interrupt_source = core_probe.find_symbol_by_name('_ZN9Interrupt8intr_srcE', 'object')
    py_Int_Src = sim.MemoryProbe(mem_name, pyth_Interrupt_source.size, pyth_Interrupt_source.start_address - mem_start_address)
    NVIC_index = py_Int_Src.get_value()
    #print('NVIC index is', NVIC_index)
    Irq_Pin_path = sim.get_full_model_name(interrupt_map[NVIC_index])
    Irq_Pin = sim.BoolProbe(Irq_Pin_path)
    if 0 == Irq_Pin.get_value():
        #print('Asserting : ',Irq_Pin_path)
        Irq_Pin.set_value(1)
        
def Lower_Interrupt_CB(observer, args):
    global interrupt_map
    #sim.print_message("Lower_Interrupt_CB")
    #pyth_Interrupt_source = core_probe.find_symbol_by_address(0x900b5b20, 'object')
    pyth_Interrupt_source = core_probe.find_symbol_by_name("_ZN9Interrupt8intr_srcE", 'object')
    py_Int_Src = sim.MemoryProbe(mem_name, pyth_Interrupt_source.size, pyth_Interrupt_source.start_address - mem_start_address)
    NVIC_index = py_Int_Src.get_value()
    #print('NVIC index is', NVIC_index)
    Irq_Pin_path = sim.get_full_model_name(interrupt_map[NVIC_index])
    Irq_Pin = sim.BoolProbe(Irq_Pin_path)
    if 1 == Irq_Pin.get_value():
        #print('Deasserting : ',Irq_Pin_path)
        Irq_Pin.set_value(0)

#Main method
print("****Interrupt simprobe script execution started***")

obs = []
core_probe = sim.CoreProbe(core_name)
  
Interrupt_probe_1 = core_probe.find_symbol_by_name('_ZN9Interrupt9Interrupt15Raise_InterruptEv', 'function')
core_probe.create_begin_instruction_observer(Raise_Interrupt_CB, Interrupt_probe_1.start_address)
    
Interrupt_probe_2 = core_probe.find_symbol_by_name('_ZN9Interrupt9Interrupt15Lower_InterruptEv', 'function')
core_probe.create_begin_instruction_observer(Lower_Interrupt_CB, Interrupt_probe_2.start_address)
    
    
