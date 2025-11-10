#pragma once
#include "User.h"

struct UserNode {
    User data;
    UserNode* next;
    UserNode(User u) : data(u), next(nullptr) {}
    User get_data() const { return data; }
    UserNode* get_next() const { return next; }
};

class UserList {
private:
    UserNode* head;

public:
    void init();
    void add(User u);
    UserNode* get_first() const;
    void clear();
};
