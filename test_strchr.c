/* Test de ft_strchr : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	*s[] = {"", "a", "hello world", "\200\377abc", NULL};

	for (int k = 0; s[k]; k++)
	{
		for (int c = 0; c < 256; c++)
			CHECK(ft_strchr(s[k], c) == strchr(s[k], c), "(\"%s\", %d)", s[k], c);
		CHECK(ft_strchr(s[k], 'l' + 256) == strchr(s[k], 'l' + 256), "(\"%s\", 'l' + 256)", s[k]);
	}
	return (done("ft_strchr"));
}
