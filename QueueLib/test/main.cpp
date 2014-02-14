#include "vector.h"
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    Vector v, w;
    for(int i =0; i < 25; i++)
    {       
        v.push_back(i);
    }

    w = v;

    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;

    cout << v.toString();

    int i =0;
    while(true)
    {
        v.push_back(2.0);
        v.pop_front();
        cout << i++ << endl;
    }
    
    return 0;
}