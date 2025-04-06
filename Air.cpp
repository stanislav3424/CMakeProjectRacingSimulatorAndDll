#include "Air.h"

double Air::getResult(int lengthTrack)
{
    if (exponentCalculations == true)
    {
        return exponent(lengthTrack);
    }
    return linear(lengthTrack);
}

double Air::exponent(int lengthTrack)
{
    double discountPercent{};
    discountPercent = (lengthTrack / static_cast<int>(distancePercent[0].distance)) * distancePercent[0].percent;
    return (lengthTrack * ((100 - discountPercent) / 100)) / speed;
}

double Air::linear(int lengthTrack)
{
    double discountPercent{};
    for ( auto& obj : distancePercent)
    {
        discountPercent = obj.percent;
        if (lengthTrack < obj.distance)
        {
            break;
        }
    }
    return (lengthTrack * ((100 - discountPercent) / 100)) / speed;
}