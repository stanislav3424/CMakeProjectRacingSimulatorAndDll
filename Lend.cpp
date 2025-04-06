#include "Lend.h"

double Lend::getResult(int lengthTrack)
{
    double time{};
    double currentLocation{};
    double currentStamina{stamina};
    int indexVector{};
    while (currentLocation < lengthTrack)
    {
        if (currentStamina > 0)
        {
        ++time;
        currentLocation += speed;
        --currentStamina;
        }
        else
        {
            currentStamina = stamina;
            time += staminaDelayVector[indexVector];
            if (indexVector + 1 < staminaDelayVector.size())
            {
                ++indexVector;
            }
        }
    }
    //time += (lengthTrack - (currentLocation - speed)) / speed;
    return time;
}