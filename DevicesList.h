#pragma once
#include "Devices.h"
#include <stdexcept>

// Node של רשימה מקושרת
class DeviceNode {
public:
    Devices data;
    DeviceNode* _next = nullptr;  // אתחול ברירת מחדל ל-nullptr

    // Constructor
    DeviceNode(const Devices& device) : data(device), _next(nullptr) {}
};

// רשימת מכשירים
class DeviceList {
private:
    DeviceNode* head = nullptr;  // ראש הרשימה, אתחול ל-nullptr

public:
    DeviceList() : head(nullptr) {}
    ~DeviceList() { clear(); }

    void add(const Devices& device);          // הוספת מכשיר
    void clear();                             // ניקוי כל הרשימה
    unsigned int size() const;                // גודל הרשימה
    Devices& get(unsigned int index);          // גישה למכשיר לפי אינדקס
    const Devices& get(unsigned int index) const; // גישה למכשיר מתוך const
};
