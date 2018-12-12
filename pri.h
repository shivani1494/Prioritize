#ifndef PRI_H
#define PRI_H
#include "graph.h"
#include "priorityqueue.h"

using namespace std;

class Prioritize {

    private:
        //constructor
        Prioritize(){};        
    public:
        void GetAllTasks();
        void GetAllSubTasks(int taskNum);
        pqNode* FindTask(int taskNum);
        
        void AddTask(string taskName, string taskDetails, int priority);
        void AddSubTask(string subTaskName, string subTaskDetails, int taskNum);

        void DeleteTask(int taskNum);
        void DeleteSubTask(int taskNum);
        
        //can add functionality to modify task

};

#endif