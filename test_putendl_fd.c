/* Test de ft_putendl_fd : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	OUT(ft_putendl_fd("salut", fd), "salut\n");
	OUT(ft_putendl_fd("", fd), "\n");
	return (done("ft_putendl_fd"));
}
