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

#memory names : pflash
mem_name = "/S32K388_System/S32K388_MCU/Memories/PFLASH/mUtest"
func_reset_name = "/S32K388_System/S32K388_MCU/Security_Device_GPRs/DCM_0/p_func_reset_in"
#top level start addresses
mem_address = int(0x400000000)
utest_start_address = int(0x1B000000) - mem_address #relative address
lc_start_address = utest_start_address + int(0x00000220)

#helper defines
DEFINE_LC_SLOT_LENGTH = 16
DEFINE_LC_MARKED_PATTERN = 0x55AA50AF
DEFINE_LC_ERASED_PATTERN = 0xFFFFFFFF
DEFINE_DCF_RECORD_LENGTH = 8
DEFINE_DCF_START_RECORD_U = 0x00000000
DEFINE_DCF_START_RECORD_L = 0xAF55AA05 #big endian
DEFINE_DCF_END_RECORD_U = 0xFFFFFFFF
DEFINE_DCF_END_RECORD_L = 0xFFFFFFFF
DEFINE_DBG_PSWD = 0xDEADBEEF
DEFINE_MEM_ACCESS_SIZE = 4

#offsets
debug_pswd_offset_in_utest = int(0x00000080)
lc_slots_offset_in_utest = int(0x00000220)
#slot 2
oem_prod_offset_in_utest = int(0x00000230)
#slot 3
in_field_offset_in_utest = int(0x00000240)
#slot 4
prefa_offset_in_utest = int(0x00000250)
#slot 5
fa_offset_in_utest = int(0x00000260)

#dcf offsets
dcf_start_record_offset = int(0x00000700)


    

#Required Start Addresses
debug_pswd_start_address = utest_start_address + debug_pswd_offset_in_utest
lc_slots_start_address = utest_start_address + lc_slots_offset_in_utest
oem_prod_start_address = utest_start_address + oem_prod_offset_in_utest
in_field_start_address = utest_start_address + in_field_offset_in_utest
prefa_start_address = utest_start_address + prefa_offset_in_utest
fa_start_address = utest_start_address + fa_offset_in_utest
dcf_start_address = utest_start_address + dcf_start_record_offset

#DCF initType
RESET = 0
DEADBEEF = 1

#LC Types
OEM_PROD = 2
IN_FIELD_1 = 3
IN_FIELD_2 = 0
PRE_FA = 4
FA = 5

#Reset Types
POR = 0
FUNCTIONAL = 1
DESTRUCTIVE = 2

is_suspend = True

#control words
CLIENTUTESTMISC = 0x00100004
CLIENTRESETPAD  = 0x00100008
CLIENTDESTRESET = 0x0010000C
CLIENTSDID0     = 0x00100010
CLIENTSDID1     = 0x00100014
CLIENTSDID2     = 0x00100018
CLIENTSDID3     = 0x0010001C
CLIENTSDID4     = 0x00100020
CLIENTSDID5     = 0x00100024
CLIENTSDID6     = 0x00100028
CLIENTSDID7     = 0x0010002C
CLIENTSDID8     = 0x00100030
CLIENTSDID9     = 0x00100034
CLIENTSDID10    = 0x00100038
CLIENTSDID11    = 0x0010003C
CLIENTSDID12    = 0x00100040
CLIENTSDID13    = 0x00100044
CLIENTSDID14    = 0x00100048
CLIENTSDID15    = 0x0010004C
CLIENTDAPINSTANCEID = 0x00100050



def populate_record_structure(initType):
    print("In populate_record_structure()")
    #data format --> key : [control word, data]
    records = {}
    if initType == RESET:
        records = {'a'      : [CLIENTUTESTMISC,0x01010000], #utest_misc
                   'b'      : [CLIENTRESETPAD, 0x01000000], #reset_pad
                   'c'      : [CLIENTDESTRESET,0x00000000], #dest_reset
                   'd'      : [CLIENTSDID0,    0x00000000], #sdid0
                   'e'      : [CLIENTSDID1,    0x00000000], #sdid1
                   'f'      : [CLIENTSDID2,    0x00000000], #sdid2
                   'g'      : [CLIENTSDID3,    0x00000000], #sdid3
                   'h'      : [CLIENTSDID4,    0x00000000], #sdid4
                   'i'      : [CLIENTSDID5,    0x00000000], #sdid5
                   'j'      : [CLIENTSDID6,    0x00000000], #sdid6
                   'k'      : [CLIENTSDID7,    0x00000000], #sdid7
                   'l'      : [CLIENTSDID8,    0x00000000], #sdid8
                   'm'      : [CLIENTSDID9,    0x00000000], #sdid9
                   'n'      : [CLIENTSDID10,   0x00000000], #sdid10
                   'o'      : [CLIENTSDID11,   0x00000000], #sdid11
                   'p'      : [CLIENTSDID12,   0x00000000], #sdid12
                   'q'      : [CLIENTSDID13,   0x00000000], #sdid13
                   'r'      : [CLIENTSDID14,   0x00000000], #sdid14
                   's'      : [CLIENTSDID15,   0x00000000], #sdid15
                   't'      : [CLIENTDAPINSTANCEID, 0x00000000], #dap_id
                   }
    elif initType == DEADBEEF:
        records = {'a'      : [CLIENTUTESTMISC,0xEFBEADDE], #utest_misc
                   'b'      : [CLIENTRESETPAD, 0xEFBEADDE], #reset_pad
                   'c'      : [CLIENTDESTRESET,0xEFBEADDE], #dest_reset
                   'd'      : [CLIENTSDID0,    0xEFBEADDE], #sdid0
                   'e'      : [CLIENTSDID1,    0xEFBEADDE], #sdid1
                   'f'      : [CLIENTSDID2,    0xEFBEADDE], #sdid2
                   'g'      : [CLIENTSDID3,    0xEFBEADDE], #sdid3
                   'h'      : [CLIENTSDID4,    0xEFBEADDE], #sdid4
                   'i'      : [CLIENTSDID5,    0xEFBEADDE], #sdid5
                   'j'      : [CLIENTSDID6,    0xEFBEADDE], #sdid6
                   'k'      : [CLIENTSDID7,    0xEFBEADDE], #sdid7
                   'l'      : [CLIENTSDID8,    0xEFBEADDE], #sdid8
                   'm'      : [CLIENTSDID9,    0xEFBEADDE], #sdid9
                   'n'      : [CLIENTSDID10,   0xEFBEADDE], #sdid10
                   'o'      : [CLIENTSDID11,   0xEFBEADDE], #sdid11
                   'p'      : [CLIENTSDID12,   0xEFBEADDE], #sdid12
                   'q'      : [CLIENTSDID13,   0xEFBEADDE], #sdid13
                   'r'      : [CLIENTSDID14,   0xEFBEADDE], #sdid14
                   's'      : [CLIENTSDID15,   0xEFBEADDE], #sdid15
                   't'      : [CLIENTDAPINSTANCEID, 0xEFBEADDE], #dap_id
                   }
    return records


def populate_dcf_records(recordDict, validStartRecord, validStopRecord):
    print("In populate_dcf_records()")
    if validStartRecord:
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address)).set_value(DEFINE_DCF_START_RECORD_L)
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address) + 4).set_value(DEFINE_DCF_START_RECORD_U)
    else:
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address)).set_value(0xFFFFFFFF)
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address) + 4).set_value(0xFFFFFFFF)
    
    indexInMem = 2    
    for key, value in sorted(recordDict.iteritems()):
        print (key + '\n')
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address) + (indexInMem*4)).set_value(value[1])
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address) + ((indexInMem + 1)*4)).set_value(value[0])
        indexInMem = indexInMem + 2
        
    if validStopRecord:
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address) + (indexInMem*4)).set_value(DEFINE_DCF_END_RECORD_L)
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address) + ((indexInMem + 1)*4)).set_value(DEFINE_DCF_END_RECORD_U)
    else:
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address)+ (indexInMem*4)).set_value(0x00000000)
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (dcf_start_address - utest_start_address) + ((indexInMem + 1)*4)).set_value(0x00000000)
 
      
def populate_lc_slots(slotType):
    print("In populate_lc_slots()")
    
    if slotType == OEM_PROD:
        #slot 2
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address)).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address) + 4).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address) + 8).set_value(DEFINE_LC_MARKED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address) + 12).set_value(DEFINE_LC_MARKED_PATTERN);
        
        #slot 3
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address)).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address) + 4).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address) + 8).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address) + 12).set_value(DEFINE_LC_ERASED_PATTERN);
        
        #slot 4
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address)).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address) + 4).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address) + 8).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address) + 12).set_value(DEFINE_LC_ERASED_PATTERN);
        
        #slot 5
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address)).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address) + 4).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address) + 8).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address) + 12).set_value(DEFINE_LC_ERASED_PATTERN);
    elif slotType == IN_FIELD_1:
         #slot 2
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address)).set_value(DEFINE_LC_MARKED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address) + 4).set_value(DEFINE_LC_MARKED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address) + 8).set_value(DEFINE_LC_MARKED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (oem_prod_start_address - utest_start_address) + 12).set_value(DEFINE_LC_MARKED_PATTERN);
        
        #slot 3
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address)).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address) + 4).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address) + 8).set_value(DEFINE_LC_MARKED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (in_field_start_address - utest_start_address) + 12).set_value(DEFINE_LC_MARKED_PATTERN);
        
        #slot 4
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address)).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address) + 4).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address) + 8).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (prefa_start_address - utest_start_address) + 12).set_value(DEFINE_LC_ERASED_PATTERN);
        
        #slot 5
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address)).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address) + 4).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address) + 8).set_value(DEFINE_LC_ERASED_PATTERN);
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (fa_start_address - utest_start_address) + 12).set_value(DEFINE_LC_ERASED_PATTERN);

def assert_reset(resetType):
    
    if resetType == POR:
        print ("por")
    elif resetType == FUNCTIONAL:
        print ("assert functional reset")
        reset_probe = sim.BoolProbe(func_reset_name)
        reset_probe.set_clamp_value(0)
#         sim.wait_for((10,'ns'))
        print (sim.get_time_in_ps())
    else:
        print ("destructive")

def deassert_reset(resetType):
    
    if resetType == POR:
        print ("por")
    elif resetType == FUNCTIONAL:
        print ("deassert functional reset")
        reset_probe = sim.BoolProbe(func_reset_name)
        reset_probe.set_clamp_value(1)
        print (sim.get_time_in_ps())
    else:
        print ("destructive")

def populate_dcf_and_lc_at_por():
    #Reset values and OEM_PROD lc
    #populate debug password, 32 bytes
    for i in range(4):
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (debug_pswd_start_address - utest_start_address) + (i*4)).set_value(DEFINE_DBG_PSWD)

    #populate memory with required data
    recordDict = populate_record_structure(RESET)
    populate_dcf_records(recordDict, 1, 1) #valid start record and valid stop record
    populate_lc_slots(OEM_PROD)
    # reset will get triggered at initial crunch
      
def py_populate_dcf_records_lc_cb(observer, args):
    #DEADBEEF and IN_FIELD lc
    #populate debug password, 32 bytes
    for i in range(4):
        flash_probe = sim.MemoryProbe(mem_name, DEFINE_MEM_ACCESS_SIZE, (debug_pswd_start_address - utest_start_address) + (i*4)).set_value(DEFINE_DBG_PSWD)

    #populate memory with required data
    recordDict = populate_record_structure(DEADBEEF)
    populate_dcf_records(recordDict, 1, 1) #valid start record and valid stop record
    populate_lc_slots(IN_FIELD_1)
#     assert_reset(FUNCTIONAL)
#     sim.resume_script()
#     deassert_reset(FUNCTIONAL)
#     sim.suspend_script()
#     reset_probe = sim.BoolProbe("/S32K388_System/S32K388_MCU/Reset_Boot/MC_RGM_0/ipp_ind_ext_rst_b")
#     reset_probe.set_clamp_value(0)
#     reset_probe.set_clamp_value(1)
try:
    print("#---In DCM test Py script---#")
    
    populate_dcf_and_lc_at_por();
    
    core_name = sys.argv[1]
    #print(core_name)
    core_probe = sim.CoreProbe(core_name)
    
    print(core_probe)
    func_probe1 = core_probe.find_symbol_by_name('_Z26py_populate_dcf_records_lcv', 'function') # '_Z26py_populate_dcf_records_lcv'
    #print('symbol name for py_assert_hw_trigger is %s', func_probe1.name)
    core_probe.create_begin_instruction_observer(py_populate_dcf_records_lc_cb, func_probe1.start_address)    

#     func_probe2 = core_probe.find_symbol_by_name('_Z22py_deassert_hw_triggerv', 'function') # '_Z22py_deassert_hw_triggerv'
#     #print('symbol name for py_deassert_hw_trigger is %s', func_probe2.name)
#     core_probe.create_begin_instruction_observer(py_deassert_hw_trigger_cb, func_probe2.start_address)    
#     
#     func_probe3 = core_probe.find_symbol_by_name('_Z18py_attach_observerv', 'function') # '_Z18py_attach_observerv'
#     #print('symbol name for py_attach_observer is %s', func_probe3.name)
#     core_probe.create_begin_instruction_observer(py_attach_observer, func_probe3.start_address)    
    
except StandardError as detail:
        print "Error: ",detail

        sim.print_message("PY:- ERROR. DCM test Py script.")


sim.suspend_script()
# deassert_reset(FUNCTIONAL)    
