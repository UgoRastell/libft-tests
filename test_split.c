/* Test de ft_split : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	SPLIT(ft_split("  hello world  42 ", ' '), "hello", "world", "42", NULL);
	SPLIT(ft_split("hello", ' '), "hello", NULL);
	SPLIT(ft_split("", ' '), NULL);
	SPLIT(ft_split(",,,,", ','), NULL);
	SPLIT(ft_split("a,b,,c,", ','), "a", "b", "c", NULL);
	SPLIT(ft_split("a b", '\0'), "a b", NULL);
	return (done("ft_split"));
}
