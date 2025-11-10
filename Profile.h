#pragma once
#include <string>
#include <vector>
#include "User.h"

class Profile {
private:
    User owner;
    std::vector<User> friends;
    std::string page; // כולל סטטוס + פוסטים

public:
    void init(const User& user);

    User getOwner() const;
    std::string getPage() const;

    void setStatus(const std::string& status);
    void addPostToProfilePage(const std::string& post);

    void addFriend(const User& newFriend);
    std::string getFriends() const;
    int getFriendsWithSameNameLength() const;

    void clear();

    // --- Bonus ---
    void changeAllWordsInStatus(const std::string& newWord);
    void changeWordInStatus(const std::string& oldWord, const std::string& newWord);
};
