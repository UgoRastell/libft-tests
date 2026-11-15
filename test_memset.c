/* Test de ft_memset : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	a[32];
	char	b[32];

	memset(a, 'x', 32);
	memset(b, 'x', 32);
	CHECK(ft_memset(a, 'A', 10) == a, "doit renvoyer le pointeur");
	memset(b, 'A', 10);
	CHECK(!memcmp(a, b, 32), "10 x 'A'");
	ft_memset(a, 300, 5);
	memset(b, 300, 5);
	CHECK(!memcmp(a, b, 32), "valeur 300 -> (unsigned char)44");
	ft_memset(a, 'z', 0);
	CHECK(!memcmp(a, b, 32), "n = 0 ne change rien");
	return (done("ft_memset"));
}
