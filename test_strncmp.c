/* Test de ft_strncmp : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	*a[] = {"abc", "abd", "", "ab", "\200", "abc", "test\0x"};
	const char	*b[] = {"abc", "abc", "a", "abc", "\0", "abcd", "test\0y"};

	for (int k = 0; k < 7; k++)
		for (size_t n = 0; n < 8; n++)
			CHECK(SIGN(ft_strncmp(a[k], b[k], n)) == SIGN(strncmp(a[k], b[k], n)),
				"(\"%s\", \"%s\", %zu)", a[k], b[k], n);
	return (done("ft_strncmp"));
}
