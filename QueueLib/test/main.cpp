#include "vector.h"
#include <iostream>
using namespace std;

int main()
{
    Vector v;
    for(int i =0; i < 25; i++)
    {       
        v.push_back(i);
    }

    

    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;

    cout << v.toString();

    return 0;
}