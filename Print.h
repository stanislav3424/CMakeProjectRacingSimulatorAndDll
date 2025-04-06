#pragma once

#include "InputConsole.h"
#include "GameRule.h"

#include <iostream>
#include <vector>
#include <iomanip>

void printMain();
bool printRestart();

int printSelect(int rangeMin, int rangeMax);
bool printTableTransports(GameRule& gameRule, std::vector<std::string>& typeGameStrVector);
void printTableResult(GameRule& gameRule);
void printStrVector(std::vector<std::string>& typeGameVector);

void setTypeGameStrVector(std::vector<std::string>& typeGameVector);
void setRestartStrVector(std::vector<std::string>& typeGameVector);