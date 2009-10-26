/*
 * ruby_krb5_auth.c: Ruby bindings for Kerberos authentication
 *
 * Copyright (C) 2008 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 * Author: Chris Lalancette <clalance@redhat.com>
 */

#include <krb5.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int Krb5_get_init_creds_password_proxy(char* userString, int userSize, char* pwString, int pwSize);
char Krb5_get_init_creds_password(char* user, char* pass);
