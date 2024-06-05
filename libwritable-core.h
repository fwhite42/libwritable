#ifndef WRITABLE_CORE_H
# define WRITABLE_CORE_H

# include"libwritable-types.h"

void	writable_init(t_writable *self, char *buffer, size_t fd);
bool	writable_writeone(t_writable *self, char c);
char	*writable_realloc(t_writable *self);

#endif
