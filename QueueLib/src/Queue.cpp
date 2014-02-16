#include "Queue.h"

///////////////////////////// Constructors ////////////////////////////////////
Queue::Queue()
{
    queue = new Vector();    
}
/*****************************************************************************/
Queue::Queue(const Queue &q)
{
    this->queue = new Vector(*q.queue);
}
/*****************************************************************************/
Queue::Queue(unsigned int length) 
{// I implement this constructor only for not change the Tests
    this->queue = new Vector(length);
}

///////////////////////////// Destructor ////////////////////////////////////
Queue::~Queue()
{
    delete queue;
}

///////////////////////////// Class Methods ////////////////////////////////////
void Queue::enqueue(const double element)
{
    queue->push_back(element);
}
/*****************************************************************************/
double* Queue::getArray()
{
    return queue->getArray();
}
/*****************************************************************************/
double Queue::dequeue()
{
    return queue->pop_front();
}
/*****************************************************************************/
Queue& Queue::operator=(const Queue& other)
{
    if (this == &other)     
        return *this; 

    delete this->queue;

    this->queue = new Vector(*other.queue);
    return *this;
}
