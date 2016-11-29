/*
 * ZMap Copyright 2013 Regents of the University of Michigan
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 */

// probe module for performing TCP SYN scans

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "../../lib/includes.h"
#include "../fieldset.h"
#include "probe_modules.h"
#include "packet.h"

int fingerprint_global_initialize(struct state_conf *state);

int fingerprint_init_perthread(void* buf, macaddr_t *src,
		macaddr_t *gw, port_h_t dst_port,
		__attribute__((unused)) void **arg_ptr);

int fingerprint_make_packet(void *buf, ipaddr_n_t src_ip, ipaddr_n_t dst_ip,
		uint32_t *validation, int probe_num, __attribute__((unused)) void *arg);

void fingerprint_print_packet(FILE *fp, void* packet);

int fingerprint_validate_packet(const struct ip *ip_hdr, uint32_t len,
		__attribute__((unused))uint32_t *src_ip,
		uint32_t *validation);

void fingerprint_process_packet(const u_char *packet,
		__attribute__((unused)) uint32_t len, fieldset_t *fs,
        __attribute__((unused)) uint32_t *validation);
