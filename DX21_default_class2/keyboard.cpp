//--------------------------------------------------------------------------------------
// File: Keyboard.cpp
//
// キーボードモジュール
//
//--------------------------------------------------------------------------------------
// 2020/06/07
//     DirectXTKより、なんちゃってC言語用にシェイプアップ改変
//
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//--------------------------------------------------------------------------------------
#include "keyboard.h"

#include <assert.h>


static_assert(sizeof(Keyboard_State) == 256 / 8, "キーボード状態構造体のサイズ不一致");


static Keyboard_State gState = {};
//直前(Immediately)のキーステート
static Keyboard_State g_ImState = {};


static void keyDown(int key)
{
    if (key < 0 || key > 0xfe) { return;  }

    unsigned int* p = (unsigned int*)&gState;
    unsigned int bf = 1u << (key & 0x1f);
    p[(key >> 5)] |= bf;
}


static void keyUp(int key)
{
    if (key < 0 || key > 0xfe) { return; }

    unsigned int* p = (unsigned int*)&gState;
    unsigned int bf = 1u << (key & 0x1f);
    p[(key >> 5)] &= ~bf;
}


void Keyboard_Initialize(void)
{
    Keyboard_Reset();
}


bool Keyboard_IsKeyDown(Keyboard_Keys key, const Keyboard_State* pState)
{
    if (key <= 0xfe)
    {
        unsigned int* p = (unsigned int*)pState;
        unsigned int bf = 1u << (key & 0x1f);
        return (p[(key >> 5)] & bf) != 0;
    }
    return false;
}


bool Keyboard_IsKeyUp(Keyboard_Keys key, const Keyboard_State* pState)
{
    if (key <= 0xfe)
    {
        unsigned int* p = (unsigned int*)pState;
        unsigned int bf = 1u << (key & 0x1f);
        return (p[(key >> 5)] & bf) == 0;
    }
    return false;
}


bool Keyboard_IsKeyDown(Keyboard_Keys key)
{
    return Keyboard_IsKeyDown(key, &gState);
}


bool Keyboard_IsKeyUp(Keyboard_Keys key)
{
    return Keyboard_IsKeyUp(key, &gState);
}

bool InputGetKeyDown(Keyboard_Keys key)
{
    if (key <= 0xfe)
    {
        const unsigned int* p = (unsigned int*)&gState;
        const unsigned int* q = (unsigned int*)&g_ImState;
        unsigned int bf = 1u << (key & 0x1f);
        if((q[(key >> 5)] & bf) == 0 && (p[(key >> 5)] & bf) != 0){
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}

bool InputGetKeyExit(Keyboard_Keys key)
{
    if (key <= 0xfe)
    {
        const unsigned int* p = (unsigned int*)&gState;
        const unsigned int* q = (unsigned int*)&g_ImState;
        unsigned int bf = 1u << (key & 0x1f);
        if ((q[(key >> 5)] & bf) != 0 && (p[(key >> 5)] & bf) == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}

bool InputGetKey(Keyboard_Keys key)
{
    if (key <= 0xfe)
    {
        const unsigned int* p = (unsigned int*)&gState;
        const unsigned int* q = (unsigned int*)&g_ImState;
        unsigned int bf = 1u << (key & 0x1f);
        if ((q[(key >> 5)] & bf) != 0 && (p[(key >> 5)] & bf) != 0) {
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}


// キーボードの現在の状態を取得する
const Keyboard_State* Keyboard_GetState(void)
{
    return &gState;
}


void Keyboard_Reset(void)
{
    ZeroMemory(&gState, sizeof(Keyboard_State));
}


// キーボード制御のためのウォンどうメッセージプロシージャフック関数
void Keyboard_ProcessMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    bool down = false;

    switch (message)
    {
    case WM_ACTIVATEAPP:
        Keyboard_Reset();
        return;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        down = true;
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        break;

    default:
        return;
    }

    int vk = (int)wParam;
    switch (vk)
    {
    case VK_SHIFT:
        vk = (int)MapVirtualKey(((unsigned int)lParam & 0x00ff0000) >> 16u, MAPVK_VSC_TO_VK_EX);
        if (!down)
        {
            // 左シフトと右シフトの両方が同時に押された場合にクリアされるようにするための回避策
            keyUp(VK_LSHIFT);
            keyUp(VK_RSHIFT);
        }
        break;

    case VK_CONTROL:
        vk = ((UINT)lParam & 0x01000000) ? VK_RCONTROL : VK_LCONTROL;
        break;

    case VK_MENU:
        vk = ((UINT)lParam & 0x01000000) ? VK_RMENU : VK_LMENU;
        break;
    }

    if (down)
    {
        keyDown(vk);
    }
    else
    {
        keyUp(vk);
    }
}

void SetImmediatelyKeyState(void)
{
    g_ImState = gState;
}
