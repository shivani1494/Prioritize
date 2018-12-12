#include <iostream>
#include <array>
#include <string>
#include "pq.h"

using namespace std;

int main()
{
    prioriyQueue pq =  prioriyQueue();
    pq.insert("hi", "hihi", (int)4);
    pq.insert("hi", "hihi", (int)5);
    pq.insert("hi", "hihi", (int)6);
    
    pq.printAllPQNodes();
    //pqNode* node = pq.extractMax();
    cout << " This is the maximum element- " << (pq.extractMax())->pri << "\n";
    cout << " This is the maximum element- " << (pq.extractMax())->pri << "\n";
    cout << " This is the maximum element- " << (pq.extractMax())->pri << "\n";
}