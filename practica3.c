#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define	M 20


void main() {
	char opcion1 , opcion2;
	int plaza1 = 0, plaza2 = 0, plaza3 = 0, plaza4 = 0, num_plaza;
	char matricula1[8], matricula2[8], matricula3[8], matricula4[8];
	int n, m, i, j;
	char matricula_buscada[8];
	int comp1, comp2, comp3, comp4;
	char tip_vehiculo;
	int fallos;
	char comp_usuario[M], comp_contraseña[M];
	char usuario[M] = "Administrador";
	char contraseña[M] = "1234";
	int comp5, comp6;
	n = 1;
	m = 1;
	i = 0;
	fallos = 0;	

	while (m == 1) {
		printf("Introduzca el usuario:\n");
		gets(comp_usuario);
		fflush(stdin);

		comp5 = strcmp(usuario, comp_usuario);
		while (comp5 == 0) {
			printf("Introduzca la contraseña: \n");
			scanf("%s", comp_contraseña);
			fflush(stdin);

			comp6 = strcmp(contraseña, comp_contraseña);

			if (comp6 == 0) {
				fallos = 0;
				m = 2;
				comp5 = 1;

			}
			if (comp6 != 0) {
				fallos++;
				
				if (fallos >= 3) {
					m = 2;
					n = 2;
					comp5 = 1;
				}
			}
		}
		getchar();
	}

	
	while (n == 1) {
		printf("Introduce una opcion\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza \n");
		printf("E - Estado aparcamiento \n");
		printf("B - Buscar el coche por matricula\n");
		printf("S - Cerrar programa.\n");
		scanf("%c", &opcion2);
		fflush(stdin);

		switch (opcion2){

		case 'r':
		case 'R':
				printf("¿Que vehiculo tiene?\n");
				printf("C - Coche\n");
				printf("M - Moto\n");
				getchar();
				scanf("%c", &tip_vehiculo);
				switch(tip_vehiculo) {

				case 'c':
				case 'C':
					if (plaza1 == 1 && plaza2 == 1) {
						printf("No hay plazas libres \n");
					}
					if (plaza1 != 0 && plaza2==0){
						plaza2 = 1;
						printf("Ha reservado la plaza 2.\nAhora introduzca su matricula.\n");
						scanf("%s", matricula2);
						fflush(stdin);
					}
					if (plaza1 == 0) {
						plaza1 = 1;
						printf("Se ha reservado la plaza 1 .\nIntroduzca su matricula.\n");
						scanf("%s", matricula1);
						fflush(stdin);
					}
					break;

				case 'm':
				case 'M':
					if (plaza3 == 1 && plaza4 == 1) {
						printf("No quedan plazas disponibles\n");
					}
					if (plaza3 == 1 && plaza4 == 0) {
						plaza4 == 1;
						printf("Se ha reservado la plaza 4 para usted.\nIntroduzca su matricula:\n ");
						scanf("%s", &matricula4);
						fflush(stdin);
					}
					if (plaza3 == 0) {
						plaza3 = 1;
						printf("Ha reservado la plaza 3 .\nIntroduzca su matricula: \n");
						scanf("%s", matricula3);
						fflush(stdin);
					}
				}
				break;

		case 'a':
		case 'A':
			printf("Introduzca su matricula\n");
			scanf("%s", &matricula_buscada);
			fflush(stdin);
			if (matricula_buscada == matricula1) {
				printf("Muchas gracias por contratar nuestros servicios, vaya con cuidado \n");
				plaza1 = 0;
			}
			else if (matricula_buscada == matricula2) {
				printf("Muchas gracias por contratar nuestros servicios, vaya con cuidado \n");
				plaza2 = 0;
			}
			else if (matricula_buscada == matricula3) {
				printf("Muchas gracias por contratar nuestros servicios, vaya con cuidado\n");
				plaza3 = 0;
			}
			else if (matricula_buscada == matricula4) {
				plaza4 = 0;
				printf("Gracias por contratar nuestros servicios, vaya con cuidado\n");
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
			if (plaza3 == 0) {
				printf("La plaza 3 esta libre \n");
			}
			if (plaza3 == 1) {
				printf("La plaza 3 esta ocupada\n");
			}
			if (plaza4 == 0) {
				printf("La plaza 4 esta libre\n");
			}
			if (plaza4 == 1) {
				printf("La plaza 4 esta ocupada\n");
			}

			break;
		case 'b':
		case 'B':
			printf("Introduzca su matricula\n");
			scanf("%s", matricula_buscada);
			fflush(stdin);

			comp1 = strcmp(matricula_buscada, matricula1);
			comp2 = strcmp(matricula_buscada, matricula2);
			comp3 = strcmp(matricula_buscada, matricula3);
			comp4 = strcmp(matricula_buscada, matricula4);

			if (comp1 == 0) {
				printf("Su coche esta en la plza 1 \n");
			}
			else if (comp2 == 0) {
				printf("Su coche esta en la plaza 2 \n");
			}
			else if (comp3 == 0) {
				printf("Su coche esta en la plaza 3\n");
			}
			else if (comp4 == 0) {
				printf("Su coche esta en la plaza 4\n");
			}
			else (printf("Su cohce no se encuentra en nuestro parkin \n"));
			break;

		case 's':
		case 'S':
			n++;
			break;

		default:
			printf("Opcion incorrecta\n");
			break;
		}
		printf("\n\n");
		getchar();
	}
	
}