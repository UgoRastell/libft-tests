/* Test de ft_toupper : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	for (int c = -1; c <= 255; c++)
		CHECK(ft_toupper(c) == toupper(c), "c = %d -> %d au lieu de %d", c, ft_toupper(c), toupper(c));
	return (done("ft_toupper"));
}
