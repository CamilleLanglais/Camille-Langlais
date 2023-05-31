#include "tp6.h"
#include <QApplication>
#include <time.h>
#include <cmath>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */
	for(int n = 0; n < nodeCount ; n++){
		GraphNode *new_node = new GraphNode[n];
		this->appendNewNode(new_node);
	}
	 for(int i = 0; i < nodeCount; i++){
		for(int j = 0; j < nodeCount ; j++){
			if(adjencies[i][j]>=1){
				this->nodes[i]->appendNewEdge(this->nodes[j], adjacencies[i][j]);
			}
		}
	 }
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
	  */
   nodes[nodesSize] = first;
   nodesSize ++;
   visited[first->value] = true;

   for(Edge *edge = first->edges; edge!=nullptr; edge = edge->next ){
		if(!visited[edge->destination->value]){
			deepTravel(edge->destination, nodes, nodesSize, visited);
		}
   }
}
/**
 * Fill nodes array by travelling graph starting from first and using queue
 * nodeQueue.push(a_node)
 * nodeQueue.front() -> first node of the queue
 * nodeQueue.pop() -> remove first node of the queue
 * nodeQueue.size() -> size of the queue
 */

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	std::queue<GraphNode *> nodeQueue;
	nodeQueue.push(first);
	visited[first->value] = true;

	while (!nodeQueue.empty())
	{
		GraphNode *current_node = nodeQueue.front();
		nodeQueue.pop();
		nodes[nodesSize] = current_node;
		nodesSize++;

		for (Edge *tmp_edge = current_node->edges; tmp_edge != nullptr; tmp_edge = tmp_edge->next)
		{
			if (!visited[tmp_edge->destination->value])
			{
				nodeQueue.push(tmp_edge->destination);
				visited[tmp_edge->destination->value] = true;
			}
		}
	}
}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
	**/
	visited[first->value] = true;
	
	for (Edge *edge = first->edges; edge != nullptr; edge = edge->next)
	{
		if (!visited[edge->destination->value])
		{
			bool answer = detectCycle(edge->destination, visited);
			if (answer == true)
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}

	return false;

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}
