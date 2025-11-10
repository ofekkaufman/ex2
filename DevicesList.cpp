#include "DevicesList.h"

// הוספת מכשיר חדש לסוף הרשימה
void DeviceList::add(const Device& device)
{
    DeviceNode* newNode = new DeviceNode(device);
    if (!head) {
        head = newNode;
    }
    else {
        DeviceNode* temp = head;
        while (temp->_next) {
            temp = temp->_next;
        }
        temp->_next = newNode;
    }
}

// ניקוי הרשימה ושחרור זיכרון
void DeviceList::clear()
{
    DeviceNode* current = head;
    while (current) {
        DeviceNode* next = current->_next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// חישוב גודל הרשימה
unsigned int DeviceList::size() const
{
    unsigned int count = 0;
    DeviceNode* temp = head;
    while (temp) {
        count++;
        temp = temp->_next;
    }
    return count;
}

// גישה למכשיר לפי אינדקס
Device& DeviceList::get(unsigned int index)
{
    DeviceNode* temp = head;
    unsigned int count = 0;
    while (temp) {
        if (count == index) return temp->data;
        count++;
        temp = temp->_next;
    }
    throw std::out_of_range("Index out of range in DeviceList::get");
}

// גישה למכשיר מתוך const
const Device& DeviceList::get(unsigned int index) const
{
    DeviceNode* temp = head;
    unsigned int count = 0;
    while (temp) {
        if (count == index) return temp->data;
        count++;
        temp = temp->_next;
    }
    throw std::out_of_range("Index out of range in DeviceList::get const");
}
