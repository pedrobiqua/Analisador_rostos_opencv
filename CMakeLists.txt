cmake_minimum_required(VERSION 3.27)
project(OpenCV_Learn)

set(CMAKE_CXX_STANDARD 17)

# Adiciona as flags de compilação
add_compile_options(-Wall -g -MMD)

# Adiciona a pasta include
include_directories(include)

# Encontre o pacote OpenCV
find_package(OpenCV REQUIRED)
# Inclua os diretórios de cabeçalho do OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Encontre as bibliotecas GTK+ 2.0
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK2_INCLUDE_DIRS})

# Adicione a flag para definir WITH_GTK=2.0
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWITH_GTK=3.0")

# Encontre o pacote GTKmm
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Inclua os diretórios de cabeçalho do GTKmm
include_directories(${GTKMM_INCLUDE_DIRS})

# Defina as flags de compilação apropriadas para o GTKmm
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(OpenCV_Learn src/main.cpp
        util/ReaderFilesInFolder.cpp
        include/util/ReaderFilesInFolder.h
        gui/MainWindow.cpp
        include/gui/MainWindow.hpp
        options/ReaderFacesInFolder.cpp
        include/options/ReaderFacesInFolder.hpp
        gui/OptionsWindow.cpp
        include/gui/OptionsWindow.hpp
        util/Config.cpp
        include/util/Config.hpp
        util/FolderManagment.cpp
        include/util/FolderManagment.hpp
)

# Vincule o OpenCV ao executável
target_link_libraries(OpenCV_Learn PRIVATE ${GTK3_LIBRARIES} ${OpenCV_LIBS} ${GTKMM_LIBRARIES} stdc++fs)

# target_link_libraries(OpenCV_Learn PRIVATE ${OpenCV_LIBS} ${GTKMM_LIBRARIES})
message(STATUS "CMake CXX Flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "GTK Include Directories: ${GTK2_INCLUDE_DIRS}")
message(STATUS "GTK Libraries: ${GTK2_LIBRARIES}")