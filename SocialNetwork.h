#pragma once
#include <string>
#include "Profile.h"
#include "ProfileList.h"

class SocialNetwork {
private:
    std::string networkName;
    int minAge;
    ProfileList profiles;

public:
    // אתחול הרשת החברתית
    void init(const std::string& name, int minimumAge);

    // ניקוי הזיכרון והאובייקט
    void clear();

    // גישה לשם הרשת
    std::string getNetworkName() const;

    // גישה לגיל מינימלי להרשמה
    int getMinAge() const;

    // הוספת פרופיל לרשת – מחזירה false אם הגיל קטן מהמינימום
    bool addProfile(const Profile& profile_to_add);
};
