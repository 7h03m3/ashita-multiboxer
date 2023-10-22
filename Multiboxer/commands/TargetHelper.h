#pragma once

#include <Ashita.h>
#include <cstdint>
#include <string>

namespace commands
{
    class TargetHelper
    {
    public:
        TargetHelper(IAshitaCore& ashita);

        uint32_t getServerIdFromArgument(const std::string& argument);

        uint32_t getTargetIndexFromArgument(const std::string& argument);

    private:
        IAshitaCore& mAshita;
    };
} // namespace commands
