#include <iostream>
#include <string>

#include "vector.h"

class SIGN {
private:
    std::string lastName;
    std::string firstName;
    std::string zodiacSign;
    int birthDate[3];

public:
    // Конструктор класса
    SIGN(const std::string& last, const std::string& first, const std::string& sign, int day, int month, int year) {
        lastName = last;
        firstName = first;
        zodiacSign = sign;
        birthDate[0] = day;
        birthDate[1] = month;
        birthDate[2] = year;
    }

    SIGN() {}

    // Методы доступа
    std::string getLastName() const {
        return lastName;
    }

    void setLastName(const std::string& last) {
        lastName = last;
    }

    std::string getFirstName() const {
        return firstName;
    }

    void setFirstName(const std::string& first) {
        firstName = first;
    }

    std::string getZodiacSign() const {
        return zodiacSign;
    }

    void setZodiacSign(const std::string& sign) {
        zodiacSign = sign;
    }

    int getDayOfBirth() const {
        return birthDate[0];
    }

    int getMonthOfBirth() const {
        return birthDate[1];
    }

    int getYearOfBirth() const {
        return birthDate[2];
    }

    // Перегруженные операторы
    friend std::ostream& operator<<(std::ostream& os, const SIGN& sign) {
        os << "Name: " << sign.firstName << " " << sign.lastName << std::endl;
        os << "Zodiac Sign: " << sign.zodiacSign << std::endl;
        os << "Birth Date: " << sign.birthDate[0] << "/" << sign.birthDate[1] << "/" << sign.birthDate[2] << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, SIGN& sign) {
        std::cout << "Enter last name: ";
        is >> sign.lastName;
        std::cout << "Enter first name: ";
        is >> sign.firstName;
        std::cout << "Enter zodiac sign: ";
        is >> sign.zodiacSign;
        std::cout << "Enter birth date (day month year): ";
        is >> sign.birthDate[0] >> sign.birthDate[1] >> sign.birthDate[2];
        return is;
    }

    // Метод для сравнения по знаку зодиака
    bool operator<(const SIGN& other) const {
        return zodiacSign < other.zodiacSign;
    }

    // Метод для сортировки по знаку зодиака (пузырьковая сортировка)
    static void sortByZodiacSign(MyVector<SIGN>& signs) {
        int n = signs.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (!(signs[j] < signs[j + 1])) {
                    // Обмен местами
                    SIGN temp = signs[j];
                    signs[j] = signs[j + 1];
                    signs[j + 1] = temp;
                }
            }
        }
    }

};