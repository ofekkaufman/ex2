#include "Devices.h"

void Devices::init(unsigned int _id, DeviceType _type, OS _os) {
    id = _id;
    type = _type;
    os = _os;
    active = false;
}

unsigned int Devices::getID() const { return id; }
DeviceType Devices::getType() const { return type; }

std::string Devices::getOS() const {
    switch (os) {
    case WINDOWS7: return "Windows 7";
    case WINDOWS10: return "Windows 10";
    case WINDOWS11: return "Windows 11";
    case UbuntuOS: return "Ubuntu";
    case RedHatOS: return "RedHat";
    case MacOS: return "MacOS";
    case ANDROID: return "Android";
    case IOS: return "iOS";
    default: return "Unknown";
    }
}

bool Devices::isActive() const { return active; }
void Devices::setActive(bool value) { active = value; }
