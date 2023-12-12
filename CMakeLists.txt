cmake_minimum_required(VERSION 3.27)
project(OpenCV_Learn)

set(CMAKE_CXX_STANDARD 17)

# Encontre o pacote OpenCV
find_package(OpenCV REQUIRED)
# Inclua os diretórios de cabeçalho do OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Encontre as bibliotecas GTK+ 2.0
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)
include_directories(${GTK2_INCLUDE_DIRS})

# Adicione a flag para definir WITH_GTK=2.0
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWITH_GTK=2.0")

add_executable(OpenCV_Learn main.cpp
        ReaderFilesInFolder.cpp
        ReaderFilesInFolder.h)

# Vincule o OpenCV ao executável
target_link_libraries(OpenCV_Learn PRIVATE ${GTK2_LIBRARIES} ${OpenCV_LIBS})
message(STATUS "CMake CXX Flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "GTK Include Directories: ${GTK2_INCLUDE_DIRS}")
message(STATUS "GTK Libraries: ${GTK2_LIBRARIES}")