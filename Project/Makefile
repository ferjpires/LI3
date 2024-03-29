CC = gcc
CFLAGS = -Wall `pkg-config --cflags --libs glib-2.0` -I./include -lncurses


# Lista de todos os arquivos fonte do programa principal
MAIN_SRC = main.c
MAIN_SRC += $(wildcard src/catalogs/*.c)
MAIN_SRC += $(wildcard src/entities/*.c)
MAIN_SRC += $(wildcard src/data_manager/*.c)
MAIN_SRC += $(wildcard src/program/*.c)
MAIN_SRC += $(wildcard src/queries/*.c)
MAIN_SRC += $(wildcard src/stats/*.c)
MAIN_SRC += $(wildcard src/utils/*.c)

# Lista de todos os arquivos fonte dos testes
TEST_SRC = $(wildcard tests/*.c)
TEST_SRC += $(wildcard src/tests/queries/*.c)
TEST_SRC += $(wildcard src/tests/test_struct/*.c)
TEST_SRC += $(wildcard src/**/*.c)

# Lista de todos os objetos gerados pelo programa principal
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Lista de todos os objetos gerados pelos testes
TEST_OBJ = $(TEST_SRC:.c=.o)

# Nome dos executáveis
MAIN_EXEC = programa-principal
TEST_EXEC = programa-testes

# Nome da pasta de resultados
RESULTS_DIR = Resultados

# Regra padrão, compila o programa principal
all: $(MAIN_EXEC) $(TEST_EXEC) $(RESULTS_DIR)

# Regra para compilar o programa principal
$(MAIN_EXEC): $(MAIN_OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

# Regra para compilar os testes
$(TEST_EXEC): $(TEST_OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

# Regra para criar a pasta de resultados
$(RESULTS_DIR):
	mkdir -p $(RESULTS_DIR)

# Regra para compilar os objetos do programa principal
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Regra para compilar os objetos dos testes
tests/%.o: tests/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Regra para limpar os arquivos gerados
clean:
	rm -rf $(MAIN_OBJ) $(TEST_OBJ) $(MAIN_EXEC) $(TEST_EXEC) $(RESULTS_DIR)

.PHONY: all clean
