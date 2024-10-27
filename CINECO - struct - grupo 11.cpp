#include <iostream>
using namespace std;

struct tarjeta {
    int id;
    double saldo;
};

int main()
{   
    char opcion;
    int IDTarjeta = 0;
    int contadorTarjetas = 1127;
    double SaldoInicial, DineroRecarga;
    double tarjetas[100] = {0};

    do
    {
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

        switch (opcion)
        {
            case '1':
                cout << " 1. Crear una nueva tarjeta. \n";
                cout << "\nIngresa el saldo inicial a recargar: ";
                cin >> SaldoInicial;
                tarjetas[contadorTarjetas - 1127] = SaldoInicial;
                cout << "\nTarjeta creada con el ID: " << contadorTarjetas << " y el saldo inicial es: " << tarjetas[contadorTarjetas - 1127] << "\n";
                contadorTarjetas++; 
                break;

            case '2':
                cout << " 2. Recargar una tarjeta. \n";
                cout << "\nIngresa el ID de tu tarjeta: ";
                cin >> IDTarjeta;
                if (IDTarjeta < 1127 || IDTarjeta >= contadorTarjetas) {
                    cout << "\nID de tarjeta no válido.\n";
                } else {
                    cout << "\nIngresa el monto a recargar: ";
                    cin >> DineroRecarga;
                    tarjetas[IDTarjeta - 1127] += DineroRecarga;
                    cout << "\nRecarga exitosa. El nuevo saldo de la tarjeta " << IDTarjeta << " es: " << tarjetas[IDTarjeta - 1127] << "\n";
                }
                break;

            case '3':
                cout << " 3. Crear una reserva. \n";
                cout << "\n";
                break;

            case '4':
                cout << " 4. Eliminar la reserva actual. \n";
                cout << "\n";
                break;
                
            case '5':
                cout << " 5. Pagar una reserva en efectivo. \n";
                cout << "\n";
                break;

            case '6':
                cout << " 6. Pagar la reserva con tarjeta CINEMAS. \n";
                cout << "\n";
                break;
                
            case '7':
                cout << " 7. Visualizar las sillas del cine. \n";
                cout << "\n";
                break;

            case '8':
                cout << " 8. Visualizar el dinero en caja. \n";
                cout << "\n";
                break;
                
            case '9':
                cout << " Salir. \n";
                cout << "\n";
                break;

            default:
                cout << " Opción no válida. Intente nuevamente." << endl;
                break;
        }

    } while (opcion != '9');
    
    return 0;
}
