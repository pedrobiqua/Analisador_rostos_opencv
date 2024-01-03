//
// Created by pedro on 12/12/23.
//

#ifndef OPENCV_LEARN_READERFILESINFOLDER_H
#define OPENCV_LEARN_READERFILESINFOLDER_H

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

namespace reader_files {

    class ReaderFilesInFolder {
    public:
        static std::vector<std::string> read_files_in_folder(const std::string& folder_path);
    };

} // reader_files

#endif //OPENCV_LEARN_READERFILESINFOLDER_H
