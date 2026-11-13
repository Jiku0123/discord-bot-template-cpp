cmake_minimum_required(VERSION 3.20)

project(Template LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
    laserpants_dotenv
    GIT_REPOSITORY https://github.com/laserpants/dotenv-cpp.git
    GIT_TAG 9275210b8abf1a551fb81e0ba45866286d764acd
)


FetchContent_MakeAvailable(laserpants_dotenv)
find_package(DPP REQUIRED)

message(STATUS "DPP version: ${DPP_VERSION}")

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/bot.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    dotenv
    dpp::dpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)