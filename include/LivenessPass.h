#pragma once

#include "IR.h"

namespace slim {

class LivenessPass {
private:
    slim::IR *ir;

public:
    LivenessPass(slim::IR *ir);
    void run();
};

} // namespace slim
