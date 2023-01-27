#include "anemone/application/win32/WindowWin32.hpp"
#include "anemone/basic/ConditionalCompilation.h"

// FIXME: [WIP]
const char* windowClassName = "wip_classname";
constexpr DWORD windowStyleEx = WS_OVERLAPPEDWINDOW;

namespace anemone::detail::win32 {

class WindowWin32::Impl final
{
public:
  ~Impl();

  [[nodiscard]] bool Initialize();

  void SetTitle(const std::string& title);

  std::string title;
  HWND windowHandle = nullptr;

private:
  static LRESULT CALLBACK WindowProcedure(const HWND windowHandle, const UINT msg, const WPARAM wParam, LPARAM lParam);
};

WindowWin32::Impl::~Impl()
{
  if (windowHandle != nullptr)
  {
    ::DestroyWindow(windowHandle);
    windowHandle = nullptr;
  }
}

bool WindowWin32::Impl::Initialize()
{
  auto hInstance = ::GetModuleHandleW(nullptr);

  WNDCLASSEX windowClassEx = {};
  windowClassEx.cbSize = sizeof(WNDCLASSEX);
  windowClassEx.style = (CS_HREDRAW | CS_VREDRAW);
  windowClassEx.lpfnWndProc = reinterpret_cast<WNDPROC>(WindowProcedure);
  windowClassEx.cbClsExtra = 0;
  windowClassEx.cbWndExtra = 0;
  windowClassEx.hInstance = hInstance;
  windowClassEx.hIcon = LoadIcon(nullptr, IDI_APPLICATION);  // TODO:Resource.h
  windowClassEx.hCursor = LoadCursor(nullptr, IDC_ARROW);    // TODO:Resource.h
  windowClassEx.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
  windowClassEx.lpszMenuName = nullptr;
  windowClassEx.lpszClassName = windowClassName;
  windowClassEx.hIconSm = LoadIcon(nullptr, IDI_WINLOGO);  // TODO:Resource.h

  windowHandle = CreateWindowEx(0,
                        windowClassName,
                        title.c_str(),
                        windowStyleEx,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        1280, //[wip]
                        980, //[wip]
                        nullptr,
                        nullptr,
                        hInstance,
                        nullptr);

  return false;
}

void WindowWin32::Impl::SetTitle(const std::string& titleIn)
{
  this->title = titleIn;
}

LRESULT CALLBACK WindowWin32::Impl::WindowProcedure(const HWND windowHandle,
                                                    const UINT message,
                                                    const WPARAM wParam,
                                                    LPARAM lParam)
{
  // auto window = reinterpret_cast<WindowWin32::Impl*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));

  switch (message)
  {
  case WM_CLOSE: {
  }
  case WM_SETFOCUS: {
  }

  default:
    break;
  }

  return DefWindowProcW(windowHandle, message, wParam, lParam);
}

WindowWin32::WindowWin32()
  : impl(std::make_unique<Impl>())
{
}

WindowWin32::~WindowWin32()
{
  if (impl.get() != nullptr)
  {
    impl.reset();
  }
}

bool WindowWin32::Initialize()
{
  return false;
}

void WindowWin32::SetTitle(const std::string& title)
{
  impl->SetTitle(title);
}

const std::string& WindowWin32::GetTitle() const
{
  return impl->title;
}

void WindowWin32::Close()
{
}

}  // namespace anemone::detail::win32
