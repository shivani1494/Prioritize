#include <iostream>
#include <string>
//#include <prioriyQueue.h>

using namespace std;

//add edge to a node

//you can at most have 1000 tasks at a given point in time
//TODO - use vectors/lists of dynamically increase size of arrays

struct pqNode {
    string taskName;
    string taskDetails;
    int taskNum;
    int pri;
    //graph* depTasks;
    pqNode(string name, string details, int pri)
    :taskName(name), taskDetails(details), pri(pri), taskNum(0){}
};
//add edge to a node

//you can at most have 1000 tasks at a given point in time
//TODO - use vectors/lists of dynamically increase size of arrays

class prioriyQueue {

    private:
        //constructor
        int totalTaskCount;
        int front;
        int rear;
        int size;
        pqNode* pqArray;
        

    public:
        prioriyQueue();
        pqNode* extractMax();
        void swap(pqNode *x, pqNode *y);
        void insert(string taskName, string taskDetails, int pri);
        void heapify();
        pqNode* findPQNode(int taskNum);
        void printAllPQNodes();
        int parent(int n);
        int leftChild(int n);
        int rightChild(int n);
};


prioriyQueue::prioriyQueue()
{
    front = rear = 0;
    size = 100;
    pqArray = new pqNode[size];
}

void swap(pqNode *x, pqNode *y) 
{ 
    pqNode temp = *x; 
    *x = *y; 
    *y = temp; 
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
  
int prioriyQueue::leftChild(int n) 
{ 
    return (2*n + 1); 
} 

int prioriyQueue::rightChild(int n) 
{ 
    return (2*n + 2); 
} 

void prioriyQueue::insert(string taskName, string taskDetails, int pri)
{
    pqNode* node = new pqNode(taskName, taskDetails, pri)
    node->taskNum = (this->totalTaskCount)++;
    cout << "printing taskNum- " << node->taskNum << "\n";
    totalTaskCount++;

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
        swap(&pqArray[curr], &pqArray[parent(curr)]);
        curr = parent(curr); //this returns a 
    }

}

pqNode* prioriyQueue::extractMax()
{
    if (rear <= 0) 
        return INT_MAX; 
    if (rear == 1) 
    { 
        rear--; 
        return pqArray[0]; 
    } 
  
    // Store the max node, and remove it from heap 
    int root = pqArray[0]; 
    pqArray[0] = pqArray[rear-1]; 
    rear--; 
    heapify(0);
    return root;
}

void prioriyQueue::::heapify(int curr) 
{ 
    int l = left(curr); 
    int r = right(curr); 
    int largest = curr; 
    if (l < size && (pqArray[l])->pri > (pqArray[curr])->pri)
        largest = l; 
    if (r < size && (pqArray[r])->pri > (pqArray[largest])->pri)
        largest = r; 
    if (largest != curr) 
    { 
        swap(&pqArray[curr], &pqArray[largest]); 
        heapify(largest); 
    } 
} 

pqNode* prioriyQueue::findPQNode(int taskNum)
{
    for(int i = 0; i < rear; i++)
    {
        if(pqArray[i]->taskNum == taskNum)
            return pqArray[i];
    }
    return nil;
}

void prioriyQueue::printAllPQNodes()
{
    for(int i = 0; i < rear; i++)
    {
        cout << "Task name- " << pqArray[i]->taskName << " Task details- " << pqArray[i]->taskDetails << " Task Num- " << pqArray[i]->taskNum;
        cout << "\n";
    }
}