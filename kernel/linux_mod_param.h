/*-
 * Copyright (c) 201 Hans Petter Selasky. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _LINUX_MOD_PARAM_H_
#define	_LINUX_MOD_PARAM_H_

struct mod_param;

struct mod_param {
	TAILQ_ENTRY(mod_param) entry;
	const char *name;
	const char *type;
	void   *ptr;
	uint16_t size;
	uint16_t perm;
};

#define	module_param_string(id, var, _size, _perm)	\
static void mod_param_##id##_init(void)			\
{							\
  static struct mod_param param = {			\
    .name = CURR_FILE_NAME "." #id,			\
    .ptr = &(var),					\
    .size = (_size),					\
    .type = "string",					\
    .perm = (_perm),					\
  };							\
  mod_param_register(&param);			        \
}							\
module_init(mod_param_##id##_init)

#define	module_param_named(id, var, _type, _perm)	\
static void mod_param_##id##_init(void)			\
{							\
  static struct mod_param param = {			\
    .name = CURR_FILE_NAME "." #id,			\
    .ptr = &(var),					\
    .size = sizeof(var),				\
    .type = #_type,					\
    .perm = (_perm),					\
  };							\
  mod_param_register(&param);				\
}							\
module_init(mod_param_##id##_init)

#define	module_param(name, type, perm)	\
    module_param_named(name, name, type, perm)

int	mod_set_param(const char *name, const char *value);
void	mod_show_params(void);
void	mod_param_register(struct mod_param *p);

#endif					/* _LINUX_MOD_PARAM_H_ */
