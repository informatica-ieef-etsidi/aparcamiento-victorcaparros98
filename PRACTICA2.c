#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char option;
	int plaza1 = 0, plaza2 = 0;
	char matricula1[8], matricula2[8], cliente[8], matricula[8];
	int comp1, comp2;
	int n;
	n = 1;

	while (n == 1) {
		printf("Introduce una opcion\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza \n");
		printf("E - Estado aparcamiento \n");
		printf("B - Buscar el coche por matricula\n");
		printf("C - Cerrar programa.\n");
		scanf("%c", &option);
		fflush(stdin);

		switch (option)
		{
		case 'r':
		case 'R':
			if (plaza1 == 0) {

				printf("Introduce la matricula \n");
				plaza1 = 1;
				scanf("%s", matricula1);
				fflush(stdin);
			}

			else if (plaza1 != 0 && plaza2 == 0) {

				printf("Introduce la matricula \n");
				scanf("%s", matricula2);
				fflush(stdin);
				plaza2 = 1;
			}

			else  printf("Ninguna plaza disponible, disculpen las molestias \n");

			break;

		case 'a':
		case 'A':
			printf("Introduzca su matricula\n");
			scanf("%s", &cliente);
			fflush(stdin);

			comp1 = strcmp(cliente, matricula1);
			comp2 = strcmp(cliente, matricula2);

			if (comp1 == 0) {
				printf("Muchas gracias por contratar nuestros servicios, vaya con cuidado \n");
				plaza1 = 0;
			}
			else if (comp2 == 0) {
				printf("Muchas gracias por contratar nuestros servicios, vaya con cuidado \n");
				plaza2 = 0;
			}
			else (printf("Tu coche no se encuentra en nuestras instalaciones\n"));
			break;

		case 'e':
		case 'E':
			if (plaza1 == 0) {
				printf("La plaza 1 esta libre \n");
			}
			if (plaza1 == 1) {
				printf("La plaza 1 esta ocupada \n");
			}
			if (plaza2 == 0) {
				printf("La plaza 2 esta libre \n");
			}
			if (plaza2 == 1) {
				printf("La plaza 2 esta ocupada \n");
			}

			break;
		case 'b':
		case 'B':
			printf("Introduzca su matricula\n");
			scanf("%s", matricula);
			fflush(stdin);

			comp1 = strcmp(matricula, matricula1);
			comp2 = strcmp(matricula, matricula2);

			if (comp1 == 0) {
				printf("Su coche esta en la plza 1 \n");
			}
			else if (comp2 == 0) {
				printf("Su coche esta en la plaza 2 \n");
			}
			else (printf("Su cohce no se encuentra en nuestro parkin \n"));
			break;

		case 'c':
		case 'C':
			n++;
			break;

		default:
			printf("Opcion incorrecta\n");
			break;
		}
		getchar();
	}
	system("pause");


}
