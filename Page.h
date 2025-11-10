#pragma once
#include <string>
#include <vector>

class Page {
private:
    std::string status;
    std::vector<std::string> posts;

public:
    void init();
    void setStatus(const std::string& s);
    std::string getStatus() const;
    void addLineToPosts(const std::string& post);
    std::vector<std::string> getPosts() const;
    void clear();
};
