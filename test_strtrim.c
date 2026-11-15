/* Test de ft_strtrim : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	*r;

	STR(ft_strtrim("  xxhixx ", " x"), "hi");
	STR(ft_strtrim("xxxx", "x"), "");
	STR(ft_strtrim("", "x"), "");
	STR(ft_strtrim("abc", ""), "abc");
	STR(ft_strtrim("a-b-a", "a"), "-b-");
	return (done("ft_strtrim"));
}
