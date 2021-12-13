#include "PhoneNumber.h"

[[nodiscard]] int PhoneNumber::getCountryCode() const {
    return country_code;
}

[[nodiscard]] int PhoneNumber::GetCityCode() const {
    return city_code;
}

[[nodiscard]] std::string PhoneNumber::GetNumber() const {
    return (add_number.has_value() ? std::to_string(add_number.value()) : "");
}

[[nodiscard]] std::optional<int> PhoneNumber::GetAddNumber() const {
    if (add_number.has_value())
        return add_number.value();
    else
        return std::nullopt;
}

std::ostream& operator<<(std::ostream& out, const PhoneNumber& phone_number) {
    out << '+' << phone_number.getCountryCode() << " (" << phone_number.GetCityCode() << ") " << phone_number.GetNumber();
    return out;
}

bool operator<(const PhoneNumber& num1, const PhoneNumber& num2) {
    return std::tie(num1.country_code, num1.city_code, num1.number, num1.add_number) <
        std::tie(num2.country_code, num2.city_code, num2.number, num2.add_number);
}
