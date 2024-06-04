#include"libwritable.h"

char	*writable_realloc(t_writable *self)
{
	size_t	old_capacity;
	char	*old_buffer;
	size_t	new_capacity;
	char	*new_buffer;

	old_capacaity = self->buffer_capacity;
	old_buffer = self->dst.buffer;
	new_capacaity = old_capacity * 2;
	new_buffer = malloc(new_capacity);
	if (!new_buffer)
		return (NULL);
	while (new_capacity--)
		new_buffer[new_capacity] = 0;
	while (old_capacity--)
		new_buffer[old_capacity] = old_buffer[old_capacity];
	self->dst.buffer = new_buffer;
	return (old_buffer);
}
