#pragma once

#include "Air.h"
#include "Lend.h"
#include "Transport.h"

#include <vector>
#include <map>

class GameRule
{
  private:
    int typeGame{};
    int trackLength{};
    std::vector<Transport*> transports;
    std::multimap<double, std::string> resultMap;


  public:
    GameRule(int typeGame, int trackLength) : typeGame(typeGame), trackLength(trackLength)
    {
        createTransport();
    }

    ~GameRule()
    {
        for (auto* transport : transports)
        {
            delete transport;
        }
    }

    int getTypeGame();
    int getTrackLength();

    std::multimap<double, std::string>& getResultMap();
    std::vector<Transport*> getTransports();

    void setActivation(int index);
    void startGame();

   private:
    void createTransport();
};
