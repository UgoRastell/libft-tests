/* Test de ft_memmove : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	a[] = "0123456789";
	char	b[] = "0123456789";

	ft_memmove(a + 2, a, 5);
	memmove(b + 2, b, 5);
	CHECK(!strcmp(a, b), "dest apres src : %s au lieu de %s", a, b);
	ft_memmove(a, a + 3, 5);
	memmove(b, b + 3, 5);
	CHECK(!strcmp(a, b), "dest avant src : %s au lieu de %s", a, b);
	CHECK(ft_memmove(a, a, 4) == a, "doit renvoyer dest");
	CHECK(ft_memmove(NULL, NULL, 5) == NULL, "NULL, NULL");
	return (done("ft_memmove"));
}
