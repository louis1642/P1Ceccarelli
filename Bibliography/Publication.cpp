//
// Bibliography
// Publication.cpp
// Created by Luigi Catello on 27/04/21.
// 
//

#include "Publication.h"

// costruttore
Publication::Publication(std::string newTitle, std::string newAuthors, int newYear) :
    title{newTitle}, authors{newAuthors}, year{newYear} {}

bool Publication::operator>(const Publication &rhs) const {
    return (this->authors > rhs.authors);
}
bool Publication::operator<(const Publication &rhs) const {
    return (this->authors < rhs.authors);
}
bool Publication::operator>=(const Publication &rhs) const {
    return (this->authors >= rhs.authors);
}
bool Publication::operator<=(const Publication &rhs) const {
    return (this->authors <= rhs.authors);
}

// getters & setters
std::string Publication::getAuthors() const {
    return authors;
}
void Publication::setAuthors(std::string &newAuthors) {
    this->authors = newAuthors;
}
std::string Publication::getTitle() const {
    return title;
}
void Publication::setTitle(std::string &newTitle) {
    this->title = newTitle;
}
int Publication::getYear() const {
    return year;
}
void Publication::setYear(int newYear) {
    this->year = newYear;
}

