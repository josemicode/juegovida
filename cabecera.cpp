#include<iostream>
#include"cabecera.h"

using namespace std;

	void escribirCoordenadas(Coordenadas v[], int filas, int columnas, int insectos){
		Coordenadas aux;
		bool repetir;
		int m, n;
		
		for(int k = 0; k < insectos; k++){ 
			
			cout << "Insecto " << k+1 << endl;
			do{
				cout << "Coordenada x: " << endl;
				cin >> m;
				cout << "Coordenada y: " << endl;
				cin >> n;
				
				if((m>=filas)||(n>=columnas)){
					repetir = true;
				}else{
					repetir = false;
				}
			}while(repetir);
			
			aux.x = m;
			aux.y = n;
			v[k] = aux;
		}
	}
	
	void inicializarHabitat(bool H[][MAX], Coordenadas v[], int filas, int columnas, int insectos){//bool H[][MAX], Coordenadas v[]
		bool aux;
		
		for(int i = 0; i<filas; i++){
			for(int j = 0; j<columnas; j++){
				aux = false;
				for(int k = 0; k<insectos; k++){
					if((i == v[k].x)&&(j == v[k].y)){
						aux = true;
					}
				}
				H[i][j] = aux;
			}
		}
	}
	
	void imprimirHabitat(bool H[][MAX], int filas, int columnas){
		for(int i = 0; i<filas; i++){
			cout << endl;
			for(int j = 0; j<columnas; j++){
				if(H[i][j]){
					cout << "x";
				}else{
					cout << "-";
				}
			}
		}
	}
	
	void ciclo(bool H[][MAX], int filas, int columnas){
		bool R[MAX][MAX];
		Coordenadas posicion;
		int bichos;
		
		for(int i = 0; i<filas; i++){
			for(int j = 0; j<columnas; j++){
				posicion.x = i;
				posicion.y = j;
				bichos = vecinos(H, posicion, filas - 1, columnas - 1);
				R[i][j] = nuevoEstado(bichos);
			}
		}
		
		copiarMatriz(H, R, filas, columnas);
	}
	
	bool nuevoEstado(int vecindades){
		bool res;
		
		switch(vecindades){
			case 0: case 1: case 4: case 5: case 6: case 7: case 8:
				res = false;
				break;
			case 2: case 3:
				res = true;
				break;
		}
		
		return res;
	}
	
	int vecinos(bool H[][MAX], Coordenadas posicion, int limX, int limY){
		
		int res = 0;
		
		int a[3] = {0, 1, -1};
		int b[3] = {0, 1, -1};
		
		bool limSup = (posicion.x==0);
		bool limInf = (posicion.x==limX);
		bool limIzq = (posicion.y==0);
		bool limDer = (posicion.y==limY);
		
		if(limSup){
			a[2] = limX;
		}else if(limInf){
			a[1] = -limX;
		}
		
		if(limIzq){
			b[2] = limY;
		}else if(limDer){
			b[1] = -limY;
		}
		
		for(int i = 0; i<3; i++){
			for(int j = 0; j<3; j++){
				if(!((i==0)&&(j==0))){
					if(H[posicion.x + a[i]][posicion.y + b[j]]){
						res++;
					}
					//cout<<"e";
				}
			}
		}
		
		return res;
	}
	
	void copiarMatriz(bool A[][MAX], bool B[][MAX], int filas, int columnas){ //Esta función copia un array bidimensional "A" a otro de las mismas dimensiones "B", ambos pasados por parámetros
		for(int i = 0; i<filas; i++){
			for(int j = 0; j<columnas; j++){
				A[i][j] = B[i][j];
			}
		}
	}