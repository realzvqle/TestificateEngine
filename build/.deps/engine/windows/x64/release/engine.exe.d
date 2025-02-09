{
    files = {
        [[build\.objs\engine\windows\x64\release\src\main.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\src\window.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\imgui\imgui.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\imgui\imgui_demo.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\imgui\imgui_draw.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\imgui\imgui_impl_glfw.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\imgui\imgui_impl_opengl3.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\imgui\imgui_tables.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\imgui\imgui_widgets.cpp.obj]],
        [[build\.objs\engine\windows\x64\release\src\glad.c.obj]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            "-libpath:lib",
            "glfw3dll.lib"
        }
    }
}