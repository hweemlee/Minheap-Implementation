//Hwee Lee
//CSE310 B
//util.cpp - Contains various miscellaneous functions


#include <iostream>
#include <string>
#include <fstream>

#include "heap.h"
#include "util.h"

using namespace std;

void heapChoices() {



heap heap1; //global heap
char choice;
string input;
int heapMade = 0; //checks if heap1 has been intialized

//program loops until user enters S
do{

   cout << "Enter a command: "<<endl;
   cin >> input;

if( input.length() == 1){
choice = input.at(0);



	
switch (choice){

	case 'C': //intialize heap
		{
			int heap_size;
			cin >> heap_size;
			heap1= Initialize(heap_size);
			heapMade = 1;
			break;
		}
	case 'R': //Reads HEAPinput.txt and builds heap 
		{
			//checks if heap exists
			if (heap1.capacity == NULL){
				cout << "Intialize heap first" <<endl;
			}
			else{
				int arrSize;
				ifstream myFile;
				myFile.open("HEAPinput.txt");
				if(!myFile){
				cout<< "File not found!" <<endl;
				}
				else{
				myFile >> arrSize;
				Element* notHeapArray = new Element[arrSize];
					
				for(int i = 0 ; i <  arrSize ; i++){
					myFile >> notHeapArray[i].key;
				}	
				BuildHeap(&heap1 , notHeapArray , arrSize);
			}
			myFile.close();
			}
		break;
		}
	case 'W': //writes current heap info to screen
		{
			printHeap(&heap1);
			break;
		}
	case 'I': //insert element in heap
		{
			int newKey;
			cin >> newKey;			
			
			//checks if heap was intialized
			if (heapMade == 0){
				cout << "Intialize Heap first" <<endl;
			}

			//checks if heap is full
			else if( heap1.capacity == heap1.size){
				cout << "Could not insert key, heap is full"<<endl;
			}
			else{
				Element insert;
				insert.key = newKey;
				Insert(&heap1, insert);
			}
		break;
		}
	case 'D': //delete min value in heap
	{
		Element min;
		min = DeleteMin(&heap1);
		if (min.key != -1)
		cout<<"Delete " << min.key <<endl; 
		break;
	}
	case 'K': //decrease key
	{
		int index;
		cin >> index;
		int newVal;
		cin >> newVal;
		DecreaseKey(&heap1 ,index , newVal); 
		break;
	}
}//switch statement end
		
}//if statement end

else{
cout<<"Please check input"<<endl;
}

}while(choice != 'S'); //do loop stopping condition



}//fuction end
