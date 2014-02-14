#include "Queue.h"

// Constructors
Queue::Queue()
{
    queue = new Vector();
}

Queue::Queue(const Queue &q)
{
    this->queue = new Vector(q.getVector());
}

Queue::Queue(unsigned int length) 
{// I implement this constructor only for not change the Tests
    this->queue = new Vector(length);
}

// Destructor
Queue::~Queue()
{
    delete queue;
}

// Class Methods
void Queue::enqueue(const double element)
{
    queue->push_back(element);
}

Vector Queue::getVector() const
{
    return *this->queue;
}

double Queue::dequeue()
{
    return queue->pop_front();
}
