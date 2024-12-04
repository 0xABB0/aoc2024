add_rules("mode.debug", "mode.release")

set_languages("c++23")
set_default(false)

set_toolchains("clang")

includes("./*/xmake.lua")