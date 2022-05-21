//
// Created by adela on 4/6/2022.
//

#ifndef PISICI_HUMAN_H
#define PISICI_HUMAN_H

#include <string>
#include <utility>
#include <iostream>

template <class T> class human;
template<class T> std::istream &operator>> (std::istream &is, human<T> &Human);
template<class T> std::ostream &operator<< (std::ostream &os, const human<T> &Human);



template <class T>
class human {
    std::string name;
    int age;
    bool gender;
    T role;

public:
    //constructori
    human<T> (T role_, std::string name, int age, bool gender) : role(role_), name(std::move(name)), age(age), gender(gender) {};
    human<T> (const human<T> &Person) : name(Person.name), age(Person.age), gender(Person.gender), role(Person.role) {};
    human<T> () : age(0), gender(false) {};


    //operatori
    human<T> &operator= (const human<T> &Person) {
        this->name = Person.name;
        this->age = Person.age;
        this->gender = Person.gender;
        this->role = Person.role;
        return *this;
    }
    friend std::istream &operator>> <> (std::istream &is, human<T> &Human);
    friend std::ostream &operator<< <> (std::ostream &os, const human<T> &Human);



    //getteri
    std::string getName() const {
        return this->name;
    }

    int getAge() const {
        return this->age;
    }

    bool getGender() const {
        return this->gender;
    }

    T* getRole() {
        return *role;
    }



    //setteri
    void setName(const std::string& new_name) {
        this->name = new_name;
    }

    void setAge(int new_age) {
        this->age = new_age;
    }

    void setGender(bool new_gender) {
        this->gender = new_gender;
    }



    //altele
    void print(std::ostream &os) const {
        os << "Hello! My name is " << this->getName() << " and I am a " << this->getAge()<< " years old ";
        os << (this->getGender() ? "man. " : "woman. ");
        role.print(os);
    }


    ~human<T>() = default;
};

template<class T>
std::istream &operator>> (std::istream &is, human<T> &Human) {
    is >> Human.name >> Human.age >> Human.gender;
    is >> Human.role;
    return is;
}

template<class T>
std::ostream &operator<< (std::ostream &os, const human<T> &Human) {
    Human.print(os);
    return os;
}


#endif //PISICI_HUMAN_H
