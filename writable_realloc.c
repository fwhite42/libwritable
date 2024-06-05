#include<stdlib.h>
#include"libwritable-types.h"

char	*writable_realloc(t_writable *self)
{
	size_t	old_capacity;
	char	*old_buffer;
	size_t	new_capacity;
	char	*new_buffer;

	old_capacity = self->dst.buf->capacity;
	old_buffer = self->dst.buf->buffer;
	new_capacity = old_capacity * 2;
	new_buffer = malloc(new_capacity);
	if (!new_buffer)
		return (NULL);
	self->dst.buf->capacity = new_capacity;
	while (new_capacity--)
		new_buffer[new_capacity] = 0;
	while (old_capacity--)
		new_buffer[old_capacity] = old_buffer[old_capacity];
	self->dst.buf->buffer = new_buffer;
	return (old_buffer);
}
