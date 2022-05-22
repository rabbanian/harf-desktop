#ifndef HARF_DESKTOP_SRC_GUI_WIDGET_H_
#define HARF_DESKTOP_SRC_GUI_WIDGET_H_

namespace gui
{

class Widget
{
 public:
  virtual ~Widget() = default;
  virtual void OnRender() {}
};

}

#endif  // HARF_DESKTOP_SRC_GUI_WIDGET_H_
