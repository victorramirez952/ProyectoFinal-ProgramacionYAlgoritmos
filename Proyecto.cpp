#include <iostream>
#include <cstdlib>
#include<stdlib.h>
using namespace std;
int main()
{
    int finalizar = 0;
    while(finalizar == 0)
    {
        //
        int max_regular_nacional = 32;
        int max_regular_internacional = 23;
        int max_mascota_nacional = 25;
        int max_mascota_internacional = 20;
        int max_fragil_nacional = 32;
        int max_fragil_internacional = 23;
        //

        //menu de opciones
        string opcion_de_uso = "0";
        while(opcion_de_uso != "1" && opcion_de_uso != "2" && opcion_de_uso != "3")
        {
            cout << "Selecciona una de las siguientes opciones" << endl;
            cout << "1 - Administrador" << endl;
            cout << "2 - Pasajero" << endl;
            cout << "3 - Finalizar programa" << endl;
            cin >> opcion_de_uso;
            finalizar = 0;
        }

        string respuesta = "0";
        
        if(opcion_de_uso == "1")
        {
            string usuario, password;
            cout << "Ingresa tu usuario" << endl;
            cin >> usuario;
            cout << "Ingresa tu contrasenia" << endl;
            cin >> password;

            if(usuario == "admin" && password == "1234")
            {
                // int asignar_nuevos_valores = 0;
                while(respuesta != "1" && respuesta != "2")
                {
                    cout << "Desea asignar nuevos valores a los pesos maximos?" << endl;
                    cout << "1 - Si" << endl;
                    cout << "2 - No" << endl;
                    cin >> respuesta;
                }

                if(respuesta == "1")
                {
                    respuesta = "0";
                    cout << "Ingresa el peso maximo para una maleta regular en vuelo nacional" << endl;
                    cin >> max_regular_nacional;
                    cout << "Ingresa el peso maximo para una maleta en vuelo internacional" << endl;
                    cin >> max_regular_internacional;
                    cout << "Ingresa el peso maximo para una maleta tipo de mascota en vuelo nacional" << endl;
                    cin >> max_mascota_nacional;
                    cout << "Ingresa el peso maximo para una maleta tipo de mascota en vuelo internacional" << endl;
                    cin >> max_mascota_internacional;
                    cout << "Ingresa el peso maximo para una maleta fragil en vuelo nacional" << endl;
                    cin >> max_fragil_nacional;
                    cout << "Ingresa el peso maximo para una maleta fragil en vuelo internacional" << endl;
                    cin >> max_fragil_internacional;
                }
                system("PAUSE()");
                system("cls");
            }
            else
            {
                cout << "Los credenciales ingresadas son incorrectas" << endl;
                system("PAUSE()");
                system("cls");
            }
            finalizar = 0;
        } 
        if(opcion_de_uso == "2")
        {
            string cantidad_personas_en_reserva = "0";
            bool validacion = true;
            while(validacion)
            {
                cout << "Cuantas personas viajan contigo? (Incluido usted)" << endl;
                cin >> cantidad_personas_en_reserva;
                if(cantidad_personas_en_reserva.find_first_not_of("0123456789") == string::npos)
                {
                    if(atoi(cantidad_personas_en_reserva.c_str()) > 0)
                    {
                        validacion = false;
                    }
                }
            }

            string tipo_de_vuelo = "0";
            while(tipo_de_vuelo != "1" && tipo_de_vuelo != "2")
            {
                cout << "Cual es el tipo de vuelo?" << endl;
                cout << "1 - Nacional" << endl;
                cout << "2 - Internacional" << endl;
                cin >> tipo_de_vuelo;
            }

            float precio_total = 0;
            float peso_total = 0;

            int cantidad_personas_en_reserva_num = atoi(cantidad_personas_en_reserva.c_str());

            string pasajeros[cantidad_personas_en_reserva_num][4];

            for(int i = 0; i < cantidad_personas_en_reserva_num; i++)
            {
                string nombre;
                cout << "Ingresa tu nombre" << endl;
                bool validacion = true;
                while (validacion)
                {
                    cin >> nombre;
                    if(nombre.find_first_not_of("0123456789") != string::npos)
                    {
                        cout << "Su nombre es válido" << endl;
                        validacion = false;
                    }
                }
                validacion = true;
                
                pasajeros[i][0] = nombre;

                string cantidad_maletas = "0";

                while(validacion)
                {
                    cout << "Cuantas maletas vas a ingresar?" << endl;
                    cantidad_maletas = "0";
                    cin >> cantidad_maletas;
                    if(cantidad_maletas.find_first_not_of("0123456789") == string::npos)
                {
                    if(atoi(cantidad_maletas.c_str()) > 0)
                    {
                        validacion = false;
                    }
                }
                }
                pasajeros[i][1] = cantidad_maletas;

                float peso_total_pasajero = 0;
                float precio_total_pasajero = 0;

                cout << "--------" << endl;
                
                for(int j = 0; j < atoi(cantidad_maletas.c_str()); j++)
                {
                    string peso_maleta = "0";
                    bool validacion = true;
                    while(validacion)
                    {
                        cout << "Peso de la maleta:" << endl;
                        cin >> peso_maleta;
                        if(peso_maleta.find_first_not_of("0123456789.") == string::npos)
                        {
                            if(atoi(peso_maleta.c_str()) > 0)
                            {
                                validacion = false;
                            }
                        }
                    }
                    float peso_maleta_num = atoi(peso_maleta.c_str());
                    peso_total_pasajero = peso_total_pasajero + peso_maleta_num;

                    string tipo_maleta = "0";
                    while(tipo_maleta != "1" && tipo_maleta != "2" && tipo_maleta != "3")
                    {
                        cout << "Ingresa el tipo de maleta" << endl;
                        cout << "1 - regular" << endl;
                        cout << "2 - fragil" << endl;
                        cout << "3 - mascota" << endl;
                        cin >> tipo_maleta;
                    }

                    switch (atoi(tipo_maleta.c_str()))
                    {
                    case 1:
                        if(tipo_de_vuelo == "1")
                        {
                            if(peso_maleta_num <= max_regular_nacional)
                            {
                                precio_total_pasajero += 600;
                            }
                            else { precio_total_pasajero += 600 + 500; }
                        }
                        else
                        {
                            if(peso_maleta_num <= max_regular_internacional)
                            {
                                precio_total_pasajero += 1200;
                            }
                            else { precio_total_pasajero += 1200 + 500; }
                        }
                    case 2:
                        if(tipo_de_vuelo == "1")
                        {
                            if(peso_maleta_num <= max_fragil_nacional)
                            {
                                precio_total_pasajero += 800;
                            }
                            else { precio_total_pasajero += 800 + 500; }
                        }
                        else
                        {
                            if(peso_maleta_num <= max_fragil_internacional)
                            {
                                precio_total_pasajero += 1600;
                            }
                            else { precio_total_pasajero += 1600 + 500; }
                        }
                    case 3:
                        if(tipo_de_vuelo == "1")
                        {
                            if(peso_maleta_num <= max_mascota_nacional)
                            {
                                precio_total_pasajero += 700;
                            }
                            else { precio_total_pasajero += 700 + 500; }
                        }
                        else
                        {
                            if(peso_maleta_num <= max_mascota_internacional)
                            {
                                precio_total_pasajero += 1400;
                            }
                            else { precio_total_pasajero += 1400 + 500; }
                        }
                    }

                    cout << "--------" << endl;
                } //ciclo para maletas
                pasajeros[i][2] = to_string(peso_total_pasajero);
                pasajeros[i][3] = to_string(precio_total_pasajero);

                peso_total += peso_total_pasajero;
                precio_total += precio_total_pasajero;
            } //ciclo personas reservacion

            cout << "Tu total a pagar es de " << precio_total << endl;
            cout << "El peso total de las maletas es de " << peso_total << "kg" << endl;
            cout << "1 - Aceptar" << endl;
            cout << "2 - Cancelar" << endl;
            while(respuesta != "1" && respuesta != "2")
            {
                cin >> respuesta;
            }

            if(respuesta == "2")
            {
                respuesta = "0";
                cout << "Desea ver informacion de las maletas de esta reservacion?" << endl;
                cout << "1 - Si" << endl;
                cout << "2 - No" << endl;
                while(respuesta != "1" && respuesta != "2")
                {
                    cin >> respuesta;
                }

                if(respuesta == "1")
                {
                    cout << "[Nombre][Cantidad Maletas][Peso Maletas][Total]" << endl ;
                    for(int i = 0; i < cantidad_personas_en_reserva_num; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            cout << "[" << pasajeros[i][j] << "]";
                        }
                        cout << endl;
                    } 
                }
                //limpiar pantalla
                system("PAUSE()");
                system("cls");
            }
            else //si respuesta es igual a "1"
            {
                respuesta = "0";
                cout << "Desea imprimir la factura?" << endl;
                cout << "1 - Si" << endl;
                cout << "2 - No" << endl;
                while(respuesta != "1" && respuesta !="2")
                {
                    cin >> respuesta;
                }
                if(respuesta == "1")
                {
                    cout << "[Nombre][Cantidad Maletas][Peso Maletas][Total]" << endl ;
                    for(int i = 0; i < cantidad_personas_en_reserva_num; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            cout << "[" << pasajeros[i][j] << "]";
                        }
                        cout << endl;
                    } 
                }
                //Proceso de pago
            }
            
            cout << "--------" << endl;
            system("PAUSE()");
            system("cls");
        }
        if(opcion_de_uso == "3")
        {
            finalizar = 1;
        }
    }
    return 0;
}