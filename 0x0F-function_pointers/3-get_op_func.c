#include "3-calc.h"
	#include <stdlib.h>
	/**
	 * get_op_func - Selects the correct function to perform
	 *               the operation asked by the user.
	 * @s: The operator passed as argument.
	 *
	 * Return: A pointer to the function corresponding
	 *         to the operator given as a parameter.
	 */
	int (*get_op_func(char *s))(int, int)
	{
		op_t ops[] = {
			{"+", op_add},
			{"-", op_sub},
			{"*", op_mul},
			{"/", op_div},
			{"%", op_mod},
			{NULL, NULL},
		};


		int i = 0;


		while (ops[i].op != NULL && *(ops[i].op) != *s)
			i++;


		return (ops[i].f);
	}


=======================================
3-main.c CODE


#include "function_pointers.h"
	#include <stdlib.h>
	#include <stdio.h>
	#include "3-calc.h"
	/**
	 * main - Prints the result of simple operations.
	 * @argc: The number of arguments supplied to the program.
	 * @argv: An array of pointers to the arguments.
	 *
	 * Return: Always 0.
	 */
	int main(int __attribute__((__unused__)) argc, char *argv[])
	{
		int num1, num2;
		char *op;


		if (argc != 4)
		{
			printf("Error\n");
			exit(98);
		}


		num1 = atoi(argv[1]);
		op = argv[2];
		num2 = atoi(argv[3]);


		if (get_op_func(op) == NULL || op[1] != '\0')
		{
			printf("Error\n");
			exit(99);
		}


		if ((*op == '/' && num2 == 0) ||
		    (*op == '%' && num2 == 0))
		{
			printf("Error\n");
			exit(100);
		}


		printf("%d\n", get_op_func(op)(num1, num2));


		return (0);
	}

