//Hwee Lee
//CSE310 B
//heap.cpp - contains heap and element structures with various functions to implement heap


#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "heap.h"

using namespace std;



//Heap Functions

heap Initialize(int n){
	heap heap1;   /*Initialize heap1*/

	heap1.capacity = n; /*Heap capacity initialized to n*/
	heap1.size = 0;
	heap1.H = (Element*)malloc(sizeof(Element[n]));

	return heap1;
}



void BuildHeap(heap* x , Element* A , int arraySize){
	
	//sets capacity equal to array size if read file has a larger array	
	if (x->capacity < arraySize ) {
		x->capacity = arraySize;
	}	

	x->size = arraySize; //sets size to array size

	//copies elements in A to heap->h
	for (int index = 1 ; index <= arraySize ; index++){
		x->H[index] = A[index - 1];
	}

	//heapify elements in heap array so it has a min heap property
	for (int i = (arraySize + 1 )/2 ; i >=  1 ; i--  ) {
		MinHeapify(x , i );
	}

}

void MinHeapify(heap* x, int i){
	int minVal;
	int left = 2 * i;
	int right = (2 * i) + 1;

	//left child 
	if (left <=  x->size  &&  ( x->H[left].key < x->H[i].key ) ){
		minVal = left;
	}
	else{
		minVal = i;
	}
	
	//right child
	if(right <= x->size  && x->H[right].key < x->H[minVal].key ){
		minVal = right;
	}

	if(minVal != i){
		//swapping		
		Element temp =  x->H[i];
		x->H[i] = x->H[minVal];
		x->H[minVal] = temp;
		//recursive call on heapify
		MinHeapify(x , minVal);
	}

}


void Insert(heap* x , Element insert){

	x->size = x->size + 1; //increase size by 1
	int index = x->size; //set index to size

	//shifts elements so it maintains min heap after insertion
	while (index > 1 &&  ( x->H[(index/2)].key ) > insert.key ){
		x->H[index] = x->H[index/2];
		index = index/2;
	}

	//inserting in correct location
	x->H[index] = insert;
}


Element DeleteMin(heap* x){

	Element min;

	//empty heap
	if( x->size < 1 ){
		cout << "Error, there are no elements to be deleated "<<endl;
		min.key = -1;
		return min;
	}
	else{ //top element of heap is the minimum 
		min = x->H[1];
		x->H[1] = x->H[x->size];
		x->size--;
		MinHeapify(x , 1); //maintaining min heap property
		return min;
	}

	
}

void DecreaseKey(heap *x , int index , int change){
	
	if (x->H[index].key <  change){
		cout << "The new key is larger than the current key"<<endl;
	}
x	else{ //changing value
		x->H[index].key = change;
		
		while ( (index > 1) && ( (x->H[index/2].key) > (x->H[index].key) )){

			//swapping parent and child
			Element temp = x->H[index];
			x->H[index] = x->H[index/2];
			x->H[index/2] = temp;
			index = index/2;
		}
		
		
	}
}


void printHeap(heap* x){ //print heap info

	cout << "heap size: " << x->size     <<endl;
	cout << "heap cpacity: " << x->capacity  <<endl;

	//loops through and prints out key fields of heap
	for (int i = 1 ; i <=  x->size ; i++){
		cout <<  x->H[i].key << " ";
	}
	
	cout <<endl;
}
