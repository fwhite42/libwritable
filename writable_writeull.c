#include"libwritable-core.h"
#include<stdio.h>

bool	writable_writeull(t_writable *self, char *base, unsigned long long nbr)
{
	unsigned char	digit;
	size_t		base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	digit = nbr % base_len;
	if (nbr != (nbr / base_len) &&  (nbr / base_len) != 0)
		writable_writeull(self, base, nbr / base_len);
	writable_writeone(self, base[digit]);
	return (true);
}
