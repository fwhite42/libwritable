#include"libwritable-core.h"
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

bool	writable_writeone(t_writable *self, char c)
{
	if (self->isbuf)
	{
		if (self->dst.buf->offset >= self->dst.buf->capacity)
		{
			if (self->dst.buf->requires_free_after_use)
				free(writable_realloc(self));
			else
				writable_realloc(self);
		}
		self->dst.buf->buffer[self->dst.buf->offset] = c;
		self->dst.buf->offset++;
	}
	else
	{
		if (write(self->dst.fd, &c, 1) != 1)
			return (false);
	}
	self->blen++;
	return (true);
}
