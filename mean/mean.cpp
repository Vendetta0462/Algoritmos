#include <iostream>
using namespace std;

int main()
{
    int n;
    float mean, val;
    cout << "Ingrese el número de términos: ";
    cin >> n;
    mean = 0;

    for (int i=1; i<=n; i++){
        cout << "Introduzca el valor " << i << ": ";
        cin >> val;
        mean = mean + val/n;
    }

    cout << "El promedio de los " << n << " términos es igual a: " << mean;
}
