#include "Transport.h"

std::string Transport::getName()
{
    return name;
}

bool Transport::getActivation()
{
    return activation;
}

void Transport::setActivation()
{
    activation = 1 - activation;
}