/* Test de ft_putstr_fd : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	OUT(ft_putstr_fd("salut 42", fd), "salut 42");
	OUT(ft_putstr_fd("", fd), "");
	return (done("ft_putstr_fd"));
}
