/* Test de ft_lstclear : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*l;

	l = make_list(3);
	g_freed = 0;
	ft_lstclear(&l, count_free);
	CHECK(l == NULL, "le pointeur doit valoir NULL");
	CHECK(g_freed == 3, "del appele %d fois au lieu de 3", g_freed);
	ft_lstclear(&l, count_free);
	CHECK(g_freed == 3, "liste vide");
	return (done("ft_lstclear"));
}
