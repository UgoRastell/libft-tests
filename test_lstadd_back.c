/* Test de ft_lstadd_back : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*l;

	l = NULL;
	ft_lstadd_back(&l, ft_lstnew("a"));
	CHECK(l && !strcmp(l->content, "a"), "liste vide");
	ft_lstadd_back(&l, ft_lstnew("b"));
	ft_lstadd_back(&l, ft_lstnew("c"));
	CHECK(!strcmp(l->next->content, "b") && !strcmp(l->next->next->content, "c")
		&& l->next->next->next == NULL, "ordre a -> b -> c");
	ft_lstclear(&l, nothing);
	return (done("ft_lstadd_back"));
}
