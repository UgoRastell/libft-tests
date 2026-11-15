/* Test de ft_isdigit : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	for (int c = -1; c <= 255; c++)
		CHECK(ft_isdigit(c) == B(isdigit(c)), "c = %d -> %d au lieu de %d", c, ft_isdigit(c), B(isdigit(c)));
	return (done("ft_isdigit"));
}
