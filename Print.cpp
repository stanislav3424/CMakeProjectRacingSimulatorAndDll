#include "Print.h"

void printMain()
{
    std::vector<std::string> typeGameVector;
    setTypeGameVector(typeGameVector);
    std::cout << "����� ���������� � �������� ���������.";
    int typeGame{};
    int trackLength{};
    printTypeGame(typeGameVector);
    typeGame = printSelect(3) - 1;
    std::cout << "����� ������: ";
    inputInt(trackLength, false, 0, 0);
    trackLength = abs(trackLength);
    GameRule gamerule(typeGame, trackLength);

    while (!printTable(gamerule))
    {
    }
}

bool printRestart()
{
    return false;
}

int printSelect(int range)
{
    std::cout << std::endl << "�������� ��������: ";
    int input{};
    inputInt(input, true, 1, range);
    return input;
}

bool printTable(GameRule& gamerule)
{
    system("cls");

    int index{};
    for (const auto& transport : gamerule.getTransports())
    {
        int padding{};
        ++index;
        std::cout << std::endl << index << ". " << transport->getName();
        std::cout << std::setw(padding) <<
    }
    return true;
}

void printTypeGame(std::vector<std::string>& typeGameVector)
{
    int index{};
    for (auto typeGame : typeGameVector)
    {
        ++index;
        std::cout << std::endl << index << ". " << typeGame;
    }
}

void setTypeGameVector(std::vector<std::string>& typeGameVector)
{
    typeGameVector.push_back("����� ��� ����");
    typeGameVector.push_back("����� ��� ��������� ����������");
    typeGameVector.push_back("����� ��� ���������� ����������");
}