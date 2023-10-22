#include "TargetCustom.h"

using namespace player_job;

TargetCustom::TargetCustom(const std::string& targetString)
    : Target(Custom, targetString)
{}