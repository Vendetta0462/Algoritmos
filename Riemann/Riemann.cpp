#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

// Definimos la función para aproximar su integral
double f(double x)
{
    return cos(x);
}

int main()
{
    // Pedimos los límites de integración y el número de particiones
    double a, b;
    int n;
    cout << "Ingrese los límites de integración:" << endl << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "Ahora ingrese el número de particiones:" << endl << "n: ";
    cin >> n;
    double dx = (b-a)/n;

    // Creamos el vector para alojar las áreas de cada rectángulo
    vector <double> areas;

    // Ahora iniciamos la sumatoria y calculamos las áreas
    for (int i=0; i<n; i++)
    {
        areas.push_back(f(a+dx*i)*dx);
    }

    // Imprimimos el valor de la suma
    double suma=0;
    for (int i=0; i<areas.size(); i++) suma += areas[i];
    cout << "El valor de la aproximación a la integral es: " << suma << endl;

    // (opcional) Imprimimos el valor de las áreas (Pa que sirva de algo el vector)
    // cout << "El vector de las áreas es:" << endl;
    // cout << '[' << ' '; 
    // for (double v:areas)
    // {
    //     cout << v << ' ';
    // }
    // cout << ']' << endl;
}