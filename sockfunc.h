/*
 * Copyright (c) 2010-2011, Red Hat, Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND RED HAT, INC. DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL RED HAT, INC. BE LIABLE
 * FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Author: Jan Friesse <jfriesse@redhat.com>
 */

#ifndef _SOCKFUNC_H_
#define _SOCKFUNC_H_

#include "aiifunc.h"
#include "sfset.h"

#ifdef __cplusplus
extern "C" {
#endif

enum sf_transport_method {
	SF_TM_ASM,
	SF_TM_SSM,
	SF_TM_IPBC,
};

extern int	sf_bind_socket(const struct sockaddr *bind_addr, int sock);

extern const char *sf_cast_type_to_str(enum sf_cast_type cast_type);

extern int	sf_create_multicast_socket(const struct sockaddr *mcast_addr,
    const struct sockaddr *local_addr, const char *local_ifname, uint8_t ttl,
    int allow_mcast_loop, enum sf_transport_method transport_method,
    const struct aii_list *remote_addrs, int receive_timestamp, int force_recvttl, int sndbuf_size,
    int rcvbuf_size, uint16_t bind_port);

extern int	sf_create_udp_socket(const struct sockaddr *sa);

extern int	sf_create_unicast_socket(const struct sockaddr *local_addr, uint8_t ttl,
    int mcast_send, int allow_mcast_loop, const char *local_ifname,
    enum sf_transport_method transport_method, int receive_timestamp, int force_recvttl,
    int  sndbuf_size, int rcvbuf_size, uint16_t *bind_port);

extern int	sf_is_ipbc_supported(void);

extern int	sf_is_ssm_supported(void);

extern int	sf_mcast_join_asm_group(const struct sockaddr *mcast_addr,
    const struct sockaddr *local_addr, const char *local_ifname, int sock);

extern int	sf_mcast_join_ssm_group(const struct sockaddr *mcast_addr,
    const struct sockaddr *local_addr, const struct sockaddr *remote_addr,
    const char *local_ifname, int sock);

extern int	sf_mcast_join_ssm_group_list(const struct sockaddr *mcast_addr,
    const struct sockaddr *local_addr, const struct aii_list *remote_addrs,
    const char *local_ifname, int sock);

#ifdef __cplusplus
}
#endif

#endif /* _SOCKFUNC_H_ */
