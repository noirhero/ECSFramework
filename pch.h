// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#pragma once

#pragma warning(disable : 4100) // ������� �ʴ� ���� �� ���� ��� ���� ��� ����.
#pragma warning(disable : 4201) // �̸� ���� ����ü ��� �� ��� ���� ��� ����.
#pragma warning(disable : 4819) // ���� ���ڵ� UTF-8 �� �ƴ� �� ���� ��� ����.
#include <cocos2d.h>
using namespace cocos2d;

#define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include <audio/include/AudioEngine.h>
#elif USE_SIMPLE_AUDIO_ENGINE
#endif

#pragma warning(default : 4100)
#pragma warning(default : 4201)
#pragma warning(default : 4819)

#include <gsl/gsl>

#pragma warning(disable : 4819) // ���� ���ڵ� UTF-8 �� �ƴ� �� ���� ��� ����.
#include <entt/entt.hpp>
#pragma warning(default : 4819)
