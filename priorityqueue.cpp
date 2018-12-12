#include <iostream>
#include <string>
#include "pq.h"

using namespace std;

//add edge to a node

//you can at most have 1000 tasks at a given point in time
//TODO - use vectors/lists of dynamically increase size of arrays


prioriyQueue::prioriyQueue()
{
    front = rear = 0;
    size = 100;
    totalTaskCount = 0;
    //pqArray = new pqNode*[size];
}

void swap(pqNode *x, pqNode *y) 
{ 
    pqNode* temp = x; 
    x = y; 
    y = temp; 
} 

/*
prioriyQueue::~prioriyQueue()
{
    delete[] array;
}
*/

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
    cout << "printing taskNum- " << node->taskNum << "\n";
    this->totalTaskCount++;

    //if the queue is full
    if (rear == size) 
    { 
        cout << "Task could not be inserted"; 
        return; 
    } 

    //if the queue is empty
    
    //check if this was actually incremented
    pqArray[rear+1] = node;
    rear += 1;
    int curr = rear;

    //heapify if the property is violated
    //check if you are storing objects or are you storing pointers
    while(curr != 0 && (pqArray[parent(curr)])->pri < node->pri)
    {
        //swap(pqArray[curr], pqArray[parent(curr)]);
        pqNode* temp = pqArray[curr]; 
        pqArray[curr] = pqArray[parent(curr)]; 
        pqArray[parent(curr)] = temp;
        curr = this->parent(curr); //this returns a 
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

pqNode* prioriyQueue::extractMax()
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
    pqArray[0] = pqArray[rear-1]; 
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
        cout << "Task name- " << pqArray[i]->taskName << " Task details- " << pqArray[i]->taskDetails << " Task Num- " << pqArray[i]->taskNum;
        cout << "\n";
    }
}