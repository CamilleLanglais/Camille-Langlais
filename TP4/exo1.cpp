#include "tp4.h"
#include "mainwindow.h"
#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChildIndex(int nodeIndex)
{

    return nodeIndex * 2 +1;
}

int Heap::rightChildIndex(int nodeIndex)
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
        if(this->leftChildIndex(nodeIndex)<heapSize && this->get(nodeIndex) < this->get(this->leftChildIndex(nodeIndex))){
            i_max=this->leftChildIndex(nodeIndex);
       
        }
        if(this->rightChildIndex(nodeIndex)<heapSize && this->get(i_max) < this->get(this->rightChildIndex(nodeIndex))){
            i_max=this.rightChildIndex(nodeIndex);
        }
    if(i_max != nodeIndex){
       this->swap(nodeIndex, i_max);
       this->heapify(heapSize, i_max);
    }
}

void Heap::buildHeap(Array& numbers)
{
    uint size = this->size() - 1;
    for(uint i = size ; i >0 ; i--){
        this->swap(0,i);
        this->heapify(i,0);
    }
}

void Heap::heapSort()
{
    for(int i = this->size()-1 ; i > 0 ; i--){
        this->swap(0,i);
        this->heapify(i,0);
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
