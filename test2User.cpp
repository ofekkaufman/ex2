#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <random>

#include "User.h"

using std::cout;
using std::endl;

#define GREEN 2
#define DARK_RED 4
#define PURPLE 5
#define YELLOW 6
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define TEAL 11
#define RED 12
#define PURPLE 13
#define LIGHT_YELLOW 14
#define WHITE 15

void set_console_color(unsigned int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

std::string getDeviceTypeString(const DeviceType type)
{
    if (type == PC) return "PC";
    else if (type == LAPTOP) return "Laptop";
    else if (type == TABLET) return "Tablet";
    else if (type == PHONE) return "Phone";
    return "Unknown";
}

std::string getDeviceString(const Devices& device)
{
    return "[ID: " + std::to_string(device.getID()) +
        ", Type: " + getDeviceTypeString(device.getType()) +
        ", OS: " + device.getOS() +
        ", Activated: " + (device.isActive() ? "Yes" : "No") + "]";
}

std::string getUserString(const User& user)
{
    return "[ID: " + std::to_string(user.getID()) +
        ", Username: " + user.getUserName() +
        ", Age: " + std::to_string(user.getAge()) +
        ", All devices On: " + (user.checkIfDevicesAreOn() ? "Yes" : "No") + "]";
}

std::string getUserDevicesString(const User& user)
{
    std::string result;
    const DeviceList& devices = user.getDevices();
    for (unsigned int i = 0; i < devices.size(); i++)
    {
        result += getDeviceString(devices.get(i)) + "\n";
    }
    if (!result.empty()) result.pop_back(); // להסיר את '\n' האחרון
    return result;
}

bool test2User()
{
    try
    {
        set_console_color(PURPLE);
        cout << "********************\nTest 2 - User\n********************\n\n";
        set_console_color(WHITE);

        // יצירת מכשירים
        Devices device1; device1.init(2123, LAPTOP, WINDOWS11);
        Devices device2; device2.init(3212, PC, UbuntuOS);
        Devices device3; device3.init(1121, TABLET, WINDOWS10);
        Devices device4; device4.init(4134, PHONE, ANDROID);

        // בדיקה של getDeviceString
        std::string expected = "[ID: 2123, Type: Laptop, OS: Windows11, Activated: Yes]\n"
            "[ID: 3212, Type: PC, OS: UbuntuLinux, Activated: Yes]\n"
            "[ID: 1121, Type: Tablet, OS: Windows10, Activated: Yes]\n"
            "[ID: 4134, Type: Phone, OS: Android, Activated: Yes]";
        std::string got = getDeviceString(device1) + "\n" +
            getDeviceString(device2) + "\n" +
            getDeviceString(device3) + "\n" +
            getDeviceString(device4);
        if (got != expected) { set_console_color(RED); cout << "FAILED: Device info mismatch\n"; return false; }

        // יצירת משתמשים
        User user1; user1.init(123456789, "blinkybill", 17);
        User user2; user2.init(987654321, "HatichEshMiGilShesh", 15);

        // הוספת מכשירים למשתמשים
        user1.addDevice(device1);
        user1.addDevice(device2);
        user2.addDevice(device3);
        user2.addDevice(device4);

        // בדיקה אם כל המכשירים פועלים
        if (!user1.checkIfDevicesAreOn() || !user2.checkIfDevicesAreOn())
        {
            set_console_color(RED); cout << "FAILED: User devices should all be ON\n"; return false;
        }

        // השבתה של מכשיר אחד
        user2.getDevices().get(0).deactivate();
        if (user2.checkIfDevicesAreOn())
        {
            set_console_color(RED); cout << "FAILED: User2 should have a device OFF\n"; return false;
        }

        // ניקוי
        user1.clear();
        user2.clear();
    }
    catch (...)
    {
        set_console_color(RED);
        std::cerr << "Test crashed\n";
        return false;
    }

    set_console_color(LIGHT_GREEN);
    std::cout << "\n########## User - TEST Passed!!! ##########\n\n";
    set_console_color(WHITE);
    return true;
}

int main()
{
    set_console_color(LIGHT_YELLOW);
    std::cout << "###########################\n"
        << "Exercise 2 - Social Network\n"
        << "Part 2 - User\n"
        << "###########################\n\n";
    set_console_color(WHITE);

    bool testResult = test2User();
    if (testResult)
    {
        set_console_color(GREEN);
        std::cout << "\n########## Ex2 Part2 Tests Passed!!! ##########\n\n";
    }
    else
    {
        set_console_color(RED);
        std::cout << "\n########## TEST Failed :( ##########\n";
    }
    set_console_color(WHITE);
    return 0;
}
    