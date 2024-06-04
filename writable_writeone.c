#include"libwritable.h"
#include"unistd.h"

bool	writable_writeone(t_writable *self, char c)
{
	size_t	current_size;

	current_size = self->dst.buffer - self->buffer_start;
	if (self->is_buffer)
	{
		if (!(current_size > self->buffer_capacity))
		{
			writable_realloc_and_free(self);
		}
		*(self->dst.buffer) = c;
		self->dst.buffer++;
	}
	else
	{
		if (write(self->dst.fd, &c, 1) != 1)
			return (false);
	}
	return (true);
}
