/* liblxcapi
 *
 * Copyright © 2017 Christian Brauner <christian.brauner@ubuntu.com>.
 * Copyright © 2017 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __LXC_CONFILE_UTILS_H
#define __LXC_CONFILE_UTILS_H

#include <stdbool.h>

#include "conf.h"

#ifndef MACVLAN_MODE_PRIVATE
#define MACVLAN_MODE_PRIVATE 1
#endif

#ifndef MACVLAN_MODE_VEPA
#define MACVLAN_MODE_VEPA 2
#endif

#ifndef MACVLAN_MODE_BRIDGE
#define MACVLAN_MODE_BRIDGE 4
#endif

#ifndef MACVLAN_MODE_PASSTHRU
#define MACVLAN_MODE_PASSTHRU 8
#endif

extern int parse_idmaps(const char *idmap, char *type, unsigned long *nsid,
			unsigned long *hostid, unsigned long *range);

extern bool lxc_config_value_empty(const char *value);
extern struct lxc_netdev *lxc_network_add(struct lxc_list *networks, int idx,
					  bool tail);
extern struct lxc_netdev *
lxc_get_netdev_by_idx(struct lxc_conf *conf, unsigned int idx, bool allocate);
extern void lxc_log_configured_netdevs(const struct lxc_conf *conf);
extern bool lxc_remove_nic_by_idx(struct lxc_conf *conf, unsigned int idx);
extern void lxc_free_networks(struct lxc_list *networks);
extern int lxc_macvlan_mode_to_flag(int *mode, const char *value);
extern char *lxc_macvlan_flag_to_mode(int mode);

#endif /* __LXC_CONFILE_UTILS_H */
