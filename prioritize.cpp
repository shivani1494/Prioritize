//priority queue
//with nodes as a graph

#include <iostream>
#include <array>
#include <string>

using namespace std;

//can have at most 10 nodes in the graph
//each dependent task can have at most 5 dependent tasks
//storing graph as adjacency list
//TODO - use lists/vecs or dynamically increase size of arrays


void AddTask (string task, int pri) {
    pq.addPQNode(task, pri);
}

void FindTask(string mainTask) {
    //find pqNode with the main task
    node = findPQNode(mainTask);
    //then extract the graph inside it and an edge appropriately
    
}

void FindDependentTasks(string mainTask, string depTask) {
    findTask(mainTask);
    graph = node.adjGraph;
    findGraphNode(graph, depTask)
}

void AddDependentTask(string mainTask, string depTask, string subDepTask) {
    findTask(mainTask);
}

//dependent tasks would not have a priority associated 
void AddDependentTask(string mainTask, string depTask) {
    findTask(mainTask);

}

