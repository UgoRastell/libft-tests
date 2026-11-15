/* Test de ft_putnbr_fd : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"
#include <limits.h>


int	main(void)
{
	OUT(ft_putnbr_fd(0, fd), "0");
	OUT(ft_putnbr_fd(7, fd), "7");
	OUT(ft_putnbr_fd(-7, fd), "-7");
	OUT(ft_putnbr_fd(42, fd), "42");
	OUT(ft_putnbr_fd(INT_MAX, fd), "2147483647");
	OUT(ft_putnbr_fd(INT_MIN, fd), "-2147483648");
	return (done("ft_putnbr_fd"));
}
