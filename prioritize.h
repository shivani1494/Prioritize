#ifndef PRI_H
#define PRI_H
#include "graph.h"
#include "pq.h"

using namespace std;

class Prioritize {

    private:
        prioriyQueue pq;
    public:
        Prioritize();  
        void GetAllMainTasks();
        void GetAllSubTasks(int taskNum);
        
        pqNode* FindTask(int taskNum);
        
        void AddTask();
        void AddSubTask();
    
        void HighestPriorityTask();

        void DoMainTask();
        //Missing Functionality
        void DoSubTask(int taskNum);

};

#endif