#pragma once

#include "PlayerBaseInterface.h"

namespace player
{
    class PlayerInterface : public PlayerBaseInterface
    {
    public:
        virtual void poll() = 0;

        virtual void onCommand(const std::string& command, const std::string& argument1, const std::string& argument2) = 0;

        virtual void onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2) = 0;

        virtual void onDisengage() = 0;

        virtual void onMobDeath(uint32_t mobServerId) = 0;
    };
} // namespace player