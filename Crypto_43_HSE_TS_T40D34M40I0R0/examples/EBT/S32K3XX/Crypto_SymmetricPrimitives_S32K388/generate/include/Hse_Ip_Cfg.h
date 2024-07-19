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
#include "S32K388_MU.h"
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
#define HSE_IP_MU_0                              ((uint8)0U)
#define HSE_IP_MU_1                              ((uint8)1U)

/* Max number of MU instances */
#define HSE_IP_NUM_OF_MU_INSTANCES               (2U)

/* Max number of channels per MU interface */
#define HSE_IP_NUM_OF_CHANNELS_PER_MU            (4U)

/* Pre-processor switch to enable/disable development error detection for Hse Ip API */
#define HSE_IP_DEV_ERROR_DETECT                  (STD_OFF)



/* OsIf counter type used in timeout detection for HSE IP service request */
#define HSE_IP_TIMEOUT_OSIF_COUNTER_TYPE         (OSIF_COUNTER_DUMMY)

/* Support for Hse operations using TCM addresses */
#define HSE_IP_ENABLE_TCM_SUPPORT                (STD_ON)
    #define HSE_IP_ITCM_ADDR_START_U32           (0x00000000U)
    #define HSE_IP_ITCM_ADDR_END_U32             (0x0000FFFFU)
    #define HSE_IP_DTCM_ADDR_START_U32           (0x20000000U)
    #define HSE_IP_DTCM_ADDR_END_U32             (0x2001FFFFU)

/* Initializer for the MU Host base addresses */
/* For communication with the firmware only MU_0 and MU_1 are used, MU_2 is only used for communication between application cores */
#define MU_HOST_BASE_PTRS                        { IP_MU_0__MUB, IP_MU_1__MUB }

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

#define CRYPTO_43_HSE_START_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"

/* Table containing ITCM Backdoor Address Offsets */
extern const uint32 Hse_Ip_aItcmAddrOffset[4U];

/* Table containing DTCM Backdoor Address Offsets */
extern const uint32 Hse_Ip_aDtcmAddrOffset[4U];

#define CRYPTO_43_HSE_STOP_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"

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

