/* Test de ft_atoi : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	const char	*s[] = {"42", "   -42", "\t\n\v\f\r +7x", "+-5", "--5",
		"-+5", "2147483647", "-2147483648", "", "abc", "  0012", "- 3", NULL};

	for (int k = 0; s[k]; k++)
		CHECK(ft_atoi(s[k]) == atoi(s[k]), "\"%s\" -> %d au lieu de %d",
			s[k], ft_atoi(s[k]), atoi(s[k]));
	return (done("ft_atoi"));
}
