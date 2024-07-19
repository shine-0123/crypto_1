#Simprobe handling for BCTU
import os
import sys
import re
import sim

def py_assert_hw_trigger_cb(observer, args):
    print("bctu: py_assert_hw_trigger_cb called ..")
    for i in range(23):
        pin_name = "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_chnl_inout_" + str(i)
        probe = sim.BoolProbe(pin_name)
        probe.set_value(1)

    for i in range(23):
        pin_name = "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_chnl_inout_" + str(i)
        probe = sim.BoolProbe(pin_name)
        probe.set_value(1)

    for i in range(23):
        pin_name = "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_chnl_inout_" + str(i)
        probe = sim.BoolProbe(pin_name)
        probe.set_value(1)

try:
    print("#---In BCTU test Py script---#")
    
    core_name = sys.argv[1]
    #print(core_name)
    core_probe = sim.CoreProbe(core_name)
    func_probe1 = core_probe.find_symbol_by_name('_Z23py_assert_emois_triggerv', 'function') # '_Z20py_assert_emois_triggerv'
    #print('symbol name for py_assert_hw_trigger is %s', func_probe1.name)
    core_probe.create_begin_instruction_observer(py_assert_hw_trigger_cb, func_probe1.start_address)

except StandardError as detail:
        print "Error: ",detail

        sim.print_message("PY:- ERROR. bctu test Py script.")
