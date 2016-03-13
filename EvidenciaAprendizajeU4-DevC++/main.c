/*
Programa: Simplifica-Fracci?n
Programador: ?ngel Guerrero
Descripci?n del programa:
Se requiere un programa que dada una fracci?n se calcule y muestre
la expresi?n m?xima de la misma.

Fecha de modificaci?n: 12 de Marzo de 2016
*/
#include "rlutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>	/* rand()*/
#include <conio.h>

/* Definiciones */
#define MAX_STRLEN 10

/* Variables globales */
const char titulo[] = { "\n\t\tPrograma Simplificar Fraccion\n\n" };
static int divisor = 2;
char opcion = '\0';

/*Utilizados para los acentos*/
char A = 181;
char a = 160;
char e = 130;
char iacen = 161;
char o = 162;
char u = 163;

/* Declaraci?n de estructuras */
struct NumDen
{
	int numerador;
	int denominador;
};

/* Declaraci?n de funciones prototipos */
void simplificarFraccion(int numerador, int denominador);
struct NumDen ingresarDatos();
void demo();
void menuSalir();

/* funci?n principal */
main()
{
	struct NumDen Dato;

	/* Primero muestra el men?*/
	setColor(WHITE);
	setBackgroundColor(BLACK);
	cls();
	printf("%s", titulo);
	printf("a) Ayuda\
			\nb) Comenzar\
			\nc) Demo \
			\nd) Salir\n:");
	opcion = _getche();
	fflush(stdin);
	if (opcion == 'a' || opcion == 'A')
	{
		cls();
		printf("%s", titulo);
		printf("\n\nACERCA DE ESTE PROGRAMA: \n");
		printf("Este programa es un ejercicio escolar que ingresada una fracci%cn de la forma \"numerador/denominador\" "
			"muestra la m%cnima expresi%cn de la misma. \n", o, iacen,o);
		printf(
			"\n\nFALLOS:\n\n"
			"-Este programa presenta fallos de desbordamiento, no es posible leer cifras demasiado largas\n"
			"-Si se ingresa un unico numero, hace la division entre dos");
		printf("\n\nAUTOR:\n"
			"Luis %cngel De Santiago Guerrero\n"
			"Matricula: ES1611300455\n"
			"Universidad Abierta y a Distancia de M%cxico\n\n", A,e);
		system("pause");
		main();
	}
	else if (opcion == 'b' || opcion == 'B')
	{
		Dato = ingresarDatos();
	}
	else if (opcion == 'c' || opcion == 'C')
	{
		 demo();
	}
	else if (opcion == 'd' || opcion == 'D')
	{
		exit(0);
	}
	else
	{
		printf("\nIngresa una opcion correcta\n");
		system("pause");
		main();
	}

	/* Manda los datos empaquetados a la funci?n que hace la simplificac?n */
	simplificarFraccion(Dato.numerador, Dato.denominador);

	/* Va al menuSalir, para saber qu? es lo que el usuario quiere hacer*/
	/* Bucle en el que no sale si no se ingresa la opci?n correcta */
	menuSalir();
}

/* Cuerpos de las funciones */

	/* estructura como funci?n */
struct NumDen ingresarDatos()
{
	char cad_numerador[MAX_STRLEN] = { '\0' };
	char cad_denominador[MAX_STRLEN] = { '\0' };
	char datosIngresados[MAX_STRLEN] = { '\0' };
	int datosAprovados = 0; /* Ok = 0 */

	/* Pide los datos del usuario */
	do
	{	
		datosAprovados = 0;
		/* Limpia los datos de entrada si es que se han introducido incorrectamente */
		for (int i = 0; i < strlen(datosIngresados); i++) datosIngresados[i] = 0;

		cls();
		printf("%s", titulo);
		printf("Ingresa la expresi%cn de la forma: \" numerador / denominador \"\n:",o);
		gets(datosIngresados);

		/* Verifica primero que en la entrada de datosIngresados no haya m?s que digitos */
		for (int i = 0; i < strlen(datosIngresados); i++)
		{
			/* Filtra ?nicamente los "datos" */
			if (datosIngresados[i] != 0)
			{
				/* Si encuentra por lo menos un dato que NO sea d?gito, entonces no se aprueva la entrada */
				if (!isdigit(datosIngresados[i]) && datosIngresados[i] != '/')
				{
					datosAprovados = 1;
					printf("\n\t\tEl formato de entrada \"%s\", no es correcto", datosIngresados);
					system("pause");
					break;
				}
			}
		}
	} while (datosAprovados);

	/* Toma los n?meros que se localizan antes del / y despu?s del mismo signo */
	int posicion = 0;	/* variable que toma la posici?n que tiene el signo '/' para copiar el denomiandor */
	for (int i = 0; i < strlen(datosIngresados); i++)
	{
		/* Copia los n?meros hasta que se encuentra el signo '/' */
		if (datosIngresados[i] != '/')
		{
			cad_numerador[i] = datosIngresados[i];
			posicion++;
		}
		else
		{
			break;
		}
	}

	/* Copia los n?meros que se encuentran despu?s del signo '/' */
	posicion += 1;
	for (int i = 0; posicion < strlen(datosIngresados); i++, posicion++)
	{
		if (datosIngresados[posicion] != 0)
		{
			cad_denominador[i] = datosIngresados[posicion];
		}
	}
	
	/* Convierte los datos ingresados a enteros, los empaqueta y los retorna */
	struct NumDen DatosEmpaquetados;
	DatosEmpaquetados.numerador = atoi(cad_numerador);
	DatosEmpaquetados.denominador = atoi(cad_denominador);

	return DatosEmpaquetados;
}

void simplificarFraccion(int numerador,int denominador)
{
	divisor = 2;

	/* Hace el proceso de divisi?n */
	for (;;)
	{
		if (numerador % divisor == 0 && denominador % divisor == 0)
		{
			if (numerador >= 0 || denominador >= 0)
			{
				numerador /= divisor;
				denominador /= divisor;
				divisor = 2;
				printf("Expresi%cn reducida: [ %i / %i ]\n", 162, numerador, denominador);
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
}

void demo()
{
	/* Busca un n?mero al azar para calcular */
	srand(time(NULL));
	int ran_numerador = rand() % 100000;
	int ran_denominador = rand() % 100000;

	cls();
	printf("%s", titulo);
	printf("Generando n%cmero al azar...", u);
	Sleep(500);
	printf("\n\nFracci%cn elegida: [%d / %d]\n", o, ran_numerador, ran_denominador);

	simplificarFraccion(ran_numerador, ran_denominador);
	system("pause");
	main();
}

void menuSalir()
{
	char c = '\0';
	char leerComando[] = { '\0' };
	int i = 0;
	printf("Desea volver a calcular? [s / n]\n");
	for (;;)
	{
		if (kbhit())
		{
			c = _getche();
			fflush(stdin);

			if (c == 's' || c == 'S')
			{
				struct NumDen _dato = ingresarDatos();
				simplificarFraccion(_dato.numerador, _dato.denominador);
				menuSalir();
				break;
			}
			else if (c == 'n' || c == 'N')
			{
				main();
				break;
			}
			else
			{	
				cls();
				printf("%s", titulo);
				menuSalir();
			}
		}
	}
}
