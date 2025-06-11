//En un establecimiento educativo de una localidad rural se quiere saber el estado de nutrición de los chicos que asisten a clases. 
//Actualmente se cuenta con 4 niveles pero no se sabe cuantos alumnos asisten a cada uno de ellos. 
//Por cada nivel y a cada uno de los alumnos se le pregunta sobre el desayuno y la cena, y se establecen 3 respuestas posibles: nada, poco y suficiente, esto lo establece el asistente social que releva la información. 
//Esta informacion se va procesando en tiempo real cargado un formulario en linea de google. 
//Se desea simular el proceso de relevamiento y obtener la siguiente información:
// 1. Determinar por cada uno de los niveles: total de encuestados y visualizar los porcentajes de cada una de las respuesta 
// 2. Determinar cuál de las 4 niveles fue el que tuvo mayor participación
// 3. Porcentajes de cada una de las respuesta de los 4 niveles


// Datos de entrada:

    // Encuestas desayuno: nada, poco y suficiente
    // Encuestas cena: nada, poco y suficiente

// Datos de salida:

    // Por cada nivel: total de encuestados y porcentajes de cada una de las respuesta 
    // Nivel con mayor participación
    // Porcentajes de cada una de las respuesta de los 4 niveles


PROGRAMA nutricion

 PROCEDIMIENTO CALCULO_PORCENTAJES_NIVEL_DESAYUNO(cantNadaDesayuno: ENTERO, cantPocoDesayuno: ENTERO, cantSufiDesayuno: ENTERO, cantTotalDesayuno: ENTERO, REF porcentajeNadaDesayuno: REAL, REF porcentajePocoDesayuno: REAL, REF porcentajeSufiDesayuno: REAL)
    HACER
        porcentajeNadaDesayuno = (cantNadaDesayuno / cantTotalDesayuno) * 100
        porcentajePocoDesayuno = (cantPocoDesayuno / cantTotalDesayuno) * 100
        porcentajeSufiDesayuno = (cantSufiDesayuno / cantTotalDesayuno) * 100
    FIN HACER
FIN PROCEDIMIENTO

PROCEDIMIENTO CALCULO_PORCENTAJES_NIVEL_CENA(cantNadaCena: ENTERO, cantPocoCena: ENTERO, cantSufiCena: ENTERO, cantTotalCena: ENTERO, REF porcentajeNadaCena: REAL, REF porcentajePocoCena: REAL, REF porcentajeSufiCena: REAL)
    HACER
        porcentajeNadaCena = (cantNadaCena / cantTotalCena) * 100
        porcentajePocoCena = (cantPocoCena / cantTotalCena) * 100
        porcentajeSufiCena = (cantSufiCena / cantTotalCena) * 100
    FIN HACER
FIN PROCEDIMIENTO

VARIABLES:
    maxEncuestasTotales, nivelQueMas, RtaCaso, cantNadaDesayuno, cantPocoDesayuno, cantSufiDesayuno, cantTotalDesayuno, cantNadaCena, cantPocoCena, cantSufiCena, cantTotalCena, nivel, cantTotalEncuestasNivel: ENTERO
    porcentajeNadaDesayuno, porcentajePocoDesayuno, porcentajeSufiDesayuno, porcentajeNadaCena, porcentajePocoCena, porcentajeSufiCena: REAL
    Rta: CARACTER
    acumNadaDesayuno, acumPocoDesayuno, acumSufiDesayuno: ENTERO 
    acumNadaCena, acumPocoCena, acumSufiCena: ENTERO
    totalGlobalDesayuno, totalGlobalCena: ENTERO

HACER:
    maxEncuestasTotales = 0
    
    porcentajeNadaCena = 0
    porcentajePocoCena = 0
    porcentajeSufiCena = 0
    porcentajeNadaDesayuno = 0
    porcentajePocoDesayuno = 0
    porcentajeSufiDesayuno = 0
    
    cantTotalDesayuno = 0
    cantTotalCena = 0
    
    totalGlobalDesayuno = 0
    totalGlobalCena = 0
    
    acumNadaDesayuno = 0
    acumPocoDesayuno = 0
    acumSufiDesayuno = 0
    acumNadaCena = 0
    acumPocoCena = 0
    acumSufiCena = 0

    REPETIR PARA (nivel = 1, nivel <=4, nivel++)
        cantNadaDesayuno = 0
        cantPocoDesayuno = 0
        cantSufiDesayuno = 0
        cantTotalDesayuno = 0
        cantNadaCena = 0
        cantPocoCena = 0
        cantSufiCena = 0
        cantTotalCena = 0
        cantTotalEncuestasNivel = 0
        IMPRIMIR: "NIVEL: ", nivel
        IMPRIMIR: "¿Hubo encuestas para este nivel? (S/N)"
        LEER: Rta
        REPETIR MIENTRAS (Rta = "S" O Rta = "s")
            HACER
                IMPRIMIR: "Ingrese el numero del estado de desayuno (1: Nada, 2: Poco, 3: Suficiente): "
                LEER: RtaCaso
                CASO (RtaCaso)
                    1: cantNadaDesayuno++
                    2: cantPocoDesayuno++
                    3: cantSufiDesayuno++
                FIN CASO
                cantTotalDesayuno++
                IMPRIMIR: "Ingrese el numero del estado de cena (1: Nada, 2: Poco, 3: Suficiente): "
                LEER: RtaCaso
                CASO (RtaCaso)
                    1: cantNadaCena++
                    2: cantPocoCena++
                    3: cantSufiCena++
                FIN CASO
                cantTotalCena++
                cantTotalEncuestasNivel++
                IMPRIMIR: "¿Hay otra encuesta para este nivel? (S/N)"
                LEER: Rta
            FIN HACER
        FIN REPETIR MIENTRAS
        
        acumNadaDesayuno = acumNadaDesayuno + cantNadaDesayuno  
        acumPocoDesayuno = acumPocoDesayuno + cantPocoDesayuno
        acumSufiDesayuno = acumSufiDesayuno + cantSufiDesayuno
        acumNadaCena = acumNadaCena + cantNadaCena
        acumPocoCena = acumPocoCena + cantPocoCena
        acumSufiCena = acumSufiCena + cantSufiCena
        
        totalGlobalDesayuno = totalGlobalDesayuno + cantTotalDesayuno
        totalGlobalCena = totalGlobalCena + cantTotalCena
        
        CALCULO_PORCENTAJES_NIVEL_DESAYUNO(cantNadaDesayuno, cantPocoDesayuno, cantSufiDesayuno, cantTotalDesayuno, REF porcentajeNadaDesayuno, REF porcentajePocoDesayuno, REF porcentajeSufiDesayuno)
        CALCULO_PORCENTAJES_NIVEL_CENA(cantNadaCena, cantPocoCena, cantSufiCena, cantTotalCena, REF porcentajeNadaCena, REF porcentajePocoCena, REF porcentajeSufiCena)
        
        Si (cantTotalEncuestasNivel > maxEncuestasTotales) Entonces
            maxEncuestasTotales = cantTotalEncuestasNivel
            nivelQueMas = nivel
        
        IMPRIMIR: "DESAYUNO:"
        IMPRIMIR: "Porcentaje de Nada: ", porcentajeNadaDesayuno
        IMPRIMIR: "Porcentaje de Poco: ", porcentajePocoDesayuno
        IMPRIMIR: "Porcentaje de Suficiente: ", porcentajeSufiDesayuno
        IMPRIMIR: "CANTIDAD DE ENCUESTADOS: ", cantTotalDesayuno
        
        IMPRIMIR: "CENA:"
        IMPRIMIR: "Porcentaje de Nada: ", porcentajeNadaCena
        IMPRIMIR: "Porcentaje de Poco: ", porcentajePocoCena
        IMPRIMIR: "Porcentaje de Suficiente: ", porcentajeSufiCena
        IMPRIMIR: "CANTIDAD DE ENCUESTADOS: ", cantTotalCena
    FIN REPETIR PARA

    IMPRIMIR: "El nivel con mayor participación: ", nivelQueMas, "con ", maxEncuestasTotales, " encuestas"

    IMPRIMIR: "DESAYUNO EN TODOS LOS NIVELES:"
    IMPRIMIR: "Porcentaje de Nada: ", (acumNadaDesayuno/totalGlobalDesayuno)*100
    IMPRIMIR: "Porcentaje de Poco: ", (acumPocoDesayuno/totalGlobalDesayuno)*100
    IMPRIMIR: "Porcentaje de Suficiente: ", (acumSufiDesayuno/totalGlobalDesayuno)*100
    IMPRIMIR: "CANTIDAD DE ENCUESTADOS: ", totalGlobalDesayuno

    IMPRIMIR: "CENA EN TODOS LOS NIVELES:"
    IMPRIMIR: "Porcentaje de Nada: ", (acumNadaCena/totalGlobalCena)*100
    IMPRIMIR: "Porcentaje de Poco: ", (acumPocoCena/totalGlobalCena)*100
    IMPRIMIR: "Porcentaje de Suficiente: ", (acumSufiCena/totalGlobalCena)*100
    IMPRIMIR: "CANTIDAD DE ENCUESTADOS: ", totalGlobalCena
FIN HACER
FIN PROGRAMA
