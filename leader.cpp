//
// Created by adela on 4/10/2022.
//


#include <iostream>
#include <utility>
#include "leader.h"

leader::leader(int year, std::string task_) :
        year_promoted(year), task(std::move(task_)) {}

leader::leader(const leader &new_leader) : year_promoted(new_leader.year_promoted), task(new_leader.task) {}

void leader::print(std::ostream &os) const {
    os << "I am a leader of the team since " << this->getYearPromoted();
    os << ". My job is to make sure everything involving " << this->getTask() << " goes well";
}

std::ostream &operator<<(std::ostream &os, const leader &Leader) {
    Leader.print(os);
    return os;
}

leader &leader::operator=(const leader &leader2) {
    this->year_promoted = leader2.year_promoted;
    this->task = leader2.task;
    return *this;
}

int leader::getYearPromoted() const {
    return this->year_promoted;
}

std::string leader::getTask() const {
    return this->task;
}

void leader::setYear(int new_year) {
    this->year_promoted = new_year;
}

void leader::setTask(std::string new_task) {
    this->task = std::move(new_task);
}

leader::leader() {
    year_promoted = 0;
    task = "";
}

void leader::read(std::istream &is) {
    is >> this->year_promoted;
    is >> this->task;
}

std::istream &operator>>(std::istream &is, leader &Leader) {
    Leader.read(is);
    return is;
}

leader::~leader() = default;

