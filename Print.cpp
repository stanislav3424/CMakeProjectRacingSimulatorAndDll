#include "Print.h"

void printMain()
{
    system("cls");
    std::vector<std::string> typeGameStrVector;
    setTypeGameStrVector(typeGameStrVector);
    std::cout << "Добро пожаловать в гоночный симулятор.";
    int typeGameInt{};
    int trackLength{};
    printStrVector(typeGameStrVector);
    typeGameInt = printSelect(1, typeGameStrVector.size()) - 1;
    std::cout << "Длина трассы: ";
    inputInt(trackLength, false, 0, 0);
    trackLength = abs(trackLength);
    GameRule gameRule(typeGameInt, trackLength);
    while (!printTableTransports(gameRule, typeGameStrVector))
    {
    }
    gameRule.startGame();
    printTableResult(gameRule);
}

bool printRestart()
{
    std::cout << std::endl;
    std::vector<std::string> restartStrVector;
    setRestartStrVector(restartStrVector);
    printStrVector(restartStrVector);
    if (printSelect(1, restartStrVector.size()) == 1)
    {
        return true;
    }
    return false;
}

int printSelect(int rangeMin, int rangeMax)
{
    std::cout << std::endl << "Выберете действие: ";
    int input{};
    inputInt(input, true, rangeMin, rangeMax);
    return input;
}

bool printTableTransports(GameRule& gameRule, std::vector<std::string>& typeGameStrVector)
{
    system("cls");
    int index{};
    int activationCounter{};
    std::cout << typeGameStrVector[gameRule.getTypeGame()];
    std::cout << std::endl << "Длина трассы: " << gameRule.getTrackLength();
    for (const auto& transport : gameRule.getTransports())
    {
        activationCounter += transport->getActivation();
        int padding{};
        padding = 40 - (transport->getName()).length();
        ++index;
        std::cout << std::endl << index << ". " << transport->getName();
        std::cout << std::setw(padding) << (transport->getActivation() ? "участвует" : "не участвует");
    }
    int select{};
    if (activationCounter < 1)
    {
        std::cout << std::endl << "Выберете еще двух участников.";
        select = printSelect(1, gameRule.getTransports().size());
    }
    else if (activationCounter < 2)
    {
        std::cout << std::endl << "Выберете еще одного участника.";
        select = printSelect(1, gameRule.getTransports().size());
    }
    else
    {
        std::cout << std::endl << "Введите 0 для старты игры.";
        select = printSelect(0, gameRule.getTransports().size());
    }
    if (select == 0)
    {
        return true;
    }
    gameRule.setActivation(select - 1);
    return false;
}

void printTableResult(GameRule& gameRule)
{
    system("cls");
    std::cout << "Результат гонки: ";
    int index{};
    for (const auto& resultTransport : gameRule.getResultMap())
    {
        int padding{};
        padding = 40 - (resultTransport.second).length();
        ++index;
        std::cout << std::endl << index << ". " << resultTransport.second;
        std::cout << std::setw(padding) << resultTransport.first;
    }
}

void printStrVector(std::vector<std::string>& strVector)
{
    int index{};
    for (auto typeGameStr : strVector)
    {
        ++index;
        std::cout << std::endl << index << ". " << typeGameStr;
    }
}

void setTypeGameStrVector(std::vector<std::string>& typeGameVector)
{
    typeGameVector.push_back("Гонка для всех");
    typeGameVector.push_back("Гонка для назменого транспотра");
    typeGameVector.push_back("Гонка для воздушного транспорта");
}

void setRestartStrVector(std::vector<std::string>& typeGameVector)
{
    typeGameVector.push_back("Рестарт");
    typeGameVector.push_back("Выйти");
}