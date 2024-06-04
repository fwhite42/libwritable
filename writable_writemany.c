#include"libwritable.h"

bool	writable_writemany(t_writable *self, char c, size_t reps)
{
	while (reps--)
	{
		if (!writable_writeone(self, c))
			return (false);
	}
	return (true);
}
