#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

// Definimos la función de fuerza de gravedad del cuerpo 2 sobre el cuerpo 1
vector <double> f_gravedad(vector <double> cuerpo1, vector <double> cuerpo2)
{
    double G = 6.6743e-11, r_mag = 0;
    
    //Calculamos la norma de la diferencia de posiciones (magnitud de r)
    for (int i=0; i<3; i++)
    {
        r_mag += pow((cuerpo2[i]-cuerpo1[i]),2);
    }
    r_mag = sqrt(r_mag);

    //Si la distancia es nula, se devuelven ceros, de lo contrario, se calcula la fuerza
    if (r_mag == 0)
    {
        vector <double> f = {0,0,0};
        return f;
    }
    vector <double> r_dir, f;
    for (int i = 0; i<3; i++)
    {
        r_dir.push_back((cuerpo2[i]-cuerpo1[i])/r_mag);
        f.push_back((G*cuerpo1[6]*cuerpo2[6])/(pow(r_mag,2))*r_dir[i]);
    }
    return f;
}

int main()
{
    // Definimos la cantidad de cuerpos
    int n = 4;

    // Definimos los valores iniciales en la forma [posicion[m], velocidad[m/s], masa[kg]] (sol, mercurio, venus, tierra, marte, jupiter, saturno)
    vector <vector <double>> cuerpos = {{0,0,0,  0,0,0,  1.989e30}, {57.909e9,0,0,  0,47.36e3,0,  0.33011e24}, {108.209e9,0,0,  0,35.02e3,0,  4.8675e24}, {149.596e9,0,0,  0,29.78e3,0,  5.9724e24}, {227.923e9,0,0,  0,24.07e3,0,   0.64171e24}, {78.570e9,0,0,  0,13e3,0,  898.19e24}, {1433.529e9,0,0, 0,9.68e3,0,  568.34e24}};

    // Establecemos los valores temporales[s]
    double dt = 24*60*60; //Día en segundos
    double t_f = dt*365*10; //Década en segundos

    // Calculamos las fuerzas sobre cada cuerpo en cada paso temporal y sumamos su velocidad y posición
    double t = dt;
    vector <vector <double>> aceleracion(n, {0,0,0}), posiciones, fuerzas(n, {0,0,0});
    vector <double> tiempo = {t}, gravedad_j;
    for (int i=0; i<n; i++)
    {
        posiciones.push_back({cuerpos[i][0], cuerpos[i][1], cuerpos[i][2]})
    }

    while (t <= t_f)
    {
        for (int i=0; i<n, i++)
        {
            for (int j=0, j<n, j++)
            {
                gravedad_j = f_gravedad(cuerpos[i], cuerpos[j]);
                fuerzas[i][0] += gravedad_j[0];
                fuerzas[i][1] += gravedad_j[1];
                fuerzas[i][2] += gravedad_j[2];
            }
            for (int s=0; s<3; s++)
            {
                aceleracion[i][s] = fuerzas[i][s]/cuerpos[i][6];

                cuerpos[i][s+3] += aceleracion[i][s]*dt;

                cuerpos[i][s] += cuerpos[s+3]*dt;

                posiciones.push_back({cuerpos[i][0], cuerpos[i][1], cuerpos[i][2]})
            }
        }
        t+=dt
    }

    // Escribimos los archivos con los datos calculados
    ofstream archivo;
    archivo.open("Datos")
    
}

/*
struct posicion {
    float x;
    float y;
    float z;
}

posicion c1;

c1.x= 
c1.y = 

vector <posicion> todos;

posicion temp;
temp.x =


todos.push_back(temp)
*/