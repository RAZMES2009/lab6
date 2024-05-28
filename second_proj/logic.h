#pragma once

#include <iostream>

void isUint(const char *c)
{
    for (size_t i = 0; i < std::string(c).size(); i++)
    {
        if (!isdigit(c[i]))
        {
            std::cout << "Все введеные числа должны быть полижтельными и целыми";
            exit(1);
        }
    }
}

void checkEnterArgs(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cout << "Введите 5 аргументов для запуска программы";
        exit(1);
    }

    for (size_t i = 1; i < 5; i++)
        isUint(argv[i]);
}