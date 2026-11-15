/* Test de ft_substr : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	*r;

	STR(ft_substr("hello", 1, 3), "ell");
	STR(ft_substr("hello", 2, 100), "llo");
	STR(ft_substr("hello", 5, 2), "");
	STR(ft_substr("hello", 400, 2), "");
	STR(ft_substr("hello", 0, 0), "");
	STR(ft_substr("", 0, 5), "");
	return (done("ft_substr"));
}
