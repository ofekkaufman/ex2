#include "Device.h"

// אתחול המכשיר
void Device::init(unsigned int id, DeviceType type, const std::string& os)
{
    m_id = id;
    m_type = type;
    m_os = os;
    m_isActive = true; // כשנוצר מכשיר חדש, הוא פעיל כברירת מחדל
}

// איפוס המכשיר
void Device::clear()
{
    m_id = 0;
    m_type = PHONE;
    m_os = "";
    m_isActive = false;
}

// גטרים
unsigned int Device::getID() const
{
    return m_id;
}

DeviceType Device::getType() const
{
    return m_type;
}

std::string Device::getOS() const
{
    return m_os;
}

bool Device::isActive() const
{
    return m_isActive;
}

// שינוי מצב
void Device::activate()
{
    m_isActive = true;
}

void Device::deactivate()
{
    m_isActive = false;
}
