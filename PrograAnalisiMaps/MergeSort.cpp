/*
 * MergeSort.cpp
 *
 *  Created on: 15 nov. 2020
 *      Author: ferla
 */


#include <iostream>


using namespace std;


void merge(int *array,int firstIndex,int lastIndex,int middle);
void mergesort(int *array,int firstIndex,int lastIndex);

/*int main(void)(){
	const short int cantidad=15;
	srand(time(NULL));
	int *arreglo= new int[cantidad];
	cout<<"\t\tANTES DE ORDENAR\n\n";
	for (int i = 0; i < cantidad; i++) {
		arreglo[i]=rand()%51; //Asignación de número aleatorios entre 0 y 50 en el arreglo de 15 elementos
		cout<<"Arreglo["<<i+1<<"]= "<<arreglo[i]<<endl;
	}
	mergesort1(arreglo,0, cantidad-1); //llamando de la función

	cout<<"\n\n\t\tARREGLO ORDENADO\n";

	for(int i=0;i<cantidad;i++) cout<<"A["<<i+1<<"]= "<<arreglo[i]<<endl;
	delete arreglo;

}
*/
void mergesort(int *array,int firstIndex,int lastIndex){

	if(firstIndex < lastIndex){

		int middle = (firstIndex + lastIndex) /2;

		mergesort(array,firstIndex,middle);
		mergesort(array,middle+1,lastIndex);

		merge(array,firstIndex,lastIndex,middle);
	}
}

void merge(int *array,int firstIndex,int lastIndex,int middle){ //Función encargada de ordenar el arreglo

	int left=firstIndex;
	int right = middle+1;
	int counter=0;
	int *temp = new int[lastIndex - firstIndex+1];

	while ( left <= middle && right <= lastIndex){
		if(array[left]<array[right]){
			temp[counter++] = array[left++];
		}
		else{
			temp[counter++] = array[right++];
		}
	}
	while ( left <= middle) temp[counter++] = array[left++];

	while (right <= lastIndex) temp[counter++] = array[right++];
	for( left = firstIndex; left <= lastIndex; left++){
		array[left] = temp[left-firstIndex];
	}

	delete temp;
}

