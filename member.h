//
// Created by adela on 4/10/2022.
//

#ifndef PISICI_MEMBER_H
#define PISICI_MEMBER_H

#include <iostream>
#include <vector>
#include "human.h"


class member  {
private:
    int year_joined;                                                                           // the year when he joined the team
    int projects_nr;
    std::vector<int> projects_done;                                                            // the codes of his projects

public:
    member(int year, int projects_nr, std::vector<int> projects);       // constructor
    member(const member &new_member);                                                          // constructorul de copiere
    member();

    void print(std::ostream &os) const;
    void read(std::istream &is);
    friend std::istream &operator>> (std::istream &is, member &Member);
    friend std::ostream &operator<< (std::ostream &os, const member &Member);
    member &operator=(const member &member2);

    int getYearJoined() const;
    std::vector<int> getProjects() const;
    int getNr() const;

    void setYear(int year);
    void setNr(int nr);
    void setProjects(std::vector<int> projects);
    void addProject(int project);

    member* operator*() {
        return this;
    }

    ~member();
};



std::ostream &operator<< (std::ostream &os, const member &Member);                              // operatorul de afisare
std::istream &operator>> (std::istream &is, member &Member);

#endif //PISICI_MEMBER_H
