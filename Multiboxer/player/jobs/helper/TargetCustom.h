#pragma once

#include "Target.h"

namespace player_job
{
    class TargetCustom : public Target
    {
    public:
        TargetCustom(const std::string& targetString);
    };
} // namespace player_job
