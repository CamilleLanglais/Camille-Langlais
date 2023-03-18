#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	// split
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes
	int pivot=toSort[size-1];
	for(uint i=0;i<size-1;i++){
		if(toSort[i]<pivot){
			lowerArray[lowerSize]=toSort[i];
			lowerSize++;
		}
		else{
            greaterArray[greaterSize]=toSort[i];
			greaterSize++;
		}	
	}

	// recursiv sort of lowerArray and greaterArray
	if(lowerSize>1 ){
		recursivQuickSort(lowerArray,lowerSize);
	}

	if(greaterSize>1){
        recursivQuickSort(greaterArray,greaterSize);
	}

	// merge	
    for(int i=0;i<lowerSize;i++){
		toSort[i]=lowerArray[i];
	}
    toSort[lowerSize]=pivot;
    for(int i=lowerSize+1;i<size;i++){
        toSort[i]=greaterArray[i-lowerSize-1];
	}
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
