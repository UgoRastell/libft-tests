/* Test de ft_memchr : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	*s[] = {"", "a", "hello world", "\200\377abc", NULL};

	for (int k = 0; s[k]; k++)
		for (int c = 0; c < 256; c++)
			CHECK(ft_memchr(s[k], c, strlen(s[k]) + 1) == memchr(s[k], c, strlen(s[k]) + 1),
				"(\"%s\", %d)", s[k], c);
	CHECK(ft_memchr("abc", 'c', 2) == NULL, "n = 2 ne doit pas trouver 'c'");
	CHECK(ft_memchr("a\0b", 'b', 3) != NULL, "memchr ne s'arrete pas au \\0");
	return (done("ft_memchr"));
}
