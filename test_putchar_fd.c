/* Test de ft_putchar_fd : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	OUT(ft_putchar_fd('a', fd), "a");
	OUT(ft_putchar_fd('\n', fd), "\n");
	return (done("ft_putchar_fd"));
}
