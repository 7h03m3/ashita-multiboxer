#pragma once

#include "PlayerBaseInterface.h"
#include "BuffTracker.h"
#include "ChatManager.h"

namespace player
{
    class PlayerBase : public PlayerBaseInterface
    {
    public:
        PlayerBase(uint32_t id, const std::string& name, ChatManager& chatManager);

        PlayerBase(uint32_t id, uint16_t index, const std::string& name, ChatManager& chatManager);

        const PlayerStats& getStats() const override;

        void setJobs(uint8_t mainJob, uint8_t subJob) override;

        void setCasting(bool isCasting) override;

        void updatePlayerInfo(uint32_t playerId, uint16_t playerIndex) override;

        void updatePlayerInfo(uint32_t playerId, uint16_t playerIndex, const std::string& name) override;

        void updateStats(const PlayerStats& stats) override;

        void updateBuffs(const uint8_t buffArray[BuffTracker::MaxBuffCount], const uint8_t buffBits[BuffTracker::MaxBuffBits]) override;

        uint32_t getId() const override;

        uint16_t getIndex() const override;

        const std::string& getName() const override;

        uint8_t getMainJob() const override;

        uint8_t getSubJob() const override;

        void setZone(uint16_t zone) override;

        uint16_t getZone() const override;

        bool isCasting() const override;

        size_t getBuffCount(shared::BuffId buff) const override;

    protected:
        ChatManager& mChatManager;

    private:
        uint32_t mID;
        uint16_t mIndex;
        std::string mName;
        uint16_t mZone;
        uint8_t mMainJob;
        uint8_t mSubJob;
        PlayerStats mStats;
        BuffTracker mBuffs;
        bool mIsCasting;

        void setId(uint32_t id);

        void setIndex(uint16_t index);

        void setName(const std::string& name);
    };
} // namespace player
