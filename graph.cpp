#include "graph.h"

using namespace std;

graph::graph()
{
    front = rear = 0;
    //Note- logically one should have more than x number of tasks at time t
    //can use dynamic allocation to change size.
    size = 10;
    allDepTaskCount = 0;
    root = false;
    
    //Note - implement desctructor to deallocate the space 
    edgeMatrix = new int*[size];
    for (int i = 0; i < size; i++) 
    {
      edgeMatrix[i] = new int[size];
      for (int j = 0; j < size; j++)
            edgeMatrix[i][j] = 0;
    }
    
}

//calling this function without checking for nullptr will lead to segfault
gVertex* graph::findVertex() 
{
    return nullptr;
}

int graph::addVertex(string taskName, string taskDetails)
{
    //can dynamically increase the size
    if(rear == size)
    {
        cout << "Please finish the tasks before adding new";
    }
    
    vertices[rear] = new gVertex(taskName, taskDetails, rear);
    rear += 1;
    return rear - 1;
}

void graph::setRoot(string taskName, string taskDetails)
{
    addVertex(taskName, taskDetails);
    this->rootTask = taskName;
    this->root = true;
}

void graph::addEdge(int mainTask, int depTask)
{
    //directed graph
    //cout << "mainTask- " << mainTask << "dep- " << depTask << "\n";
    edgeMatrix[mainTask][depTask] = 1;
}

void graph::printDepGraph()
{
    //note- root main task is always at 0th position, since it is inserted at the time of creation
    cout << "This is your root main task: " << rootTask << ", its vertex number in your dependency graph- 0" << "\n";
    
    for(int i= 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(edgeMatrix[i][j] == 1)
            {
                cout << "Main Dependent task name: " << vertices[i]->depTaskName << ", its task number(vertex)- " << i << "\n";
                cout << "Sub Dependent task name: " << vertices[j]->depTaskName << ", its task number(vertex)- " << j << "\n";
            }
        }
    }
    return;
}