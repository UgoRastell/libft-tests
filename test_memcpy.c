/* Test de ft_memcpy : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	a[16];

	memset(a, 'x', 16);
	CHECK(ft_memcpy(a, "abcdef", 6) == a, "doit renvoyer dest");
	CHECK(!memcmp(a, "abcdefxx", 8), "copie 6 octets, pas plus");
	CHECK(ft_memcpy(a, "zz", 0) == a && a[0] == 'a', "n = 0");
	CHECK(ft_memcpy(NULL, NULL, 3) == NULL, "NULL, NULL");
	return (done("ft_memcpy"));
}
