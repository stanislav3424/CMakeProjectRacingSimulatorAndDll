#pragma once

#include "Air.h"
#include "Lend.h"
#include "Transport.h"

#include <memory>
#include <vector>

class GameRule
{
  private:
    int typeGame{};
    int trackLength{};
    std::vector<Transport*> transports;

  public:
    GameRule(int typeGame, int trackLength) : typeGame(typeGame), trackLength(trackLength)
    {
        createTransport();
    }

    ~GameRule()
    {
    }

    int getTypeGame();
    int getTrackLength();

    std::vector<Transport*> getTransports();

   private:
    void createTransport();
};
