#include <stdio.h>
#include <stdlib.h>

void CALCULO_PORCENTAJES_NIVEL_DESAYUNO(int cantNadaDesayuno, int cantPocoDesayuno, int cantSufiDesayuno, int cantTotalDesayuno, float *porcentajeNadaDesayuno, float *porcentajePocoDesayuno, float *porcentajeSufiDesayuno) {
    if (cantTotalDesayuno > 0) {
        *porcentajeNadaDesayuno = ((float)cantNadaDesayuno / cantTotalDesayuno) * 100;
        *porcentajePocoDesayuno = ((float)cantPocoDesayuno / cantTotalDesayuno) * 100;
        *porcentajeSufiDesayuno = ((float)cantSufiDesayuno / cantTotalDesayuno) * 100;
    } else {
        *porcentajeNadaDesayuno = 0;
        *porcentajePocoDesayuno = 0;
        *porcentajeSufiDesayuno = 0;
    }
}

void CALCULO_PORCENTAJES_NIVEL_CENA(int cantNadaCena, int cantPocoCena, int cantSufiCena, int cantTotalCena, float *porcentajeNadaCena, float *porcentajePocoCena, float *porcentajeSufiCena) {
    if (cantTotalCena > 0) {
        *porcentajeNadaCena = ((float)cantNadaCena / cantTotalCena) * 100;
        *porcentajePocoCena = ((float)cantPocoCena / cantTotalCena) * 100;
        *porcentajeSufiCena = ((float)cantSufiCena / cantTotalCena) * 100;
    } else {
        *porcentajeNadaCena = 0;
        *porcentajePocoCena = 0;
        *porcentajeSufiCena = 0;
    }
}

int main() {
    int maxEncuestasTotales = 0, nivelQueMas = 0, RtaCaso;
    int cantNadaDesayuno, cantPocoDesayuno, cantSufiDesayuno, cantTotalDesayuno;
    int cantNadaCena, cantPocoCena, cantSufiCena, cantTotalCena;
    int cantTotalEncuestasNivel;
    int nivel;
    float porcentajeNadaDesayuno, porcentajePocoDesayuno, porcentajeSufiDesayuno;
    float porcentajeNadaCena, porcentajePocoCena, porcentajeSufiCena;
    char Rta;
    int acumNadaDesayuno = 0, acumPocoDesayuno = 0, acumSufiDesayuno = 0;
    int acumNadaCena = 0, acumPocoCena = 0, acumSufiCena = 0;
    int totalGlobalDesayuno = 0, totalGlobalCena = 0;

    for (nivel = 1; nivel <= 4; nivel++) {
        cantNadaDesayuno = cantPocoDesayuno = cantSufiDesayuno = cantTotalDesayuno = 0;
        cantNadaCena = cantPocoCena = cantSufiCena = cantTotalCena = 0;
        cantTotalEncuestasNivel = 0;

        printf("\nNIVEL: %d\n", nivel);
        printf("¿Hubo encuestas para este nivel? (S/N): ");
        scanf(" %c", &Rta);

        while (Rta == 'S' || Rta == 's') {
            printf("Ingrese el número del estado de DESAYUNO (1: Nada, 2: Poco, 3: Suficiente): ");
            scanf("%d", &RtaCaso);
            switch (RtaCaso) {
                case 1: cantNadaDesayuno++; break;
                case 2: cantPocoDesayuno++; break;
                case 3: cantSufiDesayuno++; break;
                default: printf("Opción inválida\n"); break;
            }
            cantTotalDesayuno++;

            printf("Ingrese el número del estado de CENA (1: Nada, 2: Poco, 3: Suficiente): ");
            scanf("%d", &RtaCaso);
            switch (RtaCaso) {
                case 1: cantNadaCena++; break;
                case 2: cantPocoCena++; break;
                case 3: cantSufiCena++; break;
                default: printf("Opción inválida\n"); break;
            }
            cantTotalCena++;
            cantTotalEncuestasNivel++;

            printf("¿Hay otra encuesta para este nivel? (S/N): ");
            scanf(" %c", &Rta);
        }

        acumNadaDesayuno += cantNadaDesayuno;
        acumPocoDesayuno += cantPocoDesayuno;
        acumSufiDesayuno += cantSufiDesayuno;

        acumNadaCena += cantNadaCena;
        acumPocoCena += cantPocoCena;
        acumSufiCena += cantSufiCena;

        totalGlobalDesayuno += cantTotalDesayuno;
        totalGlobalCena += cantTotalCena;

        CALCULO_PORCENTAJES_NIVEL_DESAYUNO(cantNadaDesayuno, cantPocoDesayuno, cantSufiDesayuno, cantTotalDesayuno, &porcentajeNadaDesayuno, &porcentajePocoDesayuno, &porcentajeSufiDesayuno);
        CALCULO_PORCENTAJES_NIVEL_CENA(cantNadaCena, cantPocoCena, cantSufiCena, cantTotalCena, &porcentajeNadaCena, &porcentajePocoCena, &porcentajeSufiCena);

        if (cantTotalEncuestasNivel > maxEncuestasTotales) {
            maxEncuestasTotales = cantTotalEncuestasNivel;
            nivelQueMas = nivel;
        }

        printf("\n---- RESULTADOS NIVEL %d ----\n", nivel);
        printf("DESAYUNO:\n");
        printf("Nada: %.2f%%\n", porcentajeNadaDesayuno);
        printf("Poco: %.2f%%\n", porcentajePocoDesayuno);
        printf("Suficiente: %.2f%%\n", porcentajeSufiDesayuno);
        printf("Cantidad encuestados: %d\n", cantTotalDesayuno);

        printf("CENA:\n");
        printf("Nada: %.2f%%\n", porcentajeNadaCena);
        printf("Poco: %.2f%%\n", porcentajePocoCena);
        printf("Suficiente: %.2f%%\n", porcentajeSufiCena);
        printf("Cantidad encuestados: %d\n", cantTotalCena);
    }

    printf("\n== RESULTADO GLOBAL ==\n");
    printf("Nivel con mayor participación: %d con %d encuestas\n", nivelQueMas, maxEncuestasTotales);

    printf("\nDESAYUNO EN TODOS LOS NIVELES:\n");
    printf("Nada: %.2f%%\n", ((float)acumNadaDesayuno / totalGlobalDesayuno) * 100);
    printf("Poco: %.2f%%\n", ((float)acumPocoDesayuno / totalGlobalDesayuno) * 100);
    printf("Suficiente: %.2f%%\n", ((float)acumSufiDesayuno / totalGlobalDesayuno) * 100);
    printf("Cantidad total encuestados: %d\n", totalGlobalDesayuno);

    printf("\nCENA EN TODOS LOS NIVELES:\n");
    printf("Nada: %.2f%%\n", ((float)acumNadaCena / totalGlobalCena) * 100);
    printf("Poco: %.2f%%\n", ((float)acumPocoCena / totalGlobalCena) * 100);
    printf("Suficiente: %.2f%%\n", ((float)acumSufiCena / totalGlobalCena) * 100);
    printf("Cantidad total encuestados: %d\n", totalGlobalCena);

    printf("\nPresione la tecal ENTER para finalizar el programa...");
    getchar();
    getchar();
    return 0;
}
