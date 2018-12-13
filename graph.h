#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
using namespace std;

struct gVertex
{
  string depTaskName;
  string depTaskDetails;
  int taskNum;

    gVertex (string name, string details, int num):depTaskName (name),
    depTaskDetails (details), taskNum (num){}
};

class graph
{

private:
  //Note- can be implemented using AdjLists more efficiently
  //Note- constraining size to 10, can do dynamic allocation, refrained from using vectors
  gVertex * vertices[10];
  int **edgeMatrix;
  int allDepTaskCount;
  int rear;
  int front;
  int size;
  bool root;
  string rootTask;

public:
    graph ();
  void setRoot (string taskName, string taskDetails);
  gVertex *findVertex ();
  int addVertex (string taskName, string taskDetails);
  void addEdge (int mainTask, int depTask);
  void printDepGraph ();

};

#endif
