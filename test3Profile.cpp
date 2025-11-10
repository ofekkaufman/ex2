#include <iostream>
#include <windows.h>
#include <random>

#include "Devices.h"
#include "User.h"
#include "Profile.h"

using std::cout;
using std::endl;

#define GREEN 2
#define RED 12
#define WHITE 15
#define LIGHT_GREEN 10
#define LIGHT_BLUE 9
#define PURPLE 5
#define LIGHT_YELLOW 14

std::string posts[] = { "Hello world!", "Good morning :)", "Magshimim forever ***", "Ekronot is the best...", "Happy birthday! Ad 120" };
std::string statusMessages[] = {
    "Feeling sick, need chicken soup... can you bring me some?",
    "Which witch watched which watch??? you must tell me!!!",
    "Finally got my driver license !!!, when are you getting yours?",
    "\"No matter how smart you are, you can never convince someone stupid that they are stupid.\"",
    "Have you ever wondered why you can't taste your tongue?"
};

void set_console_color(unsigned int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int getRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

std::string getDeviceTypeString(const DeviceType type) {
    switch (type) {
    case PC: return "PC";
    case LAPTOP: return "Laptop";
    case TABLET: return "Tablet";
    case PHONE: return "Phone";
    default: return "Unknown";
    }
}

std::string getDeviceString(const Devices& device) {
    return "[ID: " + std::to_string(device.getID()) +
        ", Type: " + getDeviceTypeString(device.getType()) +
        ", OS: " + device.getOS() +
        ", Activated: " + (device.isActive() ? "Yes" : "No") + "]";
}

std::string getUserString(const User& user) {
    return "[ID: " + std::to_string(user.getID()) +
        ", Username: " + user.getUserName() +
        ", Age: " + std::to_string(user.getAge()) +
        ", All devices On: " + (user.checkIfDevicesAreOn() ? "Yes" : "No") + "]";
}

std::string getProfileString(const Profile& profile) {
    return "Owner: " + getUserString(profile.getOwner()) + "\n" +
        profile.getOwner().getUserName() + "'s page:\n" +
        profile.getPage();
}

void allFriends(Profile* profiles[], const int numOfProfiles) {
    for (int i = 0; i < numOfProfiles; i++) {
        for (int j = 0; j < numOfProfiles; j++) {
            if (i != j) profiles[i]->addFriend(profiles[j]->getOwner());
        }
    }
}

void generateRandomPage(Profile& profile) {
    profile.setStatus(statusMessages[getRandomInt(0, 4)]);
    int numberOfPosts = getRandomInt(0, 3);
    for (int i = 0; i < numberOfPosts; i++) {
        profile.addPostToProfilePage(posts[getRandomInt(0, 4)]);
    }
}

// --- Helper functions for Bonus ---
bool checkAllWordsAreAlikeInStatus(std::string str) {
    const std::string word = "Magshimim";
    int pos = -1;
    while ((pos = str.find('\n')) != std::string::npos)
        str.replace(pos, 1, "");
    while ((pos = str.find(' ')) != std::string::npos)
        str.replace(pos, 1, "");
    while ((pos = str.find('\t')) != std::string::npos)
        str.replace(pos, 1, "");
    while ((pos = str.find(word)) != std::string::npos)
        str.replace(pos, word.length(), "");
    return str.length() == 0;
}

bool checkWordDoesNotExistInStatus(std::string status, const std::string& word) {
    return status.find(word) == std::string::npos;
}

// --- Test functions ---
bool test3Profile() {
    try {
        set_console_color(LIGHT_BLUE);
        cout << "*******************\nTest 3 - Profile\n*******************\n" << endl;
        set_console_color(WHITE);

        // --- Devices ---
        Devices device1; device1.init(2123, LAPTOP, WINDOWS11);
        Devices device2; device2.init(3212, PC, UbuntuOS);
        Devices device3; device3.init(1121, TABLET, WINDOWS10);
        Devices device4; device4.init(4134, PHONE, ANDROID);
        Devices device5; device5.init(5522, LAPTOP, MacOS);
        Devices device6; device6.init(5361, PC, WINDOWS7);
        Devices device7; device7.init(6611, PHONE, IOS);
        Devices device8; device8.init(6613, LAPTOP, RedHatOS);
        Devices device9; device9.init(7711, TABLET, WINDOWS11);
        Devices device10; device10.init(8181, TABLET, ANDROID);
        Devices device11; device11.init(8654, LAPTOP, UbuntuOS);
        Devices device12; device12.init(9444, PC, WINDOWS11);

        // --- Users ---
        User user1; user1.init(123456789, "Gal", 17);
        User user2; user2.init(987654321, "Avi", 15);
        User user3; user3.init(135792486, "Tom", 12);
        User user4; user4.init(123456789, "Nitzan", 12);
        User user5; user5.init(111222333, "Shlomo", 14);
        User user6; user6.init(222444666, "Rinat", 16);

        // --- Add devices to users ---
        user1.addDevice(device1); user1.addDevice(device2);
        user2.addDevice(device3); user2.addDevice(device4);
        user3.addDevice(device5); user3.addDevice(device6);
        user4.addDevice(device7); user4.addDevice(device8);
        user5.addDevice(device9); user5.addDevice(device10);
        user6.addDevice(device11); user6.addDevice(device12);

        // --- Profiles ---
        Profile profile1; profile1.init(user1);
        Profile profile2; profile2.init(user2);
        Profile profile3; profile3.init(user3);
        Profile profile4; profile4.init(user4);
        Profile profile5; profile5.init(user5);
        Profile profile6; profile6.init(user6);

        // --- Add friends ---
        Profile* profiles[] = { &profile1, &profile2, &profile3, &profile4, &profile5, &profile6 };
        allFriends(profiles, 6);

        // --- Set status and posts ---
        profile1.setStatus(statusMessages[1]);
        profile1.addPostToProfilePage(posts[0]);
        profile1.addPostToProfilePage(posts[1]);
        profile1.addPostToProfilePage(posts[2]);

        // --- Check output ---
        cout << getProfileString(profile1) << endl;
        cout << "Friends of Gal: " << profile1.getFriends() << endl;
        cout << "Friends same name length: " << profile1.getFriendsWithSameNameLength() << endl;

        // --- Clear objects ---
        user1.clear(); user2.clear(); user3.clear();
        user4.clear(); user5.clear(); user6.clear();
        profile1.clear(); profile2.clear(); profile3.clear();
        profile4.clear(); profile5.clear(); profile6.clear();
    }
    catch (...) {
        set_console_color(RED);
        cout << "FAILED: The program crashed, check your lists and initialization\n";
        set_console_color(WHITE);
        return false;
    }

    set_console_color(LIGHT_GREEN);
    cout << "\n########## Profile - TEST Passed!!! ##########\n\n";
    set_console_color(WHITE);
    return true;
}

// --- Main ---
int main() {
    set_console_color(LIGHT_YELLOW);
    cout << "###########################\nExercise 2 - Social Network\nPart 3 - Profile\n###########################\n" << endl;
    set_console_color(WHITE);

    bool testResult = test3Profile();

    if (testResult) {
        set_console_color(GREEN);
        cout << "\n########## Ex2 Part3 Tests Passed!!! ##########\n\n";
        set_console_color(WHITE);
    }
    else {
        set_console_color(RED);
        cout << "\n########## TEST Failed :( ##########\n";
        set_console_color(WHITE);
    }

    return 0;
}
