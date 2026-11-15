/* Test de ft_lstiter : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*l;

	l = make_list(3);
	ft_lstiter(l, inc_first);
	CHECK(!strcmp(l->content, "b") && !strcmp(l->next->next->content, "d"),
		"chaque contenu incremente");
	ft_lstclear(&l, free);
	return (done("ft_lstiter"));
}
