/*
	Programa: Simplifica-Fracción
	Programador: Ángel Guerrero
	Descripción del programa:
	Se requiere un programa que dada una fracción se calcule y muestre
	la expresión máxima de la misma. 

	Fecha de modificación: 9 de Marzo de 2016
*/
#include <stdio.h>
#include <string.h>
#include <Windows.h>

/* Definiciones */
#define MAX_STRLEN 50

/* Variables globales */
char cadena[MAX_STRLEN] = { '\0' };
char cad_num[MAX_STRLEN] = { '\0' };
char cad_den[MAX_STRLEN] = { '\0' };
int numerador, denominador;
int divisor = 2;

int aprovado = 1;
int i;

char opcion = ' ';

/*Utilizados para los acentos*/
char A = 181;
char a = 160;
char e = 130;
char iacen = 161;
char o = 162;
char u = 163;

/*Función prototipo*/
void aprovar_datos();
void calcularFraccion(int num, int den);


/* función principal */
main()
{
	/* Pide y guarda los datos del usuario en el array cadena y verifica la entrada */
	do
	{
		system("cls");
		printf("\n\t\tPrograma que simplifica la expresi%cn m%cnima de una fracci%cn\n\n", o, iacen, o);
		printf("Ingresa la operacion de la forma \" 20/10 \" sin las comillas\n: ");
		scanf("%s", &cadena);

		printf("\n\tExpresi%cn original: [ %s ]\n",o, cadena);
		aprovar_datos();

	} while (aprovado);

	/* Hace un conteo de las posiciones, para copiar los caracteres que están antes del signo '/' y después del signo */
	i = 0;
	int contador = 0;
	int num_elementos = 0;
	while (cadena[i])
	{
		if ((int)cadena[i] == 47)
		{
			contador = i;
		}
		if (cadena[i] != 0)
		{
			num_elementos++;
		}
		i++;
	}

	/* Copia los caracteres que están antes del signo '/', para la cad_num, que le corresponde el numerador */
	for (int i = 0; i < contador; i++)
	{
		cad_num[i] = cadena[i];
	}

	/* Copia los caracteres que están después del signo '/', para la cad_den, que le corresponde al denominador */
	for (int i = contador + 1, j = 0; i < num_elementos; i++, j++)
	{
		cad_den[j] = cadena[i];
	}


	/* Convirtiendo los datos de entrada a enteros */
	numerador = atoi(cad_num);
	denominador = atoi(cad_den);

	/* Manda los datos a una función */
	calcularFraccion(numerador, denominador);

	fflush(stdin); getchar();
	getchar();
}


/*Cuerpo de Funciones*/
void calcularFraccion(int num, int den)
{
	if (num % divisor == 0 && den % divisor == 0)
	{
		num /= divisor;
		den /= divisor;
		printf("\t\t\t    [ %i / %i ]\n", num, den);
		calcularFraccion(num, den);
	}
	else
	{
		if (divisor >= num || divisor >= den || num <= 0 || den <= 0)
		{
			printf("\nLa m%cnima expresi%cn es: ",iacen,o);
			printf("[ %i / %i ]\n", num, den);
		}
		else
		{
			divisor++;
			calcularFraccion(num, den);
		}
	}
}

void aprovar_datos()
{
	/* Función que verifica que los datos ingresados sean números y el signo '/' únicamente */
	i = 0;
	while (cadena[i])
	{
		if (!isdigit(cadena[i]) && cadena[i] != '/')
		{
			printf("\n\t\tEl formato: \"%c\" no es un formato aceptable\n", cadena[i]);
			system("pause");
			aprovado = 1;
			break;
		}
		else
		{
			aprovado = 0;
		}
		i++;
	}
}