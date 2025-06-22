// Un centro deportivo municipal está realizando un estudio sobre los hábitos de actividad física en diferentes sectores de la ciudad. 
// Se han seleccionado 4 centro deportivos y se está encuestando a los usuarios sobre su nivel de actividad física. 
// Las respuesta posibles son sedentario, moderados y activo. La información se registra en una plataforma web en tiempo real.

// Se necesita:

//  1) Determinar cual es el nivel de actividad física más frecuente en cada centro deportivo.

//  2) Por cada centro calcular el promedio de nivel de actividad física, indicar cual de las actividades supera el promedio

//  3) Mostrar, para cada nivel de actividad física en que centro deportivo se observo la mayor cantidad de repuestas correspondientes

// DATOS DE ENTRADA:
    // Encuestas de actividad fisica: y sus respuestas posibles (sedentario, moderados y activo)

// PROCESOS:
    // Calculo de nivel de actividad mas mencionado en cada centro
    // Calculo de promedio de nivel de actividad fisica
    // Indicar para cada nivel en que centro se observo la mayor cantidad de respuestas.
    // Indicar que actividad o actividades superan el promedio


PROGRAMA CENTRO_DEPORTIVO

    VARIABLES:
        actFisica_NIVEL1, actFisica_NIVEL2, actFisica_NIVEL3, actFisica_NIVEL4: ENTERO
        
        actividad: ENTERO
        promedioACT1, promedioACT2, promedioACT3: REAL
        promedioTotal: REAL
        
        cantTotalACT1, cantTotalACT2, cantTotalACT3: ENTERO
        cantTotalEncuestas: ENTERO
        
        actividadMasFrecuenteCENTRO1: ENTERO
        actividadMasFrecuente: CARACTER

        i: ENTERO
        Rta, Hay: CARACTER
        maxActNivel1, maxActNivel2, maxActNivel3: ENTERO
        centroMaxAct1, centroMaxAct2, centroMaxAct3: ENTERO
        
        actividadMasFrecuenteACT1, actividadMasFrecuenteACT2, actividadMasFrecuenteACT3: ENTERO
        
    PROCEDIMIENTO CALCULO_PROMEDIOS(cantTotalACT1: ENTERO, cantTotalACT2: ENTERO, cantTotalACT3: ENTERO, cantTotalEncuestas: ENTERO, REF promedioACT1: REAL, REF promedioACT2: REAL, REF promedioACT3: REAL, REF promedioTotal: REAL)
        HACER
            promedioTotal = ((cantTotalACT1 * 1)+(cantTotalACT2 * 2)+(cantTotalACT3 * 3))/cantTotalEncuestas
            
            promedioACT1 = cantTotalACT1/cantTotalEncuestas
            promedioACT2 = cantTotalACT2/cantTotalEncuestas
            promedioACT3 = cantTotalACT3/cantTotalEncuestas

            IMPRIMIR: "El promedio total de actividad en este nivel es de: ", promedioTotal
            Si (1 * promedioACT1 > promedioTotal) Entonces
                IMPRIMIR: "Las personas sedentarias superan el promedio en este nivel, con un promedio de: ", promedioACT1
            Fin Si
            
            Si (2 * promedioACT2 > promedioTotal) Entonces
                IMPRIMIR: "Las personas moderadas superan el promedio en este nivel, con un promedio de: ", promedioACT2
            Fin Si
            
            Si (3 * promedioACT3 > promedioTotal) Entonces
                IMPRIMIR: "Las personas activas superan el promedio en este nivel, con un promedio de: ", promedioACT3
            Fin Si
        FIN HACER    
    FIN PROCEDIMIENTO
    
        maxActNivel1 = 0
        maxActNivel2 = 0
        maxActNivel3 = 0

        centroMaxAct1 = 0
        centroMaxAct2 = 0
        centroMaxAct3 = 0
        
        REPETIR PARA (i=1, i<=4, i++)
            cantTotalEncuestas = 0
            actFisica_NIVEL1 = 0
            actFisica_NIVEL2 = 0
            actFisica_NIVEL3 = 0
            
            promedioACT1 = 0
            promedioACT2 = 0
            promedioACT3 = 0
            
            promedioTotal = 0
            Rta = "S"

            
            REPETIR MIENTRAS (Rta = "S" o "s")
                IMPRIMIR: "NIVEL: ", i
                IMPRIMIR: "INGRESE CON LOS NUMEROS INDICADOS EL NIVEL DE ACTIVIDAD FISICA"
                IMPRIMIR: "1: Sedentario, 2: Moderado, 3: Activo"
                LEER: actividad 
                Si (actividad = 1) Entonces
                    actFisica_NIVEL1++
                    Sino Si (actividad = 2) Entonces
                    actFisica_NIVEL2++
                        Sino Si (actividad = 3) Entonces
                        actFisica_NIVEL3++
                        Fin Si
                    Fin Si
                Fin Si
                cantTotalEncuestas++
                IMPRIMIR: "¿Hay otra encuesta para este nivel? (S/N)"
                LEER: Hay
                Si (Hay = "S" o "s") Entonces
                    Rta = "S"
                    Sino Si (Hay = "N" o "n") Entonces
                        Rta = "N"
                    Fin Si
                Fin Si
            FIN REPETIR MIENTRAS

            CALCULO_PROMEDIOS(actFisica_NIVEL1, actFisica_NIVEL2, actFisica_NIVEL3, cantTotalEncuestas, REF promedioACT1, REF promedioACT2, REF promedioACT3, REF promedioTotal)
            
            Si (actFisica_NIVEL1 > actFisica_NIVEL2 y actFisica_NIVEL1 > actFisica_NIVEL3) Entonces
                actividadMasFrecuenteCentro1 = actFisica_NIVEL1
                actividadMasFrecuente = "Sedentario"
                Sino Si (actFisica_NIVEL2 > actFisica_NIVEL1 y actFisica_NIVEL2 > actFisica_NIVEL3) Entonces
                actividadMasFrecuenteCentro1 = actFisica_NIVEL2
                actividadMasFrecuente = "Moderado"
                    Sino Si (actFisica_NIVEL3 > actFisica_NIVEL1 y actFisica_NIVEL3 > actFisica_NIVEL2) Entonces
                actividadMasFrecuenteCentro1 = actFisica_NIVEL3
                actividadMasFrecuente = "Activo"
                    Fin Si
                Fin Si
            Fin Si
            
            Si (actFisica_NIVEL1 > maxActNivel1) Entonces
                maxActNivel1 = actFisica_NIVEL1
                centroMaxAct1 = i
            Fin Si
            
            Si (actFisica_NIVEL2 > maxActNivel2) Entonces
                maxActNivel2 = actFisica_NIVEL2
                centroMaxAct2 = i
            Fin Si
            
            Si (actFisica_NIVEL3 > maxActNivel3) Entonces
                maxActNivel3 = actFisica_NIVEL3
                centroMaxAct3 = i
            Fin Si
            
            IMPRIMIR: "El nivel de actividad mas frecuentado en el nivel: ", i, "es: ", actividadMasFrecuente, "con una cantidad de: ", actividadMasFrecuenteCentro1
            IMPRIMIR: "CANTIDAD DE RESPUESTAS EN CENTRO: ", i
            IMPRIMIR: "Sedentarios: ", actFisica_NIVEL1
            IMPRIMIR: "Moderados: ", actFisica_NIVEL2
            IMPRIMIR: "Activos: ", actFisica_NIVEL3

        FIN REPETIR PARA 
            IMPRIMIR: "El centro con mas respuestas de actividad sedentaria es: ", centroMaxAct1, " con una cantidad de: ", maxActNivel1, " respuestas."
            IMPRIMIR: "El centro con mas respuestas de actividad moderada es: ", centroMaxAct2, " con una cantidad de: ", maxActNivel2, " respuestas."
            IMPRIMIR: "El centro con mas respuestas de actividad activa es: ", centroMaxAct3, " con una cantidad de: ", maxActNivel3, " respuestas."
    FIN HACER      
FIN PROGRAMA