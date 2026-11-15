/* Test de ft_strlcat : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <bsd/string.h>


int	main(void)
{
	const char	*src[] = {"", "hi", "hello world 42", NULL};
	char		x[32];
	char		y[32];

	for (int k = 0; src[k]; k++)
	{
		for (size_t sz = 0; sz < 20; sz++)
		{
			memset(x, 'x', 32);
			memset(y, 'x', 32);
			strcpy(x, "abc");
			strcpy(y, "abc");
			size_t r1 = ft_strlcat(x, src[k], sz);
			size_t r2 = strlcat(y, src[k], sz);
			CHECK(r1 == r2 && !memcmp(x, y, 32),
				"(\"abc\", \"%s\", %zu) -> %zu \"%s\" au lieu de %zu \"%s\"",
				src[k], sz, r1, x, r2, y);
		}
	}
	return (done("ft_strlcat"));
}
