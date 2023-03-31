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
    
    // use (*this)[i] or this->get(i) to get a value at index i
    int i_max = nodeIndex;
        if((*this).leftChild(nodeIndex)<heapSize && (*this)[leftChild(nodeIndex)]>(*this)[nodeIndex]){
            i_max=(*this).leftChild(nodeIndex);
       
        }
        if((*this).rightChild(nodeIndex)<heapSize && (*this)[rightChild(nodeIndex)]>(*this)[i_max]){
            i_max=(*this).rightChild(nodeIndex);
        }
    if(i_max != nodeIndex){
        (*this).swap(nodeIndex, i_max);
        (*this).heapify(heapSize, i_max);
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
