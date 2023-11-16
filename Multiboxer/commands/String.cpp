#include "String.h"

using namespace commands;

String::String(const std::vector<std::string>& args)
    : mArgs(args)
{}

std::string String::getArg(const size_t index) const
{
    return (index < mArgs.size() ? mArgs[index] : "");
}

bool String::hasArg(const size_t index) const
{
    return index < mArgs.size();
}

size_t String::getCount() const
{
    return mArgs.size();
}

bool String::isEmpty() const
{
    return mArgs.empty();
}

String String::getSub() const
{
    std::vector<std::string> args = mArgs;

    if (args.size() > 0)
    {
        args.erase(args.begin());
    }

    return args;
}

bool String::match(const std::string& arg) const
{
    return getArg(0u) == arg;
}

bool String::match(const std::string& arg1, const std::string& arg2) const
{
    return match(arg1) && (getArg(1u) == arg2);
}