#include <iostream>
#include "queuetest.h"
#include "Queue.h"


CPPUNIT_TEST_SUITE_REGISTRATION(queuetest);


queuetest::queuetest() 
{
}


queuetest::~queuetest() 
{
}


void queuetest::setUp() 
{
	nMyArray_ = 5;
    myArray_ = new double [nMyArray_];
    
    for (unsigned int i = 0; i < nMyArray_; i++){
        myArray_[i] = static_cast<double>(i);
    }
}


void queuetest::tearDown() 
{
    delete [] myArray_;
}


void queuetest::testQueue() 
{
    Queue queue;
    CPPUNIT_ASSERT(true);
}

void queuetest::testEnqueue() 
{
    Queue queue;

    for (unsigned int i = 0; i < nMyArray_; i++){
        queue.enqueue(myArray_[i]);
    }
    
    double* array = new double [nMyArray_];
    array  = getArrayAux(queue);
    
    bool ans = true;
    for (unsigned int i = 0; i < nMyArray_; i++){
        ans = ans && (myArray_[i] == array[i]);
    }
    // add delete
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}

void queuetest::testFullEnqueue() 
{
    unsigned int newSize_ = 100;
    Queue queue = Queue(newSize_);
    
    // delete original array
    delete [] myArray_;
    
    myArray_ = new double [newSize_];
    
    for (unsigned int i = 0; i < newSize_; i++){
        myArray_[i] = static_cast<double>(i);
        queue.enqueue(myArray_[i]);
    }
    
    // enqueue and dequeue till we get the original queue
    for (unsigned int i = 0; i < newSize_; i++){
        double value = queue.dequeue();
        queue.enqueue(value);
    }
    
    double* array = new double [newSize_];
    array  = getArrayAux(queue);
    
    bool ans = true;
    for (unsigned int i = 0; i < newSize_; i++){
        ans = ans && (myArray_[i] == array[i]);
    }
    
    // delete array
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}

void queuetest::testDequeue() 
{
    Queue queue;
    
    for (unsigned int i = 0; i < nMyArray_; i++){
        queue.enqueue(myArray_[i]);
    }

    double first = queue.dequeue();
    bool ans = (first == myArray_[0]);
    
    double* array = new double [nMyArray_];
    array = getArrayAux(queue);
    for (unsigned int i = 0; i < nMyArray_-1; i++){
        ans = ans && (myArray_[i + 1] == array[i]);
    }
    CPPUNIT_ASSERT(ans);
    
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    ans = ans && (queue.dequeue() == myArray_[nMyArray_-1]);
    
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}


void queuetest::testGetArray() 
{
    CPPUNIT_ASSERT(true);
}


double* queuetest::getArrayAux(Queue& queue) 
{
    double* array;
    
    switch(vector_getter_defined){
        case 0:
            //array = queue.getArray();
            break;
        case 1:
            //queue.getArray(array);
            break;
        case 2:
            break;
        case 3: 
            Vector v = queue.getVector();
            array = vectortest::getArrayAux(v);
            break;
    }
    
    return array;
}
