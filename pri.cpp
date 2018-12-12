#include <string>
#include "pri.h"

using namespace std;

pqNode* Prioritize::FindTask(int taskNum)
{
    return nil;
}

void Prioritize::GetAllTasks()
{
    cout << "Following are all tasks & task numbers with their priorities- \n";
    printAllPQNodes();
}

void Prioritize::GetAllSubTasks(int taskNum)
{
    pqNode* task = FindTask(taskNum);
    cout << ("Following are all the subtasks and sub task numbers related to task %s- \n", task->taskName);


}



/*
void findGraphNode(array<array<Node*, 5>, 10> adjGraph, string val) {

}

*/