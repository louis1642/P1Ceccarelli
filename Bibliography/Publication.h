//
// Bibliography
// Publication.h
// Created by Luigi Catello on 27/04/21.
// base class.
//

#ifndef BIBLIOGRAPHY__PUBLICATION_H_
#define BIBLIOGRAPHY__PUBLICATION_H_

#include <string>
enum publicationType {genericPublication, book, paperArticle, conferenceArticle};

class Publication {
 private:
  std::string title{};
  std::string authors{};
  int year;
 public:
  Publication(std::string newTitle, std::string newAuthors, int newYear);
  // viene fatto l'override nelle classi figlie
    virtual std::string getType() const {
        return "Generic Publication";
    }

    // overload degli operatori >, <, ... per consentire il sorting
    bool operator>(const Publication &rhs) const;
    bool operator<(const Publication &rhs) const;
    bool operator>=(const Publication &rhs) const;
    bool operator<=(const Publication &rhs) const;

    // getters e setters
    std::string getTitle() const;
    void setTitle(std::string &newTitle);
    std::string getAuthors() const;
    void setAuthors(std::string &newAuthors);
    int getYear() const;
    void setYear(int newYear);
};

#endif //BIBLIOGRAPHY__PUBLICATION_H_
