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
#include "Crypto_43_HSE_Private.h"
#include "Crypto_43_HSE.h"
#include "Crypto_43_HSE_Util.h"
#include "Hse_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_43_HSE_VENDOR_ID_CFG_C                      43
#define CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_CFG_C       7
#define CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define CRYPTO_43_HSE_SW_MAJOR_VERSION_CFG_C               4
#define CRYPTO_43_HSE_SW_MINOR_VERSION_CFG_C               0
#define CRYPTO_43_HSE_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crypto configuration source file and Crypto private header file are of the same vendor */
#if (CRYPTO_43_HSE_VENDOR_ID_CFG_C != CRYPTO_43_HSE_VENDOR_ID_PRIVATE)
    #error "Crypto_43_HSE_Cfg.c and Crypto_43_HSE_Private.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same Autosar version */
#if ((CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION_PRIVATE) \
    )
    #error "AutoSar Version Numbers of Crypto_43_HSE_Cfg.c and Crypto_43_HSE_Private.h are different"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same Software version */
#if ((CRYPTO_43_HSE_SW_MAJOR_VERSION_CFG_C != CRYPTO_43_HSE_SW_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_43_HSE_SW_MINOR_VERSION_CFG_C != CRYPTO_43_HSE_SW_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_43_HSE_SW_PATCH_VERSION_CFG_C != CRYPTO_43_HSE_SW_PATCH_VERSION_PRIVATE)    \
    )
    #error "Software Version Numbers of Crypto_43_HSE_Cfg.c and Crypto_43_HSE_Private.h are different"
#endif


/* Check if Crypto configuration source file and Crypto header file are of the same vendor */
#if (CRYPTO_43_HSE_VENDOR_ID_CFG_C != CRYPTO_43_HSE_VENDOR_ID)
    #error "Crypto_43_HSE_Cfg.c and Crypto_43_HSE.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same Autosar version */
#if ((CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crypto_43_HSE_Cfg.c and Crypto_43_HSE.h are different"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same Software version */
#if ((CRYPTO_43_HSE_SW_MAJOR_VERSION_CFG_C != CRYPTO_43_HSE_SW_MAJOR_VERSION) || \
     (CRYPTO_43_HSE_SW_MINOR_VERSION_CFG_C != CRYPTO_43_HSE_SW_MINOR_VERSION) || \
     (CRYPTO_43_HSE_SW_PATCH_VERSION_CFG_C != CRYPTO_43_HSE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crypto_43_HSE_Cfg.c and Crypto_43_HSE.h are different"
#endif


/* Check if Crypto configuration source file and Hse Ip configuration header file are of the same vendor */
#if (CRYPTO_43_HSE_VENDOR_ID_CFG_C != HSE_IP_CFG_VENDOR_ID_H)
    #error "Crypto_43_HSE_Cfg.c and Hse_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Hse Ip configuration header file are of the same Software version */
#if ((CRYPTO_43_HSE_SW_MAJOR_VERSION_CFG_C != HSE_IP_CFG_SW_MAJOR_VERSION_H) || \
     (CRYPTO_43_HSE_SW_MINOR_VERSION_CFG_C != HSE_IP_CFG_SW_MINOR_VERSION_H) || \
     (CRYPTO_43_HSE_SW_PATCH_VERSION_CFG_C != HSE_IP_CFG_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Crypto_43_HSE_Cfg.c and Hse_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define CRYPTO_43_HSE_START_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

/* Array storing the indexes of the Crypto Driver Objects */
static const uint8 Crypto_43_HSE_au8CDOs[] =
{
    0U
};

#define CRYPTO_43_HSE_STOP_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

#define CRYPTO_43_HSE_START_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"

/* Array of indexes for each Crypto Key Element referred by Crypto Key Crypto_Key_HSE_AES128 */
static const uint32 Crypto_43_HSE_au32KeyElementList_Crypto_Key_HSE_AES128[1U] =
{
    0U
};


#define CRYPTO_43_HSE_STOP_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"

#define CRYPTO_43_HSE_START_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/* Array storing the Crypto primitives in the Crypto Driver Object CDO_HSE_Symmetric */
static const Crypto_43_HSE_PrimitiveType Crypto_43_HSE_aPrimitives_CDO_HSE_Symmetric[6U] =
{
    {
        CRYPTO_ENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_ECB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET,
        (boolean)FALSE
    },
    {
        CRYPTO_DECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_ECB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET,
        (boolean)FALSE
    },
    {
        CRYPTO_MACGENERATE,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET,
        (boolean)FALSE
    },
    {
        CRYPTO_MACVERIFY,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET,
        (boolean)FALSE
    },
    {
        CRYPTO_HASH,
        (uint8)CRYPTO_ALGOFAM_SHA1,
        (uint8)CRYPTO_ALGOMODE_NOT_SET,
        (uint8)CRYPTO_ALGOFAM_NOT_SET,
        (boolean)FALSE
    },
    {
        CRYPTO_HASH,
        (uint8)CRYPTO_ALGOFAM_SHA2_256,
        (uint8)CRYPTO_ALGOMODE_NOT_SET,
        (uint8)CRYPTO_ALGOFAM_NOT_SET,
        (boolean)FALSE
    }
};

#define CRYPTO_43_HSE_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define CRYPTO_43_HSE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_43_HSE_MemMap.h"

/* Array storing the key element information that is volatile (no need to be persistent across resets) */
static uint8 Crypto_43_HSE_au8VolatileKeyElemValues[4U];

#define CRYPTO_43_HSE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_43_HSE_MemMap.h"

#define CRYPTO_43_HSE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/* Array storing the queued jobs for the Crypto Driver Object CDO_HSE_Symmetric */
static Crypto_43_HSE_QueueElementType Crypto_43_HSE_aQueuedJobs_CDO_HSE_Symmetric[6U];

#define CRYPTO_43_HSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define CRYPTO_43_HSE_START_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

/* Array storing the mapping of the MU instance per partition */
const Crypto_43_HSE_PartitionToMuMappingType Crypto_43_HSE_aPartitionToMuMapping[CRYPTO_43_HSE_MAX_NUMBER_PARTITIONS_U8] =
{
    {HSE_IP_MU_0, 0x00U}
};

#define CRYPTO_43_HSE_STOP_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"


#define CRYPTO_43_HSE_START_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/* Array of structures storing the information of the Crypto Driver Objects mapped on partitions */
const Crypto_43_HSE_PartitionToCdoMappingType Crypto_43_HSE_aPartitionToCdoMapping[CRYPTO_43_HSE_MAX_NUMBER_PARTITIONS_U8] =
{
    /* Structure storing the information of the Crypto Driver Objects */
    {
        /* Number of Crypto Driver Objects */
        1U,
        /* Reference to array storing the indexes of the Crypto Driver Objects */
        Crypto_43_HSE_au8CDOs
    }
};

/* Array of structures storing the information about the Crypto Driver Objects */
const Crypto_43_HSE_ObjectType Crypto_43_HSE_aDriverObjectList[CRYPTO_43_HSE_NUMBER_OF_DRIVER_OBJECTS_U32] =
{
    /* Structure storing the information about Crypto Driver Object CDO_HSE_Symmetric */
    {
        /* Reference to the jobs queue */
        Crypto_43_HSE_aQueuedJobs_CDO_HSE_Symmetric,
        /* Jobs queue size */
        6U,
        /* Reference to the Crypto primitives list */
        Crypto_43_HSE_aPrimitives_CDO_HSE_Symmetric,
        /* Number of crypto primitives */
        6U
    }
};

/* Array of structures storing the information about the Crypto Keys */
const Crypto_43_HSE_KeyType Crypto_43_HSE_aKeyList[CRYPTO_43_HSE_NUMBER_OF_KEYS_U32] =
{
    {
        /* Number of key elements in the key Crypto_Key_HSE_AES128 */
        1U,
        /* Reference to the list of key elements in the key Crypto_Key_HSE_AES128 */
        Crypto_43_HSE_au32KeyElementList_Crypto_Key_HSE_AES128,
        /* Pointer to location storing the Key Status value */
        &Crypto_43_HSE_au8NvramBlock_Crypto_Key_HSE_AES128[0]
    }
};

/* Array of structures storing the information about the Crypto Key Elements */
const Crypto_43_HSE_KeyElementType Crypto_43_HSE_aKeyElementList[CRYPTO_43_HSE_NUMBER_OF_KEY_ELEMENTS_U32] =
{
    /* Structure containing information for Key Element Crypto_KE_AES128 */
    {
        /* KeyElementId */
        1U,
        /* Allow partial access */
        (boolean)FALSE,
        /* Key element format */
        CRYPTO_43_HSE_KE_FORMAT_BIN_RSA_PRIVATEKEY,
        /* Key element persistent */
        (boolean)FALSE,
        /* Read access type */
        CRYPTO_43_HSE_RA_DENIED,
        /* Key element max size */
        64U,
        /* Write access type */
        CRYPTO_43_HSE_WA_ALLOWED,
        /* Pointer to location storing the Key Element actual size */
        (uint32*)&Crypto_43_HSE_au8VolatileKeyElemValues[0U],
        /* Pointer to location storing the Key Element value */
        NULL_PTR,
        /* HSE key counter */
        0U,
        /* ECC curve id */
        HSE_EC_CURVE_NONE,
        /* Flags of the HSE key */
        (HSE_KF_USAGE_ENCRYPT | HSE_KF_USAGE_DECRYPT | HSE_KF_USAGE_SIGN | HSE_KF_USAGE_VERIFY | 0U),
        /* HSE key SMR flags */
        0x00000000U,
        /* HSE key type */
        (uint8)HSE_KEY_TYPE_AES,
        /* Identifier of the HSE key in the key catalogs */
        0x00020000U
    }
};

/* Table containing NVM key catalog entries */
const hseKeyGroupCfgEntry_t aHseNvmKeyCatalog[] =
{
    /* NvmKeyGroup_AES */
    {(HSE_MU0_MASK | HSE_MU1_MASK), HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_AES, 10U, 128U, {0U, 0U}},
    /* Marker to end the key catalog */
    {0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};

/* Table containing RAM key catalog entries */
const hseKeyGroupCfgEntry_t aHseRamKeyCatalog[] =
{
    /* RamKeyGroup_AES */
    {(HSE_MU0_MASK | HSE_MU1_MASK), HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_AES, 20U, 128U, {0U, 0U}},
    /* Marker to end the key catalog */
    {0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};

#define CRYPTO_43_HSE_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define CRYPTO_43_HSE_START_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"

/* Array storing persistent information for Key Crypto_Key_HSE_AES128 */
uint8 Crypto_43_HSE_au8NvramBlock_Crypto_Key_HSE_AES128[CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_CRYPTO_KEY_HSE_AES128] =
{
    /* Offset 0 - Key Valid information - as per SWS_CRYPTO_00251 - always set default as CRYPTO_KEYSTATUS_VALID */
    CRYPTO_KEYSTATUS_VALID
};

#define CRYPTO_43_HSE_STOP_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"

#define CRYPTO_43_HSE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

Crypto_43_HSE_ObjectQueueType Crypto_43_HSE_aObjectQueueList[CRYPTO_43_HSE_NUMBER_OF_DRIVER_OBJECTS_U32];

#define CRYPTO_43_HSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

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

