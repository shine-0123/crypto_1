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
import time

ncf_0 = "/S32K388_System/S32K388_MCU/Safety/FCCU_0/p_ncf_in_0"
ncf_7 = "/S32K388_System/S32K388_MCU/Safety/FCCU_0/p_ncf_in_7"

ncf_1 = "/S32K388_System/S32K388_MCU/Safety/FCCU_0/p_ncf_in_1"
ncf_6 = "/S32K388_System/S32K388_MCU/Safety/FCCU_0/p_ncf_in_6"

aes_mux_xbic = "/S32K388_System/S32K388_MCU/Core_Systems/AES_MUX_XBIC/p_error_out"
intm_error_out = "/S32K388_System/S32K388_MCU/Core_Systems/INTM_0/p_intm_monitor_error_out_0"
def py_set_fault_src_cb(observer, args):
    print ("set fault source")
    fault_0_probe = sim.BoolProbe(ncf_0)
    fault_0_probe.set_clamp_value(1)
    
    fault_7_probe = sim.BoolProbe(ncf_7)
    fault_7_probe.set_clamp_value(1)
    
def py_set_fault_src_1_6_cb(observer, args):
    print ("set fault source 1 and 6")
#     fault_1_probe = sim.BoolProbe(ncf_1)
    fault_1_probe = sim.BoolProbe(aes_mux_xbic)
    fault_1_probe.set_clamp_value(1)
    
#     fault_6_probe = sim.BoolProbe(ncf_6)
    fault_6_probe = sim.BoolProbe(intm_error_out)
    fault_6_probe.set_clamp_value(1)
    

try:
    print("#---In FCCU test Py script---#")
    
    core_name = sys.argv[1]
    #print(core_name)
    core_probe = sim.CoreProbe(core_name)
    
    print(core_probe)
    func_probe1 = core_probe.find_symbol_by_name('_Z16py_set_fault_srcv', 'function') # '_Z16py_set_fault_srcv'
#     func_probe1 = core_probe.find_symbol_by_address(0x000000000047eb48, 'function') # '_Z16py_set_fault_srcv'
    func_probe2 = core_probe.find_symbol_by_name('_Z20py_set_fault_src_1_6v', 'function') # '_Z20py_set_fault_srcv'
#     print('symbol name for _Z16py_set_fault_srcv is %s', func_probe1.name)
    core_probe.create_begin_instruction_observer(py_set_fault_src_cb, func_probe1.start_address)    
    core_probe.create_begin_instruction_observer(py_set_fault_src_1_6_cb, func_probe2.start_address)    

    
except StandardError as detail:
        print "Error: ",detail

        sim.print_message("PY:- ERROR. FCCU test Py script.")


sim.suspend_script()