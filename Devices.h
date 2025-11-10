#pragma once
#include <string>

enum DeviceType { PC, LAPTOP, TABLET, PHONE };
enum OS { WINDOWS7, WINDOWS10, WINDOWS11, UbuntuOS, RedHatOS, MacOS, ANDROID, IOS };

class Devices {
private:
    unsigned int id;
    DeviceType type;
    OS os;
    bool active;

public:
    void init(unsigned int id, DeviceType type, OS os);
    unsigned int getID() const;
    DeviceType getType() const;
    std::string getOS() const;
    bool isActive() const;
    void setActive(bool value);
};
