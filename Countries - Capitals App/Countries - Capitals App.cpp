#include <iostream>
#include <string>
#include "Game.h"
#include <Windows.h>
#include <conio.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Game game;
    bool byCapital;
    int choice;
    bool valid = false;
    do {
        std::cout << "Выберите что будете угадывать:\n1 Столицы\n2 Страны\n";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
        }
        else if (choice != 1 && choice != 2) {
            std::cout << "Введите 1 или 2.\n";
            std::cin.ignore(10000, '\n');
        }
        else {
            valid = true;
            std::cin.ignore(10000, '\n');
        }
    } while (!valid);
    byCapital = (choice == 1);

    if (game.loadFromFile("EuropeCapitals.txt", "EuropeCountries.txt")) {
        std::cout << "Файлы не были успешно загружены";
        _getch();
        return 1;
    }

    game.shufflePairs();

    std::string answer;
    for (size_t i = 0; i < game.getPairs().size(); ++i) {
        auto pair = game.getNextPair();
        if (pair.country.empty()) break;

        if (byCapital) {
            std::cout << "Страна: " << pair.country << "\n";
        }
        else {
            std::cout << "Столица: " << pair.capital << "\n";
        }

        std::getline(std::cin, answer);
        bool correct = game.checkAnswer(pair, answer, byCapital);
        if (correct) {
            std::cout << "Верно!\n";
        }
        else {
            std::cout << "Неверно! Правильный ответ: " << pair.country << " - " << pair.capital << "\n";
        }
    }

    std::cout << "Игра закончена. Ваш счёт: " << game.getScore() << "/" << game.getPairs().size() << "\n";
    return 0;
}