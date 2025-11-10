#include "UserList.h"

void UserList::init() {
    head = nullptr;
}

void UserList::add(User u) {
    UserNode* newNode = new UserNode(u);
    newNode->next = head;
    head = newNode;
}

UserNode* UserList::get_first() const { return head; }

void UserList::clear() {
    UserNode* current = head;
    while (current) {
        UserNode* tmp = current;
        current = current->next;
        delete tmp;
    }
    head = nullptr;
}
