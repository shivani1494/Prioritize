#include <iostream>
#include <array>
#include <string>
#include "prioriyQueue.h"

using namespace std;

int main()
{
    prioriyQueue pq =  prioriyQueue();
    pq.insert("hi", "hihi", (int)4);
    pq.printAllPQNodes();

}