#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    int arma, escudo, dano;
    srand(time(NULL));
    arma = rand()%6+1;
    arma += rand()%6+1;
    arma += 3;

    escudo = rand()%4+1;
    escudo += rand()%4+1;
    escudo += 1;
    dano = arma - escudo;
    if (dano > 0){
        cout << " el dano es " << dano << endl;
    } else {        
        cout << " no sufrio dano " << endl;
    }
}