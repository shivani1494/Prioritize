#include <iostream>
#include <string>
#include "pq.h"

using namespace std;


//TODO - use vectors/lists/array to dynamically increase size
prioriyQueue::prioriyQueue()
{
    front = rear = 0;
    //can use dynamic allocation to change size.
    size = 1000;
    totalTaskCount = 0;
}

int prioriyQueue::parent(int n) 
{ 
    return (n-1)/2; 
}
  
int prioriyQueue::left(int n) 
{ 
    return (2*n + 1); 
} 

int prioriyQueue::right(int n) 
{ 
    return (2*n + 2); 
} 

void prioriyQueue::insert(string taskName, string taskDetails, int pri)
{
    pqNode* node = new pqNode(taskName, taskDetails, pri);
    node->taskNum = (this->totalTaskCount) + 1;
    graph* g = node->depTasks;
    g->setRoot(taskName, taskDetails);
    
    totalTaskCount++;

    //if the queue is full
    if (rear == size) 
    { 
        cout << "You have a long list of pending tasks, please resolve those before adding new tasks \n"; 
        return; 
    }
    
    rear++; 
    int curr = rear - 1; 
    pqArray[curr] = node;

    //heapify if the property is violated
    while(curr != 0 && (pqArray[parent(curr)])->pri < node->pri)
    {
        pqNode* temp = pqArray[curr]; 
        pqArray[curr] = pqArray[parent(curr)]; 
        pqArray[parent(curr)] = temp;
        curr = parent(curr); 
    }

}

void prioriyQueue::heapify(int curr) 
{ 
    int l = this->left(curr);
    int r = this->right(curr);
    int largest = curr; 
    
    if (l < rear && (pqArray[l])->pri > (pqArray[curr])->pri)
        largest = l; 
    if (r < rear && (pqArray[r])->pri > (pqArray[largest])->pri)
        largest = r; 
    if (largest != curr) 
    { 
        //swap(pqArray[curr], pqArray[largest]); 
        pqNode* temp = pqArray[curr]; 
        pqArray[curr] = pqArray[largest]; 
        pqArray[largest] = temp;
        
        this->heapify(largest); 
    } 
} 


pqNode* prioriyQueue::getMax()
{
    if (rear <= 0) 
        return nullptr; 
    if (rear == 1) 
    { 
        rear--; 
        return pqArray[0]; 
    } 
    // Store the max node, and remove it from heap 
    pqNode* root = pqArray[0]; 
    return root;
    
}

pqNode* prioriyQueue::extractMax()
{
    
    // Store the max node, and remove it from heap 
    pqNode* root = getMax(); 
    pqArray[0] = pqArray[rear-1];
    
    //Note- bad practise- havent deallocated space.
    rear--;
    this->heapify(0);
    return root;
}

pqNode* prioriyQueue::findPQNode(int taskNum)
{
    for(int i = 0; i < rear; i++)
    {
        if(pqArray[i]->taskNum == taskNum)
            return pqArray[i];
    }
    return nullptr;
}

void prioriyQueue::printAllPQNodes()
{
    for(int i = 0; i < rear; i++)
    {
        cout << "TASK NAME: " << pqArray[i]->taskName << "\n";
        cout << "NUMBER: " << pqArray[i]->taskNum << " DETAILS: " << pqArray[i]->taskDetails << " PRIORITY: " << pqArray[i]->pri;
        cout << "\n";
    }
}