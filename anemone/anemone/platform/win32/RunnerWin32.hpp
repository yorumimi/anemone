#pragma once

#include "PrerequisiteWin32.h"

namespace anemone {

class RunnerWin32 final
{
public:
  RunnerWin32();

  ~RunnerWin32();

  void Run();

private:
  HINSTANCE hInstance = nullptr;
  int cmdShow = SW_SHOWDEFAULT;
};

}  // namespace anemone
