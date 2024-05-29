cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Fetch Boost
FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.85.0
)
FetchContent_MakeAvailable(boost)

# Add Boost modules
FetchContent_Declare(
        boost_uuid
        GIT_REPOSITORY https://github.com/boostorg/uuid.git
        GIT_TAG boost-1.85.0
)
FetchContent_MakeAvailable(boost_uuid)

FetchContent_Declare(
        boost_system
        GIT_REPOSITORY https://github.com/boostorg/system.git
        GIT_TAG boost-1.85.0
)
FetchContent_MakeAvailable(boost_system)

# Add Boost include directories
include_directories(${boost_SOURCE_DIR})
include_directories(${boost_uuid_SOURCE_DIR}/include)
include_directories(${boost_system_SOURCE_DIR}/include)

# Add Boost libraries
add_library(boost_uuid INTERFACE)
add_library(boost_system INTERFACE)
add_library(boost INTERFACE)
target_link_libraries(boost INTERFACE boost_uuid boost_system)

add_executable(CMakeSFMLProject src/main.cpp
        src/Game/Objects/Gameplay/Ball.cpp
        src/Game/Objects/Gameplay/Ball.h
        src/Game/MainScene.cpp
        src/Game/MainScene.h
        src/Game/Objects/Gameplay/Paddle.cpp
        src/Game/Objects/Gameplay/Paddle.h
        src/Common/Player.cpp
        src/Common/Player.h
        src/AppServer.cpp
        src/AppServer.h
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
 "src/Network/UDPCommunicator.cpp" "src/Network/UDPCommunicator.h"
        src/Game/Objects/UI/Debug/DTFixedTime.cpp
        src/Game/Objects/UI/Debug/DTFixedTime.h
 "src/Network/MainNetwork.h" "src/Network/MainNetwork.cpp"
        src/AppClient.cpp
        src/AppClient.h
        src/Common/Systems/Managers/Network/NetworkManager.cpp
        src/Common/Systems/Managers/Network/NetworkManager.h
        src/Common/Base/NetworkObject.cpp
        src/Common/Base/NetworkObject.h
        src/Common/Systems/NetPacket.h
        src/Common/Systems/PacketType.h)

# Link SFML and Boost libraries
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics boost)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS CMakeSFMLProject)
