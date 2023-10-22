#pragma once

#include <Ashita.h>
#include <string>
#include <cstdint>
#include "ChatManager.h"
#include "PlayerManager.h"
#include "TargetHelper.h"

namespace commands
{
    class Master
    {
    public:
        Master(IAshitaCore& ashita, ChatManager& chatManager, PlayerManager& playerManager);

        void onCommand(const std::string& command, const std::string& argument);

    private:
        IAshitaCore& mAshita;
        ChatManager& mChatManager;
        PlayerManager& mPlayerManager;
        TargetHelper mTargetHelper;

        void sendCommandToAllActive(const std::string& command);
    };
} // namespace commands
