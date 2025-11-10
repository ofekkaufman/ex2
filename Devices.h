#pragma once
#include <string>

enum DeviceType { PC, LAPTOP, TABLET, PHONE };

class Devices {
private:
    int id;
    DeviceType type;
    std::string os;
    bool active;

public:
    Devices(int id, DeviceType type, const std::string& os, bool active)
        : id(id), type(type), os(os), active(active) {
    }

    int getID() const { return id; }
    DeviceType getType() const { return type; }
    std::string getOS() const { return os; }
    bool isActive() const { return active; }
};
