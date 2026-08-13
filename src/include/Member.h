#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;

class Member {
private:
    int memberId;
    string name;

public:
    Member(int id, string memberName)
        : memberId(id), name(memberName) {}

    int getMemberId() const {
        return memberId;
    }

    string getName() const {
        return name;
    }
};

#endif
