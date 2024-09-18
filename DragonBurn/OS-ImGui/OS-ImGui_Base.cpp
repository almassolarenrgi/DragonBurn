﻿#include "OS-ImGui_Base.h"
#include "..\Resources\WeaponIcon.hpp"
#include "..\Resources\Font.hpp"
#include "..\Resources\Language.hpp"

namespace OSImGui
{
    bool OSImGui_Base::InitImGui(ID3D11Device* device, ID3D11DeviceContext* device_context)
    {
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.Fonts->AddFontDefault();
        (void)io;

        ImFontAtlas* fontAtlas = new ImFontAtlas();
        ImFontConfig arialConfig;
        arialConfig.FontDataOwnedByAtlas = false;
        ImFont* arialFont = fontAtlas->AddFontFromMemoryTTF((void*)MainFont, sizeof(MainFont), 19.0f, &arialConfig, io.Fonts->GetGlyphRangesDefault());
        
        ImFontConfig iconConfig;
        iconConfig.MergeMode = true;
        iconConfig.PixelSnapH = true;
        iconConfig.OversampleH = 3;
        iconConfig.OversampleV = 3;
        iconConfig.FontDataOwnedByAtlas = false;

        ImFont* WeaponIconFont = fontAtlas->AddFontFromMemoryTTF((void*)cs_icon, sizeof(cs_icon), 20.0f);

        io.Fonts = fontAtlas;

        ImGui::DragonBurnDefaultStyle();
        io.LogFilename = nullptr;

        if (!ImGui_ImplWin32_Init(Window.hWnd))
            throw OSException("ImGui_ImplWin32_Init() call failed.");
        if (!ImGui_ImplDX11_Init(device, device_context))
            throw OSException("ImGui_ImplDX11_Init() call failed.");

        return true;
    }

    void OSImGui_Base::CleanImGui()
    {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        g_Device.CleanupDeviceD3D();
        DestroyWindow(Window.hWnd);
        UnregisterClassA(Window.ClassName.c_str(), Window.hInstance);
    }

    std::wstring OSImGui_Base::StringToWstring(std::string& str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(str);
    }
}