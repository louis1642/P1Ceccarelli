//
// Bibliography
// ConferenceArticle.h
// Created by Luigi Catello on 01/05/21.
// 
//

#ifndef BIBLIOGRAPHY__CONFERENCEARTICLE_H_
#define BIBLIOGRAPHY__CONFERENCEARTICLE_H_

#include "Publication.h"

class ConferenceArticle : public Publication {
 private:
  std::string cTitle{};
  std::string location{};
  int pageNo;
 public:
  void SetCTitle(const std::string &c_title);
  void SetLocation(const std::string &location);
  void SetPageNo(int page_no);
 private:
  const publicationType type = conferenceArticle;
 public:
  ConferenceArticle(const std::string &new_title,
                    const std::string &new_authors,
                    int new_year,
                    const std::string &c_title,
                    const std::string &location,
                    int page_no);
  virtual std::string getType() const override{
      return "Conference Article";
  }

  // getters & setters
  std::string GetCTitle() const;
  std::string GetLocation() const;
  int GetPageNo() const;
};

#endif //BIBLIOGRAPHY__CONFERENCEARTICLE_H_
