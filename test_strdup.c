/* Test de ft_strdup : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	*s[] = {"", "a", "hello world", NULL};
	char		*d;

	for (int k = 0; s[k]; k++)
	{
		d = ft_strdup(s[k]);
		CHECK(d && d != s[k] && !strcmp(d, s[k]), "\"%s\"", s[k]);
		free(d);
	}
	return (done("ft_strdup"));
}
