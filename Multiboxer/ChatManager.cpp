#include "ChatManager.h"

ChatManager::ChatManager(IAshitaCore& ashita)
    : mChatManager(ashita.GetChatManager())
{
}

void ChatManager::printMessage(const std::string& message)
{
    print(Ashita::Chat::Message(message));
}

void ChatManager::printError(const std::string& message)
{
    print(Ashita::Chat::Error(message));
}

void ChatManager::print(const std::string& message)
{
    mChatManager->AddChatMessage(1, false, message.c_str());
}