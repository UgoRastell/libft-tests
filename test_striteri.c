/* Test de ft_striteri : compare avec la libc ou avec le resultat attendu. */
#include "tests.h"


int	main(void)
{
	char	s[] = "abc";
	char	e[] = "";

	ft_striteri(s, star_second);
	CHECK(!strcmp(s, "a*c"), "\"abc\" -> \"%s\" au lieu de \"a*c\"", s);
	ft_striteri(e, star_second);
	CHECK(e[0] == '\0', "chaine vide");
	return (done("ft_striteri"));
}
