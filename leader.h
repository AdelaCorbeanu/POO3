//
// Created by adela on 4/10/2022.
//

#ifndef PISICI_LEADER_H
#define PISICI_LEADER_H

#include <utility>

#include "human.h"

class leader;

class memento {
private:
    std::string _state;
    friend class leader;

public:
    explicit memento(std::string current_task) {
        _state = std::move(current_task);
    }
};


class leader {
private:
    int year_promoted;
    std::string task;

public:
    leader(int year, std::string task_);
    leader(leader const &new_leader);
    leader();

    void print(std::ostream &os) const;
    void read(std::istream &is);

    friend std::istream &operator>> (std::istream &is, leader &Leader);
    friend std::ostream &operator<< (std::ostream &os, const leader &Leader);
    leader &operator=(const leader &leader2);

    int getYearPromoted() const;
    std::string getTask() const;

    void setYear(int new_year);
    void setTask(std::string new_task);

    leader* operator*() {
        return this;
    }


    memento *create_memento() {
        return new memento(task);
    }
    void reinstate_memento(memento *mem) {
        task = mem->_state;
    }

    ~leader();
};



std::ostream &operator<< (std::ostream &os, const leader &Leader);
std::istream &operator>> (std::istream &is, leader &Leader);

#endif //PISICI_LEADER_H
