//
// Created by adela on 4/11/2022.
//

#ifndef PISICI_TEAM_H
#define PISICI_TEAM_H

#include <iostream>
#include <vector>
#include "human.h"
#include "member.h"
#include "leader.h"
#include <memory>

//singleton

class team {
private:
    static int ppl;                                                             // number of people in the team
    std::vector<human<member>> members;
    std::vector<human<leader>> leaders;

    static std::shared_ptr<team>instance;
    team();

public:
    static std::shared_ptr<team> getInstance();

    void addPerson(const human<leader>& person);
    void addPerson(const human<member>& person);

    void meetTeam();

    int getNumber();
    std::vector<human<member>> getMembers();
    std::vector<human<leader>> getLeaders();

    ~team();
};

#endif //PISICI_TEAM_H
