#include "User.h"

// אתחול משתמש חדש
void User::init(unsigned int id, const std::string& username, unsigned int age)
{
    m_id = id;
    m_username = username;
    m_age = age;
    m_devices.clear(); // מאתחל רשימת מכשירים ריקה
}

// ניקוי אובייקט
void User::clear()
{
    m_id = 0;
    m_username = "";
    m_age = 0;
    m_devices.clear(); // מנקה את רשימת המכשירים
}

// גטרים
unsigned int User::getID() const
{
    return m_id;
}

std::string User::getUserName() const
{
    return m_username;
}

unsigned int User::getAge() const
{
    return m_age;
}

// רשימת מכשירים
DeviceList& User::getDevices()
{
    return m_devices; // מחזיר reference כדי לשנות את הרשימה ישירות
}

// הוספת מכשיר לרשימה
void User::addDevice(const Device& newDevice)
{
    m_devices.add(newDevice); // שימוש ב־DeviceList
}

// בדיקה אם כל המכשירים פעילים
bool User::checkIfDevicesAreOn() const
{
    for (unsigned int i = 0; i < m_devices.size(); i++)
    {
        if (!m_devices.get(i).isActive())
            return false;
    }
    return true;
}
