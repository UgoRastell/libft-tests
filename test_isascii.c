/* Test de ft_isascii : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	for (int c = -1; c <= 255; c++)
		CHECK(ft_isascii(c) == B(isascii(c)), "c = %d -> %d au lieu de %d", c, ft_isascii(c), B(isascii(c)));
	return (done("ft_isascii"));
}
