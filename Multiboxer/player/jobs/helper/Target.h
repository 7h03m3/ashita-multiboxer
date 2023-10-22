#pragma once

#include <string>

#include "TargetType.h"

namespace player_job
{
    class Target
    {
    public:
        Target(const Target& other);

        bool isBattleTarget() const;

        bool isMe() const;

        bool isCustom() const;

        void set(const std::string& targetString);

        const std::string& get() const;

        Target& operator=(const Target& other);

    protected:
        Target(TargetType type);

        Target(TargetType type, const std::string& targetString);

    private:
        TargetType mType;
        std::string mTargetString;
    };
} // namespace player_job
