// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "UtilSound.h"

namespace UtilSound {
    std::unordered_map<std::string, int32_t> _audioInstances;

    void End() {
        AudioEngine::end();
    }

    void StopAll() {
        _audioInstances.clear();

        AudioEngine::stopAll();
    }

    bool PlayBGM(std::string&& path) {
        const auto findIter = _audioInstances.find(path);
        if(_audioInstances.end() == findIter)
        {
            _audioInstances.emplace(path, AudioEngine::play2d(path, true));
            return true;
        }

        return false;
    }
}
