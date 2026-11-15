/* Test de ft_strmapi : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <ctype.h>


int	main(void)
{
	char	*r;

	STR(ft_strmapi("abcd", up_odd), "aBcD");
	STR(ft_strmapi("", up_odd), "");
	return (done("ft_strmapi"));
}
