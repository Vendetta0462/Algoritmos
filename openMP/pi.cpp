#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <omp.h>

using namespace std;

int main()
{
    long int n = 10000000;
    long double sum = 0, pi;
    double inicio, fin;
    inicio = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum) num_threads(8)
    for (int i=0; i < n; i++)
    {
        sum += pow(-1,i)/(2*i+1);
    }

    pi = sum*4;
    cout << "El valor de pi es: " << pi << endl;
    fin = omp_get_wtime();
    cout << "El tiempo es: " << fin - inicio;

}