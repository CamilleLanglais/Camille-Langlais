#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());
    sorted[0]=toSort[0];

    for(uint n=1;n<toSort.size();n++){
		int nouveau=n;
        for(uint m=0;m<n;m++){
			if(toSort[m]>toSort[n]){
				nouveau=m;
				break;
			}
		}
		sorted.insert(nouveau, toSort[n]);
		
	}

	// insertion sort from toSort to sorted
	
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
