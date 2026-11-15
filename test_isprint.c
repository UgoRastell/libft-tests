/* Test de ft_isprint : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	for (int c = -1; c <= 255; c++)
		CHECK(ft_isprint(c) == B(isprint(c)), "c = %d -> %d au lieu de %d", c, ft_isprint(c), B(isprint(c)));
	return (done("ft_isprint"));
}
