#include <iostream>
#include <array>
#include <string>
#include "prioritize.h"

using namespace std;

int main()
{
    
    Prioritize pri = Prioritize();
    
    cout << "Prioritize" << endl;
    cout << "Limitations- I/O is basic, enter words." << endl;
    //Limitations - currently, can't delete sub tasks for a given main task.
    
    /*
        Supported Functionalities- 
        void GetAllMainTasks();
        void GetAllSubTasks(int taskNum);
        pqNode* FindTask(int taskNum);
        void AddTask();
        void AddSubTask();
        void HighestPriorityTask();
        void DoMainTask();
    */

    //Note- I/O is basic, taking only until whitespaces using cin.
    //Please enter only words, not lines.
    //Adding bunch of tasks
    pri.AddTask();
    pri.AddTask();
    pri.AddTask();
    
    //Getting main task
    pri.GetAllMainTasks();
    //Adding subtask for a given task
    pri.AddSubTask();
    
    //Note- Searching by taskNum instead of searching by task name.
    int taskNum;
    cout << "Please enter main task number for getting all subtasks- ";
    cin >> taskNum;
    cout << "\n";
    //For a given task, get all sub tasks
    pri.GetAllSubTasks(taskNum);
    
    //Extract Max Priority element
    pri.DoMainTask();
    
    //Main tasks should no longer have the done task
    pri.GetAllMainTasks();
    //HighestPriorityTask should have changed
    pri.HighestPriorityTask();
    
    
}