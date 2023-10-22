#include "Screen.h"

using namespace commands;

Screen::Screen(TaskQueue& taskQueue, ChatManager& chatManager)
    : mChatManager(chatManager)
    , mTaskQueue(taskQueue)
    , mProfiles()
{
    addProfile("left", 1920, 1080, 0, 0);
    addProfile("right", 1920, 1080, 1920, 0);

    addProfile("q1l", 928, 502, 0, 0);
    addProfile("q2l", 928, 502, 0, 530);
    addProfile("q3l", 928, 502, 992, 0);
    addProfile("q4l", 928, 502, 992, 530);
    addProfile("middlel", 800, 450, 620, 295);

    addProfile("q1r", 928, 502, 0 + 1920, 0);
    addProfile("q2r", 928, 502, 0 + 1920, 530);
    addProfile("q3r", 928, 502, 992 + 1920, 0);
    addProfile("q4r", 928, 502, 992 + 1920, 530);
    addProfile("middler", 800, 450, 620 + 1920, 295);
}

bool Screen::set(const std::string& profileName)
{
    auto profile = mProfiles.find(profileName.c_str());

    if (profile == mProfiles.end())
    {
        return false;
    }

    mTaskQueue.add("/move size " + std::to_string(profile->second.sizeX) + " " + std::to_string(profile->second.sizeY), 1, TaskQueueItem::Command);
    mTaskQueue.add("/move " + std::to_string(profile->second.posX) + " " + std::to_string(profile->second.posY), 1, TaskQueueItem::Command);

    return true;
}

void Screen::addProfile(const std::string& name, size_t sizeX, size_t sizeY, size_t posX, size_t posY)
{
    Profile profile = {.sizeX = sizeX, .sizeY = sizeY, .posX = posX, .posY = posY};
    mProfiles.insert({name, profile});
}