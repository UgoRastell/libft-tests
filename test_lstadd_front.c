/* Test de ft_lstadd_front : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*l;

	l = NULL;
	ft_lstadd_front(&l, ft_lstnew("b"));
	ft_lstadd_front(&l, ft_lstnew("a"));
	CHECK(!strcmp(l->content, "a") && !strcmp(l->next->content, "b")
		&& l->next->next == NULL, "ordre a -> b");
	ft_lstclear(&l, nothing);
	return (done("ft_lstadd_front"));
}
