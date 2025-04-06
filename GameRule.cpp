#include "GameRule.h"

int GameRule::getTypeGame()
{
    return typeGame;
}

int GameRule::getTrackLength()
{
    return trackLength;
}

void GameRule::createTransport()
{
    if (typeGame == 0 || typeGame == 1)
    {
        //transports.push_back(new Lend("fdffdf", 10, 5));
        transports.push_back(new Lend("Верблюд", 10, 30, {5, 8}));
        transports.push_back(new Lend("Верблюд-быстроход", 40, 10, {5, 6.5, 8}));
        transports.push_back(new Lend("Кентавр", 15, 8, {2}));
        transports.push_back(new Lend("Ботинки-вездеходы", 6, 60, {10, 5}));
    }
    if (typeGame == 0 || typeGame == 2)
    {
        transports.push_back(new Air("Ковёр-самолёт", 10, false, {{1000, 0}, {5000, 3}, {10000, 10}, {10000, 5}}));
        transports.push_back(new Air("Орёл", 8, false, {{0, 6}}));
        transports.push_back(new Air("Метла", 20, true, {{1000, 1}}));
    }
}

std::vector<Transport*> GameRule::getTransports()
{
    return transports;
}

void GameRule::setActivation(int index)
{
    transports[index]->setActivation();
}

void GameRule::startGame()
{
    for (auto* transport : transports)
    {
        if (transport->getActivation())
        {
            resultMap.insert({transport->getResult(trackLength), transport->getName()});
        }
    }
}

std::multimap<double, std::string>& GameRule::getResultMap()
{
    return resultMap;
}