#include "Vector.h"
#include <sstream>  

// Constructors
Vector::Vector()
{
	array_ = new double[initialSize_];
	capacity_ = initialSize_;
    size_ = 0;
}

Vector::Vector(unsigned int n)
{
	array_ = new double[n];	
	size_ = n;
    capacity_ = n;
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
   // delete [] array_;	
}

// Class Methods
void Vector::resize()
{
	double *newArray = new double[capacity_ * multiplierResize_];
	memcpy( newArray, array_, size_ * sizeof(double) );

	capacity_ = capacity_ * multiplierResize_;    
	delete [] array_;
	array_ = newArray;
}

void Vector::set(double elem, unsigned int pos) //TODO: can do an insert?
{    
    array_[pos] = elem;    
}

unsigned int Vector::getSize() const
{
    return size_;
}

double* Vector::getArray() const
{
	return array_;
}

void Vector::setArray(const double* const array, const unsigned int nArray) //TODO: Improve
{    
    /*if(array_ != NULL)
    {
        delete [] array_;
        array_ = NULL;
    }*/

	array_ = new double[nArray];	
	for(unsigned int i = 0; i < nArray; i++)
	{		
        set(array[i], i);
	}

	size_ = nArray;
    capacity_ = nArray;
}

double Vector::get(unsigned int pos) const
{
    return array_[pos];
}

Vector operator+(const Vector& v, const Vector& w)
{
    // Here i can throw an Exception instead add vectors with different size
    unsigned int maxSize = v.getSize() > w.getSize()? v.getSize() : w.getSize();

    Vector newVector(maxSize);

    double valueV = 0.0, valueW = 0.0;
    for(unsigned int i = 0; i < maxSize; i++)
    {        
        valueV = i < v.getSize()? v.get(i) : 0.0;        
        valueW = i < w.getSize()? w.get(i) : 0.0;

        newVector.set(valueV + valueW, i);
    }    
    
    return newVector;
}

void Vector::push_back(double elem)
{
    if(size_  + 1 >= (capacity_))
    {
        resize();
    }
    array_[size_++] = elem;

}

std::string Vector::toString()
{
    std::string result = "";
    std::ostringstream s;
    s << "[";

    for(unsigned int i = 0; i < getSize(); i++)
    {
        
        s << get(i);
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