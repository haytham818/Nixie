#include <CLI/CLI.hpp>
#include <iostream>
#include <raylib.h>
#include <sol/sol.hpp>
#include <string>

int main(int argc, char* argv[])
{
    std::string nixiePath = "example/example.nixie";

    CLI::App app { "Nixie Engine" };
    app.add_option("-f,--file,nixie_file", nixiePath, "Path to the .nixie file");
    CLI11_PARSE(app, argc, argv);

    // 初始化 Lua 状态机并加载nixie文件
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    sol::table nixie;
    try {
        sol::protected_function_result result = lua.script_file(nixiePath);
        if (!result.valid()) {
            sol::error err = result;
            std::cerr << "Failed to load nixie: " << err.what() << '\n';
            return 1;
        }
        nixie = result;
    } catch (const std::exception& e) {
        std::cerr << "Error loading nixie file: " << e.what() << '\n';
        return 1;
    }

    std::cout << "Loaded config: " << nixiePath << '\n';

    // 从nixie中获取窗口配置参数
    sol::table windowConfig = nixie["config"]["windows"];
    std::string title = windowConfig["title"].get_or<std::string>("Nixie");
    int width = windowConfig["resolution"]["width"].get_or(800);
    int height = windowConfig["resolution"]["height"].get_or(600);
    int fps = windowConfig["fps"].get_or(60);

    std::cout << "Window config: " << title << " (" << width << "x" << height << ") @ " << fps << " FPS\n";

    // 使用 Raylib 创建窗口
    InitWindow(width, height, title.c_str());
    SetTargetFPS(fps);

    // 主循环
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome to Nixie!", 190, 200, 40, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
