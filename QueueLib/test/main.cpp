#include "vector.h"
#include <iostream>
#include <queue>
#include <time.h> 
using namespace std;

int main()
{
    Vector v, w;
    
    clock_t init, parcial, promedio = 0;

    init=clock();
    //
    // do stuff
    //
    int ejecuciones = 1;

    for(int j=0; j < ejecuciones; j++)
    {
        //Vector v;
        init=clock();
        for(int i =0; i < 50*1000000; i++)
        {       
            v.push_back(i);
            /*if(i%1000 == 0)
            cout << i << endl;*/
        }
        parcial=clock()-init;
        cout <<parcial << endl;
        promedio += parcial;
    }
    //w = v;
    cout <<"Promedio: " << promedio/ejecuciones << endl;
    string s;
    
    cin >> s;
    

    

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