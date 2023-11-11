#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <omp.h>

using namespace std;

int main()
{
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        // int ID = 0;
        cout << "Hello World " << ID;
    }
}