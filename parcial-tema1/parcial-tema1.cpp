// Una empresa desea realizar un seguimiento detallado de las ventas realizadas durante los 7 dias de la semana por parte de sus 3 vendedores.
// Para esto, se desarrollara un programa que simule las ventas una a una, tal como si fueran ocurriendo en tiempo real.
// Cada vez que se produce una venta, se deben ingresar los siguientes datos:
    // - Nro de vendedor (1, 2, 3)
    // - Importe de la venta
// El proceso de carga de ventas continua hasta que no haya mas ventas el ultimo dia de la semana.
// Se desea obtener la siguiente informacion:
    // 1. Por dia, cual fue el vendedor que mas vendio en importe total. Y cual en cantidad de ventas.
    // 2. Por dia, promedio de cantidad de ventas de los 3 vendedores.
    // 3. Cual fue el dia de la semana con mayor importe total vendido
    // 4. Cantida de ventas total, e importe total vendido, por vendedor, y en total para la empresa

PROGRAMA VENTAS
    PROCEDIMIENTO MVD_C(C1: ENTERO, C2: ENTERO, C3: ENTERO, REF CMAX: ENTERO, REF VC: ENTERO)
        HACER
            Si (C1 >= C2 Y C1 >= C3) Entonces
                CMAX = C1
                VC = 1
            Sino 
            Si (C2 >= C1 Y C2 >= C3) Entonces
                CMAX = C2
                VC = 2
            Sino
                Si (C3 >= C1 Y C3 >= C2) Entonces
                    CMAX = C3
                    VC = 3
                    Fin Si
                Fin Si
            Fin Si
        FIN HACER
    FIN PROCEDIMIENTO

    PROCEDIMIENTO MVD_I(I1: REAL, I2: REAL, I3: REAL, REF IMAX: REAL, REF VI: ENTERO)
        HACER
            Si (I1 >= I2 Y I1 >= I3) Entonces
                IMAX = I1
                VI = 1
            Sino 
            Si (I2 >= I1 Y I2 >= I3) Entonces
                IMAX = I2
                VI = 2
            Sino
                Si (I3 >= I1 Y I3 >= I2) Entonces
                    IMAX = I3
                    VI = 3
                    Fin Si
                Fin Si
            Fin Si
        FIN HACER
    FIN PROCEDIMIENTO

    PROCEDIMIENTO PROMEDIO (CANTTOTAL: ENTERO, REF PROM: REAL)
        HACER
            PROM = CANTTOTAL / 3
        FIN HACER
    FIN PROCEDIMIENTO

    VARIABLES:
        V1_C, V2_C, V3_C: ENTERO
        V1_I, V2_I, V3_I: REAL
        PROMEDIO_VENTAS: REAL
        CANT_MAX: ENTERO
        DMAX_DIA: ENTERO
        DMAX_I: REAL
        ACUMC_V1, ACUMC_V2, ACUMC_V3: ENTERO
        ACUMI_V1, ACUMI_V2, ACUMI_V3: REAL
        ACUMC_E, ACUMI_E: ENTERO
        DIA: ENTERO
        RTA: ENTERO
        VI: REAL
        VC: ENTERO
        IMAX: REAL

        HACER
            ACUMC_V1 = 0
            ACUMC_V2 = 0
            ACUMC_V3 = 0
            ACUMI_V1 = 0
            ACUMI_V2 = 0
            ACUMI_V3 = 0
            ACUMC_E = 0
            ACUMI_E = 0
            DMAX_DIA = 0
            DMAX_I = 0
            VI = 0
            VC = 0
            IMAX = 0

            REPETIR PARA (DIA:= 1, 7, DIA+1)
                V1_C = 0
                V2_C = 0
                V3_C = 0
                V1_I = 0
                V2_I = 0
                V3_I = 0
                RTA = 1
                PROMEDIO_VENTAS = 0
                IMP= 0
                CANT_MAX = 0
                IMP_TOTAL = 0

                REPETIR MIENTRAS (RTA <> 0)
                    IMPRIMIR: "INGRESE LA RESPUESTA CON LOS NUMEROS INDICADOS"
                    IMPRIMIR: "INGRESE EL NUMERO DEL VENDEDOR, EN EL CASO DE NO HABER VENTAS, INGRESE 0 PARA PASAR AL SIGUIENTE DIA"
                    LEER: RTA
                    IMPRIMIR: "INGRESE EL IMPORTE DE LA VENTA"
                    LEER: IMP
                    Si (RTA = 1) Entonces
                        V1_C = V1_C + 1
                        V1_I = V1_I + IMP
                    Sino
                        Si (RTA = 2) Entonces
                            V2_C = V2_C + 1
                            V2_I = V2_I + IMP
                        Sino
                            Si (RTA = 3) Entonces
                                V3_C = V3_C + 1
                                V3_I = V3_I + IMP
                            Sino
                                Si (RTA <> 0) Entonces
                                    IMPRIMIR: "Opcion invalida, por favor intente nuevamente"
                                Fin Si
                            Fin Si
                        Fin Si
                    Fin Si
                FIN REPETIR MIENTRAS
                CANT_MAX = V1_C + V2_C + V3_C
                MVD_C(V1_C, V2_C, V3_C, VC, VMAX)
                IMPRIMIR: "EL VENDEDOR CON MAS VENTAS EN EL DIA ES: ", VC, "CON UN TOTAL DE: ", VMAX, "VENTAS"
                MVD_I(V1_I, V2_I, V3_I, IMAX, VI)
                IMPRIMIR: "EL VENDEDOR QUE MAS IMPORTE GENERO EN EL DIA ES: ", VI, "CON UN TOTAL DE: ", IMAX, "DE IMPORTE"
                PROMEDIO(CANT_MAX, PROMEDIO_VENTAS)
                IMPRIMIR: "EL PROMEDIO DE VENTAS EN EL DIA ES: ", PROMEDIO_VENTAS
                
                ACUMC_V1 = ACUMC_V1 + V1_C
                ACUMC_V2 = ACUMC_V2 + V2_C
                ACUMC_V3 = ACUMC_V3 + V3_C
                ACUMI_V1 = ACUMI_V1 + V1_I
                ACUMI_V2 = ACUMI_V2 + V2_I
                ACUMI_V3 = ACUMI_V3 + V3_I
                IMP_TOTAL = V1_I + V2_I + V3_I
                Si (IMP_TOTAL > DMAX_I) Entonces
                    DMAX_I = IMP_TOTAL
                    DMAX_DIA = DIA
                Fin Si
                
            FIN REPETIR PARA
                ACUMC_E = ACUMC_V1 + ACUMC_V2 + ACUMC_V3
                ACUMI_E = ACUMI_V1 + ACUMI_V2 + ACUMI_V3

            IMPRIMIR: "EL DIA CON MAYOR IMPORTE TOTAL ES: ", DMAX_DIA, "CON UN TOTAL DE: ", DMAX_I
            IMPRIMIR: "CANTIDAD DE VENTAS TOTALES DE LA SEMANA POR VENDEDOR"
            IMPRIMIR: "VENDEDOR 1:"
            IMPRIMIR: "CANTIDAD: ", ACUMC_V1
            IMPRIMIR: "IMPORTE: ", ACUMI_V1
            IMPRIMIR: "VENDEDOR 2:"
            IMPRIMIR: "CANTIDAD: ", ACUMC_V2
            IMPRIMIR: "IMPORTE: ", ACUMI_V2
            IMPRIMIR: "VENDEDOR 3:"
            IMPRIMIR: "CANTIDAD: ", ACUMC_V3
            IMPRIMIR: "IMPORTE: ", ACUMI_V3
            
            IMPRIMIR: "CANTIDAD DE VENTAS TOTALES DE LA EMPRESA"
            IMPRIMIR: "CANTIDAD: ", ACUMC_E
            IMPRIMIR: "IMPORTE: ", ACUMI_E
    FIN HACER
FIN PROGRAMA
