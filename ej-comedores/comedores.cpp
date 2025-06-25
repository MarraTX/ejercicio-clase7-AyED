// Se realiza un estudio en 4 comedores comunitarios sobre la alimentación saludable. 
// A cada asistente se le pregunta:
// ¿Consumió frutas hoy? (Sí / No)
// ¿Consumió verduras hoy? (Sí / No)

// Se desea:

// Calcular, para cada comedor, el porcentaje de personas que respondieron sí y no para frutas y verduras.

// Indicar el comedor con mayor cantidad de encuestas.

// Calcular los porcentajes totales de respuestas sí y no en frutas y verduras entre todos los comedores.

// DATOS DE ENTRADA:
    // Encuestas de consumo de frutas: Sí / No
    // Encuestas de consumo de verduras: Sí / No

// PROCESOS:
    // Tomar datos de encuesta de consumo de frutas
    // Tomar datos de encuesta de consumo de verduras
    // Calcular porcentaje por nivel
    // Comparar comedores para saber el que tuvo mayor participación
    // Calcular porcentajes generales
    // Entregar los resultados finales

// DATOS DE SALIDA:
    // Porcentaje de cada respuesta para consumo de frutas y verduras, por cada comedor
    // Comedor con mayor participación
    // Porcentajes generales de cada hábito entre todas las comedores


PROGRAMA COMEDORES

    PROCEDIMIENTO MAYOR_CANTIDAD (cantActual: ENTERO, REF cantMax: ENTERO, comedorActual: ENTERO, REF comedorMax: ENTERO)
        HACER
            Si (cantActual > cantMax) Entonces
                cantMax = cantActual
                comedorMax = comedorActual
            Fin Si
        FIN HACER
    FIN PROCEDIMIENTO

    VARIABLES:
        frutasSi, frutasNo: ENTERO
        verdurasSi, verdurasNo: ENTERO
        porcentajeFrutasSi, porcentajeFrutasNo: REAL
        porcentajeVerdurasSi, porcentajeVerdurasNo: REAL
        cantTotal: ENTERO
        cantMax: ENTERO
        comedorMax: ENTERO
        Rta: ENTERO
        comedor: ENTERO
        porcentajeTotalFrutasSi, porcentajeTotalFrutasNo: REAL
        porcentajeTotalVerdurasSi, porcentajeTotalVerdurasNo: REAL
        acumFrutasSi, acumFrutasNo, acumVerdurasSi, acumVerdurasNo: ENTERO
        acumEncuestas: ENTERO
    HACER
        porcentajeTotalFrutasSi = 0
        porcentajeTotalFrutasNo = 0
        porcentajeTotalVerdurasSi = 0
        porcentajeTotalVerdurasNo = 0
        cantMax = 0
        comedorMax = 0
        acumFrutasSi = 0
        acumFrutasNo = 0
        acumVerdurasSi = 0
        acumVerdurasNo = 0
        acumEncuestas = 0

        REPETIR PARA (comedor:= 1, 4, comedor+1)
            cantTotal = 0
            frutasSi = 0
            frutasNo = 0
            verdurasSi = 0
            verdurasNo = 0
            Rta = 1

            REPETIR MIENTRAS (Rta <> 0)
                IMPRIMIR: "COMEDOR: ", comedor
                IMPRIMIR: "INGRESE LA RESPUESTA CON LOS NUMEROS INDICADOS"
                IMPRIMIR: "Consumio frutas?"
                IMPRIMIR: "1: Si, 2: No, 0: Cambiar de comedor"
                LEER: Rta
                Si (Rta = 1) Entonces
                    frutasSi = frutasSi + 1
                    Sino
                    Si (Rta = 2) Entonces
                        frutasNo = frutasNo + 1
                        Sino
                        Si (Rta <> 0) Entonces
                            IMPRIMIR: "Opcion invalida, por favor intente nuevamente"
                        Fin Si
                    Fin Si
                Fin Si
                IMPRIMIR: "Consumio verduras?"
                IMPRIMIR: "1: Si, 2: No, 0: Cambiar de comedor"
                LEER: Rta
                Si (Rta = 1) Entonces
                    verdurasSi = verdurasSi + 1
                    Sino
                    Si (Rta = 2) Entonces
                        verdurasNo = verdurasNo + 1
                        Sino
                        Si (Rta <> 0) Entonces
                            IMPRIMIR: "Opcion invalida, por favor intente nuevamente"
                        Fin Si
                    Fin Si
                Fin Si
                cantTotal = cantTotal + 1
            FIN REPETIR MIENTRAS
            acumFrutasSi = acumFrutasSi + frutasSi
            acumFrutasNo = acumFrutasNo + frutasNo
            acumVerdurasSi = acumVerdurasSi + verdurasSi
            acumVerdurasNo = acumVerdurasNo + verdurasNo
            acumEncuestas = acumEncuestas + cantTotal

            IMPRIMIR: "TOTAL DE ENCUESTADOS EN EL COMEDOR ", comedor, "ES DE: ", cantTotal
            IMPRIMIR: "PORCENTAJE DE CONSUMO DE FRUTAS"
            IMPRIMIR: "SI: ", (frutasSi * 100) / cantTotal
            IMPRIMIR: "NO: ", (frutasNo * 100) / cantTotal
            IMPRIMIR: "PORCENTAJE DE CONSUMO DE VERDURAS"
            IMPRIMIR: "SI: ", (verdurasSi * 100) / cantTotal
            IMPRIMIR: "NO: ", (verdurasNo * 100) / cantTotal

            MAYOR_CANTIDAD(cantTotal, cantMax, comedor, comedorMax)
        FIN REPETIR PARA

        IMPRIMIR: "EL COMEDOR CON MAYOR PARTICIPACION FUE: ", comedorMax, "CON UN TOTAL DE: ", cantMax, "ENCUESTADOS"
        IMPRIMIR "LOS PORCENTAJES GENERALES PARA UN TOTAL DE ", acumEncuestas, "ENCUESTADOS ENTRE TODOS LOS COMEDORES SON"
        IMPRIMIR: "PORCENTAJE DE CONSUMO DE FRUTAS"
        IMPRIMIR: "SI: ", (acumFrutasSi * 100) / acumEncuestas
        IMPRIMIR: "NO: ", (acumFrutasNo * 100) / acumEncuestas
        IMPRIMIR: "PORCENTAJE DE CONSUMO DE VERDURAS"
        IMPRIMIR: "SI: ", (acumVerdurasSi * 100) / acumEncuestas
        IMPRIMIR: "NO: ", (acumVerdurasNo * 100) / acumEncuestas
    FIN HACER
FIN PROGRAMA