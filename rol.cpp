#include <iostream>
#include <string>

using namespace std;
int main() {
    int a, b;
    bool esMayor;
    cout << " ingrese un numero " << endl;
    cin >> a;
    cout << " ingrese otro numero " << endl;
    cin >> b;
    esMayor = a > b;
    if (esMayor){
        cout << " el numero " << a << " es mayor que " << b << endl;
    }
}