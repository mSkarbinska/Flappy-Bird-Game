#cmake_minimum_required(VERSION 3.16)
#project(untitled)
#
#set(CMAKE_CXX_STANDARD 20)
#
#
##set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
#set(SFML_STATIC_LIBRARIES TRUE)
#add_executable(untitled main.cpp)
#
#set(SFML_ROOT "C:/SFML-2.5.1")
#
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#find_package(SFML 2 REQUIRED graphics network audio window system)
#
#if(SFML_FOUND)
#    include_directories(${SFML_INCLUDE_DIR})
#    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#endif()

cmake_minimum_required(VERSION 3.2)
project(SFMLDemo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Bird.cpp Bird.h Game.cpp Game.h Obstacle.cpp Obstacle.h GameOverView.cpp GameOverView.h)
add_executable(SFMLDemo ${SOURCE_FILES})
set(SFML_ROOT "C:/Users/mskar/CLionProjects/SkarbinskaMagdalena/SFML-2.5.1")
include_directories("../SFML-2.5.1/include")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    target_link_libraries(SFMLDemo ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()