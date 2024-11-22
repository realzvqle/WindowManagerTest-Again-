set_project("zivic")

set_xmakever("2.6.0")

set_languages("c99")

target("zivic")
    set_kind("binary")  
    add_files("src/*.c")
    add_files("src/**/*.c") 
    add_includedirs("src") 
    add_linkdirs("lib") 

    if is_os("windows") then
        add_links("raylibdll", "raylib") 
        add_syslinks("gdi32", "winmm") 
    else
        add_links("libraylib.a") 
    end