//
// Bibliography
// main.cpp
// Created by Luigi Catello on 27/04/21.
//
//
#include <iostream>
#include <string>
#include <vector>
#include "Publication.h"
#include "Book.h"
#include "PaperArticle.h"
#include "ConferenceArticle.h"
#include "QuickSort.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {

    vector<Publication*> pubs{
        new PaperArticle( "Algorithms and Data Structures", "Zeccarelli M.", 1992, "Focus", 23, 130, 132),
        new ConferenceArticle("Articolo Conf", "Celentano G., Celentano L.", 2010, "IEEE conference", "Roma", 17),
        new Book("Fondamenti di controlli", "Bolzern P., Scattolini R.", 2009, "McGraw Hill", "978-98-232-4356-1"),
        new Book("Respiro", "Chiang T.", 2018, "TizioCaio", "987-12-345-5678-9")
    };

    // stampa preliminare
    cout << "Vettore non ordinato:" << endl;
    for (const auto pubPtr : pubs) {
        cout << pubPtr->getTitle() << endl;
    }

    // ordinamento vettore
    quickSort(pubs, 0, pubs.size()-1);

    // stampa vettore ordinato
    cout << "\nVettore ordinato:" << endl;
    for (const auto pubPtr : pubs) {
        cout << pubPtr->getTitle() << endl;
    }

    // contatore numero pubblicazioni
    int totalePaper{0}, totaleConference{0}, totaleBook{0};

    // contiamo le pubblicazioni per tipo utilizzando il downcasting
    // (poteva essere fatto nel ciclo for della stampa)
    for (const auto pubPtr : pubs) {
        auto paperPtr = dynamic_cast<PaperArticle*>(pubPtr);
        if (paperPtr != nullptr) {
            // è un PaperArticle
            totalePaper++;
            continue;   // se è un PaperArticle è inutile continuare a testare
        }
        auto conferencePtr = dynamic_cast<ConferenceArticle*>(pubPtr);
        if (conferencePtr != nullptr) {
            // è un ConferenceArticle
            totaleConference++;
            continue;
        }
        // esistendo solo tre tipi, se non era uno dei precedenti sicuramente sarà Book...
        // lascio la struttura nel caso un giorno venissero aggiunti altri tipi
        auto bookPtr = dynamic_cast<Book*>(pubPtr);
        if (bookPtr != nullptr) {
            // è un Book
            totaleBook++;
        }
    }       // end for
    // al posto di usare i dynamic_cast, si poteva utilizzare la funzione getType() ed effettuare uno switch

    cout << endl;
    cout << "Totale Paper Article:      " << totalePaper << endl;
    cout << "Totale Conference Article: " << totaleConference << endl;
    cout << "Totale Book:               " << totaleBook << endl;



    return 0;
}
