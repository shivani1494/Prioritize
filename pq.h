#ifndef PQ_H
#define PQ_H
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;


struct pqNode {
    string taskName;
    string taskDetails;
    int taskNum;
    int pri;
    graph* depTasks;
    pqNode(string name, string details, int pri)
    :taskName(name), taskDetails(details), pri(pri), taskNum(0), depTasks(new graph())
    {}
    //Note- need a destructor to deallocate space for the graph
};



class prioriyQueue {

    private:
        //constructor
        int totalTaskCount;
        int front;
        int rear;
        int size;
        pqNode* pqArray[1000];
        //TODO - use vectors/lists of dynamically increase size of arrays
        

    public:
        prioriyQueue();
        pqNode* extractMax();
        pqNode* getMax();
        void insert(string taskName, string taskDetails, int pri);
        void heapify(int curr);
        pqNode* findPQNode(int taskNum);
        void printAllPQNodes();
        int parent(int n);
        int left(int n);
        int right(int n);
};

#endif