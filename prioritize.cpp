#include <string>
#include<iostream>
#include "prioritize.h"

using namespace std;

//constructor, creating a priority queue
Prioritize::Prioritize()
{
    prioriyQueue pq = prioriyQueue();
}
//TODO - add a destructor

//Note- I/O is very basic, taking only until whitespaces using cin.
//Allows user to add a new main task by inserting into the priority queue
void Prioritize::AddTask()
{
    string taskName, taskDetails; 
    int priority;
    
    cout << "Please enter task name- ";
    //getline(cin, taskName);
    cin >> taskName;
    //cin.ignore();
    //cout << "\n";
    
    cout << "Please enter task details- ";
    cin >> taskDetails;
    //getline(cin, taskDetails);
    //cout << "\n";
    
    cout << "Please enter task priority- ";
    cin >> priority;
    
    
    pq.insert(taskName, taskDetails, priority);
    
}

//Allows user to add subtask by first getting the task number of the main
//task and then adding a vertex and edge for it in the dependency graph
//of the (priority queue) main task node. Note- User must enter
//the subtask(which can also be the root main task itself) 
//for which this dependency is being added as well
void Prioritize::AddSubTask()
{
    int taskNum;
    string taskName, taskDetails; 
    
    cout << "Please enter main task number- ";
    cin >> taskNum;
    //cout << "\n";
    
    pqNode* node = FindTask(taskNum);
    
    cout << "Here are all the dependent tasks- \n";
    //cout << "\n";
    
    graph* g = node->depTasks;
    g->printDepGraph();
    
    int subMainNum;
    
    //Note- Can check for invalid vertex numbers here and throw error
    cout << "Enter the task number(vertex) to add dependent task for- ";
    cout << "Note- do not enter invalid task numbers(vertices)";
    cin >> subMainNum;
    //cout << "\n";
    
    cout << "Please enter sub task name- ";
    cin >> taskName;
    //cout << "\n";
    
    cout << "Please enter sub task details- ";
    cin >> taskDetails;
    //cout << "\n";
    
    int subDepTaskNum = g->addVertex(taskName, taskDetails);
    cout << subDepTaskNum << "\n";
    g->addEdge(subMainNum, subDepTaskNum);
    
}

//This is a helper function to find task with a given task number
pqNode* Prioritize::FindTask(int taskNum)
{
    pqNode* node = pq.findPQNode(taskNum);
    return node;
    
}

//Prints all the tasks from the PQ
void Prioritize::GetAllMainTasks()
{
    cout << "Following are all your tasks \n";
    pq.printAllPQNodes();
}

//Prints all the tasks from the graph from the PQNode with given task number
void Prioritize::GetAllSubTasks(int taskNum)
{
    pqNode* task = FindTask(taskNum);
    graph* g = task->depTasks;
    g->printDepGraph();

}

//TODO- If the subtasks are unfinished refrain user from completing main task.
//Ask user to complete subtasks - by printing remaining subtasks
//deleting those once finished and then allowing user to mark of main task.
void Prioritize::DoMainTask()
{
    //As name suggests, allows user to complete main task and remove from the
    //list of task.
    pq.extractMax();
}

//Gets the highest priority task for the user to finish.
void Prioritize::HighestPriorityTask()
{
    pqNode* node = pq.getMax();
    cout << "This is your HighestPriorityTask- " << node->taskName;
    cout << "Here are the task details- " << node-> taskDetails << "\n";
}