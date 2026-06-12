#include "llvm/IRReader/IRReader.h"
#include "llvm/IR/LLVMContext.h"
#include "slim/IR.h"
#include "slim/LivenessPass.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        llvm::errs() << "Usage: ./slim_test <file.slim.ll>\n";
        return 1;
    }

    llvm::LLVMContext context;
    llvm::SMDiagnostic smDiagnostic;

    std::unique_ptr<llvm::Module> module =
        llvm::parseIRFile(argv[1], smDiagnostic, context);

    if (!module) {
        smDiagnostic.print(argv[0], llvm::errs());
        return 1;
    }

    slim::IR *slimIR = new slim::IR(module);
    slimIR->dumpIR();

    slim::LivenessPass liveness(slimIR);
    liveness.run();

    return 0;
}
