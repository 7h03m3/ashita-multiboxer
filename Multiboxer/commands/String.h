#pragma once

#include <vector>
#include <string>

namespace commands
{
    class String
    {
    public:
        String(const std::vector<std::string>& args);

        std::string getArg(size_t index) const;

        bool hasArg(size_t index) const;

        String getSub() const;

        size_t getCount() const;

        bool isEmpty() const;

        bool match(const std::string& arg) const;

        bool match(const std::string& arg1, const std::string& arg2) const;

    private:
        std::vector<std::string> mArgs;
    };
} // namespace commands
