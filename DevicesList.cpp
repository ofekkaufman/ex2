#include "DevicesList.h"
#include <vector>

void DevicesList::init() {
    devices = nullptr;
    count = 0;
}

void DevicesList::add(const Devices& device) {
    // לפשט: אפשר להמיר ל-vector מאוחר יותר
}

Devices DevicesList::get(unsigned int index) const {
    return Devices();
}

int DevicesList::size() const { return count; }

void DevicesList::clear() {
    // לפנות זיכרון אם הקצאתם מערך דינמי
}
