#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split
	for(uint i=0;i<origin.size()/2;i++){
		first[i]=origin[i];
	}
	for(uint i=0;i<origin.size()-first.size()){
		second[i]=origin[i+first.size()];
	}
	
	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second)

	// merge
	merge(first, second, origin);

}

void merge(Array& first, Array& second, Array& result)
{
	int cursor1=0;
	int cursor2=0;
	for(int i=0;i<result.size;i++){
		if(first[cursor1]<second[cursor2]){
			result[i]=cursor1;
			cursor1++;
		}
		else{
			result[i]=cursor2;
			cursor2++;
		}
		// si un des deux dépasse on break
	}

}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
