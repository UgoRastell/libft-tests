/* Test de ft_lstmap : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*l;
	t_list	*m;

	l = make_list(3);
	m = ft_lstmap(l, dup_upper, free);
	CHECK(m && m != l && ft_lstsize(m) == 3, "3 noeuds");
	CHECK(m && !strcmp(m->content, "A") && !strcmp(m->next->next->content, "C"),
		"contenus transformes");
	CHECK(m && m->content != l->content, "nouveaux contenus");
	CHECK(!strcmp(l->content, "a"), "la liste d'origine ne change pas");
	CHECK(ft_lstmap(NULL, dup_upper, free) == NULL, "NULL");
	ft_lstclear(&m, free);
	ft_lstclear(&l, free);
	return (done("ft_lstmap"));
}
