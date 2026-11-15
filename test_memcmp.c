/* Test de ft_memcmp : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	a[][4] = {"abc", "abd", "", "\200", "a\0b", "a\0c"};
	const char	b[][4] = {"abc", "abc", "", "\0", "a\0c", "a\0b"};

	for (int k = 0; k < 6; k++)
		for (size_t n = 0; n < 4; n++)
			CHECK(SIGN(ft_memcmp(a[k], b[k], n)) == SIGN(memcmp(a[k], b[k], n)),
				"cas %d, n = %zu", k, n);
	return (done("ft_memcmp"));
}
