#include"libwritable.h"

void	writable_init(t_writable *self, char *buffer, size_t fd)
{
	self->bytes_written = 0;
	if (buffer)
	{
		self->is_buffer = true;
		self->dst.buffer = buffer;
		self->buffer_start = buffer;
		self->buffer_capacity = fd;
	}
	else if (fd > 0)
	{
		self->is_buffer = false;
		self->dst.fd = fd;
	}
}
