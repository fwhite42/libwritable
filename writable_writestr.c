#include"libwritable.h"

bool	writable_writestr(t_writable *self, char *str)
{
	while (*str)
	{
		writable_writeone(self, *(str++));
	}
	return (true);
}
