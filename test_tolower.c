/* Test de ft_tolower : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	for (int c = -1; c <= 255; c++)
		CHECK(ft_tolower(c) == tolower(c), "c = %d -> %d au lieu de %d", c, ft_tolower(c), tolower(c));
	return (done("ft_tolower"));
}
