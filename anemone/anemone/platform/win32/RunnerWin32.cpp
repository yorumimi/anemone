#include "RunnerWin32.hpp"

#include "anemone/basic/ConditionalCompilation.h"

#include "anemone/application/win32/GameHostWin32.hpp"
#include "anemone/application/win32/WindowWin32.hpp"

//TODO: for Debug
#include "anemone/application/win32/ConsoleWindowWin32.hpp"

ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_BEGIN
#include <memory>
ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_END

namespace anemone {

RunnerWin32::RunnerWin32()
{
}

RunnerWin32::~RunnerWin32()
{
}

void RunnerWin32::Initialize()
{
}

void RunnerWin32::Run()
{
  auto consoleWindow = std::make_unique<detail::win32::ConsoleWindowWin32>();
  auto window = std::make_unique<detail::win32::WindowWin32>();


}

}  // namespace anemone
