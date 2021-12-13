#include "Test.hpp"

void TestDate::SetUp() {
    std::ifstream file("pb.txt"); // ���� � ����� PhoneBook.txt
    phone_book = new PhoneBook(file);
}

void TestDate::TearDown() {
    delete phone_book;
}


/** DZ2
 * �������� unit-����� � ������ ��������� ������� �� ������� �����.
 */
int TestDate::Test() {
    setlocale(LC_ALL, "rus");
    {
        testing::Test::test_compare_data();
        testing::Test::test_sort_with_empty_data();
        testing::Test::test_sort_data_with_one_ellement();
        testing::Test::test_sort_data_with_many_ellements();
    }

    return EXIT_SUCCESS;
}
