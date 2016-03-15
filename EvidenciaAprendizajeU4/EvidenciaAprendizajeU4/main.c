/*
	Programa: Simplifica-Fracci�n
	Programador: �ngel Guerrero
	Descripci�n del programa:
	Se requiere un programa que dada una fracci�n se calcule y muestre
	la expresi�n m�xima de la misma. 

	Fecha de modificaci�n: 14 de Marzo de 2016

	Versi�n del programa: En esta versi�n del programa se implementan principalmente los arreglos y las estructuras
	donde se encuentran implementadas los arreglos es en la lectura de datos del usuario, los datos se guarda en una
	cadena de caracteres en donde despu�s se compara si ha ingresado �nicamente n�meros. 

	Despu�s se calculan los datos, "empaquet�ndolos" en una estructura.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Definiciones */
#define MAX_STRLEN 50

/* Variables globales */
char opcion = ' ';
static int divisor = 2;

/*Utilizados para los acentos*/
char A = 181;
char a = 160;
char e = 130;
char iacen = 161;
char o = 162;
char u = 163;

/* funci�n principal */
main()
{
	do
	{
		divisor = 2;

		/* Variables locales */
		int numerador = 0;
		int denominador = 0;

		/* Pide y guarda los datos del usuario en el array cadena y verifica la entrada */
		system("cls");
		printf("\n\t\tPrograma que simplifica la expresi%cn m%cnima de una fracci%cn\n\n", o, iacen, o);
		printf("Ingresa la operacion de la forma \" 20 10 \" sin las comillas\n: ");
		scanf("%d %d", &numerador, &denominador);
		printf("\n\tExpresi%cn original: [ %d / %d ]\n", o, numerador, denominador);
			
		
		/* Hace el proceso de divisi�n */
		for (;;)
		{
			if (numerador % divisor == 0 && denominador % divisor == 0)
			{
				if (numerador >= 0 || denominador >= 0)
				{
					numerador /= divisor;
					denominador /= divisor;
					divisor = 2;
					printf("Expresi%cn reducida: [ %i / %i ]\n", o, numerador, denominador);
				}
				else
				{
					/* Termina el bucle */
					break;
				}
			}
			else
			{
				if (divisor < numerador && divisor < denominador)
				{
					divisor++;
				}
				else
				{
					/* Termina el bucle*/
					break;
				}
			}
		}
		printf("\nLa M%cnima expresi%cn es: [ %i / %i ]\n", iacen, o, numerador, denominador);



		system("pause");
		printf("\nDeseas volver a calcular [s / n]: ");
		for (;;)
		{
			if (_kbhit())
			{
				char k = _getch();
				fflush(stdin);
				if (k == 's' || k == 'S')
				{
					main();
					break;
				}
				else if (k == 'n' || k == 'N')
				{
					exit(0);
				}
			}
		}
	} while (opcion == 's' || opcion == 'S');	
}
