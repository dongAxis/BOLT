//===------- HugifyRuntimeLibrary.h - The Hugify Runtime Library ----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TOOLS_LLVM_BOLT_HUGIFY_RUNTIME_LIBRARY_H
#define LLVM_TOOLS_LLVM_BOLT_HUGIFY_RUNTIME_LIBRARY_H

#include "bolt/RuntimeLibs/RuntimeLibrary.h"

namespace llvm {
namespace bolt {

class HugifyRuntimeLibrary : public RuntimeLibrary {
public:
  /// Add custom section names generated by the runtime libraries to \p
  /// SecNames.
  void addRuntimeLibSections(std::vector<std::string> &SecNames) const final {
    SecNames.push_back(".bolt.hugify.entries");
  }

  void adjustCommandLineOptions(const BinaryContext &BC) const final;

  void emitBinary(BinaryContext &BC, MCStreamer &Streamer) final;

  void link(BinaryContext &BC, StringRef ToolPath, RuntimeDyld &RTDyld,
            std::function<void(RuntimeDyld &)> OnLoad) final;
};

} // namespace bolt
} // namespace llvm

#endif
