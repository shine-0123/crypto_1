import sim
import sys

mem_start_address = int(0x70000000)
eth0_name = "/S32K388_System/Ethernet/ETH_0/ETH_IO_STUB_0"
eth1_name = "/S32K388_System/Ethernet/ETH_0/ETH_IO_STUB_1"
mem_name = "/S32K388_System/S32K388_MCU/Memories/TEST_MEM/m_memory"
core_name = ""
core_probe = ""
eth0_cmd_probe = ""
eth1_cmd_probe = ""

def send_ephy_message(observer, args):
    global eth0_cmd_probe
    global eth1_cmd_probe
    global core_probe
    print("ETH_IO send_ephy_message called")
    packet = "0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0x11 0x11 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88"
    eth0_cmd_probe.execute_command("send_message", ["a0:b0:c0:d0:e0:f0", "b0:b0:c0:d0:e0:f0", "true", "8100", "0", packet, "0x5E"])
    eth1_cmd_probe.execute_command("send_message", ["a0:b0:c0:d0:e0:f0", "b0:b0:c0:d0:e0:f0", "true", "8100", "0", packet, "0x5E"])



def ETH_MON_0_Rx_state(observer, args):
    print("ETH_MON_0_Rx_state called")
    rx_mgs = eth0_cmd_probe.execute_command("get_message")
    ETH_compare_pkt(rx_mgs)


def ETH_MON_1_Rx_state(observer, args):
    print("ETH_MON_1_Rx_state called")
    rx_mgs = eth1_cmd_probe.execute_command("get_message")
    ETH_compare_pkt(rx_mgs)

def ETH_compare_pkt(rx_mgs):
    global is_access_probe
    packet_search = "0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xa 0xb 0xc 0xd 0xe 0xf 0x10 0x11 0x12"

    print("rx_mgs")
    print(rx_mgs)
    data = rx_mgs.split()[4]
    #puts "Data Received $data"
    print("data")
    print(data)
    if packet_search in rx_mgs:
        print("EQoS -> ENET IO Stub Rx Packet matched test passed")
        # update variable name, that need to be sync.
        is_access_probe.set_value(0x1)
    else:
        print("EQoS -> ENET IO Stub Rx Packet not matched test failed")
        is_access_probe.set_value(0x2)

if __name__ == '__main__':
    core_name = sys.argv[1]
    #print(core_name)
    core_probe = sim.CoreProbe(core_name)
    func_probe1 = core_probe.find_symbol_by_name('_Z10inject_pktv', 'function') # '_Z20py_assert_hw_triggerv'
    #print('symbol name for py_assert_hw_trigger is %s', func_probe1.name)
    core_probe.create_begin_instruction_observer(send_ephy_message, func_probe1.start_address)    
    
    # rx trigger at iostub_0
    
    print("Sim probe for xgmac main created")
    obj0 = sim.MemoryContentObserver("/S32K388_System/Ethernet/ETH_0/ETH_IO_STUB_0/ephy_msg_recv_trigger", 0, 0, ETH_MON_0_Rx_state, "write" )
    obj1 = sim.MemoryContentObserver("/S32K388_System/Ethernet/ETH_1/ETH_IO_STUB_1/ephy_msg_recv_trigger", 0, 0, ETH_MON_1_Rx_state, "write" )

    eth0_cmd_probe = sim.CommandProcessorProbe("/S32K388_System/Ethernet/ETH_0/ETH_IO_STUB_0")
    eth1_cmd_probe = sim.CommandProcessorProbe("/S32K388_System/Ethernet/ETH_1/ETH_IO_STUB_1")
    
    is_access_obj = core_probe.find_symbol_by_name('_ZL6TxRcvd', 'object') # '_ZL8isAccess'
    #print('symbol name for is_access_obj is %s', is_access_obj.name)
    is_access_probe = sim.MemoryProbe(mem_name, 4, is_access_obj.start_address - mem_start_address)
