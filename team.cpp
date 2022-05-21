//
// Created by adela on 4/11/2022.
//

#include "team.h"
#include "human.h"


std::shared_ptr<team> team::instance = nullptr;
int team::ppl = 0;

void team::addPerson(const human<member>& person) {
    team::members.push_back(person);
    team::ppl++;
}

void team::addPerson(const human<leader>& person) {
    team::leaders.push_back(person);
    team::ppl++;
}

//void team::meetMembers() {
//    for (const auto& member : team::getPeople())
//        if (member->getRole() == role::member) member->print(std::cout), std::cout << '\n';
//}

//void team::meetLeaders() {
//    for (const auto& leader : team::people)
//        if (leader->getRole() == role::leader) leader->print(std::cout), std::cout << '\n';
//}

int team::getNumber() {
    return team::ppl;
}

std::vector<human<member>> team::getMembers() {
    return team::members;
}

std::vector<human<leader>> team::getLeaders() {
    return team::leaders;
}

void team::meetTeam() {
    std::cout << "There are " << team::getNumber() << " people in our team. They will introduce themselves below: " << '\n';
    for (const auto& member : team::getMembers())
        member.print(std::cout), std::cout << '\n';
    for (const auto& member : team::getLeaders())
        member.print(std::cout), std::cout << '\n';
}

team::team() = default;

std::shared_ptr<team> team::getInstance() {
    if (instance == nullptr) instance.reset(new team);
    return instance;
}

team::~team() = default;

//void team::deletePerson(const std::shared_ptr<human> &person) {
//    people.erase(person, person+1);
//
//}
