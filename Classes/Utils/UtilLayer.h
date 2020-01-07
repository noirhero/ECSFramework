// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#pragma once

namespace UtilLayer {
    bool ChangeAndThenDelete(gsl::owner<Layer*> newLayer, gsl::owner<Layer*> oldLayer);
}
