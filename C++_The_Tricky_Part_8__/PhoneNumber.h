#ifndef LESSON1_PHONENUMBER_H
#define LESSON1_PHONENUMBER_H

#include <regex>
#include <iostream>
#include <string>
#include <optional>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>

class PhoneNumber {
protected:
    int country_code;
    int city_code;
    std::string number;
    std::optional<int> add_number;
public:
    PhoneNumber() : country_code(0), city_code(0), add_number(std::nullopt) {}
    PhoneNumber(int country, int city, std::string num, std::optional<int> add_num)
        : country_code{ country }, city_code{ city }, number{ std::move(num) }, add_number{ add_num } {}
    [[nodiscard]] int getCountryCode() const;
    [[nodiscard]] int GetCityCode() const;
    [[nodiscard]] std::string GetNumber() const;
    [[nodiscard]] std::optional<int> GetAddNumber() const;
    friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& phone_number);
    friend bool operator<(const PhoneNumber& num1, const PhoneNumber& num2);
};


#endif
