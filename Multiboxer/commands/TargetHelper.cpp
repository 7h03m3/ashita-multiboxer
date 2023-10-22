#include "TargetHelper.h"

using namespace commands;

TargetHelper::TargetHelper(IAshitaCore& ashita)
    : mAshita(ashita)
{
}

uint32_t TargetHelper::getServerIdFromArgument(const std::string& argument)
{
    if (argument.empty())
    {
        return 0;
    }

    if (argument == "<t>")
    {
        const uint32_t targetIndex = mAshita.GetMemoryManager()->GetTarget()->GetTargetIndex(0);
        if (targetIndex == 0)
        {
            return 0;
        }

        return mAshita.GetMemoryManager()->GetEntity()->GetServerId(targetIndex);
    }
    else
    {
        return std::stoi(argument);
    }
}

uint32_t TargetHelper::getTargetIndexFromArgument(const std::string& argument)
{
    if (argument.empty())
    {
        return 0;
    }

    if (argument == "<t>")
    {
        return mAshita.GetMemoryManager()->GetTarget()->GetTargetIndex(0);
    }
    else
    {
        return std::stoi(argument);
    }
}