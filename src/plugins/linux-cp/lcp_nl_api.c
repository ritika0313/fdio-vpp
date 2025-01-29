/*
 * Copyright 2020 Rubicon Communications, LLC.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/socket.h>
#include <linux/if.h>

#include <vnet/vnet.h>
#include <vnet/plugin/plugin.h>

#include <vlibapi/api.h>
#include <vlibmemory/api.h>
#include <vpp/app/version.h>
#include <vnet/format_fns.h>

#include <linux-cp/lcp_nl.api_enum.h>
#include <linux-cp/lcp_nl.api_types.h>

#include <linux-cp/lcp_nl.h>

static u16 lcp_nl_msg_id_base;
#define REPLY_MSG_ID_BASE lcp_nl_msg_id_base
#include <vlibapi/api_helper_macros.h>


static void
vl_api_lcp_nl_resync_t_handler (vl_api_lcp_nl_resync_t *mp)
{
  vl_api_lcp_nl_resync_reply_t *rmp;
  int rv = 0;
  vlib_main_t *vm = vlib_get_main ();

  lcp_resync_state (vm);

  REPLY_MACRO_END (VL_API_LCP_NL_RESYNC_REPLY);
}

/*
 * Set up the API message handling tables
 */
#include <linux-cp/lcp_nl.api.c>


static clib_error_t *
lcp_nl_api_init (vlib_main_t *vm)
{
  /* Ask for a correctly-sized block of API message decode slots */
  lcp_nl_msg_id_base = setup_message_id_table ();

  return (NULL);
}

VLIB_INIT_FUNCTION (lcp_nl_api_init);

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
