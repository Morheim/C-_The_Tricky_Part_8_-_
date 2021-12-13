#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "PhoneBook.h"
#pragma once

using namespace std;

/*      DZ1
    Написать фреймворт для тестирования (можно взять из урока)
*/

namespace testing {

    class Test {
    public:
        static void assert_true(bool expression, const string& test_name) {
            if (expression)
                cout << "[" << test_name << "] - " << "Test passed" << endl;
            else
                cerr << "[" << test_name << "] - " << "Test failed" << endl;
        }

        static void assert_false(bool expression, const string& test_name) {
            if (!expression)
                cout << "[" << test_name << "] - " << "Test passed" << endl;
            else
                cerr << "[" << test_name << "] - " << "Test failed" << endl;
        }

        template<typename T>
        static void assert_equals(const T& lhs, const T& rhs, const string& test_name) {
            if (lhs == rhs)
                cout << "[" << test_name << "] - " << "Test passed" << endl;
            else
                cerr << "[" << test_name << "] - " << "Test failed" << endl;
        }

        static vector<int> sort(const vector<int>& data) {
            if (data.empty()) {
                throw invalid_argument("data is empty");
            }
            vector<int> result{ data };
            for (size_t i = 0u; i < result.size(); ++i)
                for (size_t j = i; j > 0 && result[j] < result[j - 1]; --j)
                    swap(result[j], result[j - 1]);
            return result;
        }

#define EXIT_SUCCESS 0

#define EXPECT_EXEPTION(code, exception)                       \
try{                                                           \
code                                                           \
   cerr << "[" << __func__ << "] - " << "Test failed" << endl; \
}catch (const exception&) {                                    \
cout << "[" << __func__  + string(":") + to_string(__LINE__)<< "] - " << "Test passed" << endl;    \
}

#define ASSERT_TRUE(expression) \
assert_true((expression), __func__ + string(":") + to_string(__LINE__))

#define ASSERT_FALSE(expression) \
assert_false((expression), __func__)

#define ASSERT_EQUALS(lhs, rhs) \
assert_equals((lhs), (rhs), __func__ + string(":") + to_string(__LINE__))

        void test_sort_with_empty_data() {
            EXPECT_EXEPTION({
                                Test::sort({});
                }, invalid_argument);
        }

        void test_sort_data_with_one_ellement() {
            Test::ASSERT_EQUALS(vector<int>{1}, Test::sort({ 1 }));
        }

        void test_sort_data_with_many_ellements() {
            vector<int> lhs = { 1, 2, 3, 5, 6, 6 };
            vector<int> rhs = Test::sort({ 1, 6, 3, 6, 2, 5 });
            Test::ASSERT_EQUALS(lhs, rhs);
        }

        void test_compare_data() {
            double value = 5.7 * 2;
            double double_value = value * 2;
            Test::ASSERT_TRUE((double_value / 2 - value) < numeric_limits<double>::epsilon());
        }

    };
}

class TestDate : public testing::Test {
protected:
    void SetUp();
    void TearDown();
    PhoneBook* phone_book{};
public:
    TestDate() {
        SetUp();
    }
    ~TestDate() {
        TearDown();
    }
    int Test();
};