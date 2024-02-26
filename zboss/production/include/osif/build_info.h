/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */
#ifndef ZBOSS_BUILD_INFO_H__
#define ZBOSS_BUILD_INFO_H__

/**
 * This is an autogenerated file.
 * Please use release scripts to update it's contents.
 *
 * Repositories:
 * platform_ncs       ec3e18dc460bd7866ee4057e0831a5be3de72049 https://projecttools.nordicsemi.no/bitbucket/scm/ZOI/platform_ncs.git
 * zboss-stack-src    be0eb18dfc322e0c519098cd652a8d7f7b76838c https://projecttools.nordicsemi.no/bitbucket/scm/zoi/zboss_stable
 * zboss-stack-doc    31a9182d4fc43bfedbcc1bb1dab2aec4e07288ad https://projecttools.nordicsemi.no/bitbucket/scm/zoi/zboss_doc
 * nrf                f660b2ae50e0484c0ea26a6edef80f747488d483 https://github.com/nrfconnect/sdk-nrf
 * zephyr             17d9e0f7bdfda0a4c88e6ba880d2b0a7314c6cf7 https://github.com/nrfconnect/sdk-zephyr
 * hostap             8022ef951c77f3bc08726d1c2b44e792b3091a35 https://github.com/nrfconnect/sdk-hostap
 * wfa-qt-control-app b3cea7b770cf8270cf25831cf3c9db063234e603 https://github.com/nrfconnect/sdk-wi-fiquicktrack-controlappc
 * mcuboot            55a0f64dbdbead3b8a9120af6e23f20e3521a37a https://github.com/nrfconnect/sdk-mcuboot
 * qcbor              751d36583a9ce1a640900c57e13c9b6b8f3a2ba2 https://github.com/laurencelundblade/QCBOR.git
 * mbedtls            31eb94eca87e4b65e5b1ce662126de2dbfd4f314 https://github.com/nrfconnect/sdk-mbedtls
 * nrfxlib            b02a54c3ae1421744d5fcd6b9519240f63192e8d https://github.com/nrfconnect/sdk-nrfxlib
 * trusted-firmware-m 2a6f6f084a2d2a6fbcd922a368ba2debd66b7697 https://github.com/nrfconnect/sdk-trusted-firmware-m
 * psa-arch-tests     94a349db22cd0e44136c281724ffc71b6e7391c3 https://github.com/nrfconnect/sdk-psa-arch-tests
 * matter             e3dd453b9bd82ee33b258cd2be94abeca9ba62c0 https://github.com/nrfconnect/sdk-connectedhomeip
 * cjson              c6af068b7f05207b28d68880740e4b9ec1e4b50a https://github.com/nrfconnect/sdk-cjson
 * azure-sdk-for-c    308c171cb4b5eed266649012a68406487ec81fb2 https://github.com/nrfconnect/azure-sdk-for-c
 * cirrus             3873a08377d93a479105a75ac390d3bbcd31d690 https://github.com/nrfconnect/sdk-mcu-drivers
 * openthread         3aa3cbc341c18a221ec77fe073bd3f665990f9b4 https://github.com/nrfconnect/sdk-openthread
 * cmock              f65066f15d8248e6dcb778efb8739904a4512087 https://github.com/ThrowTheSwitch/cmock
 * memfault-firmware-sdk 3d51c80bc58933671403eca7c5250a9b03294c5e https://github.com/memfault/memfault-firmware-sdk
 * bsim               384a091445c57b44ac8cbd18ebd245b47c71db94 https://github.com/BabbleSim/bsim_west
 * canopennode        dec12fa3f0d790cafa8414a4c2930ea71ab72ffd https://github.com/zephyrproject-rtos/canopennode
 * chre               3b32c76efee705af146124fb4190f71be5a4e36e https://github.com/zephyrproject-rtos/chre
 * lz4                8e303c264fc21c2116dc612658003a22e933124d https://github.com/zephyrproject-rtos/lz4
 * nanopb             42fa8b211e946b90b9d968523fce7b1cfe27617e https://github.com/zephyrproject-rtos/nanopb
 * tf-m-tests         08a3158f0623a4205608a52d880b17ae394e31d2 https://github.com/zephyrproject-rtos/tf-m-tests
 * zscilib            34a94b0995683822fa3626dcd5d838301c94c350 https://github.com/zephyrproject-rtos/zscilib
 * cmsis              4b96cbb174678dcd3ca86e11e1f24bc5f8726da0 https://github.com/zephyrproject-rtos/cmsis
 * cmsis-dsp          ff7b5fd1ea5f094665c090c343ec44e74dc0b193 https://github.com/zephyrproject-rtos/cmsis-dsp
 * cmsis-nn           0c8669d81381ccf3b1a01d699f3b68b50134a99f https://github.com/zephyrproject-rtos/cmsis-nn
 * edtt               64e5105ad82390164fb73fc654be3f73a608209a https://github.com/zephyrproject-rtos/edtt
 * fatfs              427159bf95ea49b7680facffaa29ad506b42709b https://github.com/zephyrproject-rtos/fatfs
 * hal_nordic         dce8519f7da37b0a745237679fd3f88250b495ff https://github.com/zephyrproject-rtos/hal_nordic
 * hal_st             fb8e79d1a261fd02aadff7c142729f1954163cf3 https://github.com/zephyrproject-rtos/hal_st
 * hal_wurthelektronik 24ca9873c3d608fad1fea0431836bc8f144c132e https://github.com/zephyrproject-rtos/hal_wurthelektronik
 * libmetal           03140d7f4bd9ba474ebfbb6256e84a9089248e67 https://github.com/zephyrproject-rtos/libmetal
 * liblc3             448f3de31f49a838988a162ef1e23a89ddf2d2ed https://github.com/zephyrproject-rtos/liblc3
 * littlefs           ca583fd297ceb48bced3c2548600dc615d67af24 https://github.com/zephyrproject-rtos/littlefs
 * loramac-node       842413c5fb98707eb5f26e619e8e792453877897 https://github.com/zephyrproject-rtos/loramac-node
 * lvgl               7c61a4cec26402d20c845c95dcad0e39dcd319f8 https://github.com/zephyrproject-rtos/lvgl
 * mipi-sys-t         a819419603a2dfcb47f7f39092e1bc112e45d1ef https://github.com/zephyrproject-rtos/mipi-sys-t
 * net-tools          d68ee9d17648a1bb3729c2023abfcb735dfe92fa https://github.com/zephyrproject-rtos/net-tools
 * nrf_hw_models      52d0b4b7b7431d8da6222cc3b17a8afdcb099baf https://github.com/zephyrproject-rtos/nrf_hw_models
 * open-amp           214f9fc1539f8e5937c0474cb6ee29b6dcb2d4b8 https://github.com/zephyrproject-rtos/open-amp
 * picolibc           1a5c603b9f8e228f9459bdafedad15ea28efc700 https://github.com/zephyrproject-rtos/picolibc
 * segger             9d0191285956cef43daf411edc2f1a7788346def https://github.com/zephyrproject-rtos/segger
 * tinycrypt          3e9a49d2672ec01435ffbf0d788db6d95ef28de0 https://github.com/zephyrproject-rtos/tinycrypt
 * uoscore-uedhoc     150f4eb2955eaf36ac0f9519d4f4f58d5ade5740 https://github.com/zephyrproject-rtos/uoscore-uedhoc
 * zcbor              d3093b5684f62268c7f27f8a5079f166772619de https://github.com/zephyrproject-rtos/zcbor
 */


/** ZBOSS build tag */
#define ZBOSS_BUILD_TAG "be0eb18df"

/** ZBOSS platform build tag */
#define ZBOSS_PLATFORM_BUILD_TAG "v3.11.2.70+v5.1.0"

/** ZBOSS build date (UTC) */
#define ZBOSS_BUILD_DATE 20240226

/** ZBOSS build time (UTC) */
#define ZBOSS_BUILD_TIME 140554


#endif /* ZBOSS_BUILD_INFO_H__ */
