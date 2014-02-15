#include "vector.h"
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    Vector v, w;
    for(int i =0; i < 3; i++)
    {       
        v.push_back(i);
    }

    w = v;

    cout << v.toString() << endl;
    while(v.isEmpty() == false)
    {
        cout << v.pop_back() << endl;
    }
    cout << v.toString() << endl;
    /*cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;*/

    //cout << v.toString() << endl;

    
    /*for(int i = 0; i < 105; i++)
    {
        v.push_back(i);
        
        //cout << i++ << "Pop: " <<  v.pop_front() << endl;
        
        cout << "Antes pop: " << v.toString() << endl;
        v.pop_front();
        cout << v.toString() << endl;
    }
    cout << v.toString();*/
    return 0;
}