#=================== ImGui ===================
target_sources(ImGui
	PRIVATE
	${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.cpp
	${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp
)

# BattleShip (and other LUS ports) use SDL_MAIN_HANDLED + a normal main() in port.cpp.
# SDL2main adds -mwindows and expects SDL_main — that breaks Linux→MinGW cross links
# (package-mingw-windows.sh uses -mconsole). MSVC native builds still use SDL2main.
if (MINGW)
    set(SDL2_NO_MWINDOWS ON)
endif()
find_package(SDL2 CONFIG REQUIRED)
if (MINGW)
    target_link_libraries(ImGui PUBLIC SDL2::SDL2)
else()
    target_link_libraries(ImGui PUBLIC SDL2::SDL2 SDL2::SDL2main)
endif()

find_package(GLEW REQUIRED)
target_link_libraries(ImGui PUBLIC opengl32 GLEW::GLEW)

# ImGui DX11 / Win32 backends (WASAPI ksguid is on libultraship — see src/CMakeLists.txt).
target_link_libraries(ImGui PUBLIC d3dcompiler dwmapi hid setupapi)
