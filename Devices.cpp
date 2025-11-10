#include "Devices.h"

void Devices::init(unsigned int id, DeviceType type, const std::string& os)
{
    m_id = id;
    m_type = type;
    m_os = os;
    m_isActive = true;
}

void Devices::clear()
{
    m_id = 0;
    m_type = PHONE;
    m_os = "";
    m_isActive = false;
}

unsigned int Devices::getID() const
{
    return m_id;
}

DeviceType Devices::getType() const
{
    return m_type;
}

std::string Devices::getOS() const
{
    return m_os;
}

bool Devices::isActive() const
{
    return m_isActive;
}

void Devices::activate()
{
    m_isActive = true;
}

void Devices::deactivate()
{
    m_isActive = false;
}
