#pragma once
#include "Devices.h"
#include <stdexcept>

// Node של רשימה מקושרת
class DeviceNode {
public:
    Device data;
    DeviceNode* _next = nullptr;  // אתחול ברירת מחדל ל-nullptr

    // Constructor
    DeviceNode(const Device& device) : data(device), _next(nullptr) {}
};

// רשימת מכשירים
class DeviceList {
private:
    DeviceNode* head = nullptr;  // ראש הרשימה, אתחול ל-nullptr

public:
    DeviceList() : head(nullptr) {}
    ~DeviceList() { clear(); }

    void add(const Device& device);          // הוספת מכשיר
    void clear();                             // ניקוי כל הרשימה
    unsigned int size() const;                // גודל הרשימה
    Device& get(unsigned int index);          // גישה למכשיר לפי אינדקס
    const Device& get(unsigned int index) const; // גישה למכשיר מתוך const
};
