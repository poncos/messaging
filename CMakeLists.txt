cmake_minimum_required (VERSION 2.6)
project (messaging CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

INCLUDE_DIRECTORIES( "/usr/include/" )
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/../main/cpp/include")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/../../c-commons/main/cpp/include")

#LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/res)
#LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/../../c-commons/build/)

message(PROJECT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_executable(c-commons-message-producer ${PROJECT_BINARY_DIR}/../main/cpp/src/MessageProducer.cpp ${PROJECT_BINARY_DIR}/../main/cpp/src/serialize/SerializeHelper.cpp)

add_executable(c-commons-message-consumer ${PROJECT_BINARY_DIR}/../main/cpp/src/MessageConsumer.cpp )

TARGET_LINK_LIBRARIES( c-commons-message-producer c-commons rt boost_serialization pthread)
TARGET_LINK_LIBRARIES( c-commons-message-consumer c-commons rt )