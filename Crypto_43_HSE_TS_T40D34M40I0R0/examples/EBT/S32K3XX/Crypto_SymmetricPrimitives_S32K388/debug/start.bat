@echo off

REM #############################################################################
REM # Copyright 1996-2016 Synopsys, Inc.                                        #
REM #                                                                           #
REM # This Synopsys software and all associated documentation are proprietary   #
REM # to Synopsys, Inc. and may only be used pursuant to the terms and          #
REM # conditions of a written license agreement with Synopsys, Inc.             #
REM # All other use, reproduction, modification, or distribution of the         #
REM # Synopsys software or the associated documentation is strictly prohibited. #
REM #############################################################################

set TEST=%1
set T32_APP=%2
set T32_DIR=%3
set VDK_DIR=%4
set VDK_TEMPLATE_NAME=%5
set VDK_TEMPLATE_VERSION=%6
set VDK_VPCONFIG_NAME=%7
set DEBUG_DIR=%8

if not "%VDK_DIR%" == "" (
    call %VDK_DIR%\setup.bat -vsdk
) else (
    echo Please configure your 'VDK_DIR' environment variable.
    exit
)

REM #############################################################################
REM # Test specific data
REM #############################################################################
REM ######### Setup T32_DIR #########
set T32SYS=%T32_DIR%

REM ######### Setup TEST_DIR #########
set TEST_DIR=%DEBUG_DIR%/../out

REM ######### Setup TEST_VDK #########
REM This variable should not be renamed to anything else.
REM When "run_simulation.py" executes "vdk.import_external_vp_config(vpconfig)", all the key attributes
REM within paramOverrides fields which begin with "ECU." will be renamed to "<TEST_VDK_NAME>."
REM This name is needed so that "ECU." will remain translated to "ECU."
set TEST_VDK_NAME=ECU
set TEST_VDK_TEMPLATE=%VDK_TEMPLATE_NAME%
set TEST_VDK_VERSION=%VDK_TEMPLATE_VERSION%

REM ######### Setup T32 executable  #########
REM set TEST_T32_EXEC=%T32SYS%\bin\windows64\%T32_APP%
set TEST_T32_EXEC=%T32SYS%\bin\windows64\%T32_APP%

REM ######### Setup config.t32 file #########
set TEST_T32_CONFIG=%DEBUG_DIR%\config.t32

REM ######### Setup cmm script #########
set TEST_T32_CMM=%DEBUG_DIR%\%TEST%.cmm

REM ######### Setup TEST_CMD to be run by the simulator #########
set TEST_T32_CMD=%TEST_T32_EXEC% -c %TEST_T32_CONFIG% -s %TEST_T32_CMM%
REM #############################################################################
REM #############################################################################


REM # define test directories
set TEST_WORKSPACE=%TEST_DIR%\ws
set TEST_LOGFILE=%TEST_DIR%\vs_output.log
set TEST_SCRIPT=%~dp0run_simulation.py

REM # define test configuration e.g. vpconfig & VDK name
echo Running on local
set TEST_VPCONFIG=%DEBUG_DIR%\VDK\%VDK_VPCONFIG_NAME%\%VDK_VPCONFIG_NAME%.vpcfg


set COWARE_SIMTOKEN_DIR=%TEST_DIR%
set DATA_OUTPUT_FOLDER=%TEST_DIR%

REM #S32 workaround
REM set PATH=%PATH%;%TEST_WORKSPACE%\%TEST_VDK_NAME%\vpconfigs\shared\other\cust_lib

REM # debugger environment
call %SNPS_VP_HOME%\..\any\external_debuggers\setup64.bat -mcd

REM # launch virtualizer studio (sh)
set SNPS_MCD_PLUGIN_DEBUGGER_TYPE=TRACE32_MCD
set SNPS_MCD_PLUGIN_FORCE_SMP_BEHAVIOUR=1

if exist "%TEST_DIR%\ws" (
    rm -r %TEST_DIR%\ws
)
if exist "%TEST_DIR%\N-2017.12" (
    rm -r %TEST_DIR%\N-2017.12
)
if exist "%TEST_DIR%\M-2017.06" (
    rm -r %TEST_DIR%\M-2017.06
)
if exist "%TEST_DIR%\Q-2020.06-SP1" (
    rm -r %TEST_DIR%\Q-2020.06-SP1
)
if exist "%TEST_DIR%\analysis_results" (
    rm -r %TEST_DIR%\analysis_results
)

if "%LM_LICENSE_FILE%" == "" (
    echo Setting LM_LICENSE_FILE
    set LM_LICENSE_FILE=9661@liv0042.nxdi.nl-cdc01.nxp.com;26585@cde-az84-103va.am.freescale.net;26585@cde-az50-104va.am.freescale.net;26585@cde-az84-108va.am.freescale.net
)

if "%SNPSLMD_LICENSE_FILE%" == "" (
    echo Setting SNPSLMD_LICENSE_FILE
    set SNPSLMD_LICENSE_FILE=9706@liv0012.nxdi.nl-cdc01.nxp.com;9706@liv0059.nxdi.us-cdc01.nxp.com;\\licenses.nxdi.nxp.com\licenses\Synopsys_System
)

REM call vssh -d %TEST_WORKSPACE% -c %TEST_DIR%  --init_dir %TEST_DIR% --logfile %TEST_LOGFILE% -s %TEST_SCRIPT%
echo Open VDK in GUI
call vs -d %TEST_WORKSPACE% -c %TEST_DIR%  --init_dir %TEST_DIR% --logfile %TEST_LOGFILE% -s %TEST_SCRIPT% -r %TEST_VPCONFIG%

REM remove temporary files
if exist "%TEST_DIR%\ws" (
    rm -r %TEST_DIR%\ws
)
if exist "%TEST_DIR%\N-2017.12" (
    rm -r %TEST_DIR%\N-2017.12
)
if exist "%TEST_DIR%\M-2017.06" (
    rm -r %TEST_DIR%\M-2017.06
)
if exist "%TEST_DIR%\Q-2020.06-SP1" (
    rm -r %TEST_DIR%\Q-2020.06-SP1
)
if exist "%TEST_DIR%\analysis_results" (
    rm -r %TEST_DIR%\analysis_results
)
exit
