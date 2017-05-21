
//Contains function declarations of the heap.cpp file
#include <cstdlib>

#ifndef HEAP_H
#define HEAP_H

struct Element{
	int key;
};

struct heap{
	int capacity;
	int size;
	Element* H;
	//H = (Element*)malloc(sizeof(int[capacity]));
};

//function declarations

heap Initialize(int n);
void BuildHeap(heap* x , Element* A, int arraySize);
void MinHeapify(heap* x, int i);
void Insert(heap* x , Element key);
Element DeleteMin(heap* x);
void DecreaseKey(heap* x , int key , int value);
void printHeap(heap* x);


#endif
