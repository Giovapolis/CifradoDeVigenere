#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//FUNCIONES
string acomodarClave(string, string);
int encontrarIndice(string, char);

int main(int argc, char const *argv[])
{
    string abcedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //ABECEDARIO A CONSIDERAR (A-Z SIN Ñ)

    //SOLICITAR LA CLAVE Y FRASE A CIFRAR
    string clave = "";
    string mensaje = "";
    cout << "Introduce una palabra para clave: ";
    cin >> clave;
    cout << "Introduce una frase a cifrar: ";
    cin >> mensaje;

    //CONVERTIR A MAYUSCULAS
    transform(clave.begin(), clave.end(), clave.begin(), ::toupper);
    transform(mensaje.begin(), mensaje.end(), mensaje.begin(), ::toupper);

    cout << "La clave introducida es: " << clave << endl;
    cout << "El mensaje introducido es: " << mensaje << endl;

    //ACOMODAMOS LA CLAVE SEGUN EL TEXTO QUE SE CIFRARA
    string claveUsar = acomodarClave(clave, mensaje);
    cout << "La clave a usar es: " << claveUsar << endl;

    //CIFRAMOS
    cout << "CIFRANDO....." << endl;
    string cifrado = "";
    int x = 0;
    int y = 0;
    int suma = 0;
    int modulo = 0;
    for (int i = 0; i < mensaje.length(); i++)
    {
        x = abcedario.find(mensaje[i]);
        y = abcedario.find(clave[i]);
        suma = x + y;
        modulo = suma % abcedario.length();
        cifrado += abcedario[modulo];
    }

    cout << "El mensaje cifrado es: " << cifrado << endl;

    //DECIFRAMOS
    cout << "DECIFRANDO....." << endl;
    string decifrado = "";
     x = 0;
     y = 0;
    int resta = 0;
    for (int i = 0; i < cifrado.length(); i++)
    {
        x = abcedario.find(cifrado[i]);
        y = abcedario.find(clave[i]);
        resta = x - y;
        modulo = resta % abcedario.length();
        decifrado += abcedario[modulo];
    }

    cout << "El mensaje decifrado es: " << decifrado << endl;

    return 0;
}

string acomodarClave(string clave_original, string mensaje_original)
{
    string claveAutilizar = "";
    if (mensaje_original.length() > clave_original.length())
    {
        claveAutilizar = clave_original;
        while (mensaje_original.length() > claveAutilizar.length())
        {
            for (int i = 0; i < clave_original.length(); i++)
            {
                if (mensaje_original.length() == claveAutilizar.length())
                {
                    break;
                }
                else
                {
                    claveAutilizar += clave_original[i];
                }
            }
        }
    }
    else if (mensaje_original.length() < clave_original.length())
    {
        for (int i = 0; i < mensaje_original.length(); i++)
        {
            claveAutilizar += clave_original[i];
        }
    }
    else
    {
        claveAutilizar = clave_original;
    }
    return claveAutilizar;
}
