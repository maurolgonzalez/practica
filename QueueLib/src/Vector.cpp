#include "Vector.h"
#include <sstream>  
#include <iostream> // TODO: Remove
// Constructors
Vector::Vector()
{	
    array_ = NULL;
	size_ = 0;
    capacity_ = 0;
    first_ = 0;
    last_ = size_;
}

Vector::Vector(unsigned int n)
{
	array_ = new double[n];	
    for(unsigned int i=0; i < n; i++)
        array_[i] = 0.0;
	size_ = n;
    capacity_ = n;
    first_ = 0;
    last_ = size_;
}

Vector::Vector(const Vector &v)
{
    setArray(v.getArray(), v.getSize());
}

Vector::Vector(const double* const array, const unsigned int nArray)
{
    array_ = NULL;
	setArray(array, nArray);
}

// Destructor
Vector::~Vector()
{
    delete [] array_;	
}

// Class Methods
void Vector::resize()
{//std::cout << toString() << std::endl;
    unsigned int newCapacity = (capacity_ <= 0? 1: capacity_) * multiplierResize_;
	double *newArray = new double[newCapacity];
	//memcpy( newArray, array_, size_ * sizeof(double) );
    
    unsigned int currentPos = first_;
    double currentElement = 0.0;
    for(unsigned int i = 0; i < getSize(); i++)
    {        
        currentElement = get(currentPos++);
        newArray[i] = currentElement;
        if(currentPos > capacity_)
            currentPos = 0;       
    }


	capacity_ = newCapacity;    
	delete [] array_;
	array_ = newArray;
    first_ = 0;
    last_ = size_ == 0? -1: size_-1;
    //std::cout << toString() << std::endl;
}

void Vector::set(double elem, unsigned int pos)
{   //TODO: Throw exception pos > size 
    array_[pos] = elem; 
}

unsigned int Vector::getSize() const
{
    return size_;
}

double* Vector::getArray() const
{
	double* newArray = new double[size_];

    unsigned int currentPos = first_;
    for(unsigned int i = 0; i < getSize(); i++)
    {        
        newArray[i] = get(currentPos++);
        if(currentPos > capacity_)
            currentPos = 0;       
    }

    return newArray;
}

void Vector::setArray(const double* const array, const unsigned int nArray) //TODO: Improve
{ 
	array_ = new double[nArray];	

    memcpy( array_, array, nArray * sizeof(double) );
    
	size_ = nArray;
    capacity_ = nArray;
    first_ = 0;
    last_ = size_;
}

double Vector::get(unsigned int pos) const
{
    return array_[pos];
}

Vector& Vector::operator+(const Vector& v)
{
    // Here i can throw an Exception instead add vectors with different size
    unsigned int maxSize = v.getSize() > this->getSize()? v.getSize() : this->getSize();
    
    Vector *newVector = new Vector(maxSize);

    double valueV = 0.0, valueW = 0.0;
    for(unsigned int i = 0; i < maxSize; i++)
    {        
        valueV = i < v.getSize()? v.get(i) : 0.0;        
        valueW = i < this->getSize()? this->get(i) : 0.0;

        newVector->set(valueV + valueW, i);
    }    
    
    return *newVector;
}

Vector& Vector::operator=(const Vector& other)
{
    if (this == &other)     
        return *this; 
    
    this->setArray(other.getArray(), other.getSize());

    return *this;
}

void Vector::push_back(const double elem)
{
    if(size_  + 1 >= (capacity_))
    {
        resize();
    }

    if(&array_[last_] == &array_[capacity_])
    {
        last_ = 0;
    }
    else
    {
        last_++;
    } 

    array_[last_] = elem; 
    size_++;

     
}

double Vector::pop_back()
{
    double lastElement = array_[last_--];
    if(last_ < 0)
        last_ = capacity_;
    size_--;
    return lastElement;
}

double Vector::pop_front()
{
    double frontElement = array_[first_];
    array_[first_++] = 0.0;

    size_--;
    if(first_ > capacity_)
        first_ = 0;

    return frontElement;
}

bool Vector::isEmpty()
{
    return size_ == 0;
}

std::string Vector::toString()
{
    std::string result = "";
    std::ostringstream s;
    s << "[";

    unsigned int firstElement = first_;
    for(unsigned int i = 0; i < getSize(); i++)
    {        
        s << get(firstElement++);
        if(firstElement > capacity_)
            firstElement = 0;

        if(i != getSize() -1)
            s << ", ";        
    }

    s << "]";
    result = s.str();
    return result;
}

double dotProduct(const Vector& v, const Vector& w)
{	
    if(v.getSize() != w.getSize())
    {
        throw new std::exception("Length of vertors cannot be different for Dot Product");
    }

    double result = 0.0;

    for(unsigned int i = 0; i < v.getSize(); i++)
    {
        result += v.get(i) * w.get(i);
    }

	return result;
}