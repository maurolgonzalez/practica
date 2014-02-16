#include "vector.h"
#include <iostream>
#include <queue>
#include <time.h> 
using namespace std;

void TestGetArray()
{    
    
    clock_t init, parcial, promedio = 0;

    init=clock();
    int ejecuciones = 2;
    for(int j=0; j < ejecuciones; j++)
    {
        Vector v;
        
        for(int i =0; i < 20*1000000; i++)
        {       
            v.push_back(i);

        }
        init=clock();
        double * newArray = v.getArray();
        parcial=clock()-init;
        cout <<parcial << endl;
        promedio += parcial;
    }

    cout <<"Promedio: " << promedio/ejecuciones << endl;


}

int main()
{
    Vector v, w;
    
    TestGetArray();

    /*clock_t init, parcial, promedio = 0;

    init=clock();
    int ejecuciones = 1;
    for(int j=0; j < ejecuciones; j++)
    {
        //Vector v;
        init=clock();
        for(int i =0; i < 50*1000000; i++)
        {       
            v.push_back(i);

        }
        parcial=clock()-init;
        cout <<parcial << endl;
        promedio += parcial;
    }

    cout <<"Promedio: " << promedio/ejecuciones << endl;
    string s;
    
    cin >> s;*/
    
    /*for(int i =0; i < 3; i++)
        {       
            v.push_back(i);
        }
    cout << v.toString() << endl;
    v.pop_front();
    cout << v.toString() << endl;
    v.pop_front();
    cout << v.toString() << endl;
    v.push_back(4);
    cout << v.toString() << endl;
    v.push_back(5);
    cout << v.toString() << endl;
    cout << v.get(1) << endl; 
    v.set(15.0, 1);
    cout << v.toString() << endl;*/

    /*while(v.isEmpty() == false)
    {
        cout << v.pop_back() << endl;
    }*/
    
        
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

