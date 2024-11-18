# Nome do executável
TARGET = corrida

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -pthread

# Arquivos de origem e cabeçalho
SRCS = main.c corrida.c
HEADERS = corrida.h

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Regra padrão para compilar o programa
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar arquivos .c em .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para compilar e limpar ao mesmo tempo
rebuild: clean $(TARGET)
