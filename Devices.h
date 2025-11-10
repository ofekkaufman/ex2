#pragma once
#include <string>

enum DeviceType { PHONE, PC, LAPTOP, TABLET };

#define UbuntuOS "UbuntuLinux"                        
#define RedHatOS "RedHatLinux"							 
#define MacOS "MacOS"									 
#define IOS "IOS"										 
#define WINDOWS7 "Windows7"                              
#define WINDOWS10 "Windows10"                            
#define WINDOWS11 "Windows11"                            
#define ANDROID "Android"                                

class Devices
{
private:
    unsigned int m_id;
    DeviceType m_type;
    std::string m_os;
    bool m_isActive;

public:
    void init(unsigned int id, DeviceType type, const std::string& os);
    void clear();

    unsigned int getID() const;
    DeviceType getType() const;
    std::string getOS() const;
    bool isActive() const;

    void activate();
    void deactivate();
};
