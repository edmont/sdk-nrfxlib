/*
 * ZBOSS Zigbee 3.0
 *
 * Copyright (c) 2012-2022 DSR Corporation, Denver CO, USA.
 * www.dsr-zboss.com
 * www.dsr-corporation.com
 * All rights reserved.
 *
 *
 * Use in source and binary forms, redistribution in binary form only, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 2. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 3. This software, with or without modification, must only be used with a Nordic
 *    Semiconductor ASA integrated circuit.
 *
 * 4. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* PURPOSE: Messaging cluster definitions
*/
#ifndef ZB_ZCL_MESSAGING_H_
#define ZB_ZCL_MESSAGING_H_

#include "zboss_api_core.h" /* ZBOSS core API types */
#include "zboss_api_aps.h"

#define ZB_ZCL_MESSAGING_DISPLAY_MSG_MAX_NON_FRAG_SIZE 48
#define ZB_ZCL_MESSAGING_MSG_CONFIRM_RESP_MSG_MAX_SIZE 21

/** @cond DOXYGEN_ZCL_SECTION */

/** @addtogroup ZB_ZCL_MESSAGING
  * @{
  *   @details
  *   The Messaging cluster provides an interface for passing text messages
  *   between Zigbee devices.
  */


/** @defgroup ZB_ZCL_MESSAGING_COMMANDS Messaging cluster commands
 *  @{
 */


/** Commands generated by Messaging Server
 * @see SE spec, subclause D.5.2.3
 */
typedef enum zb_zcl_messaging_srv_cmd_e
{

  /** @see SE spec, subclause D.5.2.3.1
   * @see zb_zcl_messaging_display_message_payload_s
   */
  ZB_ZCL_MESSAGING_SRV_CMD_DISPLAY_MESSAGE           = 0x00,

  /** @e TheCancelMessage command provides the ability
   * to cancel the sending or acceptance of previously sent messages. When this
   * message is received the recipient device has the option of clearing any
   * display or user interfaces it supports, or has the option of logging the
   * message for future reference.
   * @see SE spec, subclause D.5.2.3.2
   * @see zb_zcl_messaging_cancel_message_payload_s
   */
  ZB_ZCL_MESSAGING_SRV_CMD_CANCEL_MESSAGE            = 0x01,

  /** The Display Protected Message command is for use with messages that are
   * protected by a password or PIN.
   * @see zb_zcl_messaging_display_message_payload_s
   */
  ZB_ZCL_MESSAGING_SRV_CMD_DISPLAY_PROTECTED_MESSAGE = 0x02,

  /** @e TheCancelAllMessages command indicates to a client device that it should
   * cancel all display messages currently held by it.
   * @note @e TheCancelAllMessages command in this revision of this specification
   * is provisional and not certifiable. This feature may change before reaching
   * certifiable status in a future revision of this specification.
   * @see zb_zcl_messaging_cancel_all_message_payload_s
   */
  ZB_ZCL_MESSAGING_SRV_CMD_CANCEL_ALL_MESSAGES       = 0x03
} zb_zcl_messaging_srv_cmd_t;


/** Commands generated by Messaging Client
  * @see SE spec, D.5.3.3
  */
typedef enum zb_zcl_messaging_cli_cmd_e
{

  /** On receipt of this command, the device shall send a @e DisplayMessage or
   * @e DisplayProtectedMessage command as appropriate. A ZCL Default Response
   * with status @e NOT_FOUND shall be returned if no message is available.
   * @see SE spec, subclause D.5.3.3.1
   * @note This command has no payload.
   */
  ZB_ZCL_MESSAGING_CLI_CMD_GET_LAST_MESSAGE = 0x00,

  /** @e TheMessageConfirmation command provides an indication that a Utility
    * Customer has acknowledged and/or accepted the contents of a message
    * previously received from the Messaging cluster server. Enhanced Message
    * Confirmation commands shall contain an answer of ‘NO’, ‘YES’ and/or a
    * message confirmation string.
    * If the optional Message Confirmation Response is required, the Message
    * Confirmation Control field shall also be present.
    * @see SE spec, subclause D.5.3.3.2
    * @see zb_zcl_messaging_message_confirm_payload_s
    */
  ZB_ZCL_MESSAGING_CLI_CMD_MESSAGE_CONFIRMATION = 0x01,

  /** This command initiates the return of the first (and maybe only) @e
   * CancelAllMessages command held on the associated server, and which has an
   * implementation time equal to or later than the value indicated in the payload.
   * @note The @e GetMessageCancellation command in this revision of this
   * specification is provisional and not certifiable. This feature may change
   * before reaching certifiable status in a future revision of this specification.
   * @see zb_zcl_messaging_get_message_cancellation_payload_s
   */
  ZB_ZCL_MESSAGING_CLI_CMD_GET_MESSAGE_CANCELLATION = 0x02
} zb_zcl_messaging_cli_cmd_t;

/* MESSAGING cluster commands list : only for information - do not modify */
#define ZB_ZCL_CLUSTER_ID_MESSAGING_SERVER_ROLE_GENERATED_CMD_LIST                  \
                                      ZB_ZCL_MESSAGING_SRV_CMD_CANCEL_MESSAGE,      \
                                      ZB_ZCL_MESSAGING_SRV_CMD_DISPLAY_MESSAGE

#define ZB_ZCL_CLUSTER_ID_MESSAGING_CLIENT_ROLE_RECEIVED_CMD_LIST ZB_ZCL_CLUSTER_ID_MESSAGING_SERVER_ROLE_GENERATED_CMD_LIST

#define ZB_ZCL_CLUSTER_ID_MESSAGING_CLIENT_ROLE_GENERATED_CMD_LIST                  \
                                      ZB_ZCL_MESSAGING_CLI_CMD_GET_LAST_MESSAGE,    \
                                      ZB_ZCL_MESSAGING_CLI_CMD_MESSAGE_CONFIRMATION

#define ZB_ZCL_CLUSTER_ID_MESSAGING_SERVER_ROLE_RECEIVED_CMD_LIST ZB_ZCL_CLUSTER_ID_MESSAGING_CLIENT_ROLE_GENERATED_CMD_LIST


/* Payload description */

/** Extended Message Control Field values
 * @see SE spec, Table D-118
 * @see zb_zcl_messaging_display_message_payload_t::extended_message_control
 */
typedef enum zb_zcl_messaging_extended_message_control_e
{
  ZB_ZCL_MESSAGING_MESSAGE_HAS_NOT_BEEN_CONFIRMED = 0,  /**< Message has not been confirmed */
  ZB_ZCL_MESSAGING_MESSAGE_HAS_BEEN_CONFIRMED     = 1,  /**< Message has been confirmed */
} zb_zcl_messaging_extended_message_control_field_t;

/** Extended Message Control Field Bit Map
 * @see SE spec, Table D-118
 */
enum zb_zcl_messaging_extended_message_control_field_bitmap_e
{
  ZB_ZCL_MESSAGING_MESSAGE_CONFIRMATION_STATUS = 0,  /**< @see zb_zcl_messaging_extended_message_control_field_e*/
};


/** @ref ZB_ZCL_MESSAGING_SRV_CMD_DISPLAY_MESSAGE "DisplayMessage" command payload
  * @see SE spec, subclause D.5.2.3.1.1
  */
typedef ZB_PACKED_PRE struct zb_zcl_messaging_display_message_payload_s
{
  /** 32-bit number identifier for the message. */
  zb_uint32_t message_id;                                              /* (M) */

  /** BitMap field indicating control information related to the message */
  zb_uint8_t message_control;                                          /* (M) */

  /** The time at which the message becomes valid */
  zb_uint32_t start_time;                                              /* (M) */

  /** The amount of time in minutes after the Start Time during which
   * the message is displayed  */
  zb_uint16_t duration_in_minutes;                                     /* (M) */

  /** Message (variable): Character String
   * WARNING: Variable length of message supported, but remember to pass strings in global memory only!
   */
  zb_uint8_t message_len;  /* (M) */
  zb_uint8_t *message;  /* (M) */

  /** BitMap field indicating additional control
   * and status information for a given message.
   */
  zb_uint8_t extended_message_control;                                 /* (O) */
} ZB_PACKED_STRUCT zb_zcl_messaging_display_message_payload_t;


/** @e MessageControl field's transmission mechanism values
 * @see SE spec, Table D-117
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_TRANSMISSION_MECHANISM
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_TRANSMISSION_MECHANISM
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_TRANSMISSION_MECHANISM
 */
typedef enum zb_zcl_messaging_message_control_transmission_mechanism_e
{
  ZB_ZCL_MESSAGING_NORMAL_TRANSMISSION_ONLY             = 0,  /**< Send message through normal command
                                                                * function to client.
                                                                */
  ZB_ZCL_MESSAGING_NORMAL_AND_INTERNAL_PAN_TRANSMISSION = 1,  /**< Send message through normal command
                                                                * function to client and pass message onto the
                                                                * Inter-PAN transmission mechanism.
                                                                */
  ZB_ZCL_MESSAGING_INTER_PAN_TRANSMISSION_ONLY          = 2,  /**< Send message through the Inter-PAN
                                                                * transmission mechanism.
                                                                */
} zb_zcl_messaging_control_field_transmission_mechanism_t;

/** @brief Default value for Messaging cluster revision global attribute */
#define ZB_ZCL_MESSAGING_CLUSTER_REVISION_DEFAULT ((zb_uint16_t)0x0002u)

/*!
  @brief Declare attribute list for Messaging cluster (only cluster revision attribute)
  @param attr_list - attribute list name
*/
#define ZB_ZCL_DECLARE_MESSAGING_ATTR_LIST(attr_list)                            \
  ZB_ZCL_START_DECLARE_ATTRIB_LIST_CLUSTER_REVISION(attr_list, ZB_ZCL_MESSAGING) \
  ZB_ZCL_FINISH_DECLARE_ATTRIB_LIST

/**
 * Set @e MessageControl's transmission mechanism value
 * @param  x   - variable to store transmission mechanism value
 * @param  val - @ref zb_zcl_messaging_control_field_transmission_mechanism_t value
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_TRANSMISSION_MECHANISM(x, val) ((x) &= (0xFC | ((val) & 0x03)))


/**
 * Get @e MessageControl's transmission mechanism value
 * @param  x - variable that stores transmission mechanism value
 * @see zb_zcl_messaging_control_field_transmission_mechanism_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_TRANSMISSION_MECHANISM(x) ((x) & 0x03)


/**
 * Clear @e MessageControl's transmission mechanism value
 * @param  x - variable that stores transmission mechanism value
 * @see zb_zcl_messaging_control_field_transmission_mechanism_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_TRANSMISSION_MECHANISM(x) ((x) &= 0xFC)


/** @e MessageControl field's control importance values
 * @see SE spec, Table D-117
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_IMPORTANCE_LEVEL
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_IMPORTANCE_LEVEL
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_IMPORTANCE_LEVEL
 */
typedef enum zb_zcl_messaging_message_control_importance_level_e
{
  ZB_ZCL_MESSAGING_IMPORTANCE_LEVEL_LOW      = 0,  /**< Low importance level */
  ZB_ZCL_MESSAGING_IMPORTANCE_LEVEL_MEDIUM   = 1,  /**< Medium importance level */
  ZB_ZCL_MESSAGING_IMPORTANCE_LEVEL_HIGH     = 2,  /**< High importance level */
  ZB_ZCL_MESSAGING_IMPORTANCE_LEVEL_CRITICAL = 3,  /**< Critical importance level */
} zb_zcl_messaging_message_control_importance_level_t;


/**
 * Set @e MessageControl's control importance value
 * @param  x   - variable to store control importance value
 * @param  val - @ref zb_zcl_messaging_message_control_importance_level_t value
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_IMPORTANCE_LEVEL(x, val) ((x) &= (0xF3 | ((val) & 0x03) << 2)


/**
 * Get @e MessageControl's control importance value
 * @param  x - variable that stores control importance value
 * @see zb_zcl_messaging_message_control_importance_level_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_IMPORTANCE_LEVEL(x) (((x) >> 2) & 0x03)


/**
 * Clear @e MessageControl's control importance value
 * @param  x - variable that stores control importance value
 * @see zb_zcl_messaging_message_control_importance_level_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_IMPORTANCE_LEVEL(x) ((x) &= 0xF3)


/** @e MessageControl field's enhanced confirmation values
 * @see SE spec, Table D-117
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_ENHANCED_CONFIRMATION
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_ENHANCED_CONFIRMATION
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_ENHANCED_CONFIRMATION
 */
typedef enum zb_zcl_messaging_message_control_enhanced_confirmation_e
{
  ZB_ZCL_MESSAGING_ENHANCED_CONFIRMATION_NOT_REQUIRED  = 0,  /**< Enhanced Confirmation not required */
  ZB_ZCL_MESSAGING_ENHANCED_CONFIRMATION_REQUIRED      = 1,  /**< Enhanced Confirmation required */
} zb_zcl_messaging_message_control_enhanced_confirmation_t;


/**
 * Set @e MessageControl's enhanced confirmation value
 * @param  x   - variable to store enhanced confirmation value
 * @param  val - @ref zb_zcl_messaging_message_control_enhanced_confirmation_t value
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_ENHANCED_CONFIRMATION(x, val) ((x) &= (0xDF | ((val) & 0x01) << 5)

/**
 * Get @e MessageControl's enhanced confirmation value
 * @param  x - variable that stores enhanced confirmation value
 * @see zb_zcl_messaging_message_control_enhanced_confirmation_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_ENHANCED_CONFIRMATION(x) (((x) >> 5) & 0x01)

/**
 * Clear @e MessageControl's enhanced confirmation value
 * @param  x - variable that stores enhanced confirmation value
 * @see zb_zcl_messaging_message_control_enhanced_confirmation_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_ENHANCED_CONFIRMATION(x) ((x) &= 0xDF )


/** @e MessageControl field's message confirmation values
 * @see SE spec, Table D-117
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_MESSAGE_CONFIRMATION
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_MESSAGE_CONFIRMATION
 * @see ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_MESSAGE_CONFIRMATION
 */
typedef enum zb_zcl_messaging_message_control_message_confirmation_e
{
  ZB_ZCL_MESSAGING_MESSAGE_CONFIRMATION_NOT_REQUIRED = 0x00,  /**< Message Confirmation not required. */
  ZB_ZCL_MESSAGING_MESSAGE_CONFIRMATION_REQUIRED     = 0x01,  /**< Message Confirmation required. */
} zb_zcl_messaging_message_control_message_confirmation_t;


/**
 * Set @e MessageControl's message confirmation value
 * @param  x   - variable to store message confirmation value
 * @param  val - @ref zb_zcl_messaging_message_control_message_confirmation_t value
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_SET_MESSAGE_CONFIRMATION(x, val) ((x) &= (0x7F | ((val) & 0x01) << 7)


/**
 * Get @e MessageControl's message confirmation value
 * @param  x - variable that stores message confirmation value
 * @see zb_zcl_messaging_message_control_message_confirmation_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_GET_MESSAGE_CONFIRMATION(x) (((x) >> 7) & 0x01)

/**
 * Clear @e MessageControl's message confirmation value
 * @param  x - variable that stores message confirmation value
 * @see zb_zcl_messaging_message_control_message_confirmation_t
 */
#define ZB_ZCL_MESSAGING_MESSAGE_CONTROL_CLR_MESSAGE_CONFIRMATION(x) ((x) &= 0x7F)


/** Check if some size in range of variable size of specified payload.
 */
#define ZB_ZCL_MESSAGING_DISPLAY_MSG_PAYLOAD_SIZE_IS_VALID(size) \
((size) >= ((zb_int16_t)sizeof(zb_zcl_messaging_display_message_payload_t) - \
(zb_int16_t)ZB_SIZEOF_FIELD(zb_zcl_messaging_display_message_payload_t, message) -\
(zb_int16_t)ZB_SIZEOF_FIELD(zb_zcl_messaging_display_message_payload_t, extended_message_control)))

/* 8/16/2017 NK CR:MINOR Do all compilers support such initializing? More common way to initialize
 * is to provide pointer as parameter and operate with it inside the macro. */
/* 8/21/2017 IA: It is C99 features. I hope, they are supported by all "our" compilers. */

/** @ref zb_zcl_messaging_display_message_payload_t initializer */
#define ZB_ZCL_MESSAGING_DISPLAY_MSG_PAYLOAD_INIT \
  (zb_zcl_messaging_display_message_payload_t)\
  { \
    .extended_message_control = 0x00, \
  }

/** @ref ZB_ZCL_MESSAGING_SRV_CMD_CANCEL_MESSAGE "CancelMessage" command payload
 * @see SE spec, subclause D.5.2.3.2.1
 */
typedef ZB_PACKED_PRE struct zb_zcl_messaging_cancel_message_payload_s
{
  /** 32-bit number identifier for the message. */
  zb_uint32_t message_id;                     /* (M) */

  /** This field is deprecated and should be set to 0x00 */
  zb_uint8_t message_control;                 /* (M) */
} ZB_PACKED_STRUCT zb_zcl_messaging_cancel_message_payload_t;

/** @ref zb_zcl_messaging_cancel_message_payload_t initializer */
#define ZB_ZCL_MESSAGING_CANCEL_MSG_PAYLOAD_INIT \
  (zb_zcl_messaging_cancel_message_payload_t) {0}

/** Check if some size in range of variable size of specified payload. */
#define ZB_ZCL_MESSAGING_MSG_CANCEL_MESSAGE_SIZE_IS_VALID(size) \
  ((size) >= sizeof(zb_zcl_messaging_cancel_message_payload_t))

/** Message Confirmation Control
 * @see SE spec, Table D-120
 * @see zb_zcl_messaging_message_confirm_payload_t::message_confirmation_control
 */
typedef enum zb_zcl_messaging_message_confirmation_control_e
{
  ZB_ZCL_MESSAGING_NO_RETURNED  = 1 << 0,  /**< The answer is ‘NO’ */
  ZB_ZCL_MESSAGING_YES_RETURNED = 1 << 1,  /**< The answer is ‘YES’ */
} zb_zcl_messaging_message_confirmation_control_t;


/** @ref ZB_ZCL_MESSAGING_CLI_CMD_MESSAGE_CONFIRMATION "MessageConfirmation" command payload
  * @see SE spec, subclause D.5.3.3.2.1
  */
typedef ZB_PACKED_PRE struct zb_zcl_messaging_message_confirm_payload_s
{
  /** 32-bit number identifier for the message being confirmed. */
  zb_uint32_t message_id;                      /* (M) */

  /** UTCTime of user confirmation of message */
  zb_uint32_t confirmation_time;               /* (M) */

  /** BitMap field indicating the simple confirmation that is
   * contained within the response.
   */
  zb_uint8_t message_confirmation_control;     /* (O) */

  /** ZCL Octet String containing the message to be returned.
   * The first Octet indicates length (21 is max).
   * The string shall be encoded in the UTF-8 format.
   * If this optional field is not available, a default value of 0x00 shall be used.
   */
  zb_uint8_t message_confirmation_response[ZB_ZCL_MESSAGING_MSG_CONFIRM_RESP_MSG_MAX_SIZE]; /* (O) */
} ZB_PACKED_STRUCT zb_zcl_messaging_message_confirm_payload_t;


/** @ref ZB_ZCL_MESSAGING_SRV_CMD_CANCEL_ALL_MESSAGES "CancelAllMessages" command payload
 * @see SE spec, subclause D.5.2.3.4.2
 */
typedef ZB_PACKED_PRE struct zb_zcl_messaging_cancel_all_message_payload_s
{
  /** A UTC Time field to indicate the date/time at which all existing display
   * messages should be cleared.
   */
  zb_uint32_t implementation_date;  /* (M) */
} ZB_PACKED_STRUCT zb_zcl_messaging_cancel_all_message_payload_t;


/** @ref ZB_ZCL_MESSAGING_CLI_CMD_GET_MESSAGE_CANCELLATION "GetMessageCancellation" command payload
 * @see SE spec, subclause D.5.3.3.3.2
 */
typedef ZB_PACKED_PRE struct zb_zcl_messaging_get_message_cancellation_payload_s
{
  /** UTC Timestamp indicating the earliest implementation time of a @e CancelAllMessages
   *  command to be returned.
   */
  zb_uint32_t earliest_implementation_time;  /* (M) */
} ZB_PACKED_STRUCT zb_zcl_messaging_get_message_cancellation_payload_t;


/** Check if some size in range of variable size of specified payload. */
#define ZB_ZCL_MESSAGING_MSG_CONFIRM_PAYLOAD_SIZE_IS_VALID(size) \
  ((size) >= sizeof(zb_zcl_messaging_message_confirm_payload_t) - \
   ZB_SIZEOF_FIELD(zb_zcl_messaging_message_confirm_payload_t, message_confirmation_control) -\
   ZB_SIZEOF_FIELD(zb_zcl_messaging_message_confirm_payload_t, message_confirmation_response))

typedef enum zb_zcl_messaging_response_type_e {
  ZB_ZCL_MESSAGING_RESPONSE_TYPE_NORMAL,
  ZB_ZCL_MESSAGING_RESPONSE_TYPE_PROTECTED,
  ZB_ZCL_MESSAGING_RESPONSE_TYPE_NOT_FOUND,
} zb_zcl_messaging_response_type_t;

/** According to SE spec, server could send following responses to
 *  @ref ZB_ZCL_MESSAGING_CLI_CMD_GET_LAST_MESSAGE "GetLastMessage" command:
 *  <ul>
 *    <li>
 *      \b NOT_FOUND as default response
 *    </li>
 *    <li>
 *      \b DisplayMessage command
 *    </li>
 *    <li>
 *      \b DisplayProtectedMessage command
 *    </li>
 *  </ul>
 */
typedef struct zb_zcl_messaging_get_last_message_response_s {
  zb_zcl_messaging_response_type_t resp_type;
  union {
    zb_zcl_messaging_display_message_payload_t display_message;
    zb_zcl_messaging_display_message_payload_t display_protected_message;
  } resp;
} zb_zcl_messaging_get_last_message_response_t;

/** @ref zb_zcl_messaging_get_last_message_response_t initializer */
#define ZB_ZCL_MESSAGING_GET_LAST_MESSAGE_RESPONSE_INIT \
  (zb_zcl_messaging_get_last_message_response_t) \
  { \
    .resp_type = ZB_ZCL_MESSAGING_RESPONSE_TYPE_NOT_FOUND, \
    .resp.display_message = ZB_ZCL_MESSAGING_DISPLAY_MSG_PAYLOAD_INIT, \
  }

/** @ref zb_zcl_messaging_message_confirm_payload_t initializer */
#define ZB_ZCL_MESSAGING_MSG_CONFIRM_PAYLOAD_INIT \
  (zb_zcl_messaging_message_confirm_payload_t) \
  {\
    .message_confirmation_response = {0x00} \
  }

/** Function for send @ref ZB_ZCL_MESSAGING_CLI_CMD_GET_LAST_MESSAGE "GetLastMessage" command
 * @n On receiver's side callback ZCL device callback @ref ZB_ZCL_REGISTER_DEVICE_CB will be called with
 * @ref ZB_ZCL_MESSAGING_GET_LAST_MSG_CB_ID callback id.
 * @param  param - Reference to buffer.
 * @param  dst_addr - Address of the device to send command to.
 * @param  dst_addr_mode - Address mode for dst_addr.
 * @param  dst_ep - Destination endpoint.
 * @param  src_ep - Current endpoint.
 * @param cb - Callback which should be called when the ZCL stack receives APS ack.
 * @par Usage
 * @n Example of sending ZB_ZCL_MESSAGING_CLI_CMD_GET_LAST_MESSAGE "GetLastMessage" command
 */
void zb_zcl_messaging_send_get_last_msg(zb_uint8_t param,
                                             const zb_addr_u *dst_addr,
                                             zb_aps_addr_mode_t dst_addr_mode,
                                             zb_uint8_t dst_ep,
                                             zb_uint8_t src_ep,
                                             zb_callback_t cb);

/** Function for send @ref ZB_ZCL_MESSAGING_SRV_CMD_DISPLAY_MESSAGE "DisplayMessage" command.
 * On sender's side callback ZCL device callback @ref ZB_ZCL_REGISTER_DEVICE_CB will be called with @ref ZB_ZCL_MESSAGING_GET_LAST_MSG_CB_ID
 * callback id on reception of @ref ZB_ZCL_MESSAGING_CLI_CMD_GET_LAST_MESSAGE "GetLastMessage" command.
 * @n On receiver's side callback ZCL device callback @ref ZB_ZCL_REGISTER_DEVICE_CB will be called with
 * @ref ZB_ZCL_MESSAGING_DISPLAY_MSG_CB_ID callback id.
 * @param  param - Reference to buffer.
 * @param  dst_addr - Address of the device to send command to.
 * @param  dst_addr_mode - Address mode for dst_addr.
 * @param  dst_ep - Destination endpoint.
 * @param  src_ep - Current endpoint.
 * @param payload - Packet payload (@ref zb_zcl_messaging_display_message_payload_t).
 * @param cb - Callback which should be called when the ZCL stack receives APS ack.
 * @par Usage
 * @n Handle @ref ZB_ZCL_MESSAGING_CLI_CMD_GET_LAST_MESSAGE "GetLastMessage" command
 */
void zb_zcl_messaging_send_display_msg(zb_uint8_t param,
                                            const zb_addr_u *dst_addr,
                                            zb_aps_addr_mode_t dst_addr_mode,
                                            zb_uint8_t dst_ep,
                                            zb_uint8_t src_ep,
                                            const zb_zcl_messaging_display_message_payload_t *payload,
                                            zb_callback_t cb);

/** Function for send @ref ZB_ZCL_MESSAGING_CLI_CMD_MESSAGE_CONFIRMATION "MessageConfirmation" command
 * On receiver's side callback ZCL device callback @ref ZB_ZCL_REGISTER_DEVICE_CB will be called with
 * @ref ZB_ZCL_MESSAGING_MSG_CONFIRMATION_CB_ID callback id.
 * @param  param - Reference to buffer.
 * @param  dst_addr - Address of the device to send command to.
 * @param  dst_addr_mode - Address mode for dst_addr.
 * @param  dst_ep - Destination endpoint.
 * @param  src_ep - Current endpoint.
 * @param payload - Packet payload (@ref zb_zcl_messaging_message_confirm_payload_t).
 * @param cb - Callback which should be called when the ZCL stack receives APS ack.
 */
void zb_zcl_messaging_send_msg_confirmation(zb_uint8_t param,
                                            const zb_addr_u *dst_addr,
                                            zb_aps_addr_mode_t dst_addr_mode,
                                            zb_uint8_t dst_ep,
                                            zb_uint8_t src_ep,
                                            const zb_zcl_messaging_message_confirm_payload_t *payload,
                                            zb_callback_t cb);

/** Function for send @ref ZB_ZCL_MESSAGING_SRV_CMD_CANCEL_MESSAGE "CancelMessage" command
 * On receiver's side callback ZCL device callback @ref ZB_ZCL_REGISTER_DEVICE_CB will be called with
 * @ref ZB_ZCL_MESSAGING_CANCEL_MSG_CB_ID callback id.
 * @param  param - Reference to buffer.
 * @param  dst_addr - Address of the device to send command to.
 * @param  dst_addr_mode - Address mode for dst_addr.
 * @param  dst_ep - Destination endpoint.
 * @param  src_ep - Current endpoint.
 * @param payload - Packet payload (@ref zb_zcl_messaging_cancel_message_payload_t).
 * @param cb - Callback which should be called when the ZCL stack receives APS ack.
 */
void zb_zcl_messaging_send_cancel_msg(zb_uint8_t param,
                                           const zb_addr_u *dst_addr,
                                           zb_aps_addr_mode_t dst_addr_mode,
                                           zb_uint8_t dst_ep,
                                           zb_uint8_t src_ep,
                                           const zb_zcl_messaging_cancel_message_payload_t *payload,
                                           zb_callback_t cb);

/** Macro for call @ref zb_zcl_messaging_send_get_last_msg function */
#define ZB_ZCL_MESSAGING_SEND_GET_LAST_MSG(_param, _dst_addr, _addr_mode, \
                                           _dst_ep, _src_ep)              \
  zb_zcl_messaging_send_get_last_msg(_param, _dst_addr, _addr_mode,       \
                                     _dst_ep, _src_ep, NULL)              \

/** Macro for call @ref zb_zcl_messaging_send_display_msg function */
#define ZB_ZCL_MESSAGING_SEND_DISPLAY_MSG(_param, _dst_addr, _addr_mode, \
                                          _dst_ep, _src_ep, _payload)    \
  zb_zcl_messaging_send_display_msg(_param, _dst_addr, _addr_mode,       \
                                    _dst_ep, _src_ep, _payload, NULL)

/** Macro for call @ref zb_zcl_messaging_send_msg_confirmation function */
#define ZB_ZCL_MESSAGING_SEND_MSG_CONFIRMATION(_param, _dst_addr, _addr_mode, \
                                               _dst_ep, _src_ep, _payload)    \
  zb_zcl_messaging_send_msg_confirmation(_param, _dst_addr, _addr_mode,       \
                                         _dst_ep, _src_ep, _payload, NULL)

/** Macro for call @ref zb_zcl_messaging_send_cancel_msg function */
#define ZB_ZCL_MESSAGING_SEND_CANCEL_MSG(_param, _dst_addr, _addr_mode, \
                                         _dst_ep, _src_ep, _payload)    \
  zb_zcl_messaging_send_cancel_msg(_param, _dst_addr, _addr_mode,       \
                                   _dst_ep, _src_ep, _payload, NULL)

/** @cond internals_doc */

void zb_zcl_messaging_init_server(void);
void zb_zcl_messaging_init_client(void);
#define ZB_ZCL_CLUSTER_ID_MESSAGING_SERVER_ROLE_INIT zb_zcl_messaging_init_server
#define ZB_ZCL_CLUSTER_ID_MESSAGING_CLIENT_ROLE_INIT zb_zcl_messaging_init_client

/** @endcond */ /* internal_doc */

/** @} */ /* ZB_ZCL_MESSAGING_COMMANDS */

/** @} */ /* ZCL Messaging cluster definitions */

/** @endcond */ /* DOXYGEN_ZCL_SECTION */

#endif /* ZB_ZCL_MESSAGING_H_ */
