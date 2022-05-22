
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)


set(IMGUI_SRC
	imgui/imgui.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/imgui_demo.cpp
	imgui/backends/imgui_impl_opengl3.cpp
	imgui/backends/imgui_impl_glfw.cpp
	)

set(IMGUI_HDR
	imgui/imconfig.h
	imgui/imgui.h
	imgui/imgui_internal.h
	imgui/imstb_rectpack.h
	imgui/imstb_textedit.h
	imgui/imstb_truetype.h
	imgui/backends/imgui_impl_opengl3.h
	imgui/backends/imgui_impl_glfw.h
	)

add_library(imgui STATIC "${IMGUI_SRC}" "${IMGUI_HDR}")
target_include_directories(imgui PUBLIC imgui/)
target_link_libraries(imgui glfw)

set(GLAD_SRC
	glad/src/gles2.c
	glad/src/egl.c
	)

set(GLAD_HDR
	glad/include/glad/gles2.h
	glad/include/glad/egl.h
	glad/include/EGL/eglplatform.h
	glad/include/KHR/khrplatform.h
	)

add_library(glad STATIC "${GLAD_SRC}" "${GLAD_HDR}")
target_include_directories(glad PUBLIC glad/include)


add_library(asio INTERFACE)
target_include_directories(asio INTERFACE asio/asio/include)