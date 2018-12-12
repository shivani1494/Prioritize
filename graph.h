#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
using namespace std;

struct gVertex {
    string depTaskName;
    string depTaskDetails;
    int depTaskCount;
};

class graph {

    private:
        //constructor
        graph(){};
        int allDepTaskCount;
    public:
        gVertex* findVertex();
        gVertex* addVertex();
        gVertex* addEdge();
        void printGraph();

};

#endif