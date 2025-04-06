#pragma once

#include "DistancePercent.h"
#include "Transport.h"

#include <vector>

class Air : public Transport
{
  private:
    bool exponentCalculations{false};
    std::vector<DistancePercent> distancePercent;

  public:
    Air(std::string name, double speed, bool exponentCalculations, std::vector<DistancePercent> distancePercent)
        : Transport(name, speed), exponentCalculations(exponentCalculations), distancePercent(distancePercent)
    {
    }

    ~Air()
    {
    }

    double getResult(int lengthTrack) override;

  private:
    double exponent(int lengthTrack);
    double linear(int lengthTrack);
};
