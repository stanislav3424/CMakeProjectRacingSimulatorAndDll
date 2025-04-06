#pragma once

#include "Transport.h"

class Lend : public Transport
{
  public:
    Lend(std::string name, int speed) : Transport(name, speed)
    {
    }

    ~Lend()
    {
    }

    double getResult(int lengthTrack);
};
