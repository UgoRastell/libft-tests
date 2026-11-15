/* Test de ft_lstsize : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*l;

	l = make_list(3);
	CHECK(ft_lstsize(NULL) == 0, "NULL");
	CHECK(ft_lstsize(l) == 3, "3 noeuds -> %u", ft_lstsize(l));
	ft_lstclear(&l, free);
	return (done("ft_lstsize"));
}
