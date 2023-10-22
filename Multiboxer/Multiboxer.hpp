#ifndef ASHITA_MULTIBOXER_HPP_INCLUDED
#define ASHITA_MULTIBOXER_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "Ashita.h"
#include "TaskQueue/TaskQueue.h"
#include "PacketParser.h"
#include "PlayerManager.h"
#include "ChatManager.h"
#include "commands/Master.h"
#include "commands/Screen.h"

class Multiboxer final : public IPlugin
{
private:
    IAshitaCore* mAshitaCore;          // The pointer to the main AshitaCore object.
    ILogManager* mLogManager;          // The pointer to the main Ashita LogManager object.
    uint32_t mPluginId;                // The plugins id. (The plugins current base address.)
    IDirect3DDevice8* mDirect3DDevice; // The pointer to the games Direct3D device object.
    ChatManager* mChatManager;
    TaskQueue* mTaskQueue;
    PacketParser* mPacketParser;
    PlayerManager* mPlayerManager;
    commands::Master* mMasterCommands;
    commands::Screen* mScreenCommands;

public:
    Multiboxer(void);
    ~Multiboxer(void) override;

    // Properties (Plugin Information)
    const char* GetName(void) const override;
    const char* GetAuthor(void) const override;
    const char* GetDescription(void) const override;
    const char* GetLink(void) const override;
    double GetVersion(void) const override;
    double GetInterfaceVersion(void) const override;
    int32_t GetPriority(void) const override;
    uint32_t GetFlags(void) const override;

    // Methods
    bool Initialize(IAshitaCore* core, ILogManager* logger, uint32_t id) override;
    void Release(void) override;

    // Event Callbacks: PluginManager
    void HandleEvent(const char* eventName, const void* eventData, const uint32_t eventSize) override;

    // Event Callbacks: ChatManager
    bool HandleCommand(int32_t mode, const char* command, bool injected) override;
    bool HandleIncomingText(int32_t mode, bool indent, const char* message, int32_t* modifiedMode, bool* modifiedIndent, char* modifiedMessage, bool injected, bool blocked) override;
    bool HandleOutgoingText(int32_t mode, const char* message, int32_t* modifiedMode, char* modifiedMessage, bool injected, bool blocked) override;

    // Event Callbacks: PacketManager
    bool HandleIncomingPacket(uint16_t id, uint32_t size, const uint8_t* data, uint8_t* modified, uint32_t sizeChunk, const uint8_t* dataChunk, bool injected, bool blocked) override;
    bool HandleOutgoingPacket(uint16_t id, uint32_t size, const uint8_t* data, uint8_t* modified, uint32_t sizeChunk, const uint8_t* dataChunk, bool injected, bool blocked) override;

    // Event Callbacks: Direct3D
    bool Direct3DInitialize(IDirect3DDevice8* device) override;
    void Direct3DBeginScene(bool isRenderingBackBuffer) override;
    void Direct3DEndScene(bool isRenderingBackBuffer) override;
    void Direct3DPresent(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion) override;
    bool Direct3DSetRenderState(D3DRENDERSTATETYPE State, DWORD* Value) override;
    bool Direct3DDrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) override;
    bool Direct3DDrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT minIndex, UINT NumVertices, UINT startIndex, UINT primCount) override;
    bool Direct3DDrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) override;
    bool Direct3DDrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) override;
};

#endif // ASHITA_MULTIBOXER_HPP_INCLUDED