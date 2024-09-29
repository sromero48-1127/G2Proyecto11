#include <iostream>
using namespace std;

int main()

{   
     
    char opcion;
    int IDTarjeta;
    double SaldoInicial, DineroRecarga;

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
        cout << "  9.  Salir.\n";
        cout << "  ====================================\n";
        cout << "  Ingresa una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
            case '1':
                cout << " 1. Crear una nueva tarjeta. \n ";
                cout << "\nIngresa el saldo inicial a recargar:";
                cin >> SaldoInicial;
                IDTarjeta++;
                cout << "\nTarjeta creada con el ID: " << IDTarjeta << " y el saldo inicial es: " << SaldoInicial << "\n" ;
                break;

            case '2':
                cout << " 2. Recargar una tarjeta. \n";
                cout << "\nIngresa el ID de tu tarjeta\n";
                cin >> IDTarjeta;
                cout << "\nIngresa el monto a recargar: ";
                cin >> DineroRecarga;
                cout << "\n";
                break;
            
            case '3':
                cout << " 3. Crear una reserva. \n ";
                cout << "\n";
                break;

            case '4':
                cout << " 4. Eliminar la reserva actual. \n";
                cout << "\n";
                break;
                
            case '5':
                cout << " 5. Pagar una reserva en efectivo. \n ";
                cout << "\n";
                break;

            case '6':
                cout << " 6. Pagar la reserva con tarjeta CINEMAS. \n";
                cout << "\n";
                break;
                
            case '7':
                cout << " 7. Visualizar las sillas del cine. \n ";
                cout << "\n";
                break;

            case '8':
                cout << " 8. Visualizar el dinero en caja. \n";
                cout << "\n";
                break;
                
            case '9':
                cout << " Salir. \n ";
                cout << "\n";
                break;

            default: 
 		cout <<opcion << "Opción no valida.\n";
                	cout << endl;
        }

    }while (opcion != '9' );
    
}
    
