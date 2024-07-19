import sys
import sim
#from configure_iomuxd import IOMUXD

# test for unconnected instances
top = '/S32K388_System/'
ecu_path = top + ''
mcu_path = ecu_path + 'S32K388_MCU'
adma_path = mcu_path + 'ADMA/'
# source, spi1, spi3
spi_connect = [top+'SPI_NW_1', top+'SPI_NW_2', top+'SPI_NW_3',  top+'SPI_NW_4', top+'SPI_NW_5', top+'SPI_NW_6']

spi0 = spi_connect[0]
spi1 = spi_connect[1]
spi2 = spi_connect[2]
spi3 = spi_connect[3]
spi4 = spi_connect[4]
spi5 = spi_connect[5]
    
spi0_probe = sim.CommandProcessorProbe(spi0)
spi1_probe = sim.CommandProcessorProbe(spi1)
spi2_probe = sim.CommandProcessorProbe(spi2)
spi3_probe = sim.CommandProcessorProbe(spi3)
spi4_probe = sim.CommandProcessorProbe(spi4)
spi5_probe = sim.CommandProcessorProbe(spi5)


def message_trigger_spi0(observer, args):
    global spi0_probe
    print("Py: message_trigger_spi0\n") 

    message = spi0_probe.execute_command("get_message")
    print "SPI Message =>", message
    
    message = message.strip("\n")
    message_parts = message.split(" ")
    frame_type = message_parts[0]
    ss_type = message_parts[1]
    slave_en = message_parts[2]
    slaveid = message_parts[3]
    bit_length = message_parts[4]
    cont_select = message_parts[len(message_parts) - 1]

    start = "\""
    end = "\""
    payload = message[(message.find(start) + len(start)) : message.rfind(end)]
    
    bittime = spi0_probe.execute_command("get_baudrate")
    bittime = bittime.strip("\n")
    spi0_probe.execute_command("send_message", [frame_type, ss_type, slave_en, slaveid, bit_length, "\""+payload+"\"", str(1), "SPI_INTERFACE", cont_select])

def message_trigger_spi1(observer, args):
    global spi1_probe
    print("Py: message_trigger_spi1\n") 

    message = spi1_probe.execute_command("get_message")
    print "SPI Message =>", message
    
    message = message.strip("\n")
    message_parts = message.split(" ")
    frame_type = message_parts[0]
    ss_type = message_parts[1]
    slave_en = message_parts[2]
    slaveid = message_parts[3]
    bit_length = message_parts[4]
    cont_select = message_parts[len(message_parts) - 1]

    start = "\""
    end = "\""
    payload = message[(message.find(start) + len(start)) : message.rfind(end)]
    
    bittime = spi1_probe.execute_command("get_baudrate")
    bittime = bittime.strip("\n")
    spi1_probe.execute_command("send_message", [frame_type, ss_type, slave_en, slaveid, bit_length, "\""+payload+"\"", str(1), "SPI_INTERFACE", cont_select])

def message_trigger_spi2(observer, args):
    global spi2_probe
    print("Py: message_trigger_spi2\n") 

    message = spi2_probe.execute_command("get_message")
    print "SPI Message =>", message
    
    message = message.strip("\n")
    message_parts = message.split(" ")
    frame_type = message_parts[0]
    ss_type = message_parts[1]
    slave_en = message_parts[2]
    slaveid = message_parts[3]
    bit_length = message_parts[4]
    cont_select = message_parts[len(message_parts) - 1]

    start = "\""
    end = "\""
    payload = message[(message.find(start) + len(start)) : message.rfind(end)]
    
    bittime = spi2_probe.execute_command("get_baudrate")
    bittime = bittime.strip("\n")
    spi2_probe.execute_command("send_message", [frame_type, ss_type, slave_en, slaveid, bit_length, "\""+payload+"\"", str(1), "SPI_INTERFACE", cont_select])

def message_trigger_spi3(observer, args):
    global spi3_probe
    print("Py: message_trigger_spi3\n") 

    message = spi3_probe.execute_command("get_message")
    print "SPI Message =>", message
    
    message = message.strip("\n")
    message_parts = message.split(" ")
    frame_type = message_parts[0]
    ss_type = message_parts[1]
    slave_en = message_parts[2]
    slaveid = message_parts[3]
    bit_length = message_parts[4]
    cont_select = message_parts[len(message_parts) - 1]

    start = "\""
    end = "\""
    payload = message[(message.find(start) + len(start)) : message.rfind(end)]
    
    bittime = spi3_probe.execute_command("get_baudrate")
    bittime = bittime.strip("\n")
    spi3_probe.execute_command("send_message", [frame_type, ss_type, slave_en, slaveid, bit_length, "\""+payload+"\"", str(1), "SPI_INTERFACE", cont_select])

def message_trigger_spi4(observer, args):
    global spi4_probe
    print("Py: message_trigger_spi4\n") 

    message = spi4_probe.execute_command("get_message")
    print "SPI Message =>", message
    
    message = message.strip("\n")
    message_parts = message.split(" ")
    frame_type = message_parts[0]
    ss_type = message_parts[1]
    slave_en = message_parts[2]
    slaveid = message_parts[3]
    bit_length = message_parts[4]
    cont_select = message_parts[len(message_parts) - 1]

    start = "\""
    end = "\""
    payload = message[(message.find(start) + len(start)) : message.rfind(end)]
    
    bittime = spi4_probe.execute_command("get_baudrate")
    bittime = bittime.strip("\n")
    spi4_probe.execute_command("send_message", [frame_type, ss_type, slave_en, slaveid, bit_length, "\""+payload+"\"", str(1), "SPI_INTERFACE", cont_select])
    
def message_trigger_spi5(observer, args):
    global spi5_probe
    print("Py: message_trigger_spi5\n") 

    message = spi5_probe.execute_command("get_message")
    print "SPI Message =>", message
    
    message = message.strip("\n")
    message_parts = message.split(" ")
    frame_type = message_parts[0]
    ss_type = message_parts[1]
    slave_en = message_parts[2]
    slaveid = message_parts[3]
    bit_length = message_parts[4]
    cont_select = message_parts[len(message_parts) - 1]

    start = "\""
    end = "\""
    payload = message[(message.find(start) + len(start)) : message.rfind(end)]
    
    bittime = spi5_probe.execute_command("get_baudrate")
    bittime = bittime.strip("\n")
    spi5_probe.execute_command("send_message", [frame_type, ss_type, slave_en, slaveid, bit_length, "\""+payload+"\"", str(1), "SPI_INTERFACE", cont_select])
                                   
spi0_probe.execute_command("register_device", ['0', '0'])
spi0_observer = sim.MemoryContentObserver(spi0+'/msg_recv_trigger', 0, 0, message_trigger_spi0, 'write' )

spi1_probe.execute_command("register_device", ['0', '0'])
spi1_observer = sim.MemoryContentObserver(spi1+'/msg_recv_trigger', 0, 0, message_trigger_spi1, 'write' )

spi2_probe.execute_command("register_device", ['0', '0'])
spi2_observer = sim.MemoryContentObserver(spi2+'/msg_recv_trigger', 0, 0, message_trigger_spi2, 'write' )

spi3_probe.execute_command("register_device", ['0', '0'])
spi3_observer = sim.MemoryContentObserver(spi3+'/msg_recv_trigger', 0, 0, message_trigger_spi3, 'write' )

spi4_probe.execute_command("register_device", ['0', '0'])
spi4_observer = sim.MemoryContentObserver(spi4+'/msg_recv_trigger', 0, 0, message_trigger_spi4, 'write' )

spi5_probe.execute_command("register_device", ['0', '0'])
spi5_observer = sim.MemoryContentObserver(spi5+'/msg_recv_trigger', 0, 0, message_trigger_spi5, 'write' )

# wait for arbitrary time for reset pulse to happen
sim.wait_for((100, 'ns'))
