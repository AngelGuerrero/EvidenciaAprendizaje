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
char cad_numerador[MAX_STRLEN] = { '\0' };
char cad_denominador[MAX_STRLEN] = { '\0' };
char datosIngresados[MAX_STRLEN] = { '\0' };
int datosAprovados = 0; /* Ok = 0 */
const char titulo[] = { "\n\t\tPrograma Simplificar Fraccion\n\n" };
char opcion = ' ';
static int divisor = 2;

/*Utilizados para los acentos*/
char A = 181;
char a = 160;
char e = 130;
char iacen = 161;
char o = 162;
char u = 163;

/* Declaraci�n de estructuras */
struct NumDen
{
	int numerador;
	int denominador;
};


/* funci�n principal */
main()
{
	do
	{
		divisor = 2;

		/* Variables locales */
		int numerador = 0;
		int denominador = 0;

		/* Pide los datos del usuario */
		do
		{
			datosAprovados = 0;
			/* Limpia los datos de entrada si es que se han introducido incorrectamente */
			for (int i = 0; i < strlen(datosIngresados); i++) datosIngresados[i] = 0;

			system("cls");
			printf("%s", titulo);
			printf("Ingresa la expresi%cn de la forma: \" numerador / denominador \"\n:", o);
			gets(datosIngresados);

			/* Verifica primero que en la entrada de datosIngresados no haya m�s que digitos */
			for (int i = 0; i < strlen(datosIngresados); i++)
			{
				/* Filtra �nicamente los "datos" */
				if (datosIngresados[i] != 0)
				{
					/* Si encuentra por lo menos un dato que NO sea d�gito, entonces no se aprueva la entrada */
					if (!isdigit(datosIngresados[i]) && datosIngresados[i] != '/')
					{
						datosAprovados = 1;
						printf("\n\t\tEl formato de entrada \"%s\", no es correcto\n", datosIngresados);
						system("pause");
						break;
					}
				}
			}
		} while (datosAprovados);
		
		/* Toma los n�meros que se localizan antes del / y despu�s del mismo signo */
		int posicion = 0;	/* variable que toma la posici�n que tiene el signo '/' para copiar el denomiandor */
		for (int i = 0; i < strlen(datosIngresados); i++)
		{
			/* Copia los n�meros hasta que se encuentra el signo '/' */
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

		/* Copia los n�meros que se encuentran despu�s del signo '/' */
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

		/* Hace el proceso de divisi�n */
		for (;;)
		{
			if (DatosEmpaquetados.numerador % divisor == 0 && DatosEmpaquetados.denominador % divisor == 0)
			{
				if (DatosEmpaquetados.numerador >= 0 || DatosEmpaquetados.denominador >= 0)
				{
					DatosEmpaquetados.numerador /= divisor;
					DatosEmpaquetados.denominador /= divisor;
					divisor = 2;
					printf("Expresi%cn reducida: [ %i / %i ]\n", o, DatosEmpaquetados.numerador, DatosEmpaquetados.denominador);
				}
				else
				{
					/* Termina el bucle */
					break;
				}
			}
			else
			{
				if (divisor < DatosEmpaquetados.numerador && divisor < DatosEmpaquetados.denominador)
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
		printf("\nLa M%cnima expresi%cn es: [ %i / %i ]\n", iacen, o, DatosEmpaquetados.numerador, DatosEmpaquetados.denominador);



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
