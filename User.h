#pragma once
#include <string>
#include "Devices.h"
#include "DevicesList.h"

class User
{
private:
    unsigned int id;
    std::string username;
    unsigned int age;
    DeviceList devices; // רשימת המכשירים של המשתמש

public:
    // אתחול משתמש חדש
    void init(unsigned int id, const std::string& username, unsigned int age);

    // ניקוי המשתמש
    void clear();

    // גישה לשדות
    unsigned int getID() const;
    std::string getUserName() const;
    unsigned int getAge() const;

    // גישה לרשימת המכשירים
    DeviceList& getDevices();                   // שימוש רגיל
    const DeviceList& getDevices() const;       // שימוש עם const

    // הוספת מכשיר לרשימה
    void addDevice(const Devices& newDevice);

    // בדיקה אם כל המכשירים פועלים
    bool checkIfDevicesAreOn() const;
};
