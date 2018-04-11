#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define	M 20
#define NPLAZAS 10

struct plaza
{
	int plaza;
	char tipo;
	char matricula[8];

};


int main() {
	struct plaza num_plazas_coche[NPLAZAS];
	struct plaza num_plazas_moto[NPLAZAS];
	char opcion1, opcion2;
	int num_plaza;
	char matricula[8] = "\0";
	int n, m, i, j;
	char matricula_buscada[8];
	char tip_vehiculo;
	int fallos;
	char comp_usuario[M], comp_contraseña[M];
	char usuario[M] = "Administrador";
	char contraseña[M] = "1234";
	int comp5, comp6, comp7, comp8;
	n = 1;
	m = 1;
	i = 0;
	fallos = 0;

	for (i = 0; i < NPLAZAS; i++) {
		num_plazas_coche[i].plaza = 0;
		num_plazas_moto[i].plaza = 0;
	}

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

	}
	getchar();

	while (n == 1) {
		printf("Introduce una opcion\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza \n");
		printf("E - Estado aparcamiento \n");
		printf("B - Buscar el coche por matricula\n");
		printf("S - Cerrar programa.\n");
		scanf("%c", &opcion2);

		switch (opcion2) {

		case 'r':
		case 'R':
			printf("¿Que vehiculo tiene?\n");
			printf("C - Coche\n");
			printf("M - Moto\n");
			getchar();
			scanf("%c", &tip_vehiculo);
			switch (tip_vehiculo) {

			case 'c':
			case 'C':
				for (i = 0; i = NPLAZAS; i++) {
					if (num_plazas_coche[i].plaza == 0) {
						num_plazas_coche[i].plaza = 1;
						printf("Ha reservado la plaza %d. \nIntroduzca su matricula:\n", i + 1);
						scanf("%s", num_plazas_coche[i].matricula);
						fflush(stdin);
						break;
					}
				}
				break;

			case 'm':
			case 'M':
				for (i = 0; i = NPLAZAS; i++) {
					if (num_plazas_moto[i].plaza == 0) {
						num_plazas_moto[i].plaza = 1;
						printf("Se ha reservado la plaza %d.\nIntroduzca su matricula:\n", i + 1);
						scanf("%s", num_plazas_moto[i].matricula);
						fflush(stdin);
						break;
					}
				}
				break;
			default:
				printf("OPCION INCORRECTA\n");
				break;
			}
			break;

		case 'a':
		case 'A':
			printf("Introduzca su matricula\n");
			scanf("%s", &matricula_buscada);

			for (i = 0; i = NPLAZAS; i++) {
				comp8 = strcmp(matricula_buscada, num_plazas_coche[i].matricula);
				if (comp8 == 0) {
					num_plazas_coche[i].plaza = 0;
					printf("Muchas gracias por contratar nuestros servicios, vaya con cuidado\n");
					break;
				}

			}

			for (i = 0; i = NPLAZAS; i++) {
				comp8 = strcmp(matricula_buscada, num_plazas_moto[i].matricula);
				if (comp8 == 0) {
					num_plazas_moto[i].plaza = 0;
					printf("Muchas gracias por contratar nuestros servicios, vaya con cuidado\n");
					break;
				}

			}
			if (comp8 != 0) {
				printf("Su vehiculo no se encuentras en nuestras instalaciones\n");
			}
			break;


		case 'e':
		case 'E':
			printf("Plazas coche:\n");
			for (i = 0; i = NPLAZAS; i++) {
				if (num_plazas_coche[i].plaza == 1) {
					printf("La plaza %d esta ocupada por el coche cuya matricula es %s\n", i + 1, num_plazas_coche[i].matricula);
				}
				if (num_plazas_coche[i].plaza == 0) {
					printf("La plaza %d esta libre\n", i + 1);
				}
			}

			printf("Plazas de moto:\n");
			for (i = 0; i = NPLAZAS; i++) {
				if (num_plazas_moto[i].plaza == 1) {
					printf("La plaza %d esta ocupada por la moto cuya matriccula es %s\n", i + 1, num_plazas_moto[i].matricula);
				}
				if (num_plazas_moto[i].plaza == 0) {
					printf("La plaza %d esta libre\n", i + 11);
				}
			}
			break;

		case 'b':
		case 'B':
			printf("Introduzca su matricula\n");
			scanf("%s", matricula_buscada);
			fflush(stdin);

			for (i = 0; i = NPLAZAS; i++) {
				comp7 = strcmp(matricula_buscada, num_plazas_coche[i].matricula);
				if (comp7 == 0) {
					printf("Su coche se encuentra en la plaza %d\n", i + 1);
					break;
				}
			}

			for (i = 0; i = NPLAZAS; i++) {
				comp7 = strcmp(matricula_buscada, num_plazas_moto[i].matricula);
				if (comp7 == 0) {
					printf("Su moto se encuentra en la plaza %d\n", i + 11);
					break;
				}
			}
			if (comp7 != 0) {
				printf("Su vehiculo no se encuentra en nuestras instalaciones\n");
			}
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