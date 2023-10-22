#pragma once

#include "TaskQueue/TaskQueue.h"

#include <map>
#include <string>

namespace commands
{
    class Screen
    {
    public:
        Screen(TaskQueue& taskQueue, ChatManager& chatManager);

        bool set(const std::string& profileName);

    private:
        struct Profile
        {
            size_t sizeX;
            size_t sizeY;
            size_t posX;
            size_t posY;
        };

        ChatManager& mChatManager;
        TaskQueue& mTaskQueue;
        std::map<std::string, Profile> mProfiles;

        void addProfile(const std::string& name, size_t sizeX, size_t sizeY, size_t posX, size_t posY);
    };
} // namespace commands
