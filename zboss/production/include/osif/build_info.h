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
 * platform_ncs       c16e5d4f3a325d54729aec4d97817ef98506ea9b https://projecttools.nordicsemi.no/bitbucket/scm/ZOI/platform_ncs.git
 * zboss-stack-src    89c80f604e08ad3e5452e67e4cad86dfda3c16a2 https://projecttools.nordicsemi.no/bitbucket/scm/zoi/zboss_stable
 * zboss-stack-doc    8d80c4c62c240ba315bc0a058d08de0b8da25cd2 https://projecttools.nordicsemi.no/bitbucket/scm/zoi/zboss_doc
 * nrf                4b15ee8336a92bfb350ff4167d994760df4a6df8 https://github.com/edmont/sdk-nrf
 * zephyr             d96769facecaba386b642d2c76c92c7694c81da0 https://github.com/nrfconnect/sdk-zephyr
 * hostap             dda5457ad2cfce99e333980c7764c8d480ae4010 https://github.com/nrfconnect/sdk-hostap
 * wfa-qt-control-app d649bd1342215e089d4211757186705cda179013 https://github.com/nrfconnect/sdk-wi-fiquicktrack-controlappc
 * mcuboot            3c2f2ff12bc20625cd65730b6036d061de4da5f7 https://github.com/nrfconnect/sdk-mcuboot
 * qcbor              751d36583a9ce1a640900c57e13c9b6b8f3a2ba2 https://github.com/laurencelundblade/QCBOR
 * mbedtls            9beb52e67835a17368616b27700270b3eb99e4ca https://github.com/nrfconnect/sdk-mbedtls
 * nrfxlib            455ce1a43ef6c9db618694f6f862fdf0a09c373a https://github.com/edmont/sdk-nrfxlib
 * trusted-firmware-m 2a2e1ce5e80fa3893a7747728003552bf6cfef55 https://github.com/nrfconnect/sdk-trusted-firmware-m
 * psa-arch-tests     94a349db22cd0e44136c281724ffc71b6e7391c3 https://github.com/nrfconnect/sdk-psa-arch-tests
 * matter             7653e6c78d0aab6d9c0fd25408e5a908435955b8 https://github.com/nrfconnect/sdk-connectedhomeip
 * cjson              c6af068b7f05207b28d68880740e4b9ec1e4b50a https://github.com/nrfconnect/sdk-cjson
 * azure-sdk-for-c    308c171cb4b5eed266649012a68406487ec81fb2 https://github.com/nrfconnect/azure-sdk-for-c
 * cirrus             3873a08377d93a479105a75ac390d3bbcd31d690 https://github.com/nrfconnect/sdk-mcu-drivers
 * openthread         b9dcdbca4edd348e924d7579a2bada48bf085645 https://github.com/nrfconnect/sdk-openthread
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
 * hal_nordic         5470822384781624efb2fda28cbc6a895a227677 https://github.com/zephyrproject-rtos/hal_nordic
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
#define ZBOSS_BUILD_TAG "89c80f604"

/** ZBOSS platform build tag */
#define ZBOSS_PLATFORM_BUILD_TAG "v3.15.0.55+v5.1.5"

/** ZBOSS build date (UTC) */
#define ZBOSS_BUILD_DATE 20240719

/** ZBOSS build time (UTC) */
#define ZBOSS_BUILD_TIME 073336


#endif /* ZBOSS_BUILD_INFO_H__ */
