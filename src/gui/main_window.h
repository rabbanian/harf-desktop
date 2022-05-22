#ifndef HARF_DESKTOP_SRC_GUI_MAIN_WINDOW_H_
#define HARF_DESKTOP_SRC_GUI_MAIN_WINDOW_H_

#include "widget.h"

namespace gui {

class MainWindow : public Widget
{
 public:
  ~MainWindow() = default;
  void OnRender() override;

 private:
  bool is_click_me_ = false;
  int count_ = 0;

};

}  // namespace gui

#endif  // HARF_DESKTOP_SRC_GUI_MAIN_WINDOW_H_
