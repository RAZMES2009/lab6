#include <iostream>
#include <cmath>
#include <string>

using namespace std;

inline bool approximatelyEqual(float a, float b, float epsilon)
{
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon)
{
    float diff = fabs(a - b);
    if (diff <= absEpsilon)
        return true;
    return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

bool isFloat(const char *c)
{
    bool flg = false, flgE = false, flgSign = false;
    for (size_t i = 0; i < string(c).size(); i++)
    {
        if (c[i] == '.')
        {
            if (flg || i == 0)
            {
                cout << "������ �������� ������������ �����";
                exit(1);
            }
            flg = true;
            continue;
        }
        if (!isdigit(c[i]) && c[i] != 'e' && c[i] != '-' && c[i] != '+')
        {
            cout << "������ �������� ������������ �����";
            exit(1);
        }
        if (c[i] == 'e' && !flgE)
            flgE = true;
        else if (c[i] == 'e' && flgE)
        {
            cout << "������ �������� ������������ �����";
            exit(1);
        }
        if ((c[i] == '-' || c[i] == '+') && !flgSign)
            flgSign = true;
        else if ((c[i] == '-' || c[i] == '+') && flgSign)
        {
            cout << "������ �������� ������������ �����";
            exit(1);
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    system("chcp 1251"); // windows encode 1251

    string nameFunc = string(argv[1]);

    if (nameFunc != "approximatelyEqualAbsRel" &&
        nameFunc != "approximatelyEqual")
    {
        cout << "�������� �������� ��� ������� ��� ������� ���������";
        return 1;
    }

    if (nameFunc == "approximatelyEqualAbsRel" && argc != 6 ||
        nameFunc == "approximatelyEqual" && argc != 5)
    {
        cout << "�������� �������� ���������� ���������� ��� ������� ���������";
        return 1;
    }

    if (isFloat(argv[2]) && isFloat(argv[3]) && isFloat(argv[4]) && stof(argv[4]) < 1)
    {
        float a;
        float b;
        try
        {
            a = stof(argv[2]);
            b = stof(argv[3]);
        }
        catch (invalid_argument)
        {
            cout << "�������� �������� �������� ���������(��) ��� ������� ���������";
            return 1;
        }

        string res{""};

        if (nameFunc == "approximatelyEqual")
            approximatelyEqual(a, b, stof(argv[4])) ? res = "\0" : res = " ��";
        else if (nameFunc == "approximatelyEqualAbsRel" && isFloat(argv[5]) && stof(argv[5]) < 1)
            approximatelyEqualAbsRel(a, b, stof(argv[4]), stof(argv[5])) ? res = "\0" : res = " ��";

        cout << "����� " << a << " � " << b << res << " ����� ����� �����" << endl;
    }
    else
    {
        cout << "������ �������� ������������ �����";
        return 1;
    }

    return 0;
}
