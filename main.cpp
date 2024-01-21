#include<iostream>
#include"cabecera.h"

#define MAX 20

using namespace std;

	int main(){
		int K, M, N, C; // K = cantidad de insectos, M = filas, N = columnas, C = ciclos.
		Coordenadas vCd[MAX]; // Vector de coordenadas de los insectos iniciales
		bool H[MAX][MAX]; // Matriz que contiene el habitat
		
		do{ // Esa estructura do while lee las entradas de los los parametros esenciales para el funcionamiento, comprobando que no excedan ciertos límites
			cout << "Introduzca el numero de filas del habitat: " << endl;
			cin >> M;
			cout << "Introduzca el numero de columnas del habitat: " << endl;
			cin >> N;
			cout << "Introduzca el numero inicial de insectos: " << endl;
			cin >> K;
			
		}while((M>MAX)||(N>MAX)||(K>(M * N))); // El número de insectos no debe exceder el número máximo posible en función de las filas y columnas
		
		cout << "Introduzca el numero de ciclos: " << endl; // Se pide y lee el numero de ciclos a realizar
		cin >> C;
		
		escribirCoordenadas(vCd, M, N, K); //Se rellena el vector con las posiciones iniciales de los insectos		
		inicializarHabitat(H, vCd, M, N, K); // Inicializamos la matriz de booleanos a partir del vector con las coordenadas con los insectos iniciales
		imprimirHabitat(H, M, N); // Imprimimos el estado incial de la matriz
		
		for(int i = 0; i<C; i++){ // Este bucle muestra los proximos "C" estados, llamado a la funcion que actualiza la matriz al siguiente e imprimiendolo
			ciclo(H, M, N);
			cout << "\n\n";
			imprimirHabitat(H, M, N);
		}
		
		return 0;
	}

