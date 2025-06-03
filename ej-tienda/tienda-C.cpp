#include <stdio.h>
#include <stdlib.h> 

int vendedorMasVentas(int c1, int c2, int c3) {
    if (c1 >= c2 && c1 >= c3) return 1;
    else if (c2 >= c1 && c2 >= c3) return 2;
    else return 3;
}

int vendedorMasDinero(float m1, float m2, float m3) {
    if (m1 >= m2 && m1 >= m3) return 1;
    else if (m2 >= m1 && m2 >= m3) return 2;
    else return 3;
}

void ticketVenta(int vendedor, int dia, float importe) {
    printf("----- Ticket de Venta -----\n");
    printf("Vendedor: %d\n", vendedor);
    printf("Dia: %d\n", dia);
    printf("Importe: $%.2f\n", importe);
    printf("---------------------------\n\n");
}

int main() {
    int vendedor, dia = 1;
    float importe;

    // Totales globales
    int cantVentasV1 = 0, cantVentasV2 = 0, cantVentasV3 = 0;
    float montoV1 = 0, montoV2 = 0, montoV3 = 0;

    // Control de maximos por dia
    int diaMasCantidad = 0, diaMasRecaudo = 0;
    int maxVentasTotales = 0;
    float maxRecaudadoTotal = 0;

    while (dia <= 5) {
        int cantV1Dia = 0, cantV2Dia = 0, cantV3Dia = 0;
        float montoV1Dia = 0, montoV2Dia = 0, montoV3Dia = 0;
        int totalVentasDia = 0;
        float totalRecaudadoDia = 0;
        char huboVentas;
        char otraVenta;

        printf("\nDia %d - Hubo ventas? (S/N): ", dia);
        scanf(" %c", &huboVentas);

        while (huboVentas == 'S' || huboVentas == 's') {
            // Validar numero de vendedor
            do {
                printf("Ingrese numero de vendedor (1-3): ");
                scanf("%d", &vendedor);
                if (vendedor < 1 || vendedor > 3) {
                    printf("Vendedor invalido. Intente nuevamente.\n");
                }
            } while (vendedor < 1 || vendedor > 3);

            printf("Ingrese importe de la venta: ");
            scanf("%f", &importe);

            // Ticket
            ticketVenta(vendedor, dia, importe);

            // Acumuladores diarios y totales
            switch (vendedor) {
                case 1:
                    cantV1Dia++;
                    montoV1Dia += importe;
                    cantVentasV1++;
                    montoV1 += importe;
                    break;
                case 2:
                    cantV2Dia++;
                    montoV2Dia += importe;
                    cantVentasV2++;
                    montoV2 += importe;
                    break;
                case 3:
                    cantV3Dia++;
                    montoV3Dia += importe;
                    cantVentasV3++;
                    montoV3 += importe;
                    break;
            }

            totalVentasDia++;
            totalRecaudadoDia += importe;

            printf("Hay otra venta este dia? (S/N): ");
            scanf(" %c", &otraVenta);
            huboVentas = otraVenta;
        }

        // Resultados por dia
        int vendMasVentas = vendedorMasVentas(cantV1Dia, cantV2Dia, cantV3Dia);
        int vendMasRecaudo = vendedorMasDinero(montoV1Dia, montoV2Dia, montoV3Dia);

        printf("\n--- Resumen Dia %d ---\n", dia);
        printf("Vendedor con mas ventas: %d\n", vendMasVentas);
        printf("Vendedor con mas recaudacion: %d\n", vendMasRecaudo);

        if (totalVentasDia > maxVentasTotales) {
            maxVentasTotales = totalVentasDia;
            diaMasCantidad = dia;
        }

        if (totalRecaudadoDia > maxRecaudadoTotal) {
            maxRecaudadoTotal = totalRecaudadoDia;
            diaMasRecaudo = dia;
        }

        dia++;
    }

    // Resultados finales
    int totalVentas = cantVentasV1 + cantVentasV2 + cantVentasV3;
    float totalRecaudado = montoV1 + montoV2 + montoV3;

    printf("\n======= RESUMEN FINAL =======\n");
    printf("Vendedor 1 - Ventas: %d - Recaudado: $%.2f\n", cantVentasV1, montoV1);
    printf("Vendedor 2 - Ventas: %d - Recaudado: $%.2f\n", cantVentasV2, montoV2);
    printf("Vendedor 3 - Ventas: %d - Recaudado: $%.2f\n", cantVentasV3, montoV3);
    printf("Total de ventas: %d\n", totalVentas);
    printf("Total recaudado: $%.2f\n", totalRecaudado);
    printf("Dia con mas ventas: Dia %d con %d ventas\n", diaMasCantidad, maxVentasTotales);
    printf("Dia con mas recaudacion: Dia %d con $%.2f\n", diaMasRecaudo, maxRecaudadoTotal);

    // Esperar tecla antes de salir
    printf("\nPresione ENTER para cerrar el programa...");
    getchar(); 
    getchar(); 
    return 0;
}
