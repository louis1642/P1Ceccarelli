//
// Bibliography
// Book.cpp
// Created by Luigi Catello on 27/04/21.
// 
//

#include "Book.h"
Book::Book(const std::string &new_title, const std::string &new_authors, int new_year,
           const std::string &newPublisher, const std::string &newIsbn) :
            Publication(new_title, new_authors, new_year),
            publisher(newPublisher), isbn(newIsbn) {}

// getters & setters
std::string Book::GetPublisher() const {
    return publisher;
}
std::string Book::GetIsbn() const {
    return isbn;
}
void Book::SetPublisher(const std::string &newPublisher) {
    this->publisher = newPublisher;
}
void Book::SetIsbn(const std::string &newIsbn) {
    this->isbn = newIsbn;
}
