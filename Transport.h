#pragma once

#include <string>

class Transport
{
  private:
    std::string name{};
    int speed{};
    bool activation{false};

  public:
    Transport(std::string name, int speed) : name(name), speed(speed)
    {
    }

    ~Transport()
    {
    }

    std::string getName();
    bool getActivation();

    virtual double getResult(int lengthTrack) = 0;
};
