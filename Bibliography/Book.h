//
// Bibliography
// Book.h
// Created by Luigi Catello on 27/04/21.
// 
//

#ifndef BIBLIOGRAPHY__BOOK_H_
#define BIBLIOGRAPHY__BOOK_H_

#include "Publication.h"

class Book : public Publication{
 private:
  std::string publisher{};
  std::string isbn{};
  const publicationType type = book;
 public:
  // costruttore
  Book(const std::string &new_title,
       const std::string &new_authors,
       int new_year,
       const std::string &publisher,
       const std::string &isbn);
  std::string GetPublisher() const;
  std::string GetIsbn() const;
  void SetPublisher(const std::string &publisher);
  void SetIsbn(const std::string &isbn);
  virtual std::string getType() const override {
      return "Book";
  }

};

#endif //BIBLIOGRAPHY__BOOK_H_
