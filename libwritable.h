#ifndef WRITABLE_H
# define WRITABLE_

# include<stdbool.h>
# include<stddef.h>

typedef struct s_writable	t_writable;
typedef union u_writable_dst	t_writable_dst;

void	writable_init(t_writable *self, char *buffer, size_t fd);
char	*writable_realloc(t_writable *self);
bool	writable_realloc_and_free(t_writable *self);
bool	writable_writeone(t_writable *self, char c);
bool	writable_writemany(t_writable *self, char c, size_t reps);
bool	writable_writestr(t_writable *self, char *str);

union u_writable_dst
{
	int	fd;
	char	*buffer;
};

struct s_writable
{
	t_writable_dst	dst;
	bool		is_buffer;
	size_t		buffer_capacity;
	size_t		bytes_written;
	char		*buffer_start;
	bool		free_buffer;
};


#endif
