#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	system("cls");
	system("color 2F");
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
		printf("E - Estado del aparcamiento\n");
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
				printf("Su plaza ha sido ocupada\n");
				fflush(stdin);
			}

			else if (plaza1 != 0 && plaza2 == 0) {

				printf("Introduce la matricula \n");
				scanf("%s", matricula2);
				printf("Su plaza ha sido ocupada\n");
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

		default:
			printf("Opcion incorrecta\n");
			break;
		}
		getchar();
	}
	system("pause");


}