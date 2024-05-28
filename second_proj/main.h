#pragma once

#include <iostream>
#include <stdint.h>

using namespace std;

uint64_t swapBytes(uint64_t num, uint8_t byteIndex1, uint8_t byteIndex2)
{
    if (byteIndex1 < 0 || byteIndex1 > 7 || byteIndex2 < 0 || byteIndex2 > 7)
    {
        cout << "¬ведите байты в диапозоне от 1 до 8";
        exit(1);
    }
    uint8_t byte1 = (num >> (byteIndex1 * 8)) & 0xFF;
    uint8_t byte2 = (num >> (byteIndex2 * 8)) & 0xFF;
    num &= ~(0xFFULL << (byteIndex1 * 8));
    num &= ~(0xFFULL << (byteIndex2 * 8));
    num |= (uint64_t)byte1 << (byteIndex2 * 8);
    num |= (uint64_t)byte2 << (byteIndex1 * 8);
    return num;
}

uint64_t swap(uint64_t b, uint8_t i, uint8_t j)
{
    if (i < 0 || i > 7 || j < 0 || j > 7)
    {
        cout << "¬ведите биты в диапозоне от 1 до 64";
        exit(1);
    }

    if (i > j)
    {
        uint64_t t = i;
        i = j;
        j = t;
    }
    uint64_t maski = 1u << i;
    uint64_t maskj = 1u << j;
    return ((b & maski) << (j - i)) | ((b & maskj) >> (j - i)) | (b & ~(maski | maskj));
}

void runApp(char *argv[])
{
    switch (atoi(argv[1]))
    {
    case 4:
    {
        uint64_t result = swapBytes(atoll(argv[2]), atoi(argv[3]) - 1, atoi(argv[4]) - 1);
        cout << "–езультат смены байтов номер " << atoi(argv[3]) << " и " << atoi(argv[4])
             << " €вл€етс€ число " << result;
        break;
    }
    case 5:
    {
        uint64_t result = swap(atoll(argv[2]), atoi(argv[3]) - 1, atoi(argv[4]) - 1);
        cout << "–езультат смены бита номер " << atoi(argv[3]) << " и " << atoi(argv[4])
             << " €вл€етс€ число " << result;
        break;
    }
    default:
    {
        cout << "¬ведите номер задани€ 4 или 5";
        exit(1);
    }
    }
}
