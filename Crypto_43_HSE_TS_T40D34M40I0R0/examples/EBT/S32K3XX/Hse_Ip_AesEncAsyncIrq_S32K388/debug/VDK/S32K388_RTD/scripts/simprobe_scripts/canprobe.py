#############################################################################
# Copyright 1996-2021 Synopsys, Inc.                                        #
#                                                                           #
# This Synopsys software and all associated documentation are proprietary   #
# to Synopsys, Inc. and may only be used pursuant to the terms and          #
# conditions of a written license agreement with Synopsys, Inc.             #
# All other use, reproduction, modification, or distribution of the         #
# Synopsys software or the associated documentation is strictly prohibited. #
#############################################################################
from __future__ import print_function
import sim
import sys
import re

core_probe = sim.CoreProbe(sys.argv[1])
global stub_num


probes = dict()
for inst in [
    "/S32K388_System/CAN/CAN_0/CAN_IO_STUB_0",
    "/S32K388_System/CAN/CAN_1/CAN_IO_STUB_1",
    "/S32K388_System/CAN/CAN_2/CAN_IO_STUB_2",
    "/S32K388_System/CAN/CAN_3/CAN_IO_STUB_3",
    "/S32K388_System/CAN/CAN_4/CAN_IO_STUB_4",
    "/S32K388_System/CAN/CAN_5/CAN_IO_STUB_5",
    "/S32K388_System/CAN/CAN_6/CAN_IO_STUB_6",
    "/S32K388_System/CAN/CAN_7/CAN_IO_STUB_7"
]:
    probes[inst] = sim.CommandProcessorProbe(inst)

def can_io_frame_to_flexcan():
    global stub_num
    global probes

    #print("can_io_frame_to_flexcan  called")
    inst_name = '/S32K388_System/CAN/CAN_' + stub_num +'/CAN_IO_STUB_' + stub_num
    #print("inst_name =%s" % inst_name)
    #print("can_io_frame_to_flexcan, sending frame to flexcan")
    probes[inst_name].execute_command("send_message", ["546", "0", "4", "87 65 43 21"])
    
    
def set_can_io_stub0_path(observer, args):
    global stub_num
    stub_num = '0'
    can_io_frame_to_flexcan()
    
def set_can_io_stub1_path(observer, args):
    global stub_num
    stub_num = '1'
    can_io_frame_to_flexcan()
    
def set_can_io_stub2_path(observer, args):
    global stub_num
    stub_num = '2'
    can_io_frame_to_flexcan()

def set_can_io_stub3_path(observer, args):
    global stub_num
    stub_num = '3'
    can_io_frame_to_flexcan()
    
def set_can_io_stub4_path(observer, args):
    global stub_num
    stub_num = '4'
    can_io_frame_to_flexcan()
    
def set_can_io_stub5_path(observer, args):
    global stub_num
    stub_num = '5'
    can_io_frame_to_flexcan()
    
def set_can_io_stub6_path(observer, args):
    global stub_num
    stub_num = '6'
    can_io_frame_to_flexcan()
    
def set_can_io_stub7_path(observer, args):
    global stub_num
    stub_num = '7'
    can_io_frame_to_flexcan()
    

# function to send a frame from the CAN IO Stub model to the FlexCAN - CANDMATxRxTest
def send_can_frame_from_io_stub(observer, args):
    monitor = observer.name.rsplit('/',1)[0]
    probe = sim.CommandProcessorProbe(monitor)
    frame_received = probe.execute_command("get_message")
    frame_received = frame_received.strip("\n")
    message_parts = frame_received.split(" ")
    id_valid = message_parts[0]
    start = "\""
    end = "\""
    payload = frame_received[(frame_received.find(start) + len(start)) : frame_received.rfind(end)]
    probe.execute_command("send_message", [id_valid, "0", "8", payload])
    
obs = [ ]
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_0/CAN_IO_STUB_0/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_1/CAN_IO_STUB_1/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_2/CAN_IO_STUB_2/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_3/CAN_IO_STUB_3/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_4/CAN_IO_STUB_4/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_5/CAN_IO_STUB_5/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_6/CAN_IO_STUB_6/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))
obs.append(sim.MemoryContentObserver("/S32K388_System/CAN/CAN_7/CAN_IO_STUB_7/msg_trigger_mem", 0, 0, send_can_frame_from_io_stub, "write" ))


def create_function_observer(core_probe, function, callback):
    sym = core_probe.find_symbol_by_name(function, "function")
    f_obs = core_probe.create_about_to_execute_instruction_observer(callback, sym.start_address, sym.start_address)
    return f_obs

# attaching c++ trigger function with python callback
canstub_dma_obs = []
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io0_frame_txv", set_can_io_stub0_path))
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io1_frame_txv", set_can_io_stub1_path))
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io2_frame_txv", set_can_io_stub2_path))
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io3_frame_txv", set_can_io_stub3_path))
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io4_frame_txv", set_can_io_stub4_path))
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io5_frame_txv", set_can_io_stub5_path))
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io6_frame_txv", set_can_io_stub6_path))
canstub_dma_obs.append(create_function_observer(core_probe, "_Z24trigger_can_io7_frame_txv", set_can_io_stub7_path))
