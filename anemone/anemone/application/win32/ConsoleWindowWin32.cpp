#include "ConsoleWindowWin32.hpp"

#include "anemone/platform/win32/PrerequisiteWin32.h"
#include "anemone/basic/ConditionalCompilation.h"

ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_BEGIN
#include <stdio.h>
ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_END


namespace anemone::detail::win32 {

ConsoleWindowWin32::ConsoleWindowWin32()
{
  AllocConsole();
  freopen_s(&fp, "CON", "w", stdout);

  // NOTE: コンソールを先に終了するとリークするので
  HMENU hmenu = GetSystemMenu(GetConsoleWindow(), FALSE);
  RemoveMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);
}

ConsoleWindowWin32::~ConsoleWindowWin32()
{
  fclose(fp);
  FreeConsole();
}

}  // namespace anemone::detail::win32
