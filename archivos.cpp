#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


int main(int argc, char** argv)
{
    vector<double> X, Y;
    string nombre, linea;
    nombre = "datos.txt";
    ifstream archivo;
    archivo.open(nombre);
    int contLineas = 0;
    int n;
    if (!archivo)
    {
        cout << "Archivo inválido.";
    }
    else
    {
    while (getline(archivo, linea))
        {
            contLineas++;
            // Se imprime la línea completa
            cout << "Linea número " << contLineas << " : " << linea << endl;
            // Acá se divide la línea por los separadores
        
            char separador = ',';
            stringstream ssLinea(linea);
            string token;
            // acá se separa cada linea en los elementos entre los puntos y coma
            int cont = 0;
            while (getline(ssLinea, token, separador))
            {
                if (cont == 0) X.push_back(stof(token));
                if (cont == 1) Y.push_back(stof(token));
                cout << token << endl;
                cont++;
            } 
            //listado.push_back(elemento);
            // acá se arma el registro entero, es un <<listado>> de <<elementos>>
        }

    double sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumx2 = 0.0, A, B;
    

    n = X.size();

    for (int i = 0; i < n; i++)
    {
        sumx = sumx + X[i];
        sumy = sumy + Y[i];
        sumxy = sumxy + X[i]*Y[i];
        sumx2 = sumx2 + X[i]*X[i];
    }
    A = (n*sumxy - (sumx*sumy)) / (n*sumx2 - sumx*sumx);
    B = (sumy - A*sumx) /n;
    cout << "Valor de A: " << A <<  " , valor de B: " << B << std::endl; 
    cout << "Escribiendo " << contLineas << " registros..." << endl;
    ofstream archivoS;
    archivoS.open("salida.txt");
    double dx = (10. - 0.) / n;
    double valor = 0.0;
    for (int i = 0; i < n; i++)
    {
        valor = A * (i*dx) + B;
        archivoS << i*dx << ", " << valor << endl;
    } 
    }
}