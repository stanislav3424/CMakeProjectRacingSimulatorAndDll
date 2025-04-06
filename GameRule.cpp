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
        transports.push_back(new Lend("fdffdf", 10));
        //transports.push_back(new Lend("???????", 10, 30, {5, 8}));
        //transports.push_back(new Lend("???????-?????????", 40, 10, {5, 6.5, 8}));
        //transports.push_back(new Lend("???????", 15, 8, {2}));
        //transports.push_back(new Lend("???????-?????????", 6, 60, {10, 5}));
    }
    if (typeGame == 0 || typeGame == 2)
    {
        //transports.push_back(new Air("?????-???????", 10, {{0, 0}, {1000, 3}, {5000, 10}, {10000, 5}}));
        //transports.push_back(new Air("????", 8, {{0, 6}}));
        //transports.push_back(new Air("?????", 20, {{1000, -1}}));
    }
}
std::vector<Transport*> GameRule::getTransports()
{
    return transports;
}