#include "RunnerWin32.hpp"

#include "anemone/application/win32/GameHostWin32.hpp"
#include "anemone/application/win32/WindowWin32.hpp"

namespace anemone {

RunnerWin32::RunnerWin32()
{
}

RunnerWin32::~RunnerWin32()
{
}

void RunnerWin32::Run()
{
  using anemone::detail::win32::WindowWin32;
  auto window = std::shared_ptr<WindowWin32>();

  auto gameHost = std::shared_ptr<GameHostWin32>();

  // gameHost->Run();

  window.reset();
  gameHost.reset();
}

}  // namespace anemone
