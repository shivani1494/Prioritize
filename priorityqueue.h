#ifndef PQ_H
#define PQ_H
#include <iostream>
#include <string>
//#include "graph.h"

using namespace std;


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
//TODO- add destructor if you allocate space for the array

class prioriyQueue {

    private:
        //constructor
        int totalTaskCount;
        int front;
        int rear;
        int size;
        pqNode* pqArray[100];

    public:
        prioriyQueue();
        pqNode* extractMax();
        void swap(pqNode *x, pqNode *y);
        void insert(string taskName, string taskDetails, int pri);
        void heapify(int curr);
        pqNode* findPQNode(int taskNum);
        void printAllPQNodes();
        int parent(int n);
        int left(int n);
        int right(int n);
};

#endif