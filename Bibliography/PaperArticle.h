//
// Bibliography
// PaperArticle.h
// Created by Luigi Catello on 01/05/21.
// 
//

#ifndef BIBLIOGRAPHY__PAPERARTICLE_H_
#define BIBLIOGRAPHY__PAPERARTICLE_H_

#include "Publication.h"

class PaperArticle : public Publication{
 private:
  std::string rTitle{};
  int issueNo;
  int startPage;
  int endPage;
  const publicationType type = paperArticle;
 public:
  PaperArticle(std::string newTitle, std::string newAuthors, int newYear, std::string newRTitle, int newIssueNo, int newStartPage, int newEndPage);
  virtual std::string getType() const override {
      return "Paper Article";
  }

  // getters & setters
  std::string getRTitle() const;
  void setRTitle(std::string &newRTitle);
  int getIssueNo() const;
  void setIssueNo(int newIssueNo);
  int getStartPage() const;
  void setStartPage(int newStartPage);
  int getEndPage() const;
  void setEndPage(int newEndPage);
};

#endif //BIBLIOGRAPHY__PAPERARTICLE_H_
