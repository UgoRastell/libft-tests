/* Test de ft_itoa : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <limits.h>


int	main(void)
{
	char	*r;

	STR(ft_itoa(0), "0");
	STR(ft_itoa(7), "7");
	STR(ft_itoa(-42), "-42");
	STR(ft_itoa(INT_MAX), "2147483647");
	STR(ft_itoa(INT_MIN), "-2147483648");
	return (done("ft_itoa"));
}
