#include"writable.h"

bool	writable_writeull(t_writable *self, int offset, unsigned long long ull)
{
	unsigned char	digit;

	digit = ull % self->blen;
	if (ull != ull / self->blen)
		writable_writeull(self, offset++, ull / self->blen);
	writable_writeone(self, self->base[digit]);
	return (true);
}
