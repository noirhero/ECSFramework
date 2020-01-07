// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../pch.h"

#include "main.h"
#include "AppDelegate.h"

int32_t WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int32_t nCmdShow) {
    AppDelegate app;
    return Application::getInstance()->run();
}
