// En una campaña de higiene escolar, se realiza una encuesta en 4 escuelas rurales para conocer los hábitos de higiene de sus estudiantes. 
// Por cada alumno se consulta sobre:

// Frecuencia de lavado de manos (respuestas: Nunca, A veces, Siempre).

// Frecuencia de cepillado dental (respuestas: Nunca, A veces, Siempre).

// Se pide:

// Determinar el porcentaje de cada respuesta para lavado de manos y cepillado dental, por cada escuela.

// Determinar cuál escuela tuvo mayor participación en la encuesta.

// Mostrar los porcentajes generales de cada hábito entre todas las escuelas.

// DATOS DE ENTRADA:
    // Encuesta de frecuencia de lavado de manos: Nunca, A veces, Siempre
    // Encuesta de frecuencia de cepillado dental: Nunca, A veces, Siempre

// PROCESOS:
    // Tomar datos de encuesta de lavado de manos
    // Tomar datos de encuesta de cepillado dental
    // Calcular porcentaje por nivel
    // Comparar escuelas para saber la que tuvo mayor participación
    // Calcular porcentajes generales
    // Entregar los resultados finales

// DATOS DE SALIDA:
    // Porcentaje de cada respuesta para lavado de manos y cepillado dental, por cada escuela
    // Escuela con mayor participación
    // Porcentajes generales de cada hábito entre todas las escuelas

PROGRAMA HIGIENE_ESCUELAS

    PROCEDIMIENTO MAYOR_PARTICIPACION(CANT_TOT: ENTERO, REF CANT_MAX: ENTERO, ESCUELA: ENTERO, REF EMAX: ENTERO)
        HACER
            Si (CANT_TOT > CANT_MAX) Entonces
                CANT_MAX = CANT_TOT
                EMAX = ESCUELA
            Fin Si
        FIN HACER
    FIN PROCEDIMIENTO

    VARIABLES:
        ESCUELA, CANT_TOT,CANT_MAX,EMAX: ENTERO
        MANADA,MANAVECES,MASIEMPRE: ENTERO
        DINADA,DIAVECES,DISIEMPRE:ENTERO
        PORCE_MANADA, PORCE_MANAVECES, PORCE_MASIEMPRE: REAL
        PORCE_DINADA, PORCE_DIAVECES, PORCE_DISIEMPRE: REAL
        PORCE_TOT_MANADA, PORCE_TOT_MANAVECES, PORCE_TOT_MASIEMPRE: REAL
        PORCE_TOT_DINADA, PORCE_TOT_DIAVECES, PORCE_TOT_DISIEMPRE: REAL
        CANT_ENCUESTAS: ENTERO
        ACUM_MANADA,ACUM_MANAVECES,ACUM_MASIEMPRE: ENTERO
        ACUM_DINADA,ACUM_DIAVECES,ACUM_DISIEMPRE: ENTERO
        ACUM_ENCUESTAS: ENTERO
        RTA: ENTERO
    
    HACER
        ACUM_DISIEMPRE, ACUM_DIAVECES, ACUM_DINADA = 0
        ACUM_MANADA, ACUM_MANAVECES, ACUM_MASIEMPRE = 0
        CANT_ENCUESTAS = 0
        CANT_MAX = 0
        EMAX = 0
        PORCE_TOT_MANADA, PORCE_TOT_MANAVECES, PORCE_TOT_MASIEMPRE = 0
        PORCE_TOT_DINADA, PORCE_TOT_DIAVECES, PORCE_TOT_DISIEMPRE = 0

        REPETIR PARA (ESCUELA:= 1, 4, ESCUELA+1)
            CANT_ENCUESTAS = 0
            MANADA,MANAVECES,MASIEMPRE = 0
            DINADA,DIAVECES,DISIEMPRE = 0
            PORCE_MANADA, PORCE_MANAVECES, PORCE_MASIEMPRE = 0
            PORCE_DINADA, PORCE_DIAVECES, PORCE_DISIEMPRE = 0
            RTA = 1

            REPETIR MIENTRAS (RTA <> 0)
                IMPRIMIR: "ESCUELA : ", ESCUELA
                IMPRIMIR: "INGRESE CON LOS NUMEROS INDICADOS LA FRECUENCIA DE LAVADO DE MANOS"
                IMPRIMIR: "1: Nada, 2: A veces, 3: Siempre, 0: Cambiar de escuela"
                LEER: RTA
                Si (RTA = 1) Entonces
                    MANADA= MANADA + 1
                    Sino
                    Si (RTA = 2) Entonces
                        MANAVECES= MANAVECES + 1
                        Sino Si (RTA = 3) Entonces
                        MASIEMPRE= MASIEMPRE + 1
                        Sino
                        Si (RTA <> 0) Entonces
                            IMPRIMIR: "Opcion invalida, por favor intente nuevamente"
                        Fin Si
                    Fin Si
                Fin Si
            Fin Si
                IMPRIMIR: "INGRESE CON LOS NUMEROS INDICADOS LA FRECUENCIA DE CEPILLADO DE DIENTES"
                IMPRIMIR: "1: Nada, 2: A veces, 3: Siempre, 0: Cambiar de escuela"
                LEER: RTA
                Si (RTA = 1) Entonces
                    DINADA= DINADA + 1
                    Sino
                    Si (RTA = 2) Entonces
                        DIAVECES= DIAVECES + 1
                        Sino 
                        Si (RTA = 3) Entonces
                        DISIEMPRE= DISIEMPRE + 1
                        Sino
                        Si (RTA <> 0) Entonces
                            IMPRIMIR: "Opcion invalida, por favor intente nuevamente"
                        Fin Si
                    Fin Si
                Fin Si
            Fin Si
            CANT_ENCUESTAS = CANT_ENCUESTAS + 1
        FIN REPETIR MIENTRAS
        ACUM_ENCUESTAS = ACUM_ENCUESTAS + CANT_ENCUESTAS
        ACUM_MANADA = ACUM_MANADA + MANADA
        ACUM_MANAVECES = ACUM_MANAVECES + MANAVECES
        ACUM_MASIEMPRE = ACUM_MASIEMPRE + MASIEMPRE
        ACUM_DINADA = ACUM_DINADA + DINADA
        ACUM_DIAVECES = ACUM_DIAVECES + DIAVECES
        ACUM_DISIEMPRE = ACUM_DISIEMPRE + DISIEMPRE
        
        PORCE_MANADA = (MANADA * 100) / CANT_ENCUESTAS
        PORCE_MANAVECES = (MANAVECES * 100) / CANT_ENCUESTAS
        PORCE_MASIEMPRE = (MASIEMPRE * 100) / CANT_ENCUESTAS
        PORCE_DINADA = (DINADA * 100) / CANT_ENCUESTAS
        PORCE_DIAVECES = (DIAVECES * 100) / CANT_ENCUESTAS
        PORCE_DISIEMPRE = (DISIEMPRE * 100) / CANT_ENCUESTAS
        
        IMPRIMIR: "PORCENTAJE DE HABITOS REGISTRADA EN LA ESCUELA: ", ESCUELA
        IMPRIMIR: "TOTAL DE ENCUESTADOS: ", CANT_ENCUESTAS
        IMPRIMIR: "FRECUENCIA DE LAVADO DE MANOS"
        IMPRIMIR: "NADA: %", PORCE_MANADA
        IMPRIMIR: "AVECES: %", PORCE_MANAVECES
        IMPRIMIR: "SIEMPRE: %", PORCE_MASIEMPRE
        IMPRIMIR: "FRECUENCIA DE CEPILLADO DE DIENTES"
        IMPRIMIR: "NADA: %", PORCE_DINADA
        IMPRIMIR: "AVECES: %", PORCE_DIAVECES
        IMPRIMIR: "SIEMPRE: %", PORCE_DISIEMPRE
        
        MAYOR_PARTICIPACION(CANT_ENCUESTAS, CANT_MAX, ESCUELA, EMAX)
        FIN REPETIR PARA
        
        IMPRIMIR: "LA ESCUELA: ", EMAX, "TUVO LA MAYOR PARTICIPACION CON UN TOTAL DE: ", CANT_MAX
        IMPRIMIR: "LOS RESULTADOS GENERALES FINALES SON"
        IMPRIMIR: "PARA UN TOTAL DE ENCUESTADOS DE: ", ACUM_ENCUESTAS
        IMPRIMIR: "FRECUENCIA DE LAVADO DE MANOS"
        IMPRIMIR: "NADA: ", ACUM_MANADA
        IMPRIMIR: "AVECES: ", ACUM_MANAVECES
        IMPRIMIR: "SIEMPRE: ", ACUM_MASIEMPRE
        IMPRIMIR: "FRECUENCIA DE CEPILLADO DE DIENTES"
        IMPRIMIR: "NADA: ", ACUM_DINADA
        IMPRIMIR: "AVECES: ", ACUM_DIAVECES
        IMPRIMIR: "SIEMPRE: ", ACUM_DISIEMPRE