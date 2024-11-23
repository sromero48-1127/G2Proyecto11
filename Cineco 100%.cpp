
#include <iostream>
#include <string>

using namespace std;

struct Reserva {
    int idReserva;
    string cedulaTitular;
    string nombrePelicula;
    double totalPago;
};

int main() {
    char opcion;
    int IDTarjeta = 0;
    int contadorTarjetas = 1127;
    double SaldoInicial, DineroRecarga;
    double tarjetas[100] = {0};
    Reserva reservas[100];  
    double dineroEnCaja = 0.0;
    int contadorReservas = 1000;

    do {
        cout << "\n  Bienvenido a nuestro programa CINECO\n";
        cout << "  Ingresa una opción (1-9):\n";
        cout << "  ====================================\n";
        cout << "  1. Crear una nueva tarjeta. \n";
        cout << "  2. Recargar una tarjeta. \n";
        cout << "  3. Crear una reserva. \n";
        cout << "  4. Eliminar una reserva. \n";
        cout << "  5. Pagar una reserva en efectivo. \n";
        cout << "  6. Pagar la reserva con tarjeta CINECO. \n";
        cout << "  7. Ceder una reserva. \n";
        cout << "  8. Visualizar el dinero en caja. (admin) \n";
        cout << "  9. Salir.\n";
        cout << "  ====================================\n";
        cout << "  Ingresa una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case '1': {
                cout << " 1. Crear una nueva tarjeta. \n";
                do {
                    cout << "\nIngresa el saldo inicial a recargar (entre 1000 y 500000): ";
                    cin >> SaldoInicial;
                    if (SaldoInicial < 1000 || SaldoInicial > 500000) {
                        cout << "Saldo no válido. Debe estar entre 1000 y 500000.\n";
                    }
                } while (SaldoInicial < 1000 || SaldoInicial > 500000);

                tarjetas[contadorTarjetas - 1127] = SaldoInicial;
                cout << "\nTarjeta creada con el ID: " << contadorTarjetas << " y el saldo inicial es: " << tarjetas[contadorTarjetas - 1127] << "\n";
                contadorTarjetas++; 
                break;
            }

            case '2': {
                cout << " 2. Recargar una tarjeta. \n";
                cout << "\nIngresa el ID de tu tarjeta: ";
                cin >> IDTarjeta;
                if (IDTarjeta < 1127 || IDTarjeta >= contadorTarjetas) {
                    cout << "\nID de tarjeta no válido.\n";
                } else {
                    do {
                        cout << "\nIngresa el monto a recargar (entre 1000 y 5000000): ";
                        cin >> DineroRecarga;
                        if (DineroRecarga < 1000 || DineroRecarga > 5000000) {
                            cout << "Monto de recarga no válido. Debe estar entre 1000 y 5000000.\n";
                        }
                    } while (DineroRecarga < 1000 || DineroRecarga > 5000000);

                    tarjetas[IDTarjeta - 1127] += DineroRecarga;
                    cout << "\nRecarga exitosa. El nuevo saldo de la tarjeta " << IDTarjeta << " es: " << tarjetas[IDTarjeta - 1127] << "\n";
                }
                break;
            }

            case '3': {
                cout << " 3. Crear una reserva. \n";
                cout << "Ingrese el ID de la tarjeta: ";
                cin >> IDTarjeta;

                if (IDTarjeta < 1127 || IDTarjeta >= contadorTarjetas) {
                    cout << "\nID de tarjeta no válido.\n";
                    break;
                }

                string cedulaTitular;
                while (true) {
                    cout << "Ingrese la cédula del titular: ";
                    cin >> cedulaTitular;

                    
                    bool esNumero = true;
                    for (char c : cedulaTitular) {
                        if (c < '0' || c > '9') {
                            esNumero = false;
                            break;
                        }
                    }

                    if (esNumero) {
                        int numero = 0;
                        for (char c : cedulaTitular) {
                            numero = numero * 10 + (c - '0');
                        }

                        if (numero > 9999999 && numero < 10000000000) {
                            cout << "Número válido: " << numero << endl;
                            break;
                        } else {
                            cout << "Número fuera de rango. Debe estar entre 8 digitos a 10 digitos.\n";
                        }
                    } else {
                        cout << "Entrada inválida. Por favor, ingrese solo números.\n";
                    }
                }

                string nombrePelicula;
                cout << "Ingrese el nombre de la película: ";
                cin >> nombrePelicula;

                if (nombrePelicula == "") {
                    cout << "El nombre de la película no puede estar vacío.\n";
                    break;
                }

                int numeroReserva = contadorReservas;
                double totalPago = 15000.0;

                reservas[contadorReservas - 1000] = {numeroReserva, cedulaTitular, nombrePelicula, totalPago};

                cout << "\nReserva creada exitosamente.\n";
                cout << "Número de reserva: " << numeroReserva << endl;
                cout << "Película: " << nombrePelicula << endl;
                cout << "Monto a pagar: $" << totalPago << endl;
                contadorReservas++;
                break;
            }

            case '4': {
                int idReservaEliminar;
                cout << "Ingrese el ID de la reserva que desea eliminar: ";
                cin >> idReservaEliminar;

                bool reservaEncontrada = false;
                for (int i = 0; i < contadorReservas - 1000; i++) {
                    if (reservas[i].idReserva == idReservaEliminar) {
                        for (int j = i; j < contadorReservas - 1000 - 1; j++) {
                            reservas[j] = reservas[j + 1]; 
                        }
                        reservas[contadorReservas - 1001] = {};
                        contadorReservas--;  
                        cout << "Reserva eliminada exitosamente.\n";
                        reservaEncontrada = true;
                        break;
                    }
                }

                if (!reservaEncontrada) {
                    cout << "Reserva con el ID " << idReservaEliminar << " no encontrada.\n";
                }
                break;
            }

              case '5': {
    cout << " 5. Pagar una reserva en efectivo. \n";
    int numeroReserva;
    string cedulaTitular;
    
    cout << "Ingrese el número de reserva: ";
    cin >> numeroReserva;
    cout << "Ingrese la cédula del titular: ";
    cin >> cedulaTitular;

    bool reservaEncontrada = false;

    for (int i = 0; i < contadorReservas - 1000; i++) {
        if (reservas[i].idReserva == numeroReserva && reservas[i].cedulaTitular == cedulaTitular) {
            cout << "Monto a pagar: $" << reservas[i].totalPago << endl;
            dineroEnCaja += reservas[i].totalPago;

            
            int numeroPago = 10000000 + rand() % 900000000;
            
            if (numeroPago < 100000000) {
                numeroPago += 1000000000; 
            }

           
            cout << "Acérquese a la caja y pague con este número de pago: " << numeroPago << endl;

            
            for (int j = i; j < contadorReservas - 1000 - 1; j++) {
                reservas[j] = reservas[j + 1]; 
            }
            reservas[contadorReservas - 1001] = {}; 
            contadorReservas--; 
            reservaEncontrada = true;
            break;
        }
    }

    if (!reservaEncontrada) {
        cout << "Reserva no encontrada o datos incorrectos.\n";
    }
    break;
}


    case '6': {
    cout << " 6. Pagar la reserva con tarjeta CINECO.\n";
    int numeroReserva;
    string cedulaTitular;

    
    cout << "Ingrese el número de reserva: ";
    cin >> numeroReserva;
    cout << "Ingrese la cédula del titular: ";
    cin >> cedulaTitular;

  
    bool reservaEncontrada = false;
    for (int i = 0; i < contadorReservas - 1000; i++) {
        if (reservas[i].idReserva == numeroReserva && reservas[i].cedulaTitular == cedulaTitular) {
            int IDTarjeta;
            cout << "Ingrese el ID de su tarjeta CINECO: ";
            cin >> IDTarjeta;

            
            if (IDTarjeta < 1127 || IDTarjeta >= contadorTarjetas) {
                cout << "ID de tarjeta no válido.\n";
                break;
            }

         
            if (tarjetas[IDTarjeta - 1127] >= reservas[i].totalPago) {
                // Descontar el saldo de la tarjeta
                tarjetas[IDTarjeta - 1127] -= reservas[i].totalPago;
                cout << "Pago realizado exitosamente. Nuevo saldo de la tarjeta " 
                     << IDTarjeta << ": $" << tarjetas[IDTarjeta - 1127] << endl;

              
                for (int j = i; j < contadorReservas - 1000 - 1; j++) {
                    reservas[j] = reservas[j + 1];
                }
                reservas[contadorReservas - 1001] = {};
                contadorReservas--; 
                reservaEncontrada = true;
            } else {
                cout << "Saldo insuficiente en la tarjeta.\n";
            }
            break;
        }
    }

    if (!reservaEncontrada) {
        cout << "Reserva no encontrada o datos incorrectos.\n";
    }
    break;
}


            case '7': {
    cout << " 7. Ceder una reserva. \n";
    int numeroReserva;
    string cedulaActual, nuevaCedula;

    
    cout << "Ingrese el número de reserva: ";
    cin >> numeroReserva;

 
    cout << "Ingrese la cédula del titular actual: ";
    cin >> cedulaActual;


    bool reservaEncontrada = false;
    for (int i = 0; i < contadorReservas - 1000; i++) {
        if (reservas[i].idReserva == numeroReserva && reservas[i].cedulaTitular == cedulaActual) {
           
            cout << "Ingrese la cédula de la persona que recibirá la titularidad: ";
            cin >> nuevaCedula;

 
            reservas[i].cedulaTitular = nuevaCedula;

            cout << "La reserva con número " << numeroReserva 
                 << " ha sido transferida exitosamente a la cédula: " 
                 << nuevaCedula << endl;
            reservaEncontrada = true;
            break;
        }
    }

    if (!reservaEncontrada) {
        cout << "Reserva no encontrada o datos incorrectos.\n";
    }
    break;
}

            case '8': {
                cout << " 8. Visualizar el dinero en caja. (admin) \n";
                
                string contraseña, contraseñaCorrecta = "Cineco1127";
                
                cout << "Ingrese la contraseña para acceder: ";
                cin >> contraseña;

                if (contraseña == contraseñaCorrecta) {
                    cout << "Dinero en caja: $" << dineroEnCaja << endl;
                } else {
                    cout << "Contraseña incorrecta intente de nuevo.\n";
                }
                break;
            }

            case '9': {
                cout << "Salir. \n";
                break;
            }

            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }

    } while (opcion != '9');
    
    return 0;
}
