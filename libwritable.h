#ifndef WRITABLE_H
# define WRITABLE_H

# include"libwritable-types.h"
# include"libwritable-core.h"

bool	writable_writemany(t_writable *self, char c, size_t reps);
bool	writable_writestr(t_writable *self, char *str);
bool	writable_writeull(t_writable *self, char *base, unsigned long long n);

#endif
