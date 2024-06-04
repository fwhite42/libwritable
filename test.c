#include"writable.h"
#include<stdlib.h>

int	main()
{
	t_writable 	string;
	t_writable	output;
	char		*buffer;

	buffer = malloc(32);
	writable_init(&string, buffer, 32);
	writable_init(&output, NULL, 1);
	writable_writestr(&output, string.buffer_start);
	return (true);
}
