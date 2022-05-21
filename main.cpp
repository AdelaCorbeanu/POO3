#include <iostream>
#include "human.h"
#include "member.h"
#include "leader.h"
#include "team.h"


template<typename T> int what_year (T *role) {
    return 0;
}

template <>
int what_year <leader> (leader *role) {
    return role->getYearPromoted();
}

template <>
int what_year <member> (member *role) {
    return role->getYearJoined();
}


int main() {
    //INPUT: Ancuta 20 1 2022 7 1 2 3 4 7 8 9 Lefter 19 1 2021 RedBlackTrees

    std::vector<int> projects = {6, 9, 4, 2, 0};
    member m1(2019, 5, projects);
    human<member> Member1(m1, "Andrei", 13, false);

    leader l1(2021, "grind");
    human<leader> Leader1(l1, "Matei", 15, true);


    human<member> Member2;
    std::cin >> Member2;

    human<leader> Leader2;
    std::cin >> Leader2;


    projects = {4, 2, 0};

    human<member> Member3;
    Member3.setName("Tiberiu");
    Member3.setGender(true);
    Member3.setAge(20);
    Member3.getRole()->setYear(2022);
    Member3.getRole()->setNr(4);
    Member3.getRole()->setProjects(projects);


    human<leader> Leader3;
    Leader3.setName("Rosianu");
    Leader3.setGender(true);
    Leader3.setAge(20);
    Leader3.getRole()->setYear(2021);
    Leader3.getRole()->setTask("sapa de lemn");


    std::shared_ptr<team> Team = Team->getInstance();
    Team->addPerson(Member1);
    Team->addPerson(Leader1);
    Team->addPerson(Member2);
    Team->addPerson(Leader2);
    Team->addPerson(Member3);
    Team->addPerson(Leader3);


    Team->meetTeam();
    std::cout << '\n' << '\n';


    std::cout << "Anul in care s-a alaturat cel mai vechi membru este ";
    std::cout << std::min(std::min(what_year(Member1.getRole()), what_year(Member2.getRole())), what_year(Member3.getRole()));
    std::cout << ". \n";

    std::cout << "Anul in care a fost promovat cel mai vechi lider este ";
    std::cout << std::min(std::min(what_year(Leader1.getRole()), what_year(Leader2.getRole())), what_year(Leader3.getRole()));
    std::cout << ". \n";

    std::cout << '\n' << '\n';

    memento* mem1 = Leader3.getRole()->create_memento();
    Leader3.getRole()->setTask("smecherie");
    std::cout << Leader3 << '\n';

    Leader3.getRole()->reinstate_memento(mem1);
    std::cout << Leader3 << '\n';
    return 0;
}
