#pragma once
#include <string>
#include <vector>
#include "Devices.h"

using std::vector;

class User {
private:
    int id;
    std::string username;
    int age;
    vector<Devices> devices; // רשימת המכשירים של המשתמש

public:
    User(int id, const std::string& username, int age)
        : id(id), username(username), age(age) {
    }

    int getID() const { return id; }
    std::string getUserName() const { return username; }
    int getAge() const { return age; }

    void addDevice(const Devices& device) { devices.push_back(device); }

    bool checkIfDevicesAreOn() const {
        for (const auto& d : devices)
            if (!d.isActive()) return false;
        return true;
    }

    vector<Devices> getDevices() const { return devices; }

    vector<Devices> getWindowsDevices() const {
        vector<Devices> windowsDevices;
        for (const auto& d : devices)
            if (d.getOS() == "Windows")
                windowsDevices.push_back(d);
        return windowsDevices;
    }
};
