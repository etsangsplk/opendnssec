/*
 * Copyright (c) 2014 Jerry Lundström <lundstrom.jerry@gmail.com>
 * Copyright (c) 2014 .SE (The Internet Infrastructure Foundation).
 * Copyright (c) 2014 OpenDNSSEC AB (svb)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "enforcer_zone.h"

#include <stdlib.h>

object_t* __enforcer_zone_new_object(const db_connection_t* connection) {
	db_object_field_list_t* object_field_list;
	db_object_field_t* object_field;
	db_object_t* object;

	if (!(object = db_object_new())
		|| db_object_set_connection(object, connection)
		|| db_object_set_table(object, "EnforcerZone")
		|| db_object_set_primary_key_name(object, "id")
		!(object_field_list = db_object_field_list_new()))
	{
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "id")
		|| db_object_field_set_type(object_field, DB_TYPE_PRIMARY_KEY)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "name")
		|| db_object_field_set_type(object_field, DB_TYPE_STRING)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "policy")
		|| db_object_field_set_type(object_field, DB_TYPE_STRING)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "signconf_needs_writing")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "signconf_path")
		|| db_object_field_set_type(object_field, DB_TYPE_STRING)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "next_change")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "ttl_end_ds")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "ttl_end_dk")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "ttl_end_rs")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "roll_ksk_now")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "roll_zsk_now")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "roll_csk_now")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "adapters")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "next_ksk_roll")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "next_zsk_roll")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (!(object_field = db_object_field_new())
		|| db_object_field_set_name(object_field, "next_csk_roll")
		|| db_object_field_set_type(object_field, DB_TYPE_INTEGER)
		|| db_object_field_list_add(object_field_list, object_field))
	{
		object_field_free(object_field);
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}

	if (db_object_set_object_field_list(object, object_field_list)) {
		object_field_list_free(object_field_list);
		object_free(object);
		return NULL;
	}
}

/* ENFORCER ZONE */

enforcer_zone_t* enforcer_zone_new(const db_connection_t* connection) {
	enforcer_zone_t* enforcer_zone =
		(enforcer_zone_t*)calloc(1, sizeof(enforcer_zone_t));

	if (enforcer_zone) {
		if (!(enforcer_zone->dbo = __enforcer_zone_new_object(connection))) {
			free(enforcer_zone);
			return NULL;
		}
	}

	return enforcer_zone;
}

void enforcer_zone_free(enforcer_zone_t* enforcer_zone) {
	if (enforcer_zone) {
		if (enforcer_zone->dbo) {
			db_object_free(enforcer_zone->dbo);
		}
		if (enforcer_zone->name) {
			free(enforcer_zone->name);
		}
		if (enforcer_zone->policy) {
			free(enforcer_zone->policy);
		}
		if (enforcer_zone->signconf_path) {
			free(enforcer_zone->signconf_paths);
		}
		free(enforcer_zone);
	}
}

void enforcer_zone_reset(enforcer_zone_t* enforcer_zone) {
	if (enforcer_zone) {
		enforcer_zone->id = 0;
		if (enforcer_zone->name) {
			free(enforcer_zone->name);
		}
		enforcer_zone->name = NULL;
		if (enforcer_zone->policy) {
			free(enforcer_zone->policy);
		}
		enforcer_zone->policy = NULL;
		enforcer_zone->signconf_needs_writing = 0;
		if (enforcer_zone->signconf_path) {
			free(enforcer_zone->signconf_paths);
		}
		enforcer_zone->signconf_path = NULL;
	    enforcer_zone->next_change = 0;
	    enforcer_zone->ttl_end_ds = 0;
	    enforcer_zone->ttl_end_dk = 0;
	    enforcer_zone->ttl_end_rs = 0;
	    enforcer_zone->roll_ksk_now = 0;
	    enforcer_zone->roll_zsk_now = 0;
	    enforcer_zone->roll_csk_now = 0;
	    enforcer_zone->adapters = 0;
		enforcer_zone->next_ksk_roll = 0;
		enforcer_zone->next_zsk_roll = 0;
		enforcer_zone->next_csk_roll = 0;
	}
}

int enforcer_zone_from_result(enforcer_zone_t* enforcer_zone, const db_result_t* result) {
	const db_value_set_t* value_set;

	if (!enforcer_zone) {
		return 1;
	}
	if (!result) {
		return 1;
	}

	enforcer_zone_reset(enforcer_zone);
	if (!(value_set = db_result_value_set(result))
		|| db_value_set_size(value_set) != 16
		|| db_value_to_int(db_value_set_get(value_set, 0), &(test->id))
		|| db_value_to_string(db_value_set_get(value_set, 1), &(test->name))
		|| db_value_to_string(db_value_set_get(value_set, 2), &(test->policy))
		|| db_value_to_int(db_value_set_get(value_set, 3), &(test->signconf_needs_writing))
		|| db_value_to_string(db_value_set_get(value_set, 4), &(test->signconf_path))
		|| db_value_to_int(db_value_set_get(value_set, 5), &(test->next_change))
		|| db_value_to_int(db_value_set_get(value_set, 6), &(test->ttl_end_ds))
		|| db_value_to_int(db_value_set_get(value_set, 7), &(test->ttl_end_dk))
		|| db_value_to_int(db_value_set_get(value_set, 8), &(test->ttl_end_rs))
		|| db_value_to_int(db_value_set_get(value_set, 9), &(test->roll_ksk_now))
		|| db_value_to_int(db_value_set_get(value_set, 10), &(test->roll_zsk_now))
		|| db_value_to_int(db_value_set_get(value_set, 11), &(test->roll_csk_now))
		|| db_value_to_int(db_value_set_get(value_set, 12), &(test->adapters))
		|| db_value_to_int(db_value_set_get(value_set, 13), &(test->next_ksk_roll))
		|| db_value_to_int(db_value_set_get(value_set, 14), &(test->next_zsk_roll))
		|| db_value_to_int(db_value_set_get(value_set, 15), &(test->next_csk_roll)))
	{
		return 1;
	}
	return 0;
}

key_data_list_t* enforcer_zone_get_keys(const enforcer_zone_t* enforcer_zone) {
	return NULL;
}

adapter_list_t* enforcer_zone_get_adapters(const enforcer_zone_t* enforcer_zone) {
	return NULL;
}

key_dependency_list_t* enforcer_zone_get_key_dependencies(const enforcer_zone_t* enforcer_zone) {
	return NULL;
}

/* ENFORCER ZONE LIST */

enforcer_zone_list_t* enforcer_zone_list_new(const db_connection_t* connection) {
	enforcer_zone_list_t* enforcer_zone_list =
		(enforcer_zone_list_t*)calloc(1, sizeof(enforcer_zone_list_t));

	if (enforcer_zone_list) {
		if (!(enforcer_zone_list->dbo = __enforcer_zone_list_new_object(connection))) {
			free(enforcer_zone_list);
			return NULL;
		}
	}

	return enforcer_zone_list;
}

void enforcer_zone_list_free(enforcer_zone_list_t* enforcer_zone_list) {
	if (enforcer_zone_list) {
		if (enforcer_zone_list->dbo) {
			db_object_free(enforcer_zone_list->dbo);
		}
		if (enforcer_zone_list->result_list) {
			db_result_list_free(enforcer_zone_list->result_list);
		}
		if (enforcer_zone_list->enforcer_zone) {
			enforcer_zone_free(enforcer_zone_list->enforcer_zone);
		}
		free(enforcer_zone_list);
	}
}

int enforcer_zone_list_get(enforcer_zone_list_t* enforcer_zone_list) {
	if (!enforcer_zone_list) {
		return 1;
	}

	if (enforcer_zone_list->result_list) {
		db_result_list_free(enforcer_zone_list->result_list);
	}
	if (!(enforcer_zone_list->result_list = db_object_read(enforcer_zone_list->dbo, NULL, NULL))) {
		return 1;
	}
	return 0;
}

const enforcer_zone_t* enforcer_zone_list_begin(enforcer_zone_list_t* enforcer_zone_list) {
	if (!enforcer_zone_list) {
		return 1;
	}
	if (!enforcer_zone_list->result_list) {
		return 1;
	}

	if (!(enforcer_zone_list->result = db_result_list_begin(enforcer_zone_list->result_list))) {
		return NULL;
	}
	if (!enforcer_zone_list->enforcer_zone) {
		if (!(enforcer_zone_list->enforcer_zone = enforcer_zone_new(enforcer_zone_list->connection))) {
			return NULL;
		}
	}
	if (enforcer_zone_from_result(enforcer_zone_list->enforcer_zone, enforcer_zone_list->result)) {
		return NULL;
	}
	return enforcer_zone_list->enforcer_zone;
}

const enforcer_zone_t* enforcer_zone_list_next(enforcer_zone_list_t* enforcer_zone_list) {
	if (!enforcer_zone_list) {
		return 1;
	}
	if (!enforcer_zone_list->result) {
		return 1;
	}

	if (!(enforcer_zone_list->result = db_result_next(enforcer_zone_list->result))) {
		return NULL;
	}
	if (!enforcer_zone_list->enforcer_zone) {
		if (!(enforcer_zone_list->enforcer_zone = enforcer_zone_new(enforcer_zone_list->connection))) {
			return NULL;
		}
	}
	if (enforcer_zone_from_result(enforcer_zone_list->enforcer_zone, enforcer_zone_list->result)) {
		return NULL;
	}
	return enforcer_zone_list->enforcer_zone;
}
