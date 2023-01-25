#include "anemone/application/win32/WindowWin32.hpp"

namespace anemone::detail::win32 {

WindowWin32::WindowWin32()
{
}

WindowWin32::~WindowWin32()
{
}

void WindowWin32::SetTitle(const std::string& title)
{
  impl->SetTitle(title);
}

std::string WindowWin32::GetTitle() const
{
  return impl->title;
}

void WindowWin32::Close()
{
}

class WindowWin32::Impl final
{
public:
  ~Impl();

  void SetTitle(const std::string& title);
  std::string title;

private:
  static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

WindowWin32::Impl::~Impl()
{
}

void WindowWin32::Impl::SetTitle(const std::string& titleIn)
{
  this->title = titleIn;
}

LRESULT WindowWin32::Impl::WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  auto window = reinterpret_cast<WindowWin32::Impl*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));

  return DefWindowProc(hWnd, msg, wParam, lParam);
}

}  // namespace anemone::detail::win32
