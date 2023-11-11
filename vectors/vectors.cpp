#include <iostream>
// #include <cmath>

using namespace std;

int main()
{

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    float vec[n];
    for (int i=0; i<n; i++)
    {
        cout << "Enter the element "<<i<<": " << endl;
        cin >> vec[i];
    }

    // Promedio

    float sum = 0;
    for (int i=0; i<n; i++)
    {
        sum = sum + vec[i];
    }

    cout << "The mean of the elements of the vector is: " << sum/n << endl;

    // Orden burbuja

    int i,j, temp;
    for (i = 0; i < n ; i++)
    {
        for (j=0; j < n-1; j++)
        {
            if (vec[j] > vec[j+1])
            {
                temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
                // swap(vec[j], vec[j+1]);
            }
        }
    }

    // Imprimir el vector

    cout << "The ordered vector is: [ ";
    for (int i=0; i<n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << "]" << endl;

    // Hallar máximo y minimo

    int max, min;
    max = vec[0];
    min = vec[0];
    for (i=0; i < n-1; i++)
    {
        if(vec[i+1] > max)
        {
            max = vec[i+1];
        }
        if(vec[i+1] < min)
        {
            min = vec[i+1];
        }
    }
    cout << "The max value is: " << max << " and the min is: " << min << endl;

}