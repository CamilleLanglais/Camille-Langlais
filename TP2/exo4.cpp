#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes
	int pivot=toSort.size()/2;
	for(uint i=0;i<pivot;i++){
		lowerArray.insert(toSort[i],i)
	}
	for(uint j=pivot;j<size;j++){
		greaterArray.insert(toSort[j],j);
	}
	recursivQuickSort(lowerArray,size);
	recursivQuickSort(greaterArray,size);
	// split
	
	// recursiv sort of lowerArray and greaterArray

	// merge
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
