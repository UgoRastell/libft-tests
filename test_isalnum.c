/* Test de ft_isalnum : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	for (int c = -1; c <= 255; c++)
		CHECK(ft_isalnum(c) == B(isalnum(c)), "c = %d -> %d au lieu de %d", c, ft_isalnum(c), B(isalnum(c)));
	return (done("ft_isalnum"));
}
