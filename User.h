#pragma once
#include <string>
#include "DevicesList.h"  // כוללים את הרשימה של המכשירים

class User
{
private:
    unsigned int m_id;
    std::string m_username;
    unsigned int m_age;
    DeviceList m_devices;  // רשימת מכשירים של המשתמש

public:
    // אתחול ומנקה
    void init(unsigned int id, const std::string& username, unsigned int age);
    void clear();

    // גטרים
    unsigned int getID() const;
    std::string getUserName() const;
    unsigned int getAge() const;

    // מכשירים
    DeviceList& getDevices();
    void addDevice(const Device& newDevice);
    bool checkIfDevicesAreOn() const;
};
