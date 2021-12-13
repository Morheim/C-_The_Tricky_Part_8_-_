#include "PhoneBook.h"

Person GetPerson(const std::smatch& matches) {
    std::string name = matches[1].str();
    std::string family = matches[2].str();
    std::optional <std::string> patronymic;
    if (matches[3].matched) {
        patronymic = matches[3].str();
    }
    else {
        patronymic = std::nullopt;
    }
    Person p(name, family, patronymic);
    return p;
}

PhoneNumber GetPhone(const std::smatch& matches) {
    std::string country_code = matches[4].str();
    std::string city_code = matches[5].str();
    std::optional<int> add_number;
    if (matches[6].matched) {
        add_number = std::stoi(matches[6].str());
    }
    else {
        add_number = std::nullopt;
    }
    PhoneNumber phone(std::stoi(country_code), std::stoi(city_code),
        std::string("+").append(country_code).append(" ").append(city_code).
        append((add_number.has_value() ? std::string(" ").
            append(std::to_string(add_number.value())) : "")), add_number);
    return phone;
}

PhoneBook::PhoneBook(std::ifstream& is) {
    for (std::string line; getline(is, line);) {
        const std::regex name_regex(
            "([[:alpha:]]+) ([[:alpha:]]+) ?([[:alpha:]]+)? \\+?([[:digit:]]+) ([[:digit:]]+) ?([[:digit:]]+)?");
        std::smatch matches;
        if (std::regex_match(line, matches, name_regex)) {
            Person p = GetPerson(matches);
            PhoneNumber phone = GetPhone(matches);
            phones.emplace_back(p, phone);
        }
    }
}

void PhoneBook::SortByName() {
    std::sort(phones.begin(), phones.end());
}

void PhoneBook::SortByPhone() {
    std::sort(phones.begin(),
        phones.end(),
        [](const std::pair<Person, PhoneNumber>& phone1,
            const std::pair<Person, PhoneNumber>& phone2) {
                return phone1.second < phone2.second;
        });
}

void PhoneBook::ChangePhoneNumber(const Person& person, PhoneNumber new_phone) {
    auto user = std::find_if(phones.begin(), phones.end(), [&person](std::pair<Person, PhoneNumber>& entry) {
        return entry.first == person;
        });

    if (user != phones.end())
        user->second = std::move(new_phone);
}

std::pair<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& surname) {
    size_t count = 0;
    const PhoneNumber* phone{};
    std::for_each(phones.begin(), phones.end(), [&phone, surname, &count](std::pair<Person, PhoneNumber>& entry) {
        if (entry.first.GetLastName() == surname) {
            count++;
            phone = &entry.second;
        }
        });
    if (count == 0)
        return { "None found!", {} };
    else if (count > 1)
        return { std::string("Found ").append(std::to_string(count)).append("phones"), *phone };
    return { "", *phone };
}

[[nodiscard]] std::vector<std::pair<Person, PhoneNumber>>& PhoneBook::GetPhones() {
    return phones;
}

std::ostream& operator<<(std::ostream& out, PhoneBook& book) {
    for (const auto& iter : book.GetPhones()) {
        out << iter.first << ' ' << iter.second << std::endl;
    }
    return out;
}
