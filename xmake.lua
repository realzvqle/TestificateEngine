set_project("engine")

set_xmakever("2.6.0")



  

target("engine")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("src/*.c")
    add_files("imgui/*.cpp")
    add_includedirs("./include")  
    add_linkdirs("lib")  
    add_links("glfw3dll")  
    --add_ldflags("-llibgcc.a", "-lmingw32.a", "kernel32", "user32", {force = true})
    --add_cflags("-std=c99", "-g")
    -- if is_os("windows") then
    --     add_links("glfw3dll") 
    --     add_links("mingw32", "kernel32", "user32", "version")
    -- else
    --     --add_links("libraylib.a") 
    -- end