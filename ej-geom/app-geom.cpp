#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define PI 3.14159  

// Consigna: diseñar una app que ofrezca a traves de un menu, la posibilidad de calcular areas de figuras geometricas
// especificas. Se deben codificar funciones que calculen las area de:
//circulo, cuadrado, rectangulo, triangulo y trapecio.

int main() {
    int opcion;
    float radio, lado, base, altura, base2;
    float area;
    char rta;
    
    do {
        do {
            system("cls");
            printf("=====APP CALCULADORA DE AREAS=====\n");
            printf("Ingrese a continuacion el numero de la opcion deseada:\n\n");
            printf("1. Circulo\n");
            printf("2. Cuadrado\n");
            printf("3. Rectangulo\n");
            printf("4. Triangulo\n");
            printf("5. Trapecio\n");
            printf("6. Salir\n\n");
            printf("Opcion: ");
            
            scanf("%d", &opcion);
            
            if (opcion < 1 || opcion > 6) {
                printf("\nOpcion invalida, intente nuevamente\n");
                system("pause");
            }
        } while (opcion < 1 || opcion > 6);
        
        while (getchar() != '\n');
        
        switch (opcion) {
    case 1: 
        system("cls");
        printf("=== AREA DEL CIRCULO ===\n\n");
        printf("Ingrese el radio del circulo: ");
        scanf("%f", &radio);
        area = PI * pow(radio, 2);
        printf("\nEl area del circulo es: %.2f\n", area);
        break;
    case 2:
        system("cls");
        printf("=== AREA DEL CUADRADO ===\n\n");
        printf("Ingrese el lado del cuadrado: ");
        scanf("%f", &lado);
        area = lado * lado;
        printf("\nEl area del cuadrado es: %.2f\n", area);
        break;
    case 3:
        system("cls");
        printf("=== AREA DEL RECTANGULO ===\n\n");
        printf("Ingrese el ancho del rectangulo: ");
        scanf("%f", &lado);
        printf("Ingrese la altura del rectangulo: ");
        scanf("%f", &base);
        area = base * lado;
        printf("\nEl area del rectangulo es: %.2f\n", area);
        break;
    case 4:
        system("cls");
        printf("=== AREA DEL TRIANGULO ===\n\n");
        printf("Ingrese la base del triangulo: ");
        scanf("%f", &base);
        printf("Ingrese la altura del triangulo: ");
        scanf("%f", &altura);
        area = (base * altura) / 2;
        printf("\nEl area del triangulo es: %.2f\n", area);
        break;
    case 5:
        system("cls");
        printf("=== AREA DEL TRAPECIO ===\n\n");
        printf("Ingrese la base mayor del trapecio: ");
        scanf("%f", &base);
        printf("Ingrese la base menor del trapecio: ");
        scanf("%f", &base2);
        printf("Ingrese la altura del trapecio: ");
        scanf("%f", &altura);
        area = (base + base2) * altura / 2;
        printf("\nEl area del trapecio es: %.2f\n", area);
        break;
    case 6:
        printf("\nGracias por usar la aplicacion.\n");
        printf("Presione la tecla ENTER para salir...");   
        getchar();
        break;
    }
        if (opcion != 6) {
            printf("\n\nDesea realizar otra operacion? (s/n): ");   
            scanf(" %c", &rta);
            while (getchar() != '\n');
        } else {
            rta = 'n';
        }
    } while (rta == 's' || rta == 'S');
    
    printf("\nGracias por usar la aplicacion.\n");
    printf("Presione la tecla ENTER para salir...");
    getchar();
    return 0;
}
