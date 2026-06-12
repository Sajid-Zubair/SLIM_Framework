#include "LivenessPass.h"

namespace slim {

LivenessPass::LivenessPass(slim::IR *ir) : ir(ir) {
}

void LivenessPass::run() {
    llvm::outs() << "\n[LivenessPass] running..........\n";
    llvm::outs() << "[LivenessPass] number of functions: "
                  << ir->getNumberOfFunctions() << "\n";
}

} // namespace slim
