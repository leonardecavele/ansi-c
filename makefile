# Listes les noms de fichiers sans l'extension .c

SRC = $(wildcard $(SRC_DIR)/*.c)
FILES = $(notdir $(basename $(SRC)))

# Dossier où sont les fichiers source
SRC_DIR = chapter-1

# Suffixes automatiques
EXE = $(addprefix $(SRC_DIR)/, $(FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(EXE)

# Compilation de chaque exécutable
$(SRC_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(EXE)

re: clean all

