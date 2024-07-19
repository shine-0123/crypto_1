/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : HSE
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P16_D2403_ASR_REL_4_7_REV_0000_20240328
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup CRYPTO
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Hse_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HSE_IP_CFG_VENDOR_ID_C                       43
#define HSE_IP_CFG_SW_MAJOR_VERSION_C                4
#define HSE_IP_CFG_SW_MINOR_VERSION_C                0
#define HSE_IP_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Hse Ip configuration source file and Hse Ip configuration header file are of the same vendor */
#if (HSE_IP_CFG_VENDOR_ID_C != HSE_IP_CFG_VENDOR_ID_H)
    #error "Hse_Ip_Cfg.c and Hse_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Hse Ip configuration source file and Hse Ip configuration header file are of the same software version */
#if ((HSE_IP_CFG_SW_MAJOR_VERSION_C != HSE_IP_CFG_SW_MAJOR_VERSION_H) || \
     (HSE_IP_CFG_SW_MINOR_VERSION_C != HSE_IP_CFG_SW_MINOR_VERSION_H) || \
     (HSE_IP_CFG_SW_PATCH_VERSION_C != HSE_IP_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Hse_Ip_Cfg.c and Hse_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
[!AUTOSPACING!][!//

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

[!IF "node:value(CryptoGeneral/CryptoEnableTCMSupport) = 'true'"!][!//
#define CRYPTO_43_HSE_START_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"

/* Table containing ITCM Backdoor Address Offsets */
[!NOCODE!][!//
    [!VAR "NumItcm" = "num:i(count(ecu:list('Crypto.ItcmAddrOffset.List')))"!]
    [!CODE!]const uint32 Hse_Ip_aItcmAddrOffset[[!"$NumItcm"!]U] =[!CR!]{[!ENDCODE!][!CR!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Crypto.ItcmAddrOffset.List')))"!][!//
        [!CODE!]    /* ITCM_[!"$LoopCounter"!] Backdoor Offset */[!ENDCODE!][!CR!][!//
        [!CODE!]    [!"ecu:list('Crypto.ItcmAddrOffset.List')[num:i($LoopCounter)]"!]U[!//
        [!IF "$LoopCounter != num:i(count(ecu:list('Crypto.ItcmAddrOffset.List')))"!],[!ENDIF!][!ENDCODE!][!CR!][!//
    [!ENDFOR!][!//
    [!CODE!]};[!ENDCODE!][!CR!][!//
[!ENDNOCODE!][!//

/* Table containing DTCM Backdoor Address Offsets */
[!NOCODE!][!//
    [!VAR "NumDtcm" = "num:i(count(ecu:list('Crypto.DtcmAddrOffset.List')))"!]
    [!CODE!]const uint32 Hse_Ip_aDtcmAddrOffset[[!"$NumDtcm"!]U] =[!CR!]{[!ENDCODE!][!CR!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Crypto.DtcmAddrOffset.List')))"!][!//
        [!CODE!]    /* ITCM_[!"$LoopCounter"!] Backdoor Offset */[!ENDCODE!][!CR!][!//
        [!CODE!]    [!"ecu:list('Crypto.DtcmAddrOffset.List')[num:i($LoopCounter)]"!]U[!//
        [!IF "$LoopCounter != num:i(count(ecu:list('Crypto.ItcmAddrOffset.List')))"!],[!ENDIF!][!ENDCODE!][!CR!][!//
    [!ENDFOR!][!//
    [!CODE!]};[!ENDCODE!][!CR!][!//
[!ENDNOCODE!][!//

#define CRYPTO_43_HSE_STOP_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"
[!ENDIF!][!//

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

