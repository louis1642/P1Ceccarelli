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

    Publication* pub1 = new PaperArticle( "il titolo", "Franco Balordo", 1992, "Focus", 23, 130, 132);
    Publication* pub2 = new PaperArticle("s.v.lo", "Antonio Lello", 1981, "Nature", 3, 12, 20);

    PaperArticle art1("il titolo", "Franco Balordo", 1992, "Focus", 23, 130, 132);
    PaperArticle art2("s.v.lo", "Antonio Lello", 1981, "Nature", 3, 12, 20);

    cout << (*pub1 < *pub2) << endl;

    // TODO vettore di publication*, calcolare totale per ogni categoria (con contatore e con casting), ordinare il vettore e stampare
    vector<Publication*> pubs{
        new PaperArticle( "il titolo", "Franco Balordo", 1992, "Focus", 23, 130, 132),
        new ConferenceArticle("Articolo Conf", "Celentano G., Celentano L.", 2010, "IEEE conference", "Roma", 17),
        new Book("Fondamenti di controlli", "Bolzern P., Scattolini R.", 2009, "McGraw Hill", "978-98-232-4356-1")
    };

    // stampa preliminare
    for (const auto pubPtr : pubs) {
        cout << pubPtr->getTitle() << endl;
    }

    quickSort(pubs, 0, pubs.size()-1);

    for (const auto pubPtr : pubs) {
        cout << pubPtr->getTitle() << endl;
    }




    return 0;
}
