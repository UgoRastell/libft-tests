/* Test de ft_lstnew : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	t_list	*n;

	n = ft_lstnew("x");
	CHECK(n && !strcmp(n->content, "x") && n->next == NULL, "content et next");
	free(n);
	n = ft_lstnew(NULL);
	CHECK(n && n->content == NULL, "content NULL");
	free(n);
	return (done("ft_lstnew"));
}
