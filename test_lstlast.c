/* Test de ft_lstlast : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*l;

	l = make_list(3);
	CHECK(ft_lstlast(NULL) == NULL, "NULL");
	CHECK(ft_lstlast(l) == l->next->next, "3 noeuds");
	CHECK(ft_lstlast(l->next->next) == l->next->next, "1 noeud");
	ft_lstclear(&l, free);
	return (done("ft_lstlast"));
}
