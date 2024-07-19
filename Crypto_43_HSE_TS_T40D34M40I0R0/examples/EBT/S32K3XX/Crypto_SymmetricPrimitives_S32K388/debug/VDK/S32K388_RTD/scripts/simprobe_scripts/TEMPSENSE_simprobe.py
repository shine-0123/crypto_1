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

probe_name = "/S32K388_System/S32K388_MCU/Misc/TMU_0"
      
def py_set_temperature_scml_lc_cb(observer, args):
   cmdProbe = sim.CommandProcessorProbe(probe_name)
   cmdProbe.execute_command("set_temperature", ["26.5838"])
   
    
try:
    print("#---In TEMPSENSE test Py script---#")
    
    core_name = sys.argv[1]
    #print(core_name)
    core_probe = sim.CoreProbe(core_name)
    
    print(core_probe)
    func_probe1 = core_probe.find_symbol_by_name('_Z26py_set_temperature_scml_lcv', 'function') # '_Z26py_set_temperature_scml_lc'
    #print('symbol name for py_assert_hw_trigger is %s', func_probe1.name)
    core_probe.create_begin_instruction_observer(py_set_temperature_scml_lc_cb, func_probe1.start_address)    

    
except StandardError as detail:
        print "Error: ",detail

        sim.print_message("PY:- ERROR. TEMPSENSE test Py script.")


sim.suspend_script()