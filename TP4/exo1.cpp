#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{

    return nodeIndex * 2 +1;
}

int Heap::rightChild(int nodeIndex)
{
    return nodeIndex * 2 + 2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
    (*this)[i]=value;
    while(i>0 && (*this)[i]>(*this)[(i-1)/2]){
        swap(i, (i-1)/2);
        i=(i-1)/2;
	}

}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
    int i_max=nodeIndex;
    if(i_max == leftChild(nodeIndex && leftChild(nodeIndex)<heapsize)){
        swap( );


    }
            if(i_max == rightChild){

}
}

void Heap::buildHeap(Array& numbers)
{

}

void Heap::heapSort()
{

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
