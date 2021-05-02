//
// Bibliography
// ConferenceArticle.cpp
// Created by Luigi Catello on 01/05/21.
// 
//

#include "ConferenceArticle.h"
ConferenceArticle::ConferenceArticle(const std::string &new_title, const std::string &new_authors, int new_year,
                                     const std::string &c_title, const std::string &location, int page_no) :
                                     Publication(new_title, new_authors, new_year),
                                        cTitle(c_title), location(location), pageNo(page_no) {}

// getters & setters
std::string ConferenceArticle::GetCTitle() const {
    return cTitle;
}
std::string ConferenceArticle::GetLocation() const {
    return location;
}
int ConferenceArticle::GetPageNo() const {
    return pageNo;
}
void ConferenceArticle::SetCTitle(const std::string &c_title) {
    this->cTitle = c_title;
}
void ConferenceArticle::SetLocation(const std::string &newLocation) {
    this->location = newLocation;
}
void ConferenceArticle::SetPageNo(int page_no) {
    this->pageNo = page_no;
}
