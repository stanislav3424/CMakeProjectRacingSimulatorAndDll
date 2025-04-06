#pragma once

#include "Transport.h"

class Air : public Transport
{
  public:
    Air(std::string name, int speed) : Transport(name, speed)
    {
    }

    ~Air()
    {
    }

    double getResult(int lengthTrack);
};
