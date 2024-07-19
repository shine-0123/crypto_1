#Select a toolchain from the list: replace_toolchain_list
TOOLCHAIN = gcc

#The path to the GCC installation dir
GCC_DIR = C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi

#The path to the DIAB installation dir
DIAB_DIR = replace_diab_dir

#The path to the EB Tresos installation dir
TRESOS_DIR = C:/EB/tresos

#The path to the T32 installation dir
T32_DIR = C:/T32

#The path to the VDK installation dir
VDK_DIR = replace_vdk_dir
VDK_TEMPLATE_NAME = 
VDK_TEMPLATE_VERSION = 
VDK_VPCONFIG_NAME = 

#The path to the Tresos plugins directory
PLUGINS_DIR = ../../../../../

#The path to the Tresos add-on plugins directory
PLUGINS_DIR_ADDON = ../../../../../

#The paths to the additional directories to be included at build phase
ADDITIONAL_INCLUDE_DIRS = C:/NXP/HSE_FW_S32K358_0_2_40_0/hse_full_mem/interface \
                          C:/NXP/HSE_FW_S32K358_0_2_40_0/hse_full_mem/interface/config \
                          C:/NXP/HSE_FW_S32K358_0_2_40_0/hse_full_mem/interface/inc_common \
                          C:/NXP/HSE_FW_S32K358_0_2_40_0/hse_full_mem/interface/inc_custom \
                          C:/NXP/HSE_FW_S32K358_0_2_40_0/hse_full_mem/interface/inc_services

#Loading project to ram or flash
LOAD_TO=

#Specify connection device using for debugger: 'USB' for running on silicon, 'SIM' for running on simulator
CONNECTION_DEVICE = USB


# ------------------------------------------------------------------------------------
#Example specific parameters - do not modify 

#MCAL modules used
MCAL_MODULE_LIST := BaseNXP CryIf Csm Crypto_43_HSE Det Rte

#MCAL modules used - only for examples based on 2 software products
MCAL_MODULE_LIST_ADDON := 

#The package name for the MCAL release
AR_PKG_NAME = TS_T40D34M40I0R0

#The AUTOSAR module origin ('NXP')
AR_MODULE_ORIGIN = NXP

#The package name for the MCAL release - only for examples based on 2 software products
AR_PKG_NAME_ADDON = 

#The derivative of the device
EXAMPLE_DERIVATIVE = S32K388

#The core type of the device
EXAMPLE_CORE_TYPE = M7

#The name of the elf file
ELFNAME = main

#The test base address 
TEST_BASE_ADDR = 0x204BBF00

#The test block size
TEST_BLOCK_SIZE = 255

#The name of the Tresos project 
TRESOS_PROJECT_NAME = Crypto_SymmetricPrimitives_S32K388

#The number of variants for the Tresos project 
VARIANT_NO = 0

#Connection type of lauterbach
PBI = replace_pbi

#Specific paramater
RUN_SECOND_SAMPLEAPP_ENABLE = replace_run_second_sampleapp_enable
SECOND_SAMPLEAPP_DIR = replace_second_sampleapp_dir

#Specify example supports multiple device connection cmm script(eg: example can support multiple run mode like single core, multiple core, running on silicon, running on simulator)
MULTIPLE_DEVICE_CMM = TRUE