//
// Bibliography
// PaperArticle.cpp
// Created by Luigi Catello on 01/05/21.
// 
//

#include "PaperArticle.h"

// costruttore
PaperArticle::PaperArticle(std::string newTitle, std::string newAuthors, int newYear,
                           std::string newRTitle, int newIssueNo, int newStartPage, int newEndPage) :
    Publication(newTitle, newAuthors, newYear) {
    rTitle = newRTitle;
    issueNo = newIssueNo;
    startPage = newStartPage;
    endPage = newEndPage;
}

// getters & setters
std::string PaperArticle::getRTitle() const {
    return rTitle;
}
void PaperArticle::setRTitle(std::string &newRTitle) {
    this->rTitle = newRTitle;
}
int PaperArticle::getIssueNo() const {
    return issueNo;
}
void PaperArticle::setIssueNo(int newIssueNo) {
    this->issueNo = newIssueNo;
}
int PaperArticle::getStartPage() const {
    return startPage;
}
void PaperArticle::setStartPage(int newStartPage) {
    this->startPage = newStartPage;
}
int PaperArticle::getEndPage() const {
    return endPage;
}
void PaperArticle::setEndPage(int newEndPage) {
    this->endPage = newEndPage;
}
