cmake_minimum_required(VERSION 3.14...3.28)

project(
  HotReloadRaylib
  VERSION 0.1
  DESCRIPTION "Demos hot-reloading of gamecode in raylib"
  LANGUAGES C)


include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
set(BUILD_SHARED_LIBS ON)

FetchContent_MakeAvailable(raylib)

add_library(gamecode MODULE src/game.c src/game.h)
target_link_libraries(gamecode raylib)

add_executable(mygame src/mygame.c src/reload.c)
target_link_libraries(mygame raylib)
