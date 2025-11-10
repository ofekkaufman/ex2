#include "Page.h"

void Page::init() {
    status = "";
    posts.clear();
}

void Page::setStatus(const std::string& s) { status = s; }
std::string Page::getStatus() const { return status; }

void Page::addLineToPosts(const std::string& post) { posts.push_back(post); }
std::vector<std::string> Page::getPosts() const { return posts; }

void Page::clear() {
    status = "";
    posts.clear();
}
