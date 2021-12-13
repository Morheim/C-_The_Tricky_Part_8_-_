#include <iostream>
#include <string>
#include <optional>
#include <utility>

#include "PhoneBook.h"
#include "Test.hpp"

void DZ1()
{
	std::cout << "//===================================================[DZ1]===================================================//\n\n";
}

void DZ2()
{
	std::cout << "\n//===================================================[DZ2]===================================================//\n\n";
}

void END()
{
	std::cout << "\n//===================================================[END]===================================================//\n\n";
}

int main()
{
	{
		DZ1();

		std::ifstream file("pb.txt"); // путь к файлу PhoneBook.txt
		PhoneBook phone_book(file);
		std::cout << phone_book;

		std::cout << "------SortByPhone-------" << std::endl;
		phone_book.SortByPhone();
		std::cout << phone_book;

		std::cout << "------SortByName--------" << std::endl;
		phone_book.SortByName();
		std::cout << phone_book;

		std::cout << "-----GetPhoneNumber-----" << std::endl;

		auto print_phone_number = [&phone_book](const std::string& surname) {
			std::cout << surname << "\t";
			auto answer = phone_book.GetPhoneNumber(surname);
			if (get<0>(answer).empty())
				std::cout << get<1>(answer);
			else
				std::cout << get<0>(answer);
			std::cout << std::endl;
		};

		print_phone_number("Ivanov");
		print_phone_number("Petrov");
		print_phone_number("Wolf");

		std::cout << "----ChangePhoneNumber----" << std::endl;
		phone_book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", std::nullopt });
		phone_book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
		phone_book.ChangePhoneNumber(Person{ "Wolf", "Aard", std::nullopt }, PhoneNumber{ 16, 465, "9155448", 13 });
		std::cout << phone_book;
	}

	{
		DZ2();
		TestDate test;
		test.Test();
	}
	END();
	return 0;
}
