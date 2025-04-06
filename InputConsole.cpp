#include "InputConsole.h"

void inputInt(int& input, bool clamp, int min, int max)
{
    while (true)
    {
        if (std::cin >> input)
        {
            if (clamp)
            {
                if ((input >= min) && (input <= max))
                {
                    break;
                }
                else
                {
                    inputError("������! ������� ���������� ��������: ");
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            inputError("������! ������� �����: ");
        }
    }
}

void inputError(const std::string error)
{
    std::cout << error;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}