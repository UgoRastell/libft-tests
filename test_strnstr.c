/* Test de ft_strnstr : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <bsd/string.h>


int	main(void)
{
	const char	*big = "lorem ipsum dolor sit";
	const char	*lit[] = {"", "lorem", "ipsum", "dolor", "sit", "sitx", "z", NULL};

	for (int k = 0; lit[k]; k++)
		for (size_t n = 0; n < 25; n++)
			CHECK(ft_strnstr(big, lit[k], n) == strnstr(big, lit[k], n),
				"(\"%s\", \"%s\", %zu)", big, lit[k], n);
	return (done("ft_strnstr"));
}
