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

#ifndef HSE_IP_CFG_H
#define HSE_IP_CFG_H

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
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
#include "S32G274A_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
#include "S32G399A_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!//
#include "S32R45_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!//
#include "S32R41_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf8544')"!][!//
#include "SAF85XX_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf8644l')"!][!//
#include "SAF86XX_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310')"!][!//
#include "S32K311_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k311')"!][!//
#include "S32K311_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k312')"!][!//
#include "S32K312_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k314')"!][!//
#include "S32K314_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k324')"!][!//
#include "S32K324_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k344')"!][!//
#include "S32K344_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k342')"!][!//
#include "S32K342_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k341')"!][!//
#include "S32K341_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k322')"!][!//
#include "S32K322_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394')"!][!//
#include "S32K39_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396')"!][!//
#include "S32K39_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k358')"!][!//
#include "S32K358_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348')"!][!//
#include "S32K358_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338')"!][!//
#include "S32K358_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328')"!][!//
#include "S32K358_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k388')"!][!//
#include "S32K388_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k374')"!][!//
#include "S32K37_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k376')"!][!//
#include "S32K37_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z27')"!][!//
#include "S32Z2_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e27')"!][!//
#include "S32E2_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
#include "S32M27x_MU.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32n')"!][!//
#include "S32NZ55_SECURITY_MU.h"
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//
#include "OsIf.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HSE_IP_CFG_VENDOR_ID_H                       43
#define HSE_IP_CFG_SW_MAJOR_VERSION_H                4
#define HSE_IP_CFG_SW_MINOR_VERSION_H                0
#define HSE_IP_CFG_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Defines for the available MU instances */
[!NOCODE!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Crypto.MuInstances.List')))"!][!//
        [!CODE!]#define HSE_IP_[!"ecu:list('Crypto.MuInstances.List')[num:i($LoopCounter)]"!]                              ((uint8)[!"num:i($LoopCounter - 1)"!]U)[!ENDCODE!][!CR!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!][!//

/* Max number of MU instances */
#define HSE_IP_NUM_OF_MU_INSTANCES               ([!"num:i(count(ecu:list('Crypto.MuInstances.List')))"!]U)

/* Max number of channels per MU interface */
#define HSE_IP_NUM_OF_CHANNELS_PER_MU            ([!"num:i(ecu:get('Crypto.NumChannelsPerMu'))"!]U)

/* Pre-processor switch to enable/disable development error detection for Hse Ip API */
#define HSE_IP_DEV_ERROR_DETECT                  ([!IF "CryptoGeneral/HseIpDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


[!NOCODE!][!//
    [!IF "node:value(CryptoGeneral/CryptoTimeoutMethod) = 'OSIF_COUNTER_SYSTEM'"!]
        [!VAR "StrCounterType" = "'SYSTEM'"!][!//
        [!INDENT "0"!][!//
        [!CODE!][!//
            /* Check if the chosen counter type is enabled */
            #if (STD_OFF == OSIF_USE_SYSTEM_TIMER)
                [!INDENT "4"!][!//
                #error "OSIF System counter is disabled"
                [!ENDINDENT!][!//
            #endif
        [!ENDCODE!][!//
        [!ENDINDENT!][!//
    [!ELSEIF "node:value(CryptoGeneral/CryptoTimeoutMethod) = 'OSIF_COUNTER_CUSTOM'"!]
        [!VAR "StrCounterType" = "'CUSTOM'"!][!//
        [!INDENT "0"!][!//
        [!CODE!][!//
            /* Check if the chosen counter type is enabled */
            #if (STD_OFF == OSIF_USE_CUSTOM_TIMER)
                [!INDENT "4"!][!//
                #error "OSIF Custom counter is disabled"
                [!ENDINDENT!][!//
            #endif
        [!ENDCODE!][!//
        [!ENDINDENT!][!//
    [!ELSE!][!//
        [!VAR "StrCounterType" = "'DUMMY'"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//

/* OsIf counter type used in timeout detection for HSE IP service request */
#define HSE_IP_TIMEOUT_OSIF_COUNTER_TYPE         (OSIF_COUNTER_[!"$StrCounterType"!])

/* Support for Hse operations using TCM addresses */
[!IF "node:value(CryptoGeneral/CryptoEnableTCMSupport) = 'true'"!][!//
[!CODE!]#define HSE_IP_ENABLE_TCM_SUPPORT                (STD_ON)[!CR!][!ENDCODE!][!//
[!CODE!][!INDENT "4"!]#define HSE_IP_ITCM_ADDR_START_U32           ([!"ecu:get('Crypto.ItcmAddrStart')"!]U)[!CR!][!ENDINDENT!][!ENDCODE!][!//
[!CODE!][!INDENT "4"!]#define HSE_IP_ITCM_ADDR_END_U32             ([!"ecu:get('Crypto.ItcmAddrEnd')"!]U)[!CR!][!ENDINDENT!][!ENDCODE!][!//
[!CODE!][!INDENT "4"!]#define HSE_IP_DTCM_ADDR_START_U32           ([!"ecu:get('Crypto.DtcmAddrStart')"!]U)[!CR!][!ENDINDENT!][!ENDCODE!][!//
[!CODE!][!INDENT "4"!]#define HSE_IP_DTCM_ADDR_END_U32             ([!"ecu:get('Crypto.DtcmAddrEnd')"!]U)[!CR!][!ENDINDENT!][!ENDCODE!][!//
[!ELSE!][!//
[!CODE!]#define HSE_IP_ENABLE_TCM_SUPPORT                (STD_OFF)[!CR!][!ENDCODE!][!//
[!ENDIF!][!//

[!INDENT "0"!][!//
/* Initializer for the MU Host base addresses */
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "text:match(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g[23]')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUB, IP_MU1__MUB, IP_MU2__MUB, IP_MU3__MUB }
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUB, IP_MU1__MUB, IP_MU2__MUB, IP_MU3__MUB }
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k3')"!][!//
/* For communication with the firmware only MU_0 and MU_1 are used, MU_2 is only used for communication between application cores */
#define MU_HOST_BASE_PTRS                        { IP_MU_0__MUB, IP_MU_1__MUB }
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUB, IP_MU1__MUB }
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf8544')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUB, IP_MU1__MUB }
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf8644l')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUB, IP_MU1__MUB }
    [!ELSEIF "text:match(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32[ze]27')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUB, IP_MU1__MUB, IP_MU2__MUB, IP_MU3__MUB, IP_MU4__MUB, IP_MU5__MUB, IP_MU6__MUB, IP_MU7__MUB }
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU_0__MUB, IP_MU_1__MUB }
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32n')"!][!//
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUA, IP_MU1__MUA, IP_MU2__MUA, IP_MU3__MUA, IP_MU4__MUA, IP_MU5__MUA, IP_MU6__MUA, IP_MU7__MUA, IP_MU8__MUA, IP_MU9__MUA, IP_MU10__MUA, IP_MU11__MUA, IP_MU12__MUA, IP_MU13__MUA, IP_MU_MSI__MUA}
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugin or ResourceSubderivative field is not available."!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
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
    [!CODE!]extern const uint32 Hse_Ip_aItcmAddrOffset[[!"$NumItcm"!]U];[!CR!][!ENDCODE!][!//
[!ENDNOCODE!][!//

/* Table containing DTCM Backdoor Address Offsets */
[!NOCODE!][!//
    [!VAR "NumDtcm" = "num:i(count(ecu:list('Crypto.DtcmAddrOffset.List')))"!]
    [!CODE!]extern const uint32 Hse_Ip_aDtcmAddrOffset[[!"$NumDtcm"!]U];[!CR!][!ENDCODE!][!//
[!ENDNOCODE!][!//

#define CRYPTO_43_HSE_STOP_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"
[!ENDIF!][!//

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* HSE_IP_CFG_H */

