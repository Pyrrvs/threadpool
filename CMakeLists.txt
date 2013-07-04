cmake_minimum_required(VERSION 2.6)
project(ThreadPool)

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++0x -g3")

SET(ThreadPool_SOURCES src/WinThread.cpp src/UnixThread.cpp src/UnixMutex.cpp src/ScopedLock.cpp
src/UnixCondVar.cpp src/Worker.cpp src/ThreadPool.cpp src/WinCriticalSection.cpp src/WinCondVar.cpp)

SET(ThreadPool_HEADERS src/WinThread.hpp src/UnixThread.hpp src/Thread.hpp src/ILock.hpp src/UnixMutex.hpp
src/ScopedLock.hpp src/ICondVar.hpp src/UnixCondVar.hpp src/ASafeContainer.hpp src/ASafeStlContainer.hpp
src/ITask.hpp src/Worker.hpp src/ThreadPool.hpp src/WinCriticalSection.hpp src/AbstractThread.hpp
src/WinCondVar.hpp)

ADD_LIBRARY(ThreadPool SHARED ${ThreadPool_SOURCES} ${ThreadPool_HEADERS})


ADD_EXECUTABLE(ThreadPoolTest src/main.cpp)
TARGET_LINK_LIBRARIES(ThreadPoolTest ThreadPool)
IF("${CMAKE_SYSTEM_NAME}" MATCHES "Unix" 
    OR "${CMAKE_SYSTEM_NAME}" MATCHES "Linux" 
    OR "${CMAKE_SYSTEM_NAME}" MATCHES "Darwin")
  TARGET_LINK_LIBRARIES(ThreadPoolTest pthread)
ENDIF("${CMAKE_SYSTEM_NAME}" MATCHES "Unix" 
    OR "${CMAKE_SYSTEM_NAME}" MATCHES "Linux" 
    OR "${CMAKE_SYSTEM_NAME}" MATCHES "Darwin")
