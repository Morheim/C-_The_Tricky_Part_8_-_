#ifndef LESSON1_PHONEBOOK_H
#define LESSON1_PHONEBOOK_H

#include <regex>
#include <iostream>
#include <string>
#include <optional>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook {
protected:
	std::vector<std::pair<Person, PhoneNumber>> phones;
public:
	PhoneBook(std::ifstream& is);
	void SortByName();
	void SortByPhone();
	void ChangePhoneNumber(const Person& person, PhoneNumber new_phone);
	std::pair<std::string, PhoneNumber> GetPhoneNumber(const std::string& surname);
	[[nodiscard]] std::vector<std::pair<Person, PhoneNumber>>& GetPhones();
	friend std::ostream& operator<< (std::ostream& out, PhoneBook& book);
};

#endif