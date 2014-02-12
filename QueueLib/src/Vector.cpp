#include "Vector.h"

Vector::Vector()
{
	array_ = new double[initialSize_];
	size_ = initialSize_;
}

Vector::Vector(unsigned int n)
{
	array_ = new double[n];	
	size_ = n;
}

Vector::~Vector()
{
	if(array_ != NULL)
	{
		delete [] array_;
	}
}

void Vector::resize()
{
	double *newArray = new double[size_ * multiplierResize_];
	memcpy( newArray, array_, size_ * sizeof(double) );

	size_ = size_ * multiplierResize_;
	delete [] array_;
	array_ = newArray;
}

void Vector::set(double elem, unsigned int pos)
{
	if(pos >= size_)
	{
		resize();
	}


}
