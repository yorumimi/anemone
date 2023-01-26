#pragma once

#include "anemone/application/Window.hpp"
#include "anemone/basic/ConditionalCompilation.h"
#include "anemone/platform/win32/PrerequisiteWin32.h"

ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_BEGIN
#include <memory>
ANEMONE_SUPPRESS_WARNINGS_GENERATED_BY_STD_HEADERS_END

namespace anemone::detail::win32 {

class WindowWin32 final : public Window
{
public:
  WindowWin32();

  ~WindowWin32();

  void SetTitle(const std::string& title) override;
  [[nodiscard]] const std::string& GetTitle() const override;

  void Close();

private:
  class Impl;
  std::unique_ptr<Impl> impl;
};

}  // namespace anemone::detail::win32
