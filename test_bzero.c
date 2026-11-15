/* Test de ft_bzero : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	a[16];
	char	b[16];

	memset(a, 'x', 16);
	memset(b, 'x', 16);
	ft_bzero(a, 5);
	bzero(b, 5);
	CHECK(!memcmp(a, b, 16), "5 octets");
	ft_bzero(a, 0);
	CHECK(!memcmp(a, b, 16), "n = 0 ne change rien");
	return (done("ft_bzero"));
}
