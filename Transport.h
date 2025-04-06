#pragma once

#include <string>

class Transport
{
  private:
    std::string name{};
    bool activation{false};

  protected:
    double speed{};

  public:
    Transport(std::string name, double speed) : name(name), speed(speed)
    {
    }

    ~Transport()
    {
    }

    std::string getName();
    bool getActivation();
    void setActivation();

    virtual double getResult(int lengthTrack) = 0;
};
