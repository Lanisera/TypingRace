cmake_minimum_required(VERSION 3.15)

project(TypingRace)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# sdl2_gfx库未提供cmake文件，需手动获取其动态链接库和头文件
set(SDL2_gfx_LIBRARIES "/usr/lib/libSDL2_gfx.so")
set(SDL2_gfx_INCLUDE_DIRS "/usr/include/SDL2/")

# 寻找sdl链接库
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

set(CLIENT_DIR client)
set(SERVER_DIR server)

add_executable(server
	${SERVER_DIR}/server.cpp
)

add_executable(client
	${CLIENT_DIR}/client.cpp
)

target_include_directories(server PUBLIC
	./include
)

target_include_directories(client PUBLIC
	./include
)
