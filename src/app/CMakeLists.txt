
set(SRC
	main.cpp
	application.cpp
	)

set(INC
	application.h
	)

set(LIBS
	glfw
	imgui
	glad
	gui
	)

add_executable(${PROJECT_NAME} "${SRC};${INC}")
target_link_libraries(${PROJECT_NAME} "${LIBS}")
