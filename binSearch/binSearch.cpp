#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    // Se genera la lista alleatoriamente sobre la cual se va a ordenar y buscar
    int n;
    cout << "Ingrese el número de elementos para generar el array: "; cin >> n;
    int a[n];
    // Utilizamos una semilla distinta en cada ejecución usando el tiempo
    srand(time(0));
    for (int i = 0; i<n; i++) a[i] = rand() % 100;

    // Ordenamos el vector
    int temp;
    for (int i = 0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (a[i]>a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    // Imprimimos el vector y preguntamos el valor a buscar
    cout << "El vector en el que se busca es:" << endl << "[ ";
    for (int i:a) cout << i << " ";
    int T;
    cout << "]" << endl << "Ingrese el valor entero que se desea buscar en el array: "; cin >> T;

    // Iniciamos la busqueda asignando los límites izq y der en el array
    int L=0, R=n-1;

    // Mientras el limite izq sea menor al der, comparamos el valor en la mitad y verificamos si
    // el numero a encontrar esta en el bloque izquierdo o derecho, reseteamos el limite lateral
    // necesario y repetimos el proceso
    while (L<R)
    {
        int m = floor((L+R)/2);
        if (a[m] < T)
        {
            L = m+1;
            if (a[L]==T)
            {
                cout << "El número T = " << T << " se encuentra en la posición " << L;
                exit(0);
            }
        } else if (a[m] > T)
        {
            R = m-1;
            if (a[R]==T)
            {
                cout << "El número T = " << T << " se encuentra en la posición " << R;
                exit(0);
            }
        } else if (a[m] == T)
        {
            cout << "El número T = " << T << " se encuentra en la posición " << m;
            exit(0);
        }
    }
    cout << "El valor T = " << T << " no se encuentra en el vector";
}
