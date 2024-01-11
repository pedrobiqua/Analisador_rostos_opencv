//
// Created by pedro on 21/12/23.
//

#ifndef OPENCV_LEARN_READERFACESINFOLDER_HPP
#define OPENCV_LEARN_READERFACESINFOLDER_HPP

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/dnn/dnn.hpp>
#include "util/ReaderFilesInFolder.h"
#include "util/Config.hpp"
#include "util/FolderManagment.hpp"

using namespace cv;
using namespace std;
namespace fs = std::filesystem;
namespace ReaderFacesFolder {

    class ReaderFacesInFolder {
    public:
        static void read_faces_in_folder(bool debug_mode = false);
        static void read_faces_in_folder(const string& path_file, bool debug_mode = false);
    private:
        static Mat detected_images(const string& image_path, const string& classifier_path);
        // static Mat detected_images_tensorflow(const string& image_path, const string& savedfile_path);
        static void show_configs_libs(bool debugMode);
        static bool isSavedfile(const string& str);
    };

} // ReaderFacesFolder

#endif //OPENCV_LEARN_READERFACESINFOLDER_HPP
