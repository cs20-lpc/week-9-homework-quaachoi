#include <iostream>
#include "QueueFactory.hpp"
#include <cstdlib>

using namespace std;

int main()
{
    QueueFactory<int>* factory = new QueueFactory<int>();

    cout << "----------- Simulation 1 -----------" << endl;
    //Simulation 1
    Queue<int>* arrayQueue = factory->GetQueue(10);

    for(int i = 0; i < 100; i++)
    {
        int randomNumber = (rand() % 3) - 1;
        if(randomNumber >= 0)
        {
            arrayQueue->enqueue(i);
        }
        else
        {
            arrayQueue->dequeue();
        }
        cout << "Iteration " << i << ": ";
        cout << arrayQueue->getLength() << "\n";
    }

    cout << "----------- Simulation 2 -----------" << endl;
    //Simulation 2
    Queue<int>* linkedQueue = factory->GetQueue();

    for(int i = 0; i < 100; i++)
    {
        int randomNumber = (rand() % 3) - 1;
        if(randomNumber >= 0)
        {
            linkedQueue->enqueue(i);
        }
        else
        {
            linkedQueue->dequeue();
        }
        cout << "Iteration " << i << ": ";
        cout << linkedQueue->getLength() << "\n";
    }

    return 0;
}