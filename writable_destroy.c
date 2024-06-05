#include"libwritable-types.h"
#include<stdlib.h>

void	writable_destroy(t_writable *self)
{
	if (self->isbuf)
		free(self->dst.buf->buffer);
}
