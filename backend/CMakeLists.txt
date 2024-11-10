cmake_minimum_required(VERSION 3.0.0)
project(amep VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party_libraries")

include_directories(
    "${THIRD_PARTY_DIR}/nlohmann"
    "${THIRD_PARTY_DIR}/httplib"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

#nlohmann
file( GLOB NLOHMANN_SOURCE
    ${THIRD_PARTY_DIR}/nlohmann/nlohmann/*cpp
    ${THIRD_PARTY_DIR}/nlohmann/nlohmann/*hpp
)

#httplib
file( GLOB HTTPLIB_SOURCE
    ${THIRD_PARTY_DIR}/httplib/httplib.h
)

#main
file( GLOB MAIN_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)


add_executable(amep 
    ${NLOHMANN_SOURCE} 
    ${HTTPLIB_SOURCE}
    ${MAIN_SOURCE} 
)

target_link_libraries(amep PRIVATE -Wall -lmysqlcppconn -fstack-protector -fstack-protector-all)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
