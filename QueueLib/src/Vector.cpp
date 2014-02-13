#include "Vector.h"
#include "stdlib.h"

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
    //posLastElement_ = nArray -1;
}
Vector::~Vector()
{
   // delete [] array_;	
}

void Vector::resize()
{
	double *newArray = new double[capacity_ * multiplierResize_];
	memcpy( newArray, array_, size_ * sizeof(double) );

	capacity_ = capacity_ * multiplierResize_;    
	delete [] array_;
	array_ = newArray;
}

void Vector::set(double elem, unsigned int pos)
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
/*Vector addition(const Vector& v, const Vector& w)
{
	//TODO: Implement
	return Vector();
}*/

Vector operator+(const Vector& v, const Vector& w)
{
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

double dotProduct(const Vector& v, const Vector& w)
{	//TODO: Implement
	return 0.0;
}