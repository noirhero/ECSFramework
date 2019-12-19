// Copyright 2018-2019 TAP, Inc. All Rights Reserved.

#include "../pch.h"
#include "main.h"

#include "AppDelegate.h"

int32_t WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int32_t nCmdShow) {
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    AppDelegate app;
    return Application::getInstance()->run();
}
