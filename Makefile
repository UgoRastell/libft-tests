# Tests perso de la libft — NE PAS RENDRE (hors du dépôt de rendu)
#
#   make            compile tous les test_*.c (recompile la libft si besoin)
#   make run        lance tous les tests
#   make run-strlen lance seulement test_strlen
#   make clean      supprime les binaires

LIBFT_DIR	:= ../libft
LIBFT		:= $(LIBFT_DIR)/libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address,undefined -I$(LIBFT_DIR)
LDLIBS		:= -L$(LIBFT_DIR) -lft -lbsd

SRCS		:= $(wildcard test_*.c)
BINS		:= $(SRCS:.c=)

all: $(BINS)

$(BINS): %: %.c tests.h $(LIBFT)
	@$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

$(LIBFT): FORCE
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR)

# Lance tout, même si une fonction est KO, puis affiche le bilan
run: all
	@ko=0; for b in $(BINS); do ./$$b || ko=$$((ko + 1)); done; \
	if [ $$ko -eq 0 ]; then \
		printf '\n\033[32mTout est OK (%d fonctions)\033[0m\n' $(words $(BINS)); \
	else \
		printf '\n\033[31m%d fonction(s) KO\033[0m\n' $$ko; exit 1; \
	fi

run-%: test_%
	./test_$*

clean:
	rm -f $(BINS)

FORCE:
.PHONY: all run clean FORCE
