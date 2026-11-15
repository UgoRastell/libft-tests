# libft-tests

Tests de ma [libft](https://github.com/UgoRastell/libft), un fichier par fonction
(`test_<fonction>.c`). Ils comparent chaque fonction à la vraie libc quand elle existe,
sinon au résultat attendu par le sujet.

Ce dépôt est **séparé du rendu** : le sujet interdit de rendre des fichiers inutilisés.

## Utilisation

Le dossier doit être **à côté** de la libft :

```sh
git clone https://github.com/UgoRastell/libft.git       libft
git clone https://github.com/UgoRastell/libft-tests.git libft-tests
cd libft-tests
make run            # toutes les fonctions, puis un bilan
make run-split      # une seule fonction (test_split.c)
make clean
```

Il faut `libbsd` pour comparer `strlcpy`, `strlcat` et `strnstr` à l'original
(`sudo pacman -S libbsd` / `sudo apt install libbsd-dev`).

Les tests sont compilés avec **AddressSanitizer et UBSan** : un débordement, une fuite
ou un comportement indéfini arrête le test et affiche la ligne fautive.

Un cas qui échoue affiche la ligne et les valeurs :

```
  KO l.11 : 3 noeuds
✗ ft_lstlast : 1/3 KO
```

## Ajouter un test

`tests.h` contient les outils :

| Outil | Rôle |
|---|---|
| `CHECK(cond, "message", ...)` | Vérifie une condition ; le message est au format `printf`. |
| `STR(appel, "attendu")` | Compare une chaîne allouée au résultat attendu, puis la libère. |
| `SPLIT(appel, "mot1", ..., NULL)` | Compare le tableau de `ft_split`, puis libère tout. |
| `OUT(appel, "attendu")` | Capture ce que l'appel écrit sur `fd` (fonctions `put*_fd`). |
| `SIGN(x)` | Ramène un résultat de `strncmp`/`memcmp` à -1, 0 ou 1. |
| `return (done("ft_xxx"));` | Affiche le bilan à la fin du `main`. |

Dans VS Code, **F5** sur un `ft_xxx.c` de la libft lance `test_xxx.c` dans le débogueur.
