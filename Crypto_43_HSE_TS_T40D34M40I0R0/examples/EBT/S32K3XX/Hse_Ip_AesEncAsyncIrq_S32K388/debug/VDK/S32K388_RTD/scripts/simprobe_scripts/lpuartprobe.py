import sim
import sys
import re

global timer_uart # type timer 
global counter_uart # type : int
global instance_uart # type : string
global time_uart # type systemc time
global cm4_instance_uart
global inst

core_path = ""

#pass core name as argument
core_probe = sim.CoreProbe(sys.argv[1])

probes = dict()
for inst in [
    "/S32K388_System/UART/UART_PHY_0",
    "/S32K388_System/UART/UART_PHY_1",
    "/S32K388_System/UART/UART_PHY_2",
    "/S32K388_System/UART/UART_PHY_3",
    "/S32K388_System/UART/UART_PHY_4",
    "/S32K388_System/UART/UART_PHY_5",
    "/S32K388_System/UART/UART_PHY_6",
    "/S32K388_System/UART/UART_PHY_7",
    "/S32K388_System/UART/UART_PHY_8",
    "/S32K388_System/UART/UART_PHY_9",
    "/S32K388_System/UART/UART_PHY_10",
    "/S32K388_System/UART/UART_PHY_11",
    "/S32K388_System/UART/UART_PHY_12",
    "/S32K388_System/UART/UART_PHY_13",
    "/S32K388_System/UART/UART_PHY_14",
    "/S32K388_System/UART/UART_PHY_15",
    
    

]:
    probes[inst] = sim.CommandProcessorProbe(inst)

def timer_cb_uart(timer):
    global counter_uart
    global instance_uart
    global time_uart
    global cm4_instance_uart
    global inst
    global probes

    #print(str(sim.get_time_in_ps() + ": timer_cb_uart for insatnce LPUART " + instance_uart + " gets called with counter_uart = " + str(counter_uart))

    inst_name = '/' + inst + cm4_instance_uart + 'UART_PHY_' + instance_uart
    
    data = 0x5A + counter_uart
    #print("data =" + str(data))
    
    probes[inst_name].execute_command("send_message", ["UART_FRAME", "0", "8", "0", str(data), "1", "0"])
    
    counter_uart -= 1
    if (counter_uart > 0) :
        time3us = (10, 'us')
        timer.notify_callback_after(timer_cb_uart, time3us);
    
def send_lpuart_frame_from_uart0_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "0"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart0_phy_fifo gets called"))
    timer_cb_uart(timer_uart)
    
def send_lpuart_frame_from_uart1_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "1"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart0_phy_fifo gets called"))
    timer_cb_uart(timer_uart)
    
def send_lpuart_frame_from_uart2_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "2"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart2_phy_fifo gets called"))
    timer_cb_uart(timer_uart)
    
def send_lpuart_frame_from_uart3_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "3"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart3_phy_fifo gets called"))
    timer_cb_uart(timer_uart)
    
def send_lpuart_frame_from_uart4_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "4"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart4_phy_fifo gets called"))
    timer_cb_uart(timer_uart)
    
def send_lpuart_frame_from_uart5_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "5"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart5_phy_fifo gets called"))
    timer_cb_uart(timer_uart)


def send_lpuart_frame_from_uart6_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "6"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart6_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart7_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "7"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart7_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart8_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "8"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart8_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart9_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "9"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart9_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart10_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "10"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart10_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart11_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "11"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart11_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart12_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "12"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart12_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart13_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "13"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart13_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart14_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "14"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart14_phy_fifo gets called"))
    timer_cb_uart(timer_uart)

def send_lpuart_frame_from_uart15_phy(observer, args):
    global timer_uart
    global counter_uart
    global instance_uart
    global cm4_instance_uart
    global inst
    global time_uart
    
    counter_uart = 4 # since FIFO mode
    inst = "S32K388_System/UART/"
    cm4_instance_uart = ""
    instance_uart = "15"
    
   # print(str(sim.get_time_in_ps() + ": send_lpuart_frame_from_uart15_phy_fifo gets called"))
    timer_cb_uart(timer_uart)    
    
def create_function_observer(core_probe, function, callback):
    sym = core_probe.find_symbol_by_name(function, "function")
    obs = core_probe.create_about_to_execute_instruction_observer(callback, sym.start_address, sym.start_address)
    return obs


#Main method
print("****LPUART simprobe script execution started***")

# attaching c++ trigger function with python callback
lpuartphy0_obs = create_function_observer(core_probe, "_Z33trigger_lpuart0_write_to_terminalv", send_lpuart_frame_from_uart0_phy)
lpuartphy1_obs = create_function_observer(core_probe, "_Z33trigger_lpuart1_write_to_terminalv", send_lpuart_frame_from_uart1_phy)
lpuartphy2_obs = create_function_observer(core_probe, "_Z33trigger_lpuart2_write_to_terminalv", send_lpuart_frame_from_uart2_phy)
lpuartphy3_obs = create_function_observer(core_probe, "_Z33trigger_lpuart3_write_to_terminalv", send_lpuart_frame_from_uart3_phy)
lpuartphy4_obs = create_function_observer(core_probe, "_Z33trigger_lpuart4_write_to_terminalv", send_lpuart_frame_from_uart4_phy)
lpuartphy5_obs = create_function_observer(core_probe, "_Z33trigger_lpuart5_write_to_terminalv", send_lpuart_frame_from_uart5_phy)
lpuartphy6_obs = create_function_observer(core_probe, "_Z33trigger_lpuart6_write_to_terminalv", send_lpuart_frame_from_uart6_phy)
lpuartphy7_obs = create_function_observer(core_probe, "_Z33trigger_lpuart7_write_to_terminalv", send_lpuart_frame_from_uart7_phy)
lpuartphy8_obs = create_function_observer(core_probe, "_Z33trigger_lpuart8_write_to_terminalv", send_lpuart_frame_from_uart8_phy)
lpuartphy9_obs = create_function_observer(core_probe, "_Z33trigger_lpuart9_write_to_terminalv", send_lpuart_frame_from_uart9_phy)
lpuartphy10_obs = create_function_observer(core_probe, "_Z34trigger_lpuart10_write_to_terminalv", send_lpuart_frame_from_uart10_phy)
lpuartphy11_obs = create_function_observer(core_probe, "_Z34trigger_lpuart11_write_to_terminalv", send_lpuart_frame_from_uart11_phy)
lpuartphy12_obs = create_function_observer(core_probe, "_Z34trigger_lpuart12_write_to_terminalv", send_lpuart_frame_from_uart12_phy)
lpuartphy13_obs = create_function_observer(core_probe, "_Z34trigger_lpuart13_write_to_terminalv", send_lpuart_frame_from_uart13_phy)
lpuartphy14_obs = create_function_observer(core_probe, "_Z34trigger_lpuart14_write_to_terminalv", send_lpuart_frame_from_uart14_phy)
lpuartphy15_obs = create_function_observer(core_probe, "_Z34trigger_lpuart15_write_to_terminalv", send_lpuart_frame_from_uart15_phy)


timer_uart = sim.Timer()
timer_uart.set_callback(timer_cb_uart)

