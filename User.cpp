#include "User.h"

void User::init(unsigned long long _id, const std::string& _username, int _age) {
    id = _id;
    username = _username;
    age = _age;
    devices.init();
}

unsigned long long User::getID() const { return id; }
std::string User::getUserName() const { return username; }
int User::getAge() const { return age; }

void User::addDevice(const Devices& device) {
    devices.add(device);
}

bool User::checkIfDevicesAreOn() const {
    return true; // או לולאה על כל המכשירים
}

void User::clear() {
    devices.clear();
}
