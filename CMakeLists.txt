cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CMakeSFMLProject src/main.cpp
        src/Game/Objects/Gameplay/Ball.cpp
        src/Game/Objects/Gameplay/Ball.h
        src/Game/MainScene.cpp
        src/Game/MainScene.h
        src/Game/Objects/Gameplay/Paddle.cpp
        src/Game/Objects/Gameplay/Paddle.h
        src/Common/Player.cpp
        src/Common/Player.h
        src/App.cpp
        src/App.h
        src/Network/NetworkTransformable.cpp
        src/Network/NetworkTransformable.h
        src/Common/Base/Object.cpp
        src/Common/Base/Object.h
        src/Common/Globals.h
        src/Common/Globals.cpp
        src/Common/Systems/Managers/SceneManager.cpp
        src/Common/Systems/Managers/SceneManager.h
        src/Common/Systems/Managers/Base/BaseManager.cpp
        src/Common/Systems/Managers/Base/BaseManager.h
        src/Common/Systems/Managers/Objects/ObjectManager.cpp
        src/Common/Systems/Managers/Objects/ObjectManager.h
        src/Game/Objects/UI/Debug/FPSCounter.cpp
        src/Game/Objects/UI/Debug/FPSCounter.h
        src/Common/Base/UITextElement.cpp
        src/Common/Base/UITextElement.h
        src/Common/Systems/Managers/UI/UIManager.cpp
        src/Common/Systems/Managers/UI/UIManager.h
        src/Game/Objects/UI/Debug/DT.cpp
        src/Game/Objects/UI/Debug/DT.h
        src/Game/Objects/UI/Score/ScoreUi.cpp
        src/Game/Objects/UI/Score/ScoreUi.h
 "src/Network/UDPCommunicator.cpp" "src/Network/UDPCommunicator.h")
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS CMakeSFMLProject)
