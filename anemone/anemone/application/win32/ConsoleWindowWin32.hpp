#pragma once

#include "anemone/basic/ConditionalCompilation.h"

ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_BEGIN
#include <fstream>
ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_END

namespace anemone::detail::win32 {

class ConsoleWindowWin32 final
{
public:
  ConsoleWindowWin32();

  ~ConsoleWindowWin32();

private:
  FILE* fp;
};

}  // namespace anemone::detail::win32
