#include "SocialNetwork.h"

void SocialNetwork::init(const std::string& name, int minimumAge) {
    networkName = name;
    minAge = minimumAge;
    profiles.clear();
}

void SocialNetwork::clear() {
    profiles.clear();
    networkName = "";
    minAge = 0;
}

std::string SocialNetwork::getNetworkName() const {
    return networkName;
}

int SocialNetwork::getMinAge() const {
    return minAge;
}

bool SocialNetwork::addProfile(const Profile& profile_to_add) {
    if (profile_to_add.getOwner().getAge() < minAge) {
        return false; // המשתמש צעיר מדי – לא מוסיפים
    }
    profiles.add(profile_to_add);
    return true;
}
