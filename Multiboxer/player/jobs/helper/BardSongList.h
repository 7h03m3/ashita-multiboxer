#pragma once

#include <vector>
#include "BardSong.h"

namespace player_job
{
    class BardSongList
    {
    public:
        BardSongList(size_t maxSongs, player::InteractionManager& interactionManager);

        ~BardSongList();

        size_t getSongCount() const;

        size_t getMaxSongs() const;

        bool isRefreshRunning() const;

        bool isFirst() const;

        bool add(shared::SpellId id);

        bool add(shared::SpellId id, const Target& target);

        bool set(size_t index, shared::SpellId id);

        bool set(size_t index, shared::SpellId id, const Target& target);

        size_t getSize() const;

        const BardSong& get(size_t index) const;

        void startRefresh();

        void stopRefresh();

        void doRefresh();

        void refreshNext();

    private:
        const size_t mMaxSongs;
        player::InteractionManager& mInteractionManager;
        std::vector<BardSong*> mList;
        std::vector<BardSong*>::iterator mCurrent;
        bool mRefreshRunning;

        BardSong& getCurrent() const;
    };
} // namespace player_job
