/* Test de ft_strlen : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	*s[] = {"", "a", "hello world", "\200\377", NULL};

	for (int k = 0; s[k]; k++)
		CHECK(ft_strlen(s[k]) == strlen(s[k]), "\"%s\" -> %zu", s[k], ft_strlen(s[k]));
	return (done("ft_strlen"));
}
