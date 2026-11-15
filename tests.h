/* Outils communs aux tests : CHECK, comparaisons de chaines, capture d'un fd. */
#ifndef TESTS_H
# define TESTS_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

# define U __attribute__((unused))

static int	g_total U;
static int	g_fail U;
static int	g_freed U;

/* CHECK(condition, "message printf", ...) : affiche le cas qui echoue */
# define CHECK(cond, ...) do { g_total++; if (!(cond)) { g_fail++; \
	printf("  \033[31mKO\033[0m l.%d : ", __LINE__); printf(__VA_ARGS__); \
	printf("\n"); } } while (0)

/* SIGN : ramene un resultat de comparaison a -1, 0 ou 1 ; B : a 0 ou 1 */
# define SIGN(x) (((x) > 0) - ((x) < 0))
# define B(x) (!!(x))

/* STR(appel qui renvoie une chaine allouee, "attendu") : compare puis free */
# define STR(expr, want) do { r = (expr); CHECK(r && !strcmp(r, want), \
	"%s -> \"%s\" au lieu de \"%s\"", #expr, r ? r : "(NULL)", want); \
	free(r); } while (0)

/* OUT(appel qui ecrit sur fd, "attendu") : capture ce qui est ecrit */
# define OUT(expr, want) do { char out_[256]; FILE *f_ = tmpfile(); \
	int fd = fileno(f_); ssize_t n_; expr; lseek(fd, 0, SEEK_SET); \
	n_ = read(fd, out_, 255); out_[n_ < 0 ? 0 : n_] = '\0'; fclose(f_); \
	CHECK(!strcmp(out_, want), "%s ecrit \"%s\" au lieu de \"%s\"", \
	#expr, out_, want); } while (0)

/* SPLIT(appel, "mot1", "mot2", ..., NULL) : compare puis libere tout */
# define SPLIT(expr, ...) split_check((expr), (const char *[]){__VA_ARGS__}, \
	#expr, __LINE__)

static inline void	split_check(char **r, const char **want, const char *call,
	int line)
{
	int	i;
	int	ok;

	ok = r != NULL;
	for (i = 0; ok && want[i]; i++)
		ok = r[i] && !strcmp(r[i], want[i]);
	ok = ok && r[i] == NULL;
	g_total++;
	if (!ok)
	{
		g_fail++;
		printf("  \033[31mKO\033[0m l.%d : %s -> {", line, call);
		for (i = 0; r && r[i]; i++)
			printf("\"%s\", ", r[i]);
		printf("NULL}\n");
	}
	for (i = 0; r && r[i]; i++)
		free(r[i]);
	free(r);
}

/* Fonctions passees en parametre (strmapi, striteri, listes) */
static inline char	up_odd(unsigned int i, char c)
{
	if (i % 2 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static inline void	star_second(unsigned int i, char *c)
{
	if (i == 1)
		*c = '*';
}

static inline void	nothing(void *p)
{
	(void)p;
}

static inline void	count_free(void *p)
{
	g_freed++;
	free(p);
}

static inline void	inc_first(void *p)
{
	((char *)p)[0]++;
}

static inline void	*dup_upper(void *p)
{
	char	*s;

	s = strdup(p);
	if (s && s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
	return (s);
}

/* Liste "a" -> "b" -> "c"... de n noeuds, contenus alloues (liberer avec free) */
static inline t_list	*make_list(int n)
{
	t_list	*l;
	char	s[2];

	l = NULL;
	s[1] = '\0';
	while (n-- > 0)
	{
		s[0] = 'a' + n;
		ft_lstadd_front(&l, ft_lstnew(strdup(s)));
	}
	return (l);
}

/* A la fin du main : return (done("ft_xxx")); */
static inline int	done(const char *name)
{
	if (g_fail)
		printf("\033[31m✗ %s : %d/%d KO\033[0m\n", name, g_fail, g_total);
	else
		printf("\033[32m✓ %s : %d tests OK\033[0m\n", name, g_total);
	return (g_fail != 0);
}

#endif
