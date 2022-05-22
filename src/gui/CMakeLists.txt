set(SRC
	main_window.cpp
	)

set(INC
	widget.h
	main_window.h
	)

set(LIBS
	imgui
	)

add_library(gui "${SRC};${INC}")
target_link_libraries(gui "${LIBS}")
