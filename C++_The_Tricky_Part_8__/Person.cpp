#include "Person.h"

[[nodiscard]] const std::string& Person::GetLastName() const {
    return last_name;
}

bool Person::operator<(const Person& person2) const {
    return (std::tie(last_name, name, patronymic) < std::tie(person2.last_name, person2.name, person2.patronymic));
}

bool Person::operator==(const Person& person2) const {
    return (std::tie(last_name, name, patronymic) == std::tie(person2.last_name, person2.name, person2.patronymic));
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << person.last_name << " " << person.name;
    if (person.patronymic.has_value())
        out << " " << person.patronymic.value();
    return out;
}
