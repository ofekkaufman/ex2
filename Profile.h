#pragma once
#include <string>
#include <vector>
#include "User.h"

class Profile {
private:
    User owner;
    std::vector<std::string> friends;
    std::vector<std::string> posts;
    std::string status;

public:
    Profile(const User& user) : owner(user) {}

    User& getOwner() { return owner; }
    const User& getOwner() const;

    void addFriend(const User& u) { friends.push_back(u.getUserName()); }
    void addPostToProfilePage(const std::string& post) { posts.push_back(post); }
    void setStatus(const std::string& s) { status = s; }

    std::string getPage() const {
        std::string page;
        for (const auto& p : posts)
            page += p + "\n";
        return page;
    }
};
