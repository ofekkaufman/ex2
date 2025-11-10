#include "Profile.h"
#include <sstream>

void Profile::init(const User& user) {
    owner = user;
    page = "";
    friends.clear();
}

User Profile::getOwner() const {
    return owner;
}

std::string Profile::getPage() const {
    return page;
}

void Profile::setStatus(const std::string& status) {
    // מחליף את השורה הראשונה של ה-page בסטטוס
    std::istringstream iss(page);
    std::string restOfPage, line;
    bool firstLine = true;
    while (std::getline(iss, line)) {
        if (!firstLine) restOfPage += line + "\n";
        firstLine = false;
    }
    page = status + "\n" + restOfPage;
}

void Profile::addPostToProfilePage(const std::string& post) {
    page += post + "\n";
}

void Profile::addFriend(const User& newFriend) {
    friends.push_back(newFriend);
}

std::string Profile::getFriends() const {
    std::string result;
    for (const auto& f : friends)
        result += f.getUserName() + " ";
    if (!result.empty()) result.pop_back(); // להסיר רווח אחרון
    return result;
}

int Profile::getFriendsWithSameNameLength() const {
    int count = 0;
    int len = owner.getUserName().length();
    for (const auto& f : friends) {
        if (f.getUserName().length() == len) count++;
    }
    return count;
}

void Profile::clear() {
    friends.clear();
    page = "";
}


