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

#ifndef CRYPTO_43_HSE_CFG_H
#define CRYPTO_43_HSE_CFG_H

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
#include "Crypto_43_HSE_Types.h"
#include "SchM_Crypto_43_HSE.h"
[!IF "node:exists(CryptoNvStorage)"!][!//
#include "NvM.h"
[!ENDIF!][!//
#include "hse_interface.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_43_HSE_VENDOR_ID_CFG                       43
#define CRYPTO_43_HSE_MODULE_ID_CFG                       114
#define CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_CFG        4
#define CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_CFG        7
#define CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION_CFG     0
#define CRYPTO_43_HSE_SW_MAJOR_VERSION_CFG                4
#define CRYPTO_43_HSE_SW_MINOR_VERSION_CFG                0
#define CRYPTO_43_HSE_SW_PATCH_VERSION_CFG                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Crypto_43_HSE_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//
/* Check if Crypto Cfg header file and Crypto Types header file are of the same vendor */
#if (CRYPTO_43_HSE_VENDOR_ID_CFG != CRYPTO_43_HSE_VENDOR_ID_TYPES)
    #error "Crypto_43_HSE_Cfg.h and Crypto_43_HSE_Types.h have different vendor ids"
#endif

/* Check if Crypto Cfg header file and Crypto Types header file are of the same Autosar version */
#if ((CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_CFG    != CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_CFG    != CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION_CFG != CRYPTO_43_HSE_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Crypto_43_HSE_Cfg.h and Crypto_43_HSE_Types.h are different"
#endif

/* Check if Crypto Cfg header file and Crypto Types header file are of the same Software version */
#if ((CRYPTO_43_HSE_SW_MAJOR_VERSION_CFG != CRYPTO_43_HSE_SW_MAJOR_VERSION_TYPES) || \
     (CRYPTO_43_HSE_SW_MINOR_VERSION_CFG != CRYPTO_43_HSE_SW_MINOR_VERSION_TYPES) || \
     (CRYPTO_43_HSE_SW_PATCH_VERSION_CFG != CRYPTO_43_HSE_SW_PATCH_VERSION_TYPES)    \
    )
    #error "Software Version Numbers of Crypto_43_HSE_Cfg.h and Crypto_43_HSE_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Crypto Cfg header file and SchM_Crypto header file are of the same Autosar version */
    #if ((CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION_CFG != SCHM_CRYPTO_43_HSE_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION_CFG != SCHM_CRYPTO_43_HSE_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Crypto_43_HSE_Cfg.h and SchM_Crypto_43_HSE.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!INDENT "0"!][!//
/* Pre-processor switch to enable/disable development error detection for Crypto API */
#define CRYPTO_43_HSE_DEV_ERROR_DETECT                         ([!IF "CryptoGeneral/CryptoDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable/disable the API to read out the modules version information */
#define CRYPTO_43_HSE_VERSION_INFO_API                         ([!IF "CryptoGeneral/CryptoVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Crypto instance ID value */
#define CRYPTO_43_HSE_INSTANCE_ID                              ((uint8)[!"node:value(CryptoGeneral/CryptoInstanceId)"!])

[!IF "node:exists(CryptoGeneral/CryptoMainFunctionPeriod)"!][!//
    /* Crypto main function period */
    #define CRYPTO_43_HSE_MAIN_FUNCTION_PERIOD                     ([!"node:value(CryptoGeneral/CryptoMainFunctionPeriod)"!])

[!ENDIF!][!//
/* Set asynchronous job process method */
#define CRYPTO_43_HSE_USE_INTERRUPTS_FOR_ASYNC_JOBS            ([!IF "node:value(CryptoGeneral/CryptoAsyncJobProcessMethod) = 'INTERRUPT'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Crypto Timeout value */
#define CRYPTO_43_HSE_TIMEOUT_DURATION_U32                     ((uint32)[!"node:value("CryptoGeneral/CryptoTimeoutDuration")"!]U)

[!IF "num:i(count(CryptoGeneral/CryptoEcucPartitionRef/*)) > 0"!][!//
/* Pre-processor switch to enable multicore support in Crypto driver */
#define CRYPTO_43_HSE_ENABLE_MULTICORE_SUPPORT                 (STD_ON)

/* Max number of partitions configured from the application */
#define CRYPTO_43_HSE_MAX_NUMBER_PARTITIONS_U8                 ((uint8)[!"num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]U)

[!NOCODE!][!//
[!VAR "MaxNumPartitions" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
[!VAR "NumPartitionsMatched" = "num:i(0)"!][!//
[!FOR "x" = "0" TO "num:i($MaxNumPartitions - 1)"!][!//
    [!VAR "PartitionMatched" = "'false'"!][!//
    [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
        [!IF "node:exists(./CryptoDriverObjectEcucPartitionRef)"!][!//
            [!VAR "CurCdoPartition" = "node:value(./CryptoDriverObjectEcucPartitionRef)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                    [!IF "$CurCdoPartition = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!IF "node:refvalid(./OsApplicationCoreRef)"!][!//
                            [!IF "$x = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!][!//
                                [!VAR "PartitionMatched" = "'true'"!][!//
                                [!VAR "NumPartitionsMatched" = "$NumPartitionsMatched + 1"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
        [!IF "$PartitionMatched = 'true'"!][!//
            [!BREAK!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDFOR!][!//
[!IF "$NumPartitionsMatched = num:i(0)"!][!//
    [!ERROR!][!//
        None of the referenced ECUC partitions in the CryptoDriverObjectEcucPartitionRef list of the CryptoDriverObject list is associated with an OsApplication or the OsApplication does not have a valid OsApplicationCoreRef!
    [!ENDERROR!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/* Number of configured partitions the driver can run in */
#define CRYPTO_43_HSE_NUMBER_PARTITIONS_ALLOWED_TO_RUN_IN_U8   ((uint8)[!"num:i($NumPartitionsMatched)"!]U)
[!ELSE!][!//
/* Pre-processor switch to disable multicore support in Crypto driver */
#define CRYPTO_43_HSE_ENABLE_MULTICORE_SUPPORT                 (STD_OFF)

/* Max number of partitions configured from the application */
#define CRYPTO_43_HSE_MAX_NUMBER_PARTITIONS_U8                 ((uint8)1U)

/* Number of configured partitions the driver can run in */
#define CRYPTO_43_HSE_NUMBER_PARTITIONS_ALLOWED_TO_RUN_IN_U8   ((uint8)1U)
[!ENDIF!][!//

/* Number of configured Crypto driver objects */
#define CRYPTO_43_HSE_NUMBER_OF_DRIVER_OBJECTS_U32             ((uint32)[!"num:i(count(CryptoDriverObjects/CryptoDriverObject/*))"!]U)

[!IF "node:exists(CryptoKeys)"!][!//
    /* Compile time switch stating that there is at least one configured key */
    #define CRYPTO_43_HSE_KEYS_EXIST                               (STD_ON)

    /* Compile time switch stating that support for Nvram read/write operations is enabled or disabled */
    #define CRYPTO_43_HSE_ENABLE_KEY_STORAGE_IN_NVM                ([!IF "node:exists(CryptoNvStorage)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

    /* Number of Crypto keys */
    #define CRYPTO_43_HSE_NUMBER_OF_KEYS_U32                       ((uint32)[!"num:i(count(CryptoKeys/CryptoKey/*))"!]U)

[!VAR "NumKeyElem" = "0"!][!//
[!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
    [!LOOP "node:refs(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*)"!][!//
    [!VAR "NumKeyElem" = "$NumKeyElem + 1"!][!//
    [!ENDLOOP!][!//
[!ENDLOOP!][!//

    /* Number of Crypto key elements */
    #define CRYPTO_43_HSE_NUMBER_OF_KEY_ELEMENTS_U32               ((uint32)[!"num:i($NumKeyElem)"!]U)


    /* Switch for configuring the measure unit the Crypto driver will use for processing the inputLength and outputLengthPtr parameters of a received FastCmac job.
    *       STD_ON:  the Crypto driver will consider that the inputLength and outputLengthPtr parameters of a received FastCmac job are measured in bits.
    *       STD_OFF: the Crypto driver will consider that the inputLength and outputLengthPtr parameters of a received FastCmac job are measured in bytes. */
    #define CRYPTO_43_HSE_LENGTHS_FOR_FASTCMAC_JOBS_USE_BITS       ([!IF "CryptoGeneral/CryptoInputLengthAndOutputLengthPtrForFastCmacJobsUseBits"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!][!//
    [!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!VAR "CryptoKeyName"="node:name(.)"!][!//
        /* Minium value of 1 is for the key status - valid or invalid */
        [!VAR "SizeOfKeyElemPersistValuesBlob"="1"!][!//
        [!VAR "KeyElemPersistBlobHasAllBytesZero"="'true'"!][!//
        [!LOOP "node:refs(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*)"!][!//
            [!IF "node:value(./UseHseKey)='false' and node:value(./CryptoKeyElementPersist) = 'true' "!][!//
                /* If the key element does not use a HSE key, add the max size of the key element buffer + 4 bytes storing the 32bit value of the actual size */
                [!VAR "SizeOfKeyElemPersistValuesBlob" = "$SizeOfKeyElemPersistValuesBlob + node:value(./CryptoKeyElementSize) + num:i(4)"!][!//
                [!IF "num:i(string-length(node:value(./CryptoKeyElementInitValue)))!=0"!][!//
                    [!VAR "KeyElemPersistBlobHasAllBytesZero"="'false'"!][!//
                [!ENDIF!][!//
            [!ELSEIF "node:value(./UseHseKey)='true' and node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'NvmKeyCatalog' "!][!//
                /* If the key element uses a HSE key, add the 4 bytes storing the 32bit value of the actual size */
                [!VAR "SizeOfKeyElemPersistValuesBlob" = "$SizeOfKeyElemPersistValuesBlob + num:i(4)"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!CODE!][!//
        #define CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]                      ([!"num:i($SizeOfKeyElemPersistValuesBlob)"!]U)
        [!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//


[!ELSE!][!//
    /* Compile time switch stating that there is no configured key */
    #define CRYPTO_43_HSE_KEYS_EXIST                               (STD_OFF)

    /* Compile time switch stating that support for Nvram read/write operations is enabled or disabled */
    #define CRYPTO_43_HSE_ENABLE_KEY_STORAGE_IN_NVM                (STD_OFF)
[!ENDIF!][!//

/* Pre-processor switch to enable/disable support in Crypto driver for job redirection feature */
[!IF "node:exists(CryptoKeys)"!][!//
    #define CRYPTO_43_HSE_ENABLE_REDIRECTION_SUPPORT               ([!IF "CryptoGeneral/CryptoEnableRedirection"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
    #define CRYPTO_43_HSE_ENABLE_REDIRECTION_SUPPORT               (STD_OFF)
[!ENDIF!][!//

/* Pre-processor switch to enable/disable support in Crypto driver for feeding Hse Firmware with descriptors using Crypto_43_HSE_KeyElementGet() API */
[!IF "node:exists(CryptoKeys)"!][!//
    #define CRYPTO_43_HSE_ENABLE_FEED_HSE_DESC_SUPPORT             ([!IF "CryptoGeneral/CryptoEnableFeedHseDesc"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
    #define CRYPTO_43_HSE_ENABLE_FEED_HSE_DESC_SUPPORT             (STD_OFF)
[!ENDIF!][!//

/* Support for User mode.
*       STD_ON:  the Crypto driver can be executed from both supervisor and user mode
*       STD_OFF: the Crypto driver can be executed only from supervisor mode */
#define CRYPTO_43_HSE_ENABLE_USER_MODE_SUPPORT                 ([!IF "CryptoGeneral/CryptoEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!INDENT "0"!]#ifndef MCAL_ENABLE_USER_MODE_SUPPORT[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#ifdef CRYPTO_43_HSE_ENABLE_USER_MODE_SUPPORT[!CR!][!ENDINDENT!][!//
[!INDENT "8"!]#if (STD_ON == CRYPTO_43_HSE_ENABLE_USER_MODE_SUPPORT)[!CR!][!ENDINDENT!][!//
[!INDENT "12"!]#error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Crypto driver in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.[!CR!][!ENDINDENT!][!//
[!INDENT "8"!]#endif /* (STD_ON == CRYPTO_43_HSE_ENABLE_USER_MODE_SUPPORT) */[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#endif /* ifndef CRYPTO_43_HSE_ENABLE_USER_MODE_SUPPORT */[!CR!][!ENDINDENT!][!//
[!INDENT "0"!]#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/[!CR!][!ENDINDENT!][!//

/* Support for SHE */
#define CRYPTO_43_HSE_SPT_SHE                                  ([!"ecu:get(concat('Crypto.HseSptShe.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for Miyaguchi-Preneel compression function (SHE spec support) */
#define CRYPTO_43_HSE_SPT_MP                                   ([!"ecu:get(concat('Crypto.HseSptMP.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for AES */
#define CRYPTO_43_HSE_SPT_AES                                  ([!"ecu:get(concat('Crypto.HseSptAes.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_AES_CBC                          ([!"ecu:get(concat('Crypto.HseSptAesCbc.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_AES_CFB                          ([!"ecu:get(concat('Crypto.HseSptAesCfb.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_AES_CTR                          ([!"ecu:get(concat('Crypto.HseSptAesCtr.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_AES_ECB                          ([!"ecu:get(concat('Crypto.HseSptAesEcb.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_AES_OFB                          ([!"ecu:get(concat('Crypto.HseSptAesOfb.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]/* Support for XTS AES */[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_XTS_AES                          ([!"ecu:get(concat('Crypto.HseSptXtsAes.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//

/* Support for AEAD */
#define CRYPTO_43_HSE_SPT_AEAD                                 ([!"ecu:get(concat('Crypto.HseSptAead.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for MAC */
#define CRYPTO_43_HSE_SPT_MAC                                  ([!"ecu:get(concat('Crypto.HseSptMac.',      string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_CMAC                             ([!"ecu:get(concat('Crypto.HseSptCmac.',     string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_FAST_CMAC                        ([!"ecu:get(concat('Crypto.HseSptFastCmac.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_GMAC                             ([!"ecu:get(concat('Crypto.HseSptGmac.',     string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_HMAC                             ([!"ecu:get(concat('Crypto.HseSptHmac.',     string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_XCBCMAC                          ([!"ecu:get(concat('Crypto.HseSptXCbcmac.',  string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//

/* Support for TDES_(128, 192)_(ECB, CBC, CFB, OFB) as defined  in NIST SP 800-67 rev1. */
#define CRYPTO_43_HSE_SPT_TDES                                 ([!"ecu:get(concat('Crypto.HseSptTdes.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for HASH primitives */
#define CRYPTO_43_HSE_SPT_HASH                                 ([!"ecu:get(concat('Crypto.HseSptHash.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_MD5                              ([!"ecu:get(concat('Crypto.HseSptMd5.',          string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA1                             ([!"ecu:get(concat('Crypto.HseSptSha1.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA2_224                         ([!"ecu:get(concat('Crypto.HseSptSha2_224.',     string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA2_256                         ([!"ecu:get(concat('Crypto.HseSptSha2_256.',     string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA2_384                         ([!"ecu:get(concat('Crypto.HseSptSha2_384.',     string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA2_512                         ([!"ecu:get(concat('Crypto.HseSptSha2_512.',     string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA2_512_224                     ([!"ecu:get(concat('Crypto.HseSptSha2_512_224.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA2_512_256                     ([!"ecu:get(concat('Crypto.HseSptSha2_512_256.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHA3                             ([!"ecu:get(concat('Crypto.HseSptSha3.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//

/* Support for SIPHASH primitive */
#define CRYPTO_43_HSE_SPT_SIPHASH                              ([!"ecu:get(concat('Crypto.HseSptSiphash.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for RSA primitives */
#define CRYPTO_43_HSE_SPT_RSA                                  ([!"ecu:get(concat('Crypto.HseSptRsa.',                    string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSAES_NO_PADDING                 ([!"ecu:get(concat('Crypto.HseSptRsaesNoPadding.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSAES_OAEP                       ([!"ecu:get(concat('Crypto.HseSptRsaesOaep.',              string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSAES_PCKS1_V15                  ([!"ecu:get(concat('Crypto.HseSptRsaesPkcs1V15.',          string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSAASSA_PSS                      ([!"ecu:get(concat('Crypto.HseSptRsassaPss.',              string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSASSA_PCKS1_V15                 ([!"ecu:get(concat('Crypto.HseSptRsassaPkcs1V15.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//

/* Support for ECC primitives */
#define CRYPTO_43_HSE_SPT_ECC                                  ([!"ecu:get(concat('Crypto.HseSptEcc.',                    string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_EDDSA                            ([!"ecu:get(concat('Crypto.HseSptEddsa.',                  string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_ECDSA                            ([!"ecu:get(concat('Crypto.HseSptEcdsa.',                  string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SECP256R1                        ([!"ecu:get(concat('Crypto.HseSptEcSecSecp256R1.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SECP384R1                        ([!"ecu:get(concat('Crypto.HseSptEcSecSecp384R1.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SECP521R1                        ([!"ecu:get(concat('Crypto.HseSptEcSecSecp521R1.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_BRAINPOOLP256R1                  ([!"ecu:get(concat('Crypto.HseSptEcBrainpoolP256R1.',      string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_BRAINPOOLP320R1                  ([!"ecu:get(concat('Crypto.HseSptEcBrainpoolP320R1.',      string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_BRAINPOOLP384R1                  ([!"ecu:get(concat('Crypto.HseSptEcBrainpoolP384R1.',      string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_BRAINPOOLP512R1                  ([!"ecu:get(concat('Crypto.HseSptEcBrainpoolP512R1.',      string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_EC25519_ED25519                  ([!"ecu:get(concat('Crypto.HseSptEc25519Ed25519.',         string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_EC25519_ED25519PH                ([!"ecu:get(concat('Crypto.HseSptEc25519Ed25519PH.',       string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_EC25519_CURVE25519               ([!"ecu:get(concat('Crypto.HseSptEc25519Curve25519.',      string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_EC448_ED448                      ([!"ecu:get(concat('Crypto.HseSptEc448Ed448.',             string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_EC448_CURVE448                   ([!"ecu:get(concat('Crypto.HseSptEc448Curve448.',          string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//

/* Support for various key operations */
#define CRYPTO_43_HSE_SPT_KEY_IMPORT                           ([!"ecu:get(concat('Crypto.HseSptKeyImport.',             string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHE_KEY_IMPORT                   ([!"ecu:get(concat('Crypto.HseSptSheKeyImport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SYM_KEY_IMPORT                   ([!"ecu:get(concat('Crypto.HseSptSymKeyImport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSA_KEY_IMPORT                   ([!"ecu:get(concat('Crypto.HseSptRsaKeyImport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_ECC_KEY_IMPORT                   ([!"ecu:get(concat('Crypto.HseSptEccKeyImport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_ENC_AUTH_KEY_IMPORT              ([!"ecu:get(concat('Crypto.HseSptEncAuthKeyImport.',       string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
#define CRYPTO_43_HSE_SPT_KEY_EXPORT                           ([!"ecu:get(concat('Crypto.HseSptKeyExport.',              string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SHE_KEY_EXPORT                   ([!"ecu:get(concat('Crypto.HseSptSheKeyExport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SYM_KEY_EXPORT                   ([!"ecu:get(concat('Crypto.HseSptSymKeyExport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSA_KEY_EXPORT                   ([!"ecu:get(concat('Crypto.HseSptRsaKeyExport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_ECC_KEY_EXPORT                   ([!"ecu:get(concat('Crypto.HseSptEccKeyExport.',           string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
#define CRYPTO_43_HSE_SPT_FORMATKEYCATALOGS                    ([!"ecu:get(concat('Crypto.HseSptFormatKeyCatalogs.',      string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
#define CRYPTO_43_HSE_SPT_GETKEYINFO                           ([!"ecu:get(concat('Crypto.HseSptGetKeyInfo.',             string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
#define CRYPTO_43_HSE_SPT_KEYVERIFY                            ([!"ecu:get(concat('Crypto.HseSptKeyVerify.',             string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for key derivation */
#define CRYPTO_43_HSE_SPT_KEY_DERIVE                           ([!"ecu:get(concat('Crypto.HseSptKeyDerive.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_KDF_ANS_X963                     ([!"ecu:get(concat('Crypto.HseSptKDFAnsX963.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_PBKDF2                           ([!"ecu:get(concat('Crypto.HseSptPBKDF2.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_KDFTLS_12PRF                     ([!"ecu:get(concat('Crypto.HseSptKdfTls12Prf.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//

/* Support for Diffie-Hellman Compute Key */
#define CRYPTO_43_HSE_SPT_COMPUTE_DH                           ([!"ecu:get(concat('Crypto.HseSptComputeDH.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support Import/Export of streaming context for symmetric operations */
#define CRYPTO_43_HSE_SPT_STREAM_CTX_IMPORT_EXPORT             ([!"ecu:get(concat('Crypto.HseSptStreamCtxImportExport.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for key generation */
#define CRYPTO_43_HSE_SPT_KEY_GENERATE                         ([!"ecu:get(concat('Crypto.HseSptKeyGenerate.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_SYM_RND_KEY_GEN                  ([!"ecu:get(concat('Crypto.HseSptSymRndKeyGen.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_RSA_KEY_PAIR_GEN                 ([!"ecu:get(concat('Crypto.HseSptRsaKeyPairGen.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_ECC_KEY_PAIR_GEN                 ([!"ecu:get(concat('Crypto.HseSptEccKeyPairGen.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#define CRYPTO_43_HSE_SPT_CLASSIC_DH_KEY_PAIR_GEN          ([!"ecu:get(concat('Crypto.HseSptClassicDHKeyPairGen.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])[!CR!][!ENDINDENT!][!//

/* Support for Cipher modes flags for AES keys */
#define CRYPTO_43_HSE_AES_BLOCK_MODE_MASK                      ([!"ecu:get(concat('Crypto.HseAesBlockModeMask.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for HSE ECC key format */
#define CRYPTO_43_HSE_ECC_KEY_FORMAT                           ([!"ecu:get(concat('Crypto.HseEccKeyFormat.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

/* Support for Compressed ECC key format */
#define CRYPTO_43_HSE_ECC_COMPRESSED_FORMAT                    ([!"ecu:get(concat('Crypto.HseEccCompressedFormat.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD'))))"!])

[!NOCODE!][!//
    /* The Tresos generator code below creates the symbolic name defines for CryptoDriverObjectId, CryptoKeyId and CryptoKeyElementId attributes from their
    corresponding lists, making sure that all the values are written on the same column of the generated Crypto_43_HSE_Cfg.h file */
    [!VAR "MaxLength" = "0"!][!//
    [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
        [!IF "string-length(concat('CryptoConf_CryptoDriverObject_', node:name(.))) > $MaxLength"!][!//
            [!VAR "MaxLength" = "string-length(concat('CryptoConf_CryptoDriverObject_', node:name(.)))"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "node:exists(CryptoKeys)"!][!//
        [!LOOP "CryptoKeys/CryptoKey/*"!][!//
            [!IF "string-length(concat('CryptoConf_CryptoKey_', node:name(.))) > $MaxLength"!][!//
                [!VAR "MaxLength" = "string-length(concat('CryptoConf_CryptoKey_', node:name(.)))"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
    [!IF "node:exists(CryptoKeyElements)"!][!//
        [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
            [!IF "string-length(concat('CryptoConf_CryptoKeyElement_', node:name(.))) > $MaxLength"!][!//
                [!VAR "MaxLength" = "string-length(concat('CryptoConf_CryptoKeyElement_', node:name(.)))"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//

    [!CODE!]/* Symbolic names for the CryptoDriverObjectId attribute of all the Crypto Driver Objects */[!ENDCODE!][!CR!][!//
    [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
        [!CODE!]#define CryptoConf_CryptoDriverObject_[!"node:name(.)"!][!ENDCODE!][!//
        [!FOR "LoopCounter" = "1" TO "$MaxLength + 2 - string-length(concat('CryptoConf_CryptoDriverObject_', node:name(.)))"!][!//
            [!CODE!] [!ENDCODE!][!//
        [!ENDFOR!][!//
        [!CODE!]((uint32)[!"CryptoDriverObjectId"!]U)[!ENDCODE!][!CR!][!//
    [!ENDLOOP!][!//

    [!IF "node:exists(CryptoKeys)"!][!//
        [!CR!][!CODE!]/* Symbolic names for the CryptoKeyId attribute of all the Crypto keys */[!ENDCODE!][!CR!][!//
        [!LOOP "CryptoKeys/CryptoKey/*"!][!//
            [!CODE!]#define CryptoConf_CryptoKey_[!"node:name(.)"!][!ENDCODE!][!//
            [!FOR "LoopCounter" = "1" TO "$MaxLength + 2 - string-length(concat('CryptoConf_CryptoKey_', node:name(.)))"!][!//
                [!CODE!] [!ENDCODE!][!//
            [!ENDFOR!][!//
            [!CODE!]((uint32)[!"CryptoKeyId"!]U)[!ENDCODE!][!CR!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//

    [!IF "node:exists(CryptoKeyElements)"!][!//
        [!CR!][!CODE!]/* Symbolic names for the CryptoKeyElementId attribute of all the Crypto key elements */[!ENDCODE!][!CR!][!//
        [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
            [!CODE!]#define CryptoConf_CryptoKeyElement_[!"node:name(.)"!][!ENDCODE!][!//
            [!FOR "LoopCounter" = "1" TO "$MaxLength + 2 - string-length(concat('CryptoConf_CryptoKeyElement_', node:name(.)))"!][!//
                [!CODE!] [!ENDCODE!][!//
            [!ENDFOR!][!//
            [!CODE!]((uint32)[!"CryptoKeyElementId"!]U)[!ENDCODE!][!CR!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
[!IF "node:exists(CryptoKeys)"!][!//
/* Structure storing information about a Crypto Key Element */
typedef struct
{
    /* Members storing Autosar required information */
    const   uint32                           u32CryptoKeyElementId;
    const   boolean                          bCryptoKeyElementAllowPartialAccess;
    const   Crypto_43_HSE_KeyFormatType             eCryptoKeyFormat;
    const   boolean                          bCryptoKeyElementPersist;
    const   Crypto_43_HSE_KeyElementReadAccessType  eCryptoKeyElementReadAccess;
    const   uint32                           u32CryptoKeyElementMaxSize;
    const   Crypto_43_HSE_KeyElementWriteAccessType eCryptoKeyElementWriteAccess;
    uint32* const                            pu32CryptoElementActualSize;
    uint8*  const                            pCryptoElementArray;
    /* Members storing HW specific required information (HSE related) */
    const   uint32                           u32HseKeyCounter;
[!IF "ecu:get(concat('Crypto.HseSptEccKeyImport.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON'"!][!//
    const   uint8                            u8HseEccCurveId;
[!ENDIF!][!//
[!IF "ecu:get(concat('Crypto.HseSptSymKeyImport.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON' or
      ecu:get(concat('Crypto.HseSptRsaKeyImport.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON' or
      ecu:get(concat('Crypto.HseSptEccKeyImport.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON' or
      ecu:get(concat('Crypto.HseSptKeyDerive.',    string(node:fallback(CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON'"!][!//
    const   hseKeyFlags_t                    hseKeyFlags;
    const   uint32                           u32HseKeySmrFlags;
[!ENDIF!][!//
    const   uint8                            u8HseKeyType;
    const   uint32                           u32HseKeyHandle;
} Crypto_43_HSE_KeyElementType;

[!IF "node:exists(CryptoNvStorage)"!][!//
/* Type describing Crypto_43_HSE_NvBlockProcessingType */
typedef enum
{
    CRYPTO_43_HSE_NV_BLOCK_DEFERRED  = 0x01,
    CRYPTO_43_HSE_NV_BLOCK_IMMEDIATE = 0x02
} Crypto_43_HSE_NvBlockProcessingType;

/* Type describing Crypto Nv Blocks */
typedef struct
{
    const uint16                        NvBlockId;
    const uint16                        NvBlockFailedRetries;
    Crypto_43_HSE_NvBlockProcessingType NvBlockProcessing;
    uint16                              NumNvBlockFailedRetries;
    Crypto_KeyStatusType                CryptoKeyStatusCopy;
    uint32                              SizeOfNvBlock;
} Crypto_43_HSE_NvBlockType;

[!ENDIF!][!//
[!ENDIF!][!//


/* Structure containing the number and list of Crypto Driver Objects allocated to a partition */
typedef struct
{
    const uint8  u8NumCDOs;
    const uint8* au8CDOsList;
}Crypto_43_HSE_PartitionToCdoMappingType;

/* Structure storing information about a Crypto Driver Object */
typedef struct
{
[!IF "num:i(count(CryptoGeneral/CryptoEcucPartitionRef/*)) > 0"!][!//
    const uint32                      u32ValidPartitionId;
[!ENDIF!][!//
    Crypto_43_HSE_QueueElementType* const    pQueuedJobs;
    const uint32                      u32CryptoQueueSize;
    const Crypto_43_HSE_PrimitiveType* const pCryptoKeyPrimitives;
    const uint32                      u32NoCryptoPrimitives;
} Crypto_43_HSE_ObjectType;

/* Structure storing information about which Mu instance is allocated to a partition */
typedef struct
{
    const uint8 u8MuInstance;
    const uint8 u8IdxMuInstance;
} Crypto_43_HSE_PartitionToMuMappingType;

/*==================================================================================================
*                                  GLOBAL CONSTANTS DECLARATIONS
==================================================================================================*/

#define CRYPTO_43_HSE_START_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

/* Array storing the mapping of the MU instance per partition */
extern const Crypto_43_HSE_PartitionToMuMappingType Crypto_43_HSE_aPartitionToMuMapping[CRYPTO_43_HSE_MAX_NUMBER_PARTITIONS_U8];

#define CRYPTO_43_HSE_STOP_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

#define CRYPTO_43_HSE_START_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/* Variables related to Hse KeyCatalog feature */
[!IF "ecu:get(concat('Crypto.HseSptFormatKeyCatalogs.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON'"!][!//
extern const hseKeyGroupCfgEntry_t aHseNvmKeyCatalog[[!"num:i(count(NvmKeyCatalog/*)+1)"!]U];
extern const hseKeyGroupCfgEntry_t aHseRamKeyCatalog[[!"num:i(count(RamKeyCatalog/*)+1)"!]U];
[!ENDIF!][!//

#define CRYPTO_43_HSE_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
[!IF "node:exists(CryptoKeys)"!][!//
[!IF "node:exists(CryptoNvStorage)"!][!//
#define CRYPTO_43_HSE_START_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"

/* Ram Buffers which will be referenced by the NvM driver */
[!NOCODE!][!//
[!LOOP "node:order(CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
    [!IF "node:exists(CryptoKeyNvBlockRef)"!][!//
        [!VAR "CryptoKeyName"="node:name(.)"!][!//
        [!VAR "CryptoKeyId"="num:i(node:value(./CryptoKeyId))"!][!//
        [!CODE!]
        [!INDENT "0"!]
        extern uint8 Crypto_43_HSE_RamBuffer[!"text:toupper($CryptoKeyId)"!][CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]];
        [!ENDINDENT!]
        [!ENDCODE!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

#define CRYPTO_43_HSE_STOP_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"

#define CRYPTO_43_HSE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/* Array of configuration structs for each Crypto Key's NvBlockDescriptor */
[!NOCODE!][!//
[!CODE!]
[!INDENT "0"!]
extern Crypto_43_HSE_NvBlockType Crypto_43_HSE_aNvBlockDescriptor[CRYPTO_43_HSE_NUMBER_OF_KEYS_U32];
[!ENDINDENT!]
[!ENDCODE!]
[!ENDNOCODE!][!//

#define CRYPTO_43_HSE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

[!ENDIF!][!//

#define CRYPTO_43_HSE_START_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"

[!NOCODE!][!//
    [!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!VAR "CryptoKeyName"="node:name(.)"!][!//
        /* Create define of the size of each nvram block */
        [!CODE!][!//
        [!INDENT "0"!]
           /* Array storing persistent information for Key [!"$CryptoKeyName"!] */
            extern uint8 Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!][CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]];[!CR!][!CR!][!//
        [!ENDINDENT!][!//
        [!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
#define CRYPTO_43_HSE_STOP_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"
[!ENDIF!][!//


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

[!NOCODE!][!//
[!IF "node:exists(CryptoNvStorage) and node:exists(CryptoKeys)"!][!//
[!INDENT "0"!]
[!CODE!][!//
#define CRYPTO_43_HSE_START_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"

/* Crypto callback functions for NvRAM Storage */
/* SWS_Crypto_00246: For each configured CryptoNvBlock the Crypto driver shall provide 
   a separate set of Crypto_<vi>_<ai>_NvBlock_xxx_<NvBlock>() functions (xxx refers to Init, 
   ReadFrom, WriteTo and Callback) (see chapter Callback notification).
*/
[!ENDCODE!][!//
[!LOOP "node:order(CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
    [!IF "node:exists(CryptoKeyNvBlockRef)"!][!//
        [!VAR "CryptoNvBlockName" = "node:ref(node:value(./CryptoKeyNvBlockRef))/@name"!][!//
        [!CODE!][!//
        /* Function Crypto_43_HSE_NvBlock_Init_[!"$CryptoNvBlockName"!] */
        extern Std_ReturnType Crypto_43_HSE_NvBlock_Init_[!"$CryptoNvBlockName"!](NvM_InitBlockRequestType initBlockRequest);

        /* Function Crypto_43_HSE_NvBlock_ReadFrom_[!"$CryptoNvBlockName"!] */
        extern Std_ReturnType Crypto_43_HSE_NvBlock_ReadFrom_[!"$CryptoNvBlockName"!](const void* NvmBuffer);

        /* Function Crypto_43_HSE_NvBlock_WriteTo_[!"$CryptoNvBlockName"!] */
        extern Std_ReturnType Crypto_43_HSE_NvBlock_WriteTo_[!"$CryptoNvBlockName"!](void* NvmBuffer);

        /* Function Crypto_43_HSE_NvBlock_Callback_[!"$CryptoNvBlockName"!] */
        extern Std_ReturnType Crypto_43_HSE_NvBlock_Callback_[!"$CryptoNvBlockName"!](NvM_BlockRequestType BlockRequest, NvM_RequestResultType JobResult);
        [!ENDCODE!][!//
        [!CR!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!CODE!][!//
#define CRYPTO_43_HSE_STOP_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"
[!ENDCODE!][!//
[!ENDINDENT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRYPTO_43_HSE_CFG_H */

