#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    int a, b;
    srand(time(NULL));
    bool esMayor, esIgual;
    a= rand()%4;
    b= rand()%4;
    esMayor = a > b;
    if (esIgual){
    cout << a << " es igual a " << b << endl;   
    } else {
    if (esMayor){
        cout << a << " es mayor " << b << endl;
    } else {        
        cout << a << " es menor " << b << endl;
    esIgual = a == b;
        }
    }
}