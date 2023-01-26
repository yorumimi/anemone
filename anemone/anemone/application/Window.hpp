#pragma once

#include "anemone/basic/ConditionalCompilation.h"

ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_BEGIN
#include <string>
ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_END

namespace anemone {

class Window
{
public:
  Window();
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  virtual ~Window();

  virtual void SetTitle(const std::string& title) = 0;
  virtual const std::string& GetTitle() const = 0;
};

}  // namespace anemone
