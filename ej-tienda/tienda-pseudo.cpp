//En un comercio de indumentaria deportiva, se quiere llevar el control de las ventas de los 5 dias hábiles de la semana. El comercio cuenta con 3 vendedores.
//Se desea simular la venta diaria, registrando el monto de la venta, y la cantidad de ventas que realiza cada vendedor.
//Desarrollar un procedimiento que imprima el ticket de cada venta con: Nro de vendedor, Importe de la venta, día que se realiza la venta (del 1 al 5)
//Desarrollar una función que devuelva por cada día, el vendedor que más ventas hizo. 
//Desarrollar una función que devuelva por cada día, el vendedor que más dinero recaudó con sus ventas 
//Imprimir por día, el Nro de vendedor que más ventas hizo y cantidad, y el que más recaudó y el monto recaudado


//Al finalizar la venta de los 5 días:
//Desarrollar un procedimiento que imprima: Nro de vendedor, cantidad de ventas de cada vendedor, y monto recaudado de cada vendedor
//Desarrollar un procedimiento que calcule cantidad total de ventas y monto total recaudado
//Imprimir el día que más cantidad de ventas se hizo, y la cantidad
//Imprimir el día que más se recaudó, y el monto recaudado

//Datos de entrada:

    //Vendedores: 1, 2, 3
    //Días: 1, 2, 3, 4, 5
    //Ventas: importe, cantidad

//Datos de salida:

    //Por día:
    //Nro de vendedor que más ventas hizo y cantidad, y el que más recaudó y el monto recaudado

    //Al finalizar:
    //Nro de vendedor, cantidad de ventas de cada vendedor, y monto recaudado de cada vendedor
    //Cantidad total de ventas y monto total recaudado
    //Día que más cantidad de ventas se hizo, y la cantidad
    //Día que más se recaudó, y el monto recaudado


    PROGRAMA comercio

    PROCEDIMIENTO TICKET_VENTA(vendedor: ENTERO, dia: ENTERO, importe: REAL)
        HACER
            IMPRIMIR: "Ticket de venta:"
            IMPRIMIR: "Vendedor: ", vendedor
            IMPRIMIR: "Día: ", dia
            IMPRIMIR: "Importe total: $", importe
        FIN HACER
    FIN PROCEDIMIENTO

    FUNCION VENDEDOR_MAS_VENTAS(c1: ENTERO, c2: ENTERO, c3: ENTERO): ENTERO
        HACER
            Si (c1 >= c2 Y c1 >= c3) Entonces
                VENDEDOR_MAS_VENTAS = 1
            Sino Si (c2 >= c1 Y c2 >= c3) Entonces
                VENDEDOR_MAS_VENTAS = 2
            Sino
                VENDEDOR_MAS_VENTAS = 3
            Fin Si
        FIN HACER
    FIN FUNCION

    FUNCION VENDEDOR_MAS_DINERO(m1: REAL, m2: REAL, m3: REAL): ENTERO
        HACER
            Si (m1 >= m2 Y m1 >= m3) Entonces
                VENDEDOR_MAS_DINERO = 1
            Sino Si (m2 >= m1 Y m2 >= m3) Entonces
                VENDEDOR_MAS_DINERO = 2
            Sino
                VENDEDOR_MAS_DINERO = 3
            Fin Si
        FIN HACER
    FIN FUNCION

    VARIABLES:
        vendedor, dia, finalizarDia: ENTERO 1
        importe, montoVendedor1, montoVendedor2, montoVendedor3: REAL 7,2
        cantVentasVEND1, cantVentasVEND2, cantVentasVEND3: ENTERO 3
        cantVentasVend1Dia, cantVentasVend2Dia, cantVentasVend3Dia: ENTERO 3
        montoVend1Dia, montoVend2Dia, montoVend3Dia: REAL 7,2
        totalVentasDia, totalRecaudadoDia: ENTERO 1
        maxVentasTotales, maxRecaudadoTotal: ENTERO
        diaMasCantidad, diaMasRecaudo: ENTERO
        vendedorMasVentasDia, vendedorMasRecaudoDia: ENTERO
        huboVentas, otraVenta: CARACTER

    HACER
        // Inicialización
        montoVendedor1 = 0
        montoVendedor2 = 0
        montoVendedor3 = 0
        cantVentasVEND1 = 0
        cantVentasVEND2 = 0
        cantVentasVEND3 = 0
        maxVentasTotales = 0
        maxRecaudadoTotal = 0
        diaMasCantidad = 0
        diaMasRecaudo = 0
        finalizarDia = 1

        // Por cada día
        REPETIR MIENTRAS (finalizarDia <= 5)
            cantVentasVend1Dia = 0
            cantVentasVend2Dia = 0
            cantVentasVend3Dia = 0
            montoVend1Dia = 0
            montoVend2Dia = 0
            montoVend3Dia = 0
            totalVentasDia = 0
            totalRecaudadoDia = 0

            IMPRIMIR: "Día ", finalizarDia
            IMPRIMIR: "¿Hubo ventas este día? (S/N)"
            LEER: huboVentas

            REPETIR MIENTRAS (huboVentas = 'S')
                IMPRIMIR: "Ingrese número de vendedor (1 a 3):"
                LEER: vendedor
                IMPRIMIR: "Ingrese importe de la venta:"
                LEER: importe

                // Ticket de venta
                TICKET_VENTA(vendedor, finalizarDia, importe)

                // Acumuladores por día
                Si (vendedor = 1) Entonces
                    cantVentasVend1Dia = cantVentasVend1Dia + 1
                    montoVend1Dia = montoVend1Dia + importe
                    cantVentasVEND1 = cantVentasVEND1 + 1
                    montoVendedor1 = montoVendedor1 + importe
                Sino Si (vendedor = 2) Entonces
                    cantVentasVend2Dia = cantVentasVend2Dia + 1
                    montoVend2Dia = montoVend2Dia + importe
                    cantVentasVEND2 = cantVentasVEND2 + 1
                    montoVendedor2 = montoVendedor2 + importe
                Sino Si (vendedor = 3) Entonces
                    cantVentasVend3Dia = cantVentasVend3Dia + 1
                    montoVend3Dia = montoVend3Dia + importe
                    cantVentasVEND3 = cantVentasVEND3 + 1
                    montoVendedor3 = montoVendedor3 + importe
                Fin Si

                totalVentasDia = totalVentasDia + 1
                totalRecaudadoDia = totalRecaudadoDia + importe

                IMPRIMIR: "¿Hay otra venta para este día? (S/N)"
                LEER: otraVenta
                huboVentas = otraVenta
            FIN REPETIR MIENTRAS

            // Resultados del día
            vendedorMasVentasDia = VENDEDOR_MAS_VENTAS(cantVentasVend1Dia, cantVentasVend2Dia, cantVentasVend3Dia)
            vendedorMasRecaudoDia = VENDEDOR_MAS_DINERO(montoVend1Dia, montoVend2Dia, montoVend3Dia)

            IMPRIMIR: "Día ", finalizarDia, ":"
            IMPRIMIR: "Vendedor con más ventas: ", vendedorMasVentasDia
            IMPRIMIR: "Vendedor con más recaudación: ", vendedorMasRecaudoDia

            // Actualización de acum máximos
            Si (totalVentasDia > maxVentasTotales) Entonces
                maxVentasTotales = totalVentasDia
                diaMasCantidad = finalizarDia
            Fin Si

            Si (totalRecaudadoDia > maxRecaudadoTotal) Entonces
                maxRecaudadoTotal = totalRecaudadoDia
                diaMasRecaudo = finalizarDia
            Fin Si

            finalizarDia = finalizarDia + 1
        FIN REPETIR MIENTRAS

        // Final del programa - resumen
        IMPRIMIR: "Resumen Final:"
        IMPRIMIR: "Vendedor 1 - Ventas: ", cantVentasVEND1, " - Recaudación: $", montoVendedor1
        IMPRIMIR: "Vendedor 2 - Ventas: ", cantVentasVEND2, " - Recaudación: $", montoVendedor2
        IMPRIMIR: "Vendedor 3 - Ventas: ", cantVentasVEND3, " - Recaudación: $", montoVendedor3

        totalVentas = cantVentasVEND1 + cantVentasVEND2 + cantVentasVEND3
        totalRecaudado = montoVendedor1 + montoVendedor2 + montoVendedor3

        IMPRIMIR: "Total de ventas realizadas: ", totalVentas
        IMPRIMIR: "Total recaudado: $", totalRecaudado
        IMPRIMIR: "Día con más ventas: Día ", diaMasCantidad, " con ", maxVentasTotales, " ventas"
        IMPRIMIR: "Día con más recaudación: Día ", diaMasRecaudo, " con $", maxRecaudadoTotal
    FIN HACER
FIN PROGRAMA
