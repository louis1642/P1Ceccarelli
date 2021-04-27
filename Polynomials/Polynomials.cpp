//
// PolynomialsCLion
// Polynomials.cpp.cc
// Created by Luigi Catello on 20/04/21.
// 
//

#include "Polynomials.h"
// <iostream> è incluso in Polynomials.h

// l'operatore booleano == non può essere all'interno della classe.
// Questo perchè può essere chiamato come polynomials == polynomials
// abbiamo definito allora operator== come funzione friend: non è interna alla classe,
// ma può accedere ai dati membro privati.
bool operator==(const Polynomials &lhs, const Polynomials &rhs) {
    if (lhs.size != rhs.size) {
        // se le dimensioni non corrispondono, sicuramente non sono uguali i due polinomi
        return false;
    } else {
        for (int i = 0; i < rhs.size; ++i) {
            if (lhs.coefs[i] != rhs.coefs[i]) {
                // confronto tutti i coefficienti
                return false;
            }
        }
    }
    // se finora non ho trovato differenze, allora i due polinomi coincidono
    return true;
}

// costruttore di default: p(x)=0
Polynomials::Polynomials() : size{1}, coefs{new double[1]} {
    coefs[0] = 0.0;
}

// costruttore per i polinomi di grado 0: p(x) = cost
Polynomials::Polynomials(double const_term) : size{1}, coefs{new double[1]} {
    coefs[0] = const_term;
}

// costruttore per i polinomi completi
Polynomials::Polynomials(const double coefficients[], int _size) : size{_size}, coefs{new double[_size]} {
    for (int i = 0; i < size; i++) {
        coefs[i] = coefficients[i];
    }
}

// copy constructor
// perchè c'è necessità di implementare un copy constructor?
// tra i dati membro del polinomio, c'è solo un puntatore (ad array). Se banalmente copiassimo
// lhs.coefs = rhs.coefs, l'array sarebbe condiviso, e una modifica ad un polinomio sarebbe applicata anche
// all'altro. Allochiamo quindi un nuovo array e copiamo "a mano" tutti i coefficienti
Polynomials::Polynomials(const Polynomials &rhs) : size{rhs.size}, coefs{new double[rhs.size]} {
    for (int i = 0; i < size; i++) {
        coefs[i] = rhs.coefs[i];
    }
}

// distruttore
// il distruttore deve essere esplicito perchè non possiamo semplicemente "dimenticare" il puntatore
// dei coefficienti, ma dobbiamo anche eliminare l'array vero e proprio.
Polynomials::~Polynomials() {
    delete[] coefs;
}

// grado del polinomio
int Polynomials::degree() const {
    return size - 1;
}

// stampa del polinomio. &out di default è std::cout
void Polynomials::print(std::ostream &out) const {
    if (size == 0) {
        // niente da stampare
        return;
    }

    for (int i = size - 1; i > 0; i--) {
        out << coefs[i] << " x^" << i << " + ";
    }
    out << coefs[0];        // termine noto
}

// fa parte della classe Polynomials
Polynomials Polynomials::operator+=(const Polynomials &rhs) {
    // costruisco un nuovo polinomio
    // la dimensione è quella del polinomio di grado maggiore
    int newSize = (rhs.size > size) ? rhs.size : size;
    // nuovo array dei coefficienti, inizializzato a 0 con la lista {}
    auto *newCoef = new double[newSize]{};
    // aggiungo i coefficienti del primo e del secondo polinomio
    for (int i = 0; i < rhs.size; i++) {
        newCoef[i] += rhs.coefs[i];
    }
    for (int i = 0; i < size; i++) {
        newCoef[i] += coefs[i];
    }
    // pulisco il vecchio array coefs
    delete[] coefs;
    // setto il puntatore coefs all'array nuovo
    coefs = newCoef;
    size = newSize;
    // il tipo dell'operatore è Polynomials, quindi ritorno l'oggetto puntato dal puntatore this
    return *this;
}

// moltiplicazione per una costante
Polynomials Polynomials::operator*=(double rhs) {
    for (int i = 0; i < size; i++) {
        coefs[i] *= rhs;
    }
    return *this;
}

// operatore di assegnazione
Polynomials& Polynomials::operator=(const Polynomials &rhs) {
    if (this == &rhs) {
        return *this;
        // se erano già uguali non c'è bisogno di effettuare l'assegnazione
    } else {
        // cancello il vecchio array
        delete[] coefs;
        // creo il nuovo array e assegno i coefficienti
        coefs = new double[rhs.size];
        size = rhs.size;
        for (int i = 0; i < size; ++i) {
            coefs[i] = rhs.coefs[i];
        }
    }
    return *this;
}

//da qui le funzioni non appartengono più alla classe

// operatore somma
// non appartiene alla classe perchè viene usato come polynomial + polynomial = polynomial
// sfrutta l'operatore += dichiarato prima
Polynomials operator+(const Polynomials &lhs, const Polynomials &rhs) {
    Polynomials tmp{lhs};
    tmp += rhs;
    return tmp;
}

// operatore prodotto - come somma
// dichiarato tre volte per coprire sia i casi polinomio * costante, costante * polinomio e polinomio * polinomio
Polynomials operator*(const Polynomials &lhs, double rhs) {
    Polynomials tmp{lhs};
    tmp *= rhs;
    return tmp;
}

Polynomials operator*(double lhs, const Polynomials &rhs) {
    return rhs * lhs;
}

// prodotto tra due polinomi
Polynomials operator*(const Polynomials &lhs, const Polynomials &rhs) {
    int newSize = lhs.size + rhs.size - 1;      // occhio al -1
    auto *newCoefs = new double[newSize]{};     // le parentesi {} della lista d'inizializzazione servono
                                                // a porre ogni elemento uguale a 0
    // ciclo ogni grado da zero al grado massimo
    for (int deg = 0; deg < newSize; ++deg) {
        // ciclo ignorante molto ottimizzabile
        for (int i = 0; i < lhs.size; ++i) {
            for (int j = 0; j < rhs.size; ++j) {
                if (i + j == deg) {
                    newCoefs[deg] += lhs.coefs[i] * rhs.coefs[j];
                }
            }
        }
    }

    return Polynomials(newCoefs,newSize);
}

// operatore di inserimento
std::ostream &operator<<(std::ostream &out, const Polynomials &rhs) {
    rhs.print(out);
    return out;
}