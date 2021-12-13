#ifndef LESSON1_PERSON_H
#define LESSON1_PERSON_H

#include <regex>
#include <iostream>
#include <string>
#include <optional>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>

struct Person {
    std::string last_name;
    std::string name;
    std::optional<std::string> patronymic;

    Person(std::string last_name, std::string name, std::optional<std::string> patronymic) :
        last_name(std::move(last_name)), name(std::move(name)), patronymic(std::move(patronymic)) {};
    [[nodiscard]] const std::string& GetLastName() const;
    bool operator<(const Person& person2) const;
    bool operator==(const Person& person2) const;
    friend std::ostream& operator<< (std::ostream& out, const Person& person);
};

#endif