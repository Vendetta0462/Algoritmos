#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    int a = 0, b = 1, c;
    cout << b << " ";
    for (int i = 1; i < n; i++)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    return 0;
}