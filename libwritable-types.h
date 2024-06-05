#ifndef WRITABLE_TYPES_H
# define WRITABLE_TYPES_H

# include<stdbool.h>
# include<stddef.h>

typedef struct s_writable	t_writable;
typedef union u_writable_dst	t_writable_dst;
typedef struct s_writable_buf	t_writable_buf;

struct s_writable_buf
{
	bool	requires_free_after_use;
	size_t	offset;
	size_t	capacity;
	char	*buffer;
};

union u_writable_dst
{
	int		fd;
	t_writable_buf	*buf;
};

struct s_writable
{
	bool		isbuf;
	t_writable_dst	dst;
	size_t		blen;
};

#endif
