#include"libwritable-core.h"
#include<stdlib.h>

bool	writable_realloc_and_free(t_writable *self)
{
	char	*old_buffer;

	old_buffer = writable_realloc(self);
	free(old_buffer);
	return (true);
}
