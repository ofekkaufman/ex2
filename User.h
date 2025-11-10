#pragma once
#include <string>
#include "DevicesList.h"

class User {
private:
    unsigned long long id;
    std::string username;
    int age;
    DevicesList devices;

public:
    void init(unsigned long long id, const std::string& username, int age);
    unsigned long long getID() const;
    std::string getUserName() const;
    int getAge() const;
    void addDevice(const Devices& device);
    bool checkIfDevicesAreOn() const;
    void clear();
};
