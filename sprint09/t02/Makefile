INC=./inc
SRC=./src
OBJ=./obj
FUNCTIONS=mx_atoi mx_isdigit mx_isspace mx_printchar mx_printint mx_printstr mx_strcpy mx_strcmp mx_strlen
SRC_LIST=$(addprefix $(SRC)/,$(FUNCTIONS))
OBJ_LIST=$(addprefix $(OBJ)/, $(FUNCTIONS))

#all:

MINILIBMX:
	mkdir $(OBJ)
	gcc -c $(SRC)/mx_atoi.c -o $(OBJ)/mx_atoi.o
	gcc -c $(SRC)/mx_isdigit.c -o $(OBJ)/mx_isdigit.o
	gcc -c $(SRC)/mx_isspace.c -o $(OBJ)/mx_isspace.o
	gcc -c $(SRC)/mx_printchar.c -o $(OBJ)/mx_printchar.o
	gcc -c $(SRC)/mx_printint.c -o $(OBJ)/mx_printint.o
	gcc -c $(SRC)/mx_printstr.c -o $(OBJ)/mx_printstr.o
	gcc -c $(SRC)/mx_strcpy.c -o $(OBJ)/mx_strcpy.o
	gcc -c $(SRC)/mx_strcmp.c -o $(OBJ)/mx_strcmp.o
	gcc -c $(SRC)/mx_strlen.c -o $(OBJ)/mx_strlen.o

uninstal:
	rm -drf $(OBJ)

clean:
	

reinstal:

