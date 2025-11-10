#include "User.h"

// אתחול המשתמש
void User::init(unsigned int id, const std::string& username, unsigned int age)
{
    this->id = id;
    this->username = username;
    this->age = age;
    devices.clear(); // איפוס רשימת המכשירים
}

// ניקוי המשתמש
void User::clear()
{
    devices.clear();
    id = 0;
    username = "";
    age = 0;
}

// גישה לשדות
unsigned int User::getID() const
{
    return id;
}

std::string User::getUserName() const
{
    return username;
}

unsigned int User::getAge() const
{
    return age;
}

// גישה לרשימת המכשירים
DeviceList& User::getDevices()
{
    return devices;
}

const DeviceList& User::getDevices() const
{
    return devices;
}

// הוספת מכשיר לרשימה
void User::addDevice(const Devices& newDevice)
{
    devices.add(newDevice);
}

// בדיקה אם כל המכשירים פועלים
bool User::checkIfDevicesAreOn() const
{
    for (unsigned int i = 0; i < devices.size(); i++)
    {
        if (!devices.get(i).isActive()) // כאן נגשים ישירות ל-Devices
            return false;
    }
    return true;
}
