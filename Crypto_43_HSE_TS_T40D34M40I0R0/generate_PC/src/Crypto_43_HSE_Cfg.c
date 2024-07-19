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
[!NOCODE!][!//
[!INCLUDE "Crypto_43_HSE_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//
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
[!AUTOSPACING!][!//

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define CRYPTO_43_HSE_START_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

[!IF "num:i(count(CryptoGeneral/CryptoEcucPartitionRef/*)) > 0"!][!//
    [!VAR "MaxNumPartitions" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!FOR "x" = "0" TO "num:i($MaxNumPartitions - 1)"!][!//
        [!VAR "NumMappedCdos" = "0"!][!//
        [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
            [!IF "node:exists(./CryptoDriverObjectEcucPartitionRef)"!][!//
                [!VAR "CurCdoPartition" = "node:value(./CryptoDriverObjectEcucPartitionRef)"!][!//
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                        [!IF "$CurCdoPartition = node:value(./OsAppEcucPartitionRef)"!][!//
                            [!IF "node:refvalid(./OsApplicationCoreRef)"!][!//
                                [!IF "$x = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!][!//
                                    [!VAR "NumMappedCdos" = "$NumMappedCdos + 1"!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$NumMappedCdos > 0"!][!//
            [!INDENT "0"!][!//
                /* Array storing the indexes of the Crypto Driver Objects mapped on partition [!"as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*[num:i($x) + 1]/@name"!] */
                static const uint8 Crypto_43_HSE_au8CDOs_[!"as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*[num:i($x) + 1]/@name"!][] =
                {
            [!ENDINDENT!][!//
            [!INDENT "4"!][!//
            [!VAR "NumFoundCdos" = "0"!][!//
            [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
                [!VAR "PartitionMatched" = "'false'"!][!//
                [!VAR "IdxCdo" = "@index"!][!//
                [!IF "node:exists(./CryptoDriverObjectEcucPartitionRef)"!][!//
                    [!VAR "CurCdoPartition" = "node:value(./CryptoDriverObjectEcucPartitionRef)"!][!//
                    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                        [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                            [!IF "$CurCdoPartition = node:value(./OsAppEcucPartitionRef)"!][!//
                                [!IF "node:refvalid(./OsApplicationCoreRef)"!][!//
                                    [!IF "$x = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!][!//[!ENDIF!][!//
                                        [!VAR "PartitionMatched" = "'true'"!][!//
                                        [!VAR "NumFoundCdos" = "$NumFoundCdos + 1"!][!//
                                    [!ENDIF!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDIF!][!//
                [!IF "$PartitionMatched = 'true'"!][!//
                    [!"$IdxCdo"!]U[!IF "$NumFoundCdos < $NumMappedCdos"!],[!ENDIF!][!CR!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!ENDINDENT!][!//
            [!INDENT "0"!][!//
                };
            [!ENDINDENT!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ELSE!][!//
    [!INDENT "0"!][!//
        /* Array storing the indexes of the Crypto Driver Objects */
        static const uint8 Crypto_43_HSE_au8CDOs[] =
        {
    [!VAR "CurCdo" = "0"!][!//
    [!VAR "NumCdos" = "num:i(count(CryptoDriverObjects/CryptoDriverObject/*))"!][!//
    [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
        [!VAR "CurCdo" = "$CurCdo + 1"!][!//
        [!INDENT "4"!][!//
        [!"@index"!]U[!IF "$CurCdo < $NumCdos"!],[!ENDIF!][!CR!][!//
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
        };
    [!ENDINDENT!][!//
[!ENDIF!][!//

#define CRYPTO_43_HSE_STOP_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

[!IF "node:exists(CryptoKeyElements)"!][!//
#define CRYPTO_43_HSE_START_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"

[!IF "node:exists(CryptoKeys)"!][!//
    [!VAR "KeyElementIdx" = "0"!][!//
    [!LOOP "node:order(CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!CODE!][!//
        [!INDENT "0"!]
        /* Array of indexes for each Crypto Key Element referred by Crypto Key [!"node:name(.)"!] */
        static const uint32 Crypto_43_HSE_au32KeyElementList_[!"node:name(.)"!][[!"num:i(count(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*))"!]U] =
        {
        [!ENDINDENT!]
        [!ENDCODE!][!//
        [!VAR "CryptoLoopIt" = "num:i(count(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*))"!][!//
        [!LOOP "node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*"!]
            [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
            [!IF "$CryptoLoopIt != 0"!][!//
                [!CODE!][!//
                [!INDENT "4"!]
                [!"num:i($KeyElementIdx)"!]U,
                [!ENDINDENT!][!//
                [!ENDCODE!][!//
            [!ELSE!][!//
                [!CODE!][!//
                [!INDENT "4"!]
                [!"num:i($KeyElementIdx)"!]U
                [!ENDINDENT!][!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "KeyElementIdx" = "$KeyElementIdx + num:i(1)"!][!//
        [!ENDLOOP!][!//
        [!CODE!][!//
        [!INDENT "0"!]
        };
        [!ENDINDENT!]
        [!CR!]
        [!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//

#define CRYPTO_43_HSE_STOP_SEC_CONST_32
#include "Crypto_43_HSE_MemMap.h"
[!ENDIF!][!//

#define CRYPTO_43_HSE_START_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

[!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
    [!INDENT "0"!]
    /* Array storing the Crypto primitives in the Crypto Driver Object [!"node:name(.)"!] */
    static const Crypto_43_HSE_PrimitiveType Crypto_43_HSE_aPrimitives_[!"node:name(.)"!][[!"num:i(count(CryptoPrimitiveRef/*))"!]U] =
    {
    [!ENDINDENT!][!//
    [!VAR "CryptoLoopIt" = "num:i(count(CryptoPrimitiveRef/*))"!][!//
    [!LOOP "node:order(CryptoPrimitiveRef/*)"!][!//
        [!INDENT "4"!]
        {
        [!ENDINDENT!][!//
        [!INDENT "8"!]
        [!"node:value(as:ref(node:value(.))/CryptoPrimitiveService)"!],
        [!VAR "AlgoFamily"          = "node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmFamily/*[1])"!][!//
        [!VAR "AlgoMode"            = "node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmMode/*[1])"!][!//
        [!VAR "AlgoSecondaryFamily" = "node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmSecondaryFamily/*[1])"!][!//
        [!IF "$AlgoFamily != 'CRYPTO_ALGOFAM_CUSTOM'"!][!//
            (uint8)[!"$AlgoFamily"!],
        [!ELSE!][!//
            (uint8)[!"num:i(node:value(as:ref(node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmFamilyCustomRef/*[1]))/CryptoPrimitiveAlgorithmFamilyCustomId))"!],
        [!ENDIF!][!//
        [!IF "$AlgoMode != 'CRYPTO_ALGOMODE_CUSTOM'"!][!//
            (uint8)[!"$AlgoMode"!],
        [!ELSE!][!//
            (uint8)[!"num:i(node:value(as:ref(node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmModeCustomRef/*[1]))/CryptoPrimitiveAlgorithmModeCustomId))"!],
        [!ENDIF!][!//
        [!IF "$AlgoSecondaryFamily != 'CRYPTO_ALGOFAM_CUSTOM'"!][!//
            (uint8)[!"$AlgoSecondaryFamily"!],
        [!ELSE!][!//
            (uint8)[!"num:i(node:value(as:ref(node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmSecondaryFamilyCustomRef/*[1]))/CryptoPrimitiveAlgorithmFamilyCustomId))"!],
        [!ENDIF!][!//
        [!IF "node:ref(.)/CryptoPrimitiveSupportContext='true'"!][!//
            (boolean)TRUE
        [!ELSE!][!//
            (boolean)FALSE
        [!ENDIF!][!//
        [!ENDINDENT!]
        [!INDENT "4"!]
        [!IF "$CryptoLoopIt != 1"!][!//
            },
        [!ELSE!][!//
            }
        [!ENDIF!][!//
        [!ENDINDENT!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
    [!ENDLOOP!][!//
    [!INDENT "0"!]
    };

    [!ENDINDENT!][!//
[!ENDLOOP!]
#define CRYPTO_43_HSE_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
[!NOCODE!][!//
[!IF "node:exists(CryptoKeyElements)"!][!//
    /* Create the uint8 array with the information that needs to be stored for all non-persistent Key Elements (buffers + actual sizes) */
    /* Count first the max size of the information about the non-persistent (volatile) key elements. Need to be known when to append commas after each value */
    [!VAR "SizeOfKeyElemVolatileValues"="0"!][!//
    [!VAR "KeyElemVolatileValuesHaveAllBytesZero"="'true'"!][!//
    [!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!LOOP "node:refs(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*)"!][!//
            [!IF "node:value(./UseHseKey)='false' and node:value(./CryptoKeyElementPersist) = 'false' "!][!//
                /* If the key element does not use a HSE key, add the max size of the key element buffer + 4 bytes storing the 32bit value of the actual size */
                [!VAR "SizeOfKeyElemVolatileValues" = "$SizeOfKeyElemVolatileValues + node:value(./CryptoKeyElementSize) + num:i(4)"!][!//
                [!IF "num:i(string-length(node:value(./CryptoKeyElementInitValue)))!=0"!][!//
                    [!VAR "KeyElemVolatileValuesHaveAllBytesZero"="'false'"!][!//
                [!ENDIF!][!//
                    [!ELSEIF "node:value(./UseHseKey)='true' and node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'RamKeyCatalog' "!][!//
                        /* If the key element uses a HSE key and it is a Ram key, add the 4 bytes storing the 32bit value of the actual size */
                [!VAR "SizeOfKeyElemVolatileValues" = "$SizeOfKeyElemVolatileValues + num:i(4)"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//

    [!IF "$SizeOfKeyElemVolatileValues > 0"!][!//
        [!IF "$KeyElemVolatileValuesHaveAllBytesZero = 'true'"!][!//
            [!INDENT "0"!]
            [!CODE!][!//
                #define CRYPTO_43_HSE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_43_HSE_MemMap.h"

                /* Array storing the key element information that is volatile (no need to be persistent across resets) */
                static uint8 Crypto_43_HSE_au8VolatileKeyElemValues[[!"num:i($SizeOfKeyElemVolatileValues)"!]U];

                #define CRYPTO_43_HSE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_43_HSE_MemMap.h"

            [!ENDCODE!][!//
            [!ENDINDENT!][!//
        [!ELSE!][!// IF "$KeyElemVolatileValuesHaveAllBytesZero = 'true'"
            [!INDENT "0"!]
            [!CODE!][!//
                #define CRYPTO_43_HSE_START_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_43_HSE_MemMap.h"

                /* Array storing the key element information that is volatile (no need to be persistent across resets) */
                static uint8 Crypto_43_HSE_au8VolatileKeyElemValues[[!"num:i($SizeOfKeyElemVolatileValues)"!]U] =
                {
            [!ENDCODE!][!//
            [!ENDINDENT!][!//

            [!VAR "CurIdx"="0"!][!//
            [!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
                [!LOOP "node:refs(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*)"!][!//
                [!IF "node:value(./UseHseKey)='false' and node:value(./CryptoKeyElementPersist) = 'false' "!][!//
                    /* If the key element does not use a HSE key, add the 4 bytes storing the 32bit value of the actual size + the max size buffer of the key element */
                    [!INDENT "4"!]
                    [!CODE!][!//
                        /* Offset [!"num:i($CurIdx)"!] - The following 4 bytes store the actual length of the key element [!"node:name(.)"!] */
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),0)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),8)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),16)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),24)),255),2)"!]U,
                    [!ENDCODE!][!//
                    [!VAR "CurIdx" = "$CurIdx + 4"!][!//
                    [!CODE!][!//
                        /* Offset [!"num:i($CurIdx)"!] - The following [!"num:i(node:value(./CryptoKeyElementSize))"!] bytes store the buffer of the key element [!"node:name(.)"!] */
                    [!ENDCODE!][!//
                    [!VAR "Index" = "num:i(-1)"!][!//
                    [!FOR "Index" = "num:i(1)" TO "num:i(string-length(node:value(./CryptoKeyElementInitValue)))" STEP "num:i(2)"!][!//
                        [!VAR "CurIdx" = "$CurIdx + 1"!][!//
                        [!CODE!][!//
                            0x[!"substring(node:value(./CryptoKeyElementInitValue), $Index, 2)"!]U[!IF "num:i($CurIdx) < num:i($SizeOfKeyElemVolatileValues)"!],[!ENDIF!][!CR!]
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!VAR "CountEl" = "$Index"!][!//
                    [!FOR "Index" = "num:i($CountEl+2)" TO "num:i(2 * node:value(./CryptoKeyElementSize))" STEP "num:i(2)"!][!//
                        [!VAR "CurIdx" = "$CurIdx + 1"!][!//
                        [!CODE!][!//
                            0x00U[!IF "num:i($CurIdx) < num:i($SizeOfKeyElemVolatileValues)"!],[!ENDIF!][!CR!]
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!ENDINDENT!][!//
                [!ELSEIF "node:value(./UseHseKey)='true' and node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'RamKeyCatalog'"!][!//
                    /* If the key element uses a HSE key and it is a Ram key, add the 4 bytes storing the 32bit value of the actual size */
                    [!"keyElemActualSize = num:i(string-length(node:value(./CryptoKeyElementInitValue)))"!][!//
                    [!INDENT "4"!]
                    [!CODE!][!//
                        /* Offset [!"num:i($CurIdx)"!] - The following 4 bytes store the actual length of the key element [!"node:name(.)"!] */
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U,
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U,
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U,
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U[!IF "num:i($CurIdx) < num:i($SizeOfKeyElemVolatileValues)"!],[!ENDIF!][!CR!]
                    [!ENDCODE!][!//
                    [!ENDINDENT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//

        [!ENDLOOP!][!//

            [!INDENT "0"!]
            [!CODE!][!//
                };

                #define CRYPTO_43_HSE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_43_HSE_MemMap.h"

            [!ENDCODE!][!//
            [!ENDINDENT!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!// Loop first through all Crypto Driver Objects checking if at least one has the jobs queue enabled
[!VAR "MemMapSectionVarNoInitUnspecifiedNeeded"="'false'"!][!//
[!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
    [!IF "node:value(./CryptoQueueSize) != 0"!][!//
        [!VAR "MemMapSectionVarNoInitUnspecifiedNeeded"="'true'"!][!//
    [!ENDIF!][!//
[!ENDLOOP!]
[!IF "$MemMapSectionVarNoInitUnspecifiedNeeded = 'true'"!][!//
    [!INDENT "0"!][!//
    [!CODE!][!//
    #define CRYPTO_43_HSE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Crypto_43_HSE_MemMap.h"

    [!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
        [!IF "node:value(./CryptoQueueSize) != 0"!][!//
            /* Array storing the queued jobs for the Crypto Driver Object [!"node:name(.)"!] */
            static Crypto_43_HSE_QueueElementType Crypto_43_HSE_aQueuedJobs_[!"node:name(.)"!][[!"node:value(./CryptoQueueSize)"!]U];
        [!ENDIF!][!//
    [!ENDLOOP!]

    #define CRYPTO_43_HSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Crypto_43_HSE_MemMap.h"
    [!ENDCODE!][!//
    [!ENDINDENT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define CRYPTO_43_HSE_START_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"

[!INDENT "0"!][!//
[!VAR "MaxNumPartitions" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    /* Array storing the mapping of the MU instance per partition */
    const Crypto_43_HSE_PartitionToMuMappingType Crypto_43_HSE_aPartitionToMuMapping[CRYPTO_43_HSE_MAX_NUMBER_PARTITIONS_U8] =
    {
[!INDENT "4"!][!//
[!IF "num:i(count(CryptoGeneral/CryptoEcucPartitionRef/*)) > 0"!][!//
    [!VAR "IdxUsedMuInstance" = "-1"!][!//
    [!FOR "x" = "0" TO "num:i($MaxNumPartitions - 1)"!][!//
        [!VAR "PartitionMatched" = "'false'"!][!//
        [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
            [!VAR "UsedMu" = "concat('HSE_IP_', MuInstance)"!][!//
            [!IF "node:exists(./CryptoDriverObjectEcucPartitionRef)"!][!//
                [!VAR "CurCdoPartition" = "node:value(./CryptoDriverObjectEcucPartitionRef)"!][!//
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                        [!IF "$CurCdoPartition = node:value(./OsAppEcucPartitionRef)"!][!//
                            [!IF "node:refvalid(./OsApplicationCoreRef)"!][!//
                                [!IF "$x = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!][!//
                                    [!VAR "PartitionMatched" = "'true'"!][!//
                                    [!VAR "IdxUsedMuInstance" = "$IdxUsedMuInstance + 1"!][!//
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
        [!IF "$PartitionMatched = 'true'"!][!//
            {[!"$UsedMu"!], [!"num:inttohex($IdxUsedMuInstance,2)"!]U}[!IF "$x < ($MaxNumPartitions -1)"!],[!ENDIF!][!CR!][!//
        [!ELSE!][!//
            {0xFFU, 0xFFU}[!IF "$x < ($MaxNumPartitions -1)"!],[!ENDIF!][!CR!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ELSE!][!//
    {HSE_IP_[!"CryptoDriverObjects/CryptoDriverObject/*[1]/MuInstance"!], 0x00U}
[!ENDIF!][!//
[!ENDINDENT!][!//
    };
[!ENDINDENT!][!//

#define CRYPTO_43_HSE_STOP_SEC_CONST_8
#include "Crypto_43_HSE_MemMap.h"


#define CRYPTO_43_HSE_START_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

[!INDENT "0"!][!//
/* Array of structures storing the information of the Crypto Driver Objects mapped on partitions */
const Crypto_43_HSE_PartitionToCdoMappingType Crypto_43_HSE_aPartitionToCdoMapping[CRYPTO_43_HSE_MAX_NUMBER_PARTITIONS_U8] =
{
[!IF "num:i(count(CryptoGeneral/CryptoEcucPartitionRef/*)) > 0"!][!//
    [!VAR "MaxNumPartitions" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!FOR "x" = "0" TO "num:i($MaxNumPartitions - 1)"!][!//
        [!VAR "NumMappedCdos" = "0"!][!//
        [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
            [!IF "node:exists(./CryptoDriverObjectEcucPartitionRef)"!][!//
                [!VAR "CurCdoPartition" = "node:value(./CryptoDriverObjectEcucPartitionRef)"!][!//
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                        [!IF "$CurCdoPartition = node:value(./OsAppEcucPartitionRef)"!][!//
                            [!IF "node:refvalid(./OsApplicationCoreRef)"!][!//
                                [!IF "$x = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!][!//
                                    [!VAR "NumMappedCdos" = "$NumMappedCdos + 1"!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!INDENT "4"!][!//
            /* Structure storing the information of the Crypto Driver Objects mapped on partition [!"as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*[num:i($x) + 1]/@name"!] */
            {
        [!INDENT "8"!][!//
        [!IF "$NumMappedCdos > 0"!][!//
            /* Number of Crypto Driver Objects */
            [!"num:i($NumMappedCdos)"!]U,
            /* Reference to array storing the indexes of the Crypto Driver Objects */
            Crypto_43_HSE_au8CDOs_[!"as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*[num:i($x) + 1]/@name"!]
        [!ELSE!][!//
            /* Number of Crypto Driver Objects */
            0U,
            /* Reference to array storing the indexes of the Crypto Driver Objects */
            NULL_PTR
        [!ENDIF!][!//
        [!ENDINDENT!][!//
            }[!IF "$x < ($MaxNumPartitions -1)"!],[!ENDIF!][!CR!][!//
        [!ENDINDENT!][!//
    [!ENDFOR!][!//
[!ELSE!][!//
    [!INDENT "4"!][!//
    /* Structure storing the information of the Crypto Driver Objects */
    {
    [!INDENT "8"!][!//
        /* Number of Crypto Driver Objects */
        [!"num:i(count(CryptoDriverObjects/CryptoDriverObject/*))"!]U,
        /* Reference to array storing the indexes of the Crypto Driver Objects */
        Crypto_43_HSE_au8CDOs
    [!ENDINDENT!][!//
    }
    [!ENDINDENT!][!//
[!ENDIF!][!//
};
[!ENDINDENT!][!//

[!INDENT "0"!]
    /* Array of structures storing the information about the Crypto Driver Objects */
    const Crypto_43_HSE_ObjectType Crypto_43_HSE_aDriverObjectList[CRYPTO_43_HSE_NUMBER_OF_DRIVER_OBJECTS_U32] =
    {
[!ENDINDENT!][!//
[!VAR "CryptoLoopIt" = "count(CryptoDriverObjects/CryptoDriverObject/*)"!][!//
[!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
    [!VAR "CurCdoName" = "node:name(.)"!][!//
    [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
    [!INDENT "4"!]
    /* Structure storing the information about Crypto Driver Object [!"node:name(.)"!] */
    {
    [!ENDINDENT!]
    [!INDENT "8"!]
        [!IF "node:exists(./CryptoDriverObjectEcucPartitionRef)"!][!//
            [!VAR "PartitionMatched" = "'false'"!][!//
            [!VAR "CurCdoPartition" = "node:value(./CryptoDriverObjectEcucPartitionRef)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                    [!IF "$CurCdoPartition = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!IF "node:refvalid(./OsApplicationCoreRef)"!][!//
                            [!VAR "PartitionMatched" = "'true'"!][!//
                            /* Id of the partition that is valid for the Crypto Driver Object */
                            [!"node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]U,
                            [!BREAK!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!IF "$PartitionMatched = 'false'"!][!//
                [!ERROR!][!//
                    The referenced ECUC partition '[!"$CurCdoPartition"!]' in the CryptoEcucPartitionRef list of the Crypto Driver Object '[!"$CurCdoName"!]' is not associated with any OsApplication or the OsApplication does not have a valid OsApplicationCoreRef!
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        /* Reference to the jobs queue */
        [!IF "node:value(./CryptoQueueSize)!= 0"!][!//
            Crypto_43_HSE_aQueuedJobs_[!"node:name(.)"!],
        [!ELSE!][!//
            NULL_PTR,
        [!ENDIF!][!//
        /* Jobs queue size */
        [!"node:value(./CryptoQueueSize)"!]U,
        /* Reference to the Crypto primitives list */
        Crypto_43_HSE_aPrimitives_[!"node:name(.)"!],
        /* Number of crypto primitives */
        [!"num:i(count(CryptoPrimitiveRef/*))"!]U
        [!INDENT "4"!]
            [!IF "$CryptoLoopIt != 0"!][!//
                },
            [!ELSE!][!//
                }
            [!ENDIF!][!//
        [!ENDINDENT!][!//
    [!ENDINDENT!][!//
[!ENDLOOP!][!//
[!INDENT "0"!]
};
[!ENDINDENT!][!//

[!IF "node:exists(CryptoKeys)"!][!//
    [!INDENT "0"!]
        /* Array of structures storing the information about the Crypto Keys */
        const Crypto_43_HSE_KeyType Crypto_43_HSE_aKeyList[CRYPTO_43_HSE_NUMBER_OF_KEYS_U32] =
        {
    [!ENDINDENT!][!//
    [!VAR "CryptoLoopIt" = "count(CryptoKeys/CryptoKey/*)"!][!//
    [!LOOP "node:order(CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!VAR "CryptoKeyName"="node:name(.)"!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
        [!INDENT "4"!]
        {
        [!ENDINDENT!]
        [!INDENT "8"!]
            /* Number of key elements in the key [!"node:name(.)"!] */
            [!"num:i(count(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*))"!]U,
            /* Reference to the list of key elements in the key [!"node:name(.)"!] */
            Crypto_43_HSE_au32KeyElementList_[!"node:name(.)"!],
            /* Pointer to location storing the Key Status value */
            &Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!][0]
        [!ENDINDENT!][!//
        [!INDENT "4"!]
        [!IF "$CryptoLoopIt != 0"!][!//
            },
        [!ELSE!][!//
            }
        [!ENDIF!][!//
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
[!INDENT "0"!]
};
[!ENDINDENT!][!//
[!ENDIF!][!//

[!IF "node:exists(CryptoKeyElements)"!][!//
    [!INDENT "0"!]
        /* Array of structures storing the information about the Crypto Key Elements */
        const Crypto_43_HSE_KeyElementType Crypto_43_HSE_aKeyElementList[CRYPTO_43_HSE_NUMBER_OF_KEY_ELEMENTS_U32] =
        {
    [!ENDINDENT!][!//
    [!VAR "CryptoLoopIt" = "0"!][!//
    [!VAR "CurIdxInVolatileArray"="0"!][!//
    [!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!LOOP "node:refs(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*)"!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt + 1"!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
    [!VAR "CryptoKeyName"="node:name(.)"!][!//
    [!VAR "CurIdxInPersistentArray"="1"!][!//
    [!LOOP "node:refs(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*)"!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
        [!INDENT "4"!]
        /* Structure containing information for Key Element [!"node:name(.)"!] */
        {
        [!ENDINDENT!]
        [!INDENT "8"!]
            /* KeyElementId */
            [!"node:value(./CryptoKeyElementId)"!]U,
            /* Allow partial access */
            [!IF "node:value(./CryptoKeyElementAllowPartialAccess)"!][!//
                (boolean)TRUE,
            [!ELSE!][!//
                (boolean)FALSE,
            [!ENDIF!][!//
            /* Key element format */
            [!"text:replaceAll(node:value(./CryptoKeyElementFormat), 'CRYPTO_', concat('CRYPTO', '_43_HSE', '_'))"!],
            /* Key element persistent */
            [!IF "node:value(./UseHseKey)='true'"!][!//
                [!IF "node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'NvmKeyCatalog'"!][!//
                    (boolean)TRUE,
                [!ELSE!][!//
                    (boolean)FALSE,
                [!ENDIF!][!//
            [!ELSE!][!//
                [!IF "node:value(./CryptoKeyElementPersist)"!][!//
                    (boolean)TRUE,
                [!ELSE!][!//
                    (boolean)FALSE,
                [!ENDIF!][!//
            [!ENDIF!][!//
            /* Read access type */
            [!"text:replaceAll(node:value(./CryptoKeyElementReadAccess), 'CRYPTO_', concat('CRYPTO', '_43_HSE', '_'))"!],
            /* Key element max size */
            [!"node:value(./CryptoKeyElementSize)"!]U,
            /* Write access type */
            [!"text:replaceAll(node:value(./CryptoKeyElementWriteAccess), 'CRYPTO_', concat('CRYPTO', '_43_HSE', '_'))"!],
            [!IF "node:value(./UseHseKey)='false'"!][!//
                [!IF "node:value(./CryptoKeyElementPersist) = 'true' "!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!][[!"num:i($CurIdxInPersistentArray)"!]U],
                    [!VAR "CurIdxInPersistentArray" = "$CurIdxInPersistentArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    &Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!][[!"num:i($CurIdxInPersistentArray)"!]U],
                    [!VAR "CurIdxInPersistentArray" = "$CurIdxInPersistentArray + node:value(./CryptoKeyElementSize)"!][!//
                [!ELSE!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_43_HSE_au8VolatileKeyElemValues[[!"num:i($CurIdxInVolatileArray)"!]U],
                    [!VAR "CurIdxInVolatileArray" = "$CurIdxInVolatileArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    &Crypto_43_HSE_au8VolatileKeyElemValues[[!"num:i($CurIdxInVolatileArray)"!]U],
                    [!VAR "CurIdxInVolatileArray" = "$CurIdxInVolatileArray + node:value(./CryptoKeyElementSize)"!][!//
                [!ENDIF!][!//
            [!ELSE!][!//
                [!IF "(node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'NvmKeyCatalog') "!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!][[!"num:i($CurIdxInPersistentArray)"!]U],
                    [!VAR "CurIdxInPersistentArray" = "$CurIdxInPersistentArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    NULL_PTR,
                [!ELSEIF "(node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'RamKeyCatalog') "!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_43_HSE_au8VolatileKeyElemValues[[!"num:i($CurIdxInVolatileArray)"!]U],
                    [!VAR "CurIdxInVolatileArray" = "$CurIdxInVolatileArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    NULL_PTR,
                [!ENDIF!][!//
            [!ENDIF!][!//
            /* HSE key counter */
            [!IF "node:value(./UseHseKey) = 'true'"!][!//
                [!"node:value(./HseKeyCounter)"!]U,
            [!ELSE!][!//
                0U,
            [!ENDIF!][!//
            [!IF "ecu:get(concat('Crypto.HseSptEccKeyImport.', string(node:fallback(./../../../CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON'"!][!//
                /* ECC curve id */
                [!IF "node:value(./UseHseKey) = 'true' "!][!//
                    HSE_EC_[!"substring(node:value(./HseEccCurveId),5)"!],
                [!ELSE!][!//
                    0U,
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "ecu:get(concat('Crypto.HseSptSymKeyImport.', string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON' or
                  ecu:get(concat('Crypto.HseSptRsaKeyImport.', string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON' or
                  ecu:get(concat('Crypto.HseSptEccKeyImport.', string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON' or
                  ecu:get(concat('Crypto.HseSptKeyDerive.',    string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON'"!][!//
                /* Flags of the HSE key */
                [!IF "node:value(./UseHseKey) = 'true' "!][!//
                    ([!LOOP "HseKeyFlags/*"!]HSE_KF_[!"node:value(HseKeyFlag)"!] | [!ENDLOOP!]0U),
                [!ELSE!][!//
                    0U,
                [!ENDIF!][!//
                /* HSE key SMR flags */
                [!IF "node:value(./UseHseKey) = 'true' "!][!//
                    [!"num:inttohex(node:value(./HseSMRFlags),8)"!]U,
                [!ELSE!][!//
                    0U,
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "(ecu:get(concat('Crypto.HseSptKeyImport.',         string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON' or
                   ecu:get(concat('Crypto.HseSptKeyExport.',         string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON' or
                   ecu:get(concat('Crypto.HseSptKeyDerive.',         string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON' or
                   ecu:get(concat('Crypto.HseSptKeyGenerate.',       string(node:fallback(./../../../CryptoGeneral/HseFwType,'CUSTOM')))) = 'STD_ON')"!][!//
                /* HSE key type */
                [!IF "node:value(./UseHseKey) = 'true' "!][!//
                    (uint8)HSE_KEY_TYPE_[!"node:value(node:ref(HseKeyCatalogGroupRef)/KeyType)"!],
                [!ELSE!][!//
                    0U,
                [!ENDIF!][!//
            [!ELSE!][!//
                0U,
            [!ENDIF!][!//
            /* Identifier of the HSE key in the key catalogs */
            [!IF "node:value(./UseHseKey) = 'true'"!][!//
                [!IF "'true' "!][!//
                    [!"num:inttohex(num:i(node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'NvmKeyCatalog')    * (bit:shl(1,  16) + bit:shl(num:i(node:ref(HseKeyCatalogGroupRef)/@index), 8) + HseKeySlot)
                                  + num:i(node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'RamKeyCatalog')    * (bit:shl(2,  16) + bit:shl(num:i(node:ref(HseKeyCatalogGroupRef)/@index), 8) + HseKeySlot)
                    , 8)"!]U
                [!ELSE!][!//
                [!ENDIF!][!//
            [!ELSE!][!//
                (uint32)HSE_INVALID_KEY_HANDLE
            [!ENDIF!][!//
        [!ENDINDENT!][!//
        [!INDENT "4"!]
        [!IF "$CryptoLoopIt != 0"!][!//
            },
        [!ELSE!][!//
            }
        [!ENDIF!][!//
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!INDENT "0"!]
};
[!ENDINDENT!][!//
[!ENDIF!][!//

[!//
[!//
[!IF "ecu:get(concat('Crypto.HseSptFormatKeyCatalogs.', string(node:fallback(CryptoGeneral/HseFwType,'STANDARD')))) = 'STD_ON'"!][!//
/* Table containing NVM key catalog entries */
const hseKeyGroupCfgEntry_t aHseNvmKeyCatalog[] =
{
[!NOCODE!][!//
    [!LOOP "NvmKeyCatalog/*"!][!//
        [!VAR "IdxItem"="0"!][!//
        [!VAR "NumOfListItems"= "num:i(count(MuMask/*))-1"!][!//
        [!VAR "StrMuMask"="''"!][!//
        [!LOOP "MuMask/*"!][!//
            [!VAR "StrMuValue"="concat('HSE_MU', substring-after(./MU,'MU_'), '_MASK')"!][!//
            [!IF "$IdxItem<$NumOfListItems"!][!//
                [!VAR "StrMuMask"="concat($StrMuMask, $StrMuValue, ' | ')"!][!//
            [!ELSE!][!//
                [!VAR "StrMuMask"="concat($StrMuMask, $StrMuValue)"!][!//
            [!ENDIF!][!//
            [!VAR "IdxItem"= "$IdxItem+1"!][!//
        [!ENDLOOP!][!//
        [!CODE!][!WS"4"!]/* [!"node:name(.)"!] */[!ENDCODE!][!CR!][!//
        [!CODE!][!WS"4"!]{([!"$StrMuMask"!]), HSE_KEY_[!"node:value(KeyOwner)"!], HSE_KEY_TYPE_[!"node:value(KeyType)"!], [!"num:i(node:value(NumOfKeySlots))"!]U, [!"num:i(node:value(MaxKeyBitLen))"!]U, {0U, 0U}},[!ENDCODE!][!CR!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
    /* Marker to end the key catalog */
    {0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};

/* Table containing RAM key catalog entries */
const hseKeyGroupCfgEntry_t aHseRamKeyCatalog[] =
{
[!NOCODE!][!//
    [!LOOP "RamKeyCatalog/*"!][!//
        [!VAR "IdxItem"="0"!][!//
        [!VAR "NumOfListItems"= "num:i(count(MuMask/*))-1"!][!//
        [!VAR "StrMuMask"="''"!][!//
        [!LOOP "MuMask/*"!][!//
            [!VAR "StrMuValue"="concat('HSE_MU', substring-after(./MU,'MU_'), '_MASK')"!][!//
            [!IF "$IdxItem<$NumOfListItems"!][!//
                [!VAR "StrMuMask"="concat($StrMuMask, $StrMuValue, ' | ')"!][!//
            [!ELSE!][!//
                [!VAR "StrMuMask"="concat($StrMuMask, $StrMuValue)"!][!//
            [!ENDIF!][!//
            [!VAR "IdxItem"= "$IdxItem+1"!][!//
        [!ENDLOOP!][!//
        [!CODE!][!WS"4"!]/* [!"node:name(.)"!] */[!ENDCODE!][!CR!][!//
        [!CODE!][!WS"4"!]{([!"$StrMuMask"!]), HSE_KEY_[!"node:value(KeyOwner)"!], HSE_KEY_TYPE_[!"node:value(KeyType)"!], [!"num:i(node:value(NumOfKeySlots))"!]U, [!"num:i(node:value(MaxKeyBitLen))"!]U, {0U, 0U}},[!ENDCODE!][!CR!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
    /* Marker to end the key catalog */
    {0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};

[!ENDIF!][!//
#define CRYPTO_43_HSE_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
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
            uint8 Crypto_43_HSE_RamBuffer[!"text:toupper($CryptoKeyId)"!][CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]] = {0};
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
    Crypto_43_HSE_NvBlockType Crypto_43_HSE_aNvBlockDescriptor[CRYPTO_43_HSE_NUMBER_OF_KEYS_U32] = 
    {
    [!ENDINDENT!]
    [!ENDCODE!]
    [!VAR "CryptoLoopIt" = "count(CryptoKeys/CryptoKey/*)"!][!//
    [!LOOP "node:order(CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
        [!IF "node:exists(CryptoKeyNvBlockRef)"!][!//
            [!VAR "CryptoKeyName"="node:name(.)"!][!//
            [!VAR "CryptoNvBlockId" = "num:i(node:value(node:ref(node:ref(node:value(./CryptoKeyNvBlockRef))/CryptoNvBlockDescriptorRef)/NvMNvramBlockIdentifier))"!][!//
            [!IF "node:exists(node:ref(./CryptoKeyNvBlockRef)/CryptoNvBlockFailedRetries)"!][!//
                [!VAR "CryptoNvBlockFailedRetries" = "num:i(node:value(node:ref(./CryptoKeyNvBlockRef)/CryptoNvBlockFailedRetries))"!][!//
            [!ELSE!][!//
                [!VAR "CryptoNvBlockFailedRetries" = "num:i(0)"!][!//
            [!ENDIF!][!//
            [!VAR "CryptoNvBlockProcessing" = "node:value(node:ref(./CryptoKeyNvBlockRef)/CryptoNvBlockProcessing)"!][!//
            [!CODE!][!//
            [!INDENT "4"!][!//
            {
            [!ENDINDENT!][!//
                [!INDENT "8"!][!//
                [!"$CryptoNvBlockId"!]U,
                [!"$CryptoNvBlockFailedRetries"!]U,
                [!"$CryptoNvBlockProcessing"!],
                0U,
                CRYPTO_KEYSTATUS_INVALID,
                (uint32)CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]
                [!ENDINDENT!][!//
            [!ENDCODE!][!//
        [!ELSE!]
            [!CODE!][!//
            [!INDENT "4"!][!//
            {
            [!ENDINDENT!][!//
                [!INDENT "8"!][!//
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00
                [!ENDINDENT!][!//
            [!ENDCODE!][!//
        [!ENDIF!][!//
        [!INDENT "4"!][!//
        [!CODE!][!//
        [!IF "$CryptoLoopIt != 0"!][!//
            },
        [!ELSE!][!//
            }
        [!ENDIF!][!//
        [!ENDCODE!][!//
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
    [!CODE!][!//
    [!INDENT "0"!][!//
    };
    [!ENDINDENT!][!//
    [!ENDCODE!][!//
[!ENDNOCODE!][!//

#define CRYPTO_43_HSE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

[!ENDIF!][!//

#define CRYPTO_43_HSE_START_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"

[!NOCODE!][!//
    [!LOOP "node:order(./CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
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
        [!VAR "CryptoKeyName"="node:name(.)"!][!//
        /* Create the initializer for the array with the information that needs to be stored in Nvram for all persistent Key Elements (buffers + actual sizes) */
        [!CODE!][!//
        [!INDENT "0"!]
            /* Array storing persistent information for Key [!"$CryptoKeyName"!] */
            uint8 Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!][CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]] =[!CR!]{[!CR!][!//
        [!ENDINDENT!][!//
        [!ENDCODE!][!//
        /* Information about key validity is stored at index 0*/
        [!INDENT "4"!]
        [!CODE!][!//
        /* Offset 0 - Key Valid information - as per SWS_CRYPTO_00251 - always set default as CRYPTO_KEYSTATUS_VALID */
        CRYPTO_KEYSTATUS_VALID[!IF "num:i($SizeOfKeyElemPersistValuesBlob) > 1"!],[!ENDIF!][!CR!][!//
        [!ENDCODE!][!//
        [!ENDINDENT!][!//
        [!VAR "CurIdx"="1"!][!//
        [!IF "num:i($SizeOfKeyElemPersistValuesBlob) > 1"!][!//
            [!LOOP "node:refs(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*)"!][!//
                [!IF "node:value(./UseHseKey)='false' and node:value(./CryptoKeyElementPersist) = 'true' "!][!//
                    /* If the key element does not use a HSE key, add the 4 bytes storing the 32bit value of the actual size + the max size buffer of the key element */
                    [!INDENT "4"!]
                    [!CODE!][!//
                        /* Offset [!"num:i($CurIdx)"!] - Length of [!"node:name(.)"!] */
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),0)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),8)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),16)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),24)),255),2)"!]U,
                    [!ENDCODE!][!//
                    [!VAR "CurIdx" = "$CurIdx + 4"!][!//
                    [!CODE!][!//
                        /* Offset [!"num:i($CurIdx)"!] - Buffer of [!"node:name(.)"!] */
                    [!ENDCODE!][!//
                    [!VAR "Index" = "num:i(-1)"!][!//
                    [!FOR "Index" = "num:i(1)" TO "num:i(string-length(node:value(./CryptoKeyElementInitValue)))" STEP "num:i(2)"!][!//
                        [!VAR "CurIdx" = "$CurIdx + 1"!][!//
                        [!CODE!][!//
                            0x[!"substring(node:value(./CryptoKeyElementInitValue), $Index, 2)"!]U[!IF "num:i($CurIdx) < num:i($SizeOfKeyElemPersistValuesBlob)"!],[!ENDIF!][!CR!]
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!VAR "CountEl" = "$Index"!][!//
                    [!FOR "Index" = "num:i($CountEl+2)" TO "num:i(2 * node:value(./CryptoKeyElementSize))" STEP "num:i(2)"!][!//
                        [!VAR "CurIdx" = "$CurIdx + 1"!][!//
                        [!CODE!][!//
                            0x00U[!IF "num:i($CurIdx) < num:i($SizeOfKeyElemPersistValuesBlob)"!],[!ENDIF!][!CR!][!//
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!ENDINDENT!][!//
                [!ELSEIF "node:value(./UseHseKey)='true' and node:name(concat(noderef:ref(HseKeyCatalogGroupRef), '/../.')) = 'NvmKeyCatalog' "!][!//
                    [!INDENT "4"!]
                    /* If the key element uses a HSE key and it is a Nvm key, add the 4 bytes storing the 32bit value of the actual size */
                    [!"keyElemActualSize = num:i(string-length(node:value(./CryptoKeyElementInitValue)))"!][!//
                    [!CODE!][!//
                        /* Offset [!"num:i($CurIdx)"!] - Length of [!"node:name(.)"!] */
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U,
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U,
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U,
                        [!VAR "CurIdx" = "$CurIdx + 1"!]0x00U[!IF "num:i($CurIdx) < num:i($SizeOfKeyElemPersistValuesBlob)"!],[!ENDIF!][!CR!]
                    [!ENDCODE!][!//
                    [!ENDINDENT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
        [!CODE!]};
        [!CR!][!//
        [!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
#define CRYPTO_43_HSE_STOP_SEC_VAR_INIT_8
#include "Crypto_43_HSE_MemMap.h"
[!ENDIF!][!//

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
[!IF "node:exists(CryptoNvStorage) and node:exists(CryptoKeys)"!][!//
#define CRYPTO_43_HSE_START_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"

static Std_ReturnType Crypto_43_HSE_NvBlock_Init(uint32 u32CryptoKeyId, NvM_InitBlockRequestType initBlockRequest)
{
    Std_ReturnType RetVal;

    switch (initBlockRequest)
    {
        case (NvM_InitBlockRequestType) NVM_INIT_READ_BLOCK:
        case (NvM_InitBlockRequestType) NVM_INIT_RESTORE_BLOCK_DEFAULTS:
        case (NvM_InitBlockRequestType) NVM_INIT_READ_ALL_BLOCK:
        case (NvM_InitBlockRequestType) NVM_INIT_FIRST_INIT_ALL:
            /* Fall-through - no special case is specified for Crypto Init callback */
            /* Only need to initialize the NVRAM block, so no call to NvM_WriteBlock() is needed */
            RetVal = NvM_SetRamBlockStatus(Crypto_43_HSE_aNvBlockDescriptor[u32CryptoKeyId].NvBlockId, TRUE);
            break;

        default:
            /* Invalid argument. Return E_NOT_OK */
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    return RetVal;
}

static Std_ReturnType Crypto_43_HSE_NvBlock_Callback(uint32 u32CryptoKeyId, NvM_BlockRequestType BlockRequest, NvM_RequestResultType JobResult)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    switch (BlockRequest)
    {
        case NVM_WRITE_BLOCK:
            if ((NvM_RequestResultType)NVM_REQ_OK != JobResult)
            {
                /* SWS_Crypto_00244: If a call to an NVM service (NvM_SetRamBlockStatus() or NvM_WriteBlock()) returns with E_NOT_OK, 
                or when the callback function Crypto_<vi>_<ai>_NvBlock_Callback_<NvBlock> (see [SWS_Crypto_91026]) indicates with Nvm_RequestResultType 
                that the block write operation has failed, the runtime error CRYPTO_E_RE_NVM_ACCESS_FAILED shall be reported to the DET. */
                if ((Crypto_43_HSE_aNvBlockDescriptor[u32CryptoKeyId].NvBlockFailedRetries > 0U) \
                && (Crypto_43_HSE_aNvBlockDescriptor[u32CryptoKeyId].NvBlockFailedRetries > Crypto_43_HSE_aNvBlockDescriptor[u32CryptoKeyId].NumNvBlockFailedRetries))
                {
                    Crypto_43_HSE_aNvBlockDescriptor[u32CryptoKeyId].NumNvBlockFailedRetries++;
                }

                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Restore previous Key status value, which is changed from CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS after NvRAM is written */
                *Crypto_43_HSE_aKeyList[u32CryptoKeyId].KeyStatus = (uint8)Crypto_43_HSE_aNvBlockDescriptor[u32CryptoKeyId].CryptoKeyStatusCopy;
            }
            break;

        case NVM_READ_BLOCK:
            if ((NvM_RequestResultType)NVM_REQ_OK != JobResult)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;

                /* SWS_Crypto_00249: On initialization, when reading an NvBlock for keys and the block is available but corrupted 
                (driver internal data consistency check failed), all related keys shall be set to invalid. 
                The length value of all associated key elements, where CryptoKeyElementPersist is set to TRUE, 
                shall be set to 0 even if CryptoKeyElementInitValue is set for this key. */
                Crypto_43_HSE_Util_Memset((uint8*)Crypto_43_HSE_aKeyList[u32CryptoKeyId].KeyStatus, (uint8)0U, (uint32)Crypto_43_HSE_aNvBlockDescriptor[u32CryptoKeyId].SizeOfNvBlock);
            }
            break;

        default:
            /* Invalid command for Crypto driver. Return E_NOT_OK */
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    return RetVal;
}

#define CRYPTO_43_HSE_STOP_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"

[!ENDIF!][!//
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
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
        [!VAR "CryptoKeyId" = "num:i(node:value(./CryptoKeyId))"!][!//
        [!VAR "CryptoKeyName"="node:name(.)"!][!//
        [!CODE!][!//
        /* Function Crypto_43_HSE_NvBlock_Init_[!"$CryptoNvBlockName"!] */
        /* SWS_Crypto_91023: This function will be called by NVM. The crypto driver has the task to initialize the NVRAM block. */
        Std_ReturnType Crypto_43_HSE_NvBlock_Init_[!"$CryptoNvBlockName"!](NvM_InitBlockRequestType initBlockRequest)
        {
            [!INDENT "4"!]
            Std_ReturnType RetVal;

            RetVal = Crypto_43_HSE_NvBlock_Init([!"$CryptoKeyId"!]U, initBlockRequest);

            return RetVal;
            [!ENDINDENT!][!//
        }

        /* Function Crypto_43_HSE_NvBlock_ReadFrom_[!"$CryptoNvBlockName"!] */
        /* SWS_Crypto_91024: This function is called by NVM to let the crypto driver copy the key data from the mirror of the NVM ram block to an internal RAM buffer of the crypto driver. */
        Std_ReturnType Crypto_43_HSE_NvBlock_ReadFrom_[!"$CryptoNvBlockName"!](const void* NvmBuffer)
        {
            [!INDENT "4"!]
            Std_ReturnType RetVal = (Std_ReturnType)E_OK;

            if (NULL_PTR != NvmBuffer)
            {
                [!ENDINDENT!][!//
                [!INDENT "8"!]
                Crypto_43_HSE_Util_MemCpy8((uint8*)&Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!], (const uint8*)NvmBuffer, CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]);
                [!ENDINDENT!][!//
                [!INDENT "4"!]
            }
            else
            {
                [!ENDINDENT!][!//
                [!INDENT "8"!]
                RetVal = (Std_ReturnType)E_NOT_OK;
                [!ENDINDENT!][!//
                [!INDENT "4"!]
            }

            return RetVal;
            [!ENDINDENT!][!//
        }

        /* Function Crypto_43_HSE_NvBlock_WriteTo_[!"$CryptoNvBlockName"!] */
        /* SWS_Crypto_91025: This function is called by NVM to let the crypto driver copy the internal key element data to a mirror of the NVM ram block shortly before the data are written to NVM. */
        Std_ReturnType Crypto_43_HSE_NvBlock_WriteTo_[!"$CryptoNvBlockName"!](void* NvmBuffer)
        {
            [!INDENT "4"!]
            Std_ReturnType RetVal = (Std_ReturnType)E_OK;

            if (NULL_PTR != NvmBuffer)
            {
                [!ENDINDENT!][!//
                [!INDENT "8"!]
                Crypto_43_HSE_Util_MemCpy8((uint8*)NvmBuffer, (const uint8*)&Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!], CRYPTO_43_HSE_SIZEOF_NVRAM_BLOCK_[!"text:toupper($CryptoKeyName)"!]);
                /* Copy the Key Status separately from Crypto_43_HSE_aNvBlockDescriptor[[!"$CryptoKeyId"!]U].CryptoKeyStatusCopy, 
                because the one in Crypto_43_HSE_au8NvramBlock_[!"$CryptoKeyName"!] is now set to CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS 
                until the NVRAM write operation finishes. */
                Crypto_43_HSE_Util_MemCpy8((uint8*)NvmBuffer, (const uint8*)&Crypto_43_HSE_aNvBlockDescriptor[[!"$CryptoKeyId"!]U].CryptoKeyStatusCopy, 1U);
                [!ENDINDENT!][!//
                [!INDENT "4"!]
            }
            else
            {
                [!ENDINDENT!][!//
                [!INDENT "8"!]
                RetVal = (Std_ReturnType)E_NOT_OK;
                [!ENDINDENT!][!//
                [!INDENT "4"!]
            }

            return RetVal;
            [!ENDINDENT!][!//
        }

        /* Function Crypto_43_HSE_NvBlock_Callback_[!"$CryptoNvBlockName"!] */
        /* SWS_Crypto_91026: This function is called from NVM to notify the crypto driver that an asynchronous single block request has been finished. */
        Std_ReturnType Crypto_43_HSE_NvBlock_Callback_[!"$CryptoNvBlockName"!](NvM_BlockRequestType BlockRequest, NvM_RequestResultType JobResult)
        {
            [!INDENT "4"!]
            Std_ReturnType RetVal;

            RetVal = Crypto_43_HSE_NvBlock_Callback([!"$CryptoKeyId"!]U, BlockRequest, JobResult);

            return RetVal;
            [!ENDINDENT!][!//
        }
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

