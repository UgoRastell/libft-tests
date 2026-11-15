/* Test de ft_isalpha : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	for (int c = -1; c <= 255; c++)
		CHECK(ft_isalpha(c) == B(isalpha(c)), "c = %d -> %d au lieu de %d", c, ft_isalpha(c), B(isalpha(c)));
	return (done("ft_isalpha"));
}
