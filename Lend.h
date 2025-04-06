#pragma once

#include "Transport.h"

#include <vector>

class Lend : public Transport
{
  private:
    double stamina{};
    std::vector<double> staminaDelayVector;

  public:
    Lend(std::string name, double speed, double stamina, std::vector<double> staminaDelayVector)
        : Transport(name, speed), stamina(stamina), staminaDelayVector(staminaDelayVector)
    {
    }

    ~Lend()
    {
    }

    double getResult(int lengthTrack) override;
};
