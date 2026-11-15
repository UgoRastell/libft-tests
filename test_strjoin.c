/* Test de ft_strjoin : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	*r;

	STR(ft_strjoin("ab", "cd"), "abcd");
	STR(ft_strjoin("", "cd"), "cd");
	STR(ft_strjoin("ab", ""), "ab");
	STR(ft_strjoin("", ""), "");
	return (done("ft_strjoin"));
}
