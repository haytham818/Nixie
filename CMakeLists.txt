cmake_minimum_required(VERSION 3.16)
project(Nixie VERSION 0.1.0 LANGUAGES CXX)

# ============================================================================
# C++ Standard
# ============================================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================================
# Build Options
# ============================================================================
option(NIXIE_FETCH_DEPENDENCIES "Use FetchContent to download dependencies" ON)

# ============================================================================
# Output directories
# ============================================================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ============================================================================
# Platform Detection
# ============================================================================
if(WIN32)
    message(STATUS "Configuring for Windows")
    add_definitions(-DNIXIE_PLATFORM_WINDOWS)
    # Avoid MSVC warnings
    if(MSVC)
        add_compile_options(/W4 /WX-)
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    endif()
elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Linux")
    add_definitions(-DNIXIE_PLATFORM_LINUX)
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif(APPLE)
    message(STATUS "Configuring for macOS")
    add_definitions(-DNIXIE_PLATFORM_MACOS)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ============================================================================
# Dependencies
# ============================================================================
include(FetchContent)

if(NIXIE_FETCH_DEPENDENCIES)
    # Raylib
    message(STATUS "Fetching raylib...")
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
        GIT_SHALLOW TRUE
    )
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(raylib)

    # Lua
    message(STATUS "Fetching Lua...")
    FetchContent_Declare(
        lua
        GIT_REPOSITORY https://github.com/walterschell/Lua.git
        GIT_TAG v5.4.7
        GIT_SHALLOW TRUE
    )
    set(LUA_BUILD_BINARY OFF CACHE BOOL "" FORCE)
    set(LUA_BUILD_COMPILER OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(lua)

    # Sol2
    message(STATUS "Fetching sol2...")
    FetchContent_Declare(
        sol2
        GIT_REPOSITORY https://github.com/ThePhD/sol2.git
        GIT_TAG v3.5.0
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(sol2)

    # CLI11
    message(STATUS "Fetching CLI11...")
    FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.4.2
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(cli11)
else()
    # Use system-installed dependencies
    find_package(raylib REQUIRED)
    find_package(Lua REQUIRED)
    find_package(sol2 REQUIRED)
    find_package(CLI11 REQUIRED)
endif()

# ============================================================================
# Source Files
# ============================================================================
set(NIXIE_SOURCES
    src/main.cpp
)

set(NIXIE_HEADERS

)

# ============================================================================
# Main Executable
# ============================================================================
add_executable(${PROJECT_NAME} ${NIXIE_SOURCES} ${NIXIE_HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
    lua_static
    sol2
    CLI11::CLI11
)

# ============================================================================
# Platform-specific linking
# ============================================================================
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        winmm
        gdi32
        opengl32
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        m
        pthread
        dl
    )
    # Check for X11 or Wayland
    find_package(X11)
    if(X11_FOUND)
        target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_LIBRARIES})
    endif()
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()

# ============================================================================
# Summary
# ============================================================================
message(STATUS "")
message(STATUS "=== Nixie Configuration ===")
message(STATUS "Version:          ${PROJECT_VERSION}")
message(STATUS "C++ Standard:     ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type:       ${CMAKE_BUILD_TYPE}")
message(STATUS "Fetch Deps:       ${NIXIE_FETCH_DEPENDENCIES}")
message(STATUS "Build Examples:   ${NIXIE_BUILD_EXAMPLES}")
message(STATUS "===========================")
message(STATUS "")
