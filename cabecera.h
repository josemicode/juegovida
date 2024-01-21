#define MAX 20

typedef struct{
	int x;	// --> Fila
	int y;	// --> Columna
}Coordenadas;

/*----------------------------------------
Nombre: escribirCoordenadas
Tipo: void
Objetivo: rellenar un vector de las coordenadas escritas de forma iterativa por lectura de entradas del usuario; siendo asi que cada coordenada representara un insecto inicial.
Parametros de entrada:
	Coordenadas v[]: vector a rellenar
	int filas: numero maximo para la coordenada x
	int columnas: numero maximo para la coordenada y
	int insectos: numero total de coordenadas a introducir
Precondiciones: ninguna
Valor devuelto: nada
Autor: Jose Miguel Ojeda Gutierrez
Fecha: 15-12-2023
----------------------------------------*/
void escribirCoordenadas(Coordenadas v[], int filas, int columnas, int insectos);
/*----------------------------------------
Nombre: inicializarHabitat
Tipo: void
Objetivo: inserta los insectos iniciales en el habitat (matriz booleana).
Parametros de entrada:
	bool H[][MAX]: matriz bidimensional de valores booleanos (true = bicho, false = espacio vacio)
	Coordenadas v[]: vector con las coordenadas de los bichos iniciales
	int filas: numero maximo para la primera dimension de la matriz
	int columnas: numero maximo para la segunda dimension de la matriz
	int insectos: numero total de coordenadas a introducir
Precondiciones: haber ejecutado la funcion escribirCoordenadas previamente
Valor devuelto: nada
Autor: Jose Miguel Ojeda Gutierrez
Fecha: 15-12-2023
----------------------------------------*/
void inicializarHabitat(bool H[][MAX], Coordenadas v[], int filas, int columnas, int insectos);
/*----------------------------------------
Nombre: imprimirHabitat
Tipo: void
Objetivo: mostrar el estado actual de la matriz, representando los insectos como "x" y espacios en blanco como "-".
Parametros de entrada:
	bool H[][MAX]: matriz bidimensional de valores booleanos (true = bicho, false = espacio vacio)
	int filas: numero maximo para la primera dimension de la matriz
	int columnas: numero maximo para la segunda dimension de la matriz
Precondiciones: ninguna
Valor devuelto: nada
Autor: Jose Miguel Ojeda Gutierrez
Fecha: 15-12-2023
----------------------------------------*/
void imprimirHabitat(bool H[][MAX], int filas, int columnas);
/*----------------------------------------
Nombre: ciclo
Tipo: void
Objetivo: simula el paso de un ciclo de evolucion, utilizando una matriz auxiliar en la que realizar los cambios respecto a la principal.
Parametros de entrada:
	bool H[][MAX]: matriz bidimensional de valores booleanos (true = bicho, false = espacio vacio)
	int filas: numero maximo para la primera dimension de la matriz
	int columnas: numero maximo para la segunda dimension de la matriz
Precondiciones: preferiblemente haber inicializado la matriz, de no darse esta, no realizara ninguna operacion efectiva.
Valor devuelto: void
Autor: Jose Miguel Ojeda Gutierrez
Fecha: 15-12-2023
----------------------------------------*/
void ciclo(bool H[][MAX], int filas, int columnas);
/*----------------------------------------
Nombre: copiarMatriz
Tipo: void
Objetivo: Simplemente copia los elementos de una matriz a otra
Parametros de entrada:
	bool A[][MAX]: matriz bidimensional de valores booleanos (COPIA)
	bool B[][MAX]: matriz bidimensional de valores booleanos (PLANTILLA A COPIAR)
	int filas: numero maximo para la primera dimension de la matriz (concide con ambas)
	int columnas: numero maximo para la segunda dimension de la matriz (concide con ambas)
Precondiciones: haber llenado la matriz principal (B) de los elementos que queremos replicar en "A".
Valor devuelto: void
Autor: Jose Miguel Ojeda Gutierrez
Fecha: 15-12-2023
----------------------------------------*/
void copiarMatriz(bool A[][MAX], bool B[][MAX], int filas, int columnas);
/*----------------------------------------
Nombre: vecinos
Tipo: int (Entero)
Objetivo: Dada una matriz y una instancia de la estructura de coordenadas a la que se le asignara una posicion concreta de dicha matriz, obtener el numero de insectos que rodean a la casilola en cuestion; teniendo en cuenta el caracter circular de la matriz.
Parametros de entrada:
	bool H[][MAX]: matriz booleana
	Coordenadas posicion: conjunto de coordenadas x-y
	limX: posicion maxima de la matriz en el supuesto eje X
	limY: posicion maxima de la matriz en el supuesto eje Y
Precondiciones: ser llamada a la asignacion de un valor util, pues no actuara por si misma.
Valor devuelto: numero de casillas vecinas en un plano bidimensional circular
Autor: Jose Miguel Ojeda Gutierrez
Fecha: 15-12-2023
----------------------------------------*/
int vecinos(bool H[][MAX], Coordenadas posicion, int limX, int limY);
/*----------------------------------------
Nombre: nuevoEstado
Tipo: bool
Objetivo: evalua si en la casilla dada se dara vida o muerte a un insecto
Parametros de entrada:
	int vecindades: valor respecto al cual se evaluara con una estructura condicional los posibles resultados
Precondiciones: introducir como parametro la funcion vecinos, ademas de ser asignada a una posicion de la matriz booleana para simbolizar el estado del insecto en cuestion
Valor devuelto: verdadero si aparece un bicho, falso si desaparece
Autor: Jose Miguel Ojeda Gutierrez
Fecha: 15-12-2023
----------------------------------------*/
bool nuevoEstado(int vecindades);