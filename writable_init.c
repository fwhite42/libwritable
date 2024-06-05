#include"libwritable-types.h"
#include<stdlib.h>
#include<unistd.h>

static inline void	error_oom()
{
	write(2, "Error: Out of memory calling writable_init", 42);
	exit(-42);
}

static inline void	*safe_malloc(size_t buf_size)
{
	void	*ptr;

	ptr = malloc(buf_size);
	if (!ptr)
		error_oom();
	return (ptr);
}

void	writable_init(t_writable *self, char *buffer, size_t fd)
{
	size_t	buffer_size;
	size_t	i;

	buffer_size = fd;
	self->blen = 0;
	if (buffer && buffer_size)
	{
		self->isbuf = true;
		self->dst.buf->buffer = buffer;
		self->dst.buf->requires_free_after_use = false;
		self->dst.buf->offset = 0;
		self->dst.buf->capacity = buffer_size;
	}
	else if (buffer == (void *)1 && !buffer_size)
	{
		self->isbuf = true;
		self->dst.buf->buffer = malloc(32);
		self->dst.buf->requires_free_after_use = true;
		self->dst.buf->offset = 0;
		self->dst.buf->capacity = 32;
		i = 0;
		while (i < 32)
			self->dst.buf->buffer[i++] = 0;

	}
	else if (!buffer && fd > 0)
	{
		self->isbuf = false;
		self->dst.fd = fd;
	}
}
