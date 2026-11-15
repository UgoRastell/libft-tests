/* Test de ft_lstdelone : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*n;
	t_list	*next;

	n = ft_lstnew(strdup("x"));
	next = ft_lstnew(strdup("y"));
	n->next = next;
	g_freed = 0;
	ft_lstdelone(n, count_free);
	CHECK(g_freed == 1, "del appele %d fois au lieu de 1", g_freed);
	CHECK(!strcmp(next->content, "y"), "le noeud suivant ne doit pas etre libere");
	ft_lstdelone(next, free);
	return (done("ft_lstdelone"));
}
