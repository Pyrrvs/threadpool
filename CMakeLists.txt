cmake_minimum_required(VERSION 2.6)
project(Thread)

SET(Thread_SOURCES src/WinThread.cpp src/UnixThread.cpp src/UnixMutex.cpp src/ScopedLock.cpp
src/UnixCondVar.cpp src/Worker.cpp src/ThreadPool.cpp src/WinCriticalSection.cpp src/WinCondVar.cpp)

SET(Thread_HEADERS src/WinThread.hpp src/UnixThread.hpp src/Thread.hpp src/ILock.hpp src/UnixMutex.hpp
src/ScopedLock.hpp src/ICondVar.hpp src/UnixCondVar.hpp src/ASafeContainer.hpp src/ASafeStlContainer.hpp
src/ITask.hpp src/Worker.hpp src/ThreadPool.hpp src/WinCriticalSection.hpp src/AbstractThread.hpp
src/WinCondVar.hpp)

ADD_LIBRARY(Thread STATIC ${Thread_SOURCES} ${Thread_HEADERS})

IF("${CMAKE_SYSTEM}" MATCHES "Darwin")
	TARGET_LINK_LIBRARIES(Thread pthread)
ENDIF("${CMAKE_SYSTEM}" MATCHES "Darwin")

IF("${CMAKE_SYSTEM}" MATCHES "Unix")
	TARGET_LINK_LIBRARIES(Thread pthread)
ENDIF("${CMAKE_SYSTEM}" MATCHES "Unix")
