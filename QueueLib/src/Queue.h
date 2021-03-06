#ifndef QUEUE_H
#define	QUEUE_H

#include "Vector.h"

const int vector_getter_defined = 0; //this is just to be used for unit testing.


/**
 * Queue class
 * Representation of a Queue as in "http://en.wikipedia.org/wiki/Queue_(data_structure)"
 */
class Queue
{
public:

    /**
     * Constructor. Empty queue
     */
    Queue();

    /**
     * Constructor
     * @param length is the size of the queue
     * @warning does this method have any sense?
     * @Answer: This is not necessary, becouse the size of queue is changed dinamically with every push and pop.
     */
    Queue(unsigned int length);
    
    /**
     * Constructor (copy)
     * @param q queue to be copied
     */
    Queue(const Queue &q);
    
    /**
     * Destructor.
     * @warning should it be virtual?
     * @Answer: It is not necessary, it is only important when the Queue class will be inherited by another class (not this case).
     */
    /*virtual*/ ~Queue();

    /**
     * Enqueue an element (append it to the end of the queue)
     * @param element to be enqueued
     */
    void enqueue(const double element);

    /**
     * Dequeue an element (extract it from the front of the queue)
     * @return first element in the queue
     */
    double dequeue();

    /**
     * Getter of the inner structure to store de queue
     * @param ??
     * @return ??
     * @warning CHOOSE ONE AND ONLY ONE OF THE DEFINITIONS BELOW
     */
    double* getArray();
    //or
    //void getArray(double *array);
    //or
    //Vector getVector() const;

    //add here whatever you want
    Queue& operator=(const Queue& other);
private:

    Vector *queue;
    //add here whatever you want
};

#endif	/* QUEUE_H */

