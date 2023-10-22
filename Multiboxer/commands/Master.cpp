#include "Master.h"

using namespace commands;

Master::Master(IAshitaCore& ashita, ChatManager& chatManager, PlayerManager& playerManager)
    : mAshita(ashita)
    , mChatManager(chatManager)
    , mPlayerManager(playerManager)
    , mTargetHelper(ashita)
{
}

void Master::onCommand(const std::string& command, const std::string& argument)
{
    if (command == "sayHello")
    {
        sendCommandToAllActive("/p Hello");
        return;
    }
    else if ((command == "startBattle") && !argument.empty())
    {
        const uint32_t serverId = mTargetHelper.getServerIdFromArgument(argument);
        if (serverId == 0)
        {
            return;
        }

        sendCommandToAllActive("/mb job startBattle " + std::to_string(serverId));
        return;
    }
    else if ((command == "stopBattle") && argument.empty())
    {
        sendCommandToAllActive("/mb job stopBattle");
        return;
    }
    else if ((command == "reposition") && !argument.empty())
    {
        const uint32_t targetIndex = mTargetHelper.getTargetIndexFromArgument(argument);
        if (targetIndex == 0)
        {
            return;
        }

        sendCommandToAllActive("/mb job reposition " + std::to_string(targetIndex));
        return;
    }

    mChatManager.printError("master command not found");
}

void Master::sendCommandToAllActive(const std::string& command)
{
    std::vector<std::string> list = mPlayerManager.getActivePlayerNames();

    for (auto it = list.begin(); it != list.end(); it++)
    {
        const std::string fullCommand = "/mst " + *it + " " + command;
        mAshita.GetChatManager()->QueueCommand(0, fullCommand.c_str());
    }
}
