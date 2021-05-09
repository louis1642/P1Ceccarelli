#include <iostream>
#include <fstream>
#include <iomanip>
#include "ClientData.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;
using std::string;
using std::setw;
using std::left;
using std::right;

void BlankWrite();
void Write();
void Read();
void OutputLine(ostream &output, const ClientData &record);
void OutputLine(const ClientData &record);

int main() {
    int ans = 0;
    cout << "1 - Blank Write\n" <<
            "2 - Write\n" <<
            "3 - Read" << endl;
    cin >> ans;

    while (ans >=1 && ans <= 3) {
        switch (ans) {
            case 1:
                BlankWrite();
                break;
            case 2:
                Write();
                break;
            case 3:
                Read();
                break;
            default: exit(EXIT_FAILURE);
        }
        cout << "\n\n1 - Blank Write\n" <<
             "2 - Write\n" <<
             "3 - Read" << endl;
        cin >> ans;
    }
    cout << "Terminating..." << endl;
    return 0;
}


void BlankWrite() {
    // nota: ios::out | ios::binary sono unite da un operatore OR-bitwise
    // la ios::binary mode è necessaria per scrivere record a lunghezza fissa
    ofstream outFile("credit.dat", ios::out | ios::binary);

    // exit se non puoi aprire il file
    if (!outFile) {
        cerr << "Cannot open file. Terminating..." << endl;
        exit(EXIT_FAILURE);
    }

    ClientData blankClient;

    for (int i = 0; i < 100; ++i) {
        outFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
    }
}

void Write() {
    fstream file("credit.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Cannot open file. Terminating..." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter account number (1 to 100, 0 to terminate):" << endl;

    int num;
    string lastname;
    string firstname;
    double bal;

    cin >> num;

    while (num >= 1 && num <=100) {
        cout << "Enter first name, last name and balance:" << endl;
        cin >> firstname >> lastname >> bal;

        ClientData client(num, lastname, firstname, bal);

        // per posizionare nel file il cliente al suo posto, cerco la posizione relativa al suo accountNumber
        file.seekp((client.GetAccountNumber() - 1) * sizeof(ClientData));
        file.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

        cout << "Enter account number:" << endl;
        cin >> num;
    }
}

void Read(){
    ifstream file("credit.dat", ios::in | ios::binary);
    if (!file) {
        cerr << "Cannot open file. Terminating..." << endl;
        exit(EXIT_FAILURE);
    }

    cout << left << setw(10) << "Number" << setw(LAST_NAME_LENGHT + 1) << "Last Name" <<
        setw(FIRST_NAME_LENGHT +1) << "First Name" << setw(10) << right << "Balance" << endl;

    ClientData client;

    // leggi la prima entry
    file.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    while (file) {
        if (client.GetAccountNumber() != 0) {
            OutputLine(client);
        }

        // vai alla prossima entry
        file.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    }




}

void OutputLine(ostream &output, const ClientData &record) {
    output << left << setw(10) << record.GetAccountNumber() << setw(LAST_NAME_LENGHT + 1)
        << record.GetLastName() << setw(FIRST_NAME_LENGHT +1) << record.GetFirstName() <<
        setw(10) << std::setprecision(2) << right << std::fixed << std::showpoint <<
        record.GetBalance() << endl;
}

void OutputLine(const ClientData &record) {
    OutputLine(cout, record);
}





