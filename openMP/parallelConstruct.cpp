#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <omp.h>

using namespace std;

double f(double x)
{
    return 4/(1+pow(x,2));
}

int main()
{
    long int n = 100000000;
    int threads;
    cout << "Select num of threads: ";
    cin >> threads;
    double step, x, sum[threads] = { 0 }; long double integral;
    step = 1/(double)n;

    omp_set_num_threads(threads);

    double t1=omp_get_wtime();
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        for (int i=n/threads*ID; i<n/threads*(ID+1); i++)
        {
            x = (i+0.5)*step;
            sum[ID] += f(x);
        }
        if (ID == 0) cout << "Real num of threads: " << omp_get_num_threads() << endl;
    }
    double t2=omp_get_wtime();

    double sum1=0;
    for (double i:sum) sum1+=i;
    integral = sum1*step;
    cout << "Integral: " << integral << endl << "Tiempo: " << t2-t1;
}