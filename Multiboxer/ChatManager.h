#pragma once

#include <Ashita.h>

class ChatManager
{
public:
    ChatManager(IAshitaCore& ashita);

    void printMessage(const std::string& message);

    void printError(const std::string& message);

private:
    IChatManager* mChatManager;

    void print(const std::string& message);
};
