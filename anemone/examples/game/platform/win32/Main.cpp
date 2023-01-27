#include <Windows.h>

#include "../../../../anemone/platform/win32/RunnerWin32.hpp"

#define ENTRY_POINT                                                       \
  int APIENTRY WinMain(_In_ [[maybe_unused]] HINSTANCE hInstance,         \
                       _In_opt_ [[maybe_unused]] HINSTANCE hPrevInstance, \
                       _In_ LPSTR lpCmdLine,                              \
                       _In_ int nCmdShow)

ENTRY_POINT
{
  anemone::RunnerWin32 runner;
  runner.Run();

  return 0;
}
