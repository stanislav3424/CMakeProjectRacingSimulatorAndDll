#pragma once

#include "InputConsole.h"
#include "GameRule.h"

#include <iostream>
#include <vector>
#include <memory>

void printMain();
bool printRestart();

int printSelect(int range);
bool printTable(GameRule& gamerule);

void printTypeGame(std::vector<std::string>& typeGameVector);
void setTypeGameVector(std::vector<std::string>& typeGameVector);