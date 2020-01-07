// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "UtilLayer.h"

namespace UtilLayer {
    bool ChangeAndThenDelete(gsl::owner<Layer*> newLayer, gsl::owner<Layer*> oldLayer) {
        gsl::not_null<Scene*> scene = oldLayer->getScene();
        scene->removeChild(oldLayer);

        newLayer->autorelease();
        scene->addChild(newLayer);

        if(false == newLayer->init())
        {
            scene->removeChild(newLayer);
            return false;
        }

        return true;
    }
}
