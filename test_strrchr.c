/* Test de ft_strrchr : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	*s[] = {"", "a", "hello world", "\200\377abc", NULL};

	for (int k = 0; s[k]; k++)
	{
		for (int c = 0; c < 256; c++)
			CHECK(ft_strrchr(s[k], c) == strrchr(s[k], c), "(\"%s\", %d)", s[k], c);
		CHECK(ft_strrchr(s[k], 'l' + 256) == strrchr(s[k], 'l' + 256), "(\"%s\", 'l' + 256)", s[k]);
	}
	return (done("ft_strrchr"));
}
