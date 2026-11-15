/* Test de ft_calloc : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <stdint.h>


int	main(void)
{
	int		*p;
	int		ok;

	p = ft_calloc(10, sizeof(int));
	ok = p != NULL;
	for (int i = 0; ok && i < 10; i++)
		ok = p[i] == 0;
	CHECK(ok, "10 int a zero");
	free(p);
	p = ft_calloc(0, 0);
	CHECK(p != NULL, "calloc(0, 0) doit renvoyer un pointeur liberable");
	free(p);
	CHECK(ft_calloc(SIZE_MAX, 2) == NULL, "SIZE_MAX * 2 deborde : doit renvoyer NULL");
	return (done("ft_calloc"));
}
