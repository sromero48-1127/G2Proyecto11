#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    

using namespace std;

struct Tarjeta {
    int id;
    double saldo;
};

struct Reserva {
    int idReserva;
    int idTarjeta;
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
    vector<Reserva> reservas;
    double dineroEnCaja = 0.0;
    int contadorReservas = 1000;  

    srand(time(0)); 

    do {
        cout << "\n  Bienvenido a nuestro programa CINECO\n";
        cout << "  Ingresa una opción (1-8) o presiona 9 para salir:\n";  
        cout << "  ====================================\n";
        cout << "  1. Crear una nueva tarjeta. \n";
        cout << "  2. Recargar una tarjeta. \n";
        cout << "  3. Crear una reserva. \n";
        cout << "  4. Eliminar la reserva actual. \n";
        cout << "  5. Pagar una reserva en efectivo. \n";
        cout << "  6. Pagar la reserva con tarjeta CINEMAS. \n";
        cout << "  7. Visualizar las sillas del cine. \n";
        cout << "  8. Visualizar el dinero en caja. \n";
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
                cout << "Ingrese la cédula del titular: ";
                cin >> cedulaTitular;

                bool cedulaValida = true;
                for (char c : cedulaTitular) {
                    if (!isdigit(c)) {
                        cedulaValida = false;
                        break;
                    }
                }
                
                if (!cedulaValida || cedulaTitular.empty()) {
                    cout << "Cédula no válida. Debe contener solo números.\n";
                    break;
                }

                cin.ignore();
                string nombrePelicula;
                cout << "Ingrese el nombre de la película: ";
                getline(cin, nombrePelicula);

                if (nombrePelicula.empty()) {
                    cout << "El nombre de la película no puede estar vacío.\n";
                    break;
                }

                int numeroReserva = contadorReservas++;
                double totalPago = 15000.0;

                reservas.push_back({numeroReserva, IDTarjeta, cedulaTitular, nombrePelicula, totalPago});
                
                cout << "\nReserva creada exitosamente.\n";
                cout << "Número de reserva: " << numeroReserva << endl;
                cout << "Película: " << nombrePelicula << endl;
                cout << "Monto a pagar: $" << totalPago << endl;

                break;
            }

            case '4': {
                if (reservas.empty()) {
                    cout << "\nNo hay reservas para eliminar.\n";
                } else {
                    reservas.pop_back();
                    cout << "\nReserva eliminada exitosamente.\n";
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
                for (auto& reserva : reservas) {
                    if (reserva.idReserva == numeroReserva && reserva.cedulaTitular == cedulaTitular) {
                        int numeroPago = rand() % 9000000 + 1000000;
                        dineroEnCaja += reserva.totalPago;
                        cout << "\nDiríjase a un punto Efecty con el número de pago: " << numeroPago << endl;
                        cout << "Monto a pagar: $" << reserva.totalPago << endl;
                        reservaEncontrada = true;
                        break;
                    }
                }

                if (!reservaEncontrada) {
                    cout << "Reserva no encontrada.\n";
                }
                break;
            }

            case '8': {
                cout << " 8. Visualizar el dinero en caja. \n";
                cout << "Dinero en caja: $" << dineroEnCaja << endl;
                break;
            }

            case '9':
                cout << "Salir. \n";
                break;

            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }

    } while (opcion != '9');
    
    return 0;
}
