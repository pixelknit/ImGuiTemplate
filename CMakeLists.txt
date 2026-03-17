cmake_minimum_required(VERSION 3.11)
project(store_app)
set(CMAKE_CXX_STANDARD 20)
set(glfw3_DIR "C:/Program Files (x86)/GLFW/lib/cmake/glfw3")

# Find or add your dependencies (example with GLFW and OpenGL)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Add ImGui subdirectory
add_subdirectory(third_party/imgui)

file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link ImGui and backends
target_link_libraries(${PROJECT_NAME} PRIVATE
    imgui
    imgui_stdlib      # Optional: for std::string support
    imgui_glfw        # Platform backend
    imgui_opengl3     # Renderer backend
    glfw
    OpenGL::GL
)