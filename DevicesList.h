#pragma once
#include "Devices.h"

class DevicesList {
private:
    Devices* devices;
    int count;
public:
    void init();
    void add(const Devices& device);
    Devices get(unsigned int index) const;
    int size() const;
    void clear();
};
