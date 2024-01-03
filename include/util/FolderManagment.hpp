//
// Created by pedro on 25/12/23.
//

#ifndef OPENCV_LEARN_FOLDERMANAGMENT_HPP
#define OPENCV_LEARN_FOLDERMANAGMENT_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <pwd.h>
#include <filesystem>
#include <experimental/filesystem>

class FolderManagment {
public:
    static bool is_develop;
    static std::string get_model_folder();
    static std::string get_img_folder();
    static std::string get_config_file();
    static std::string get_image_ico();
    static std::string get_home_folder();
private:
    static std::string get_develop_folder();
};


#endif //OPENCV_LEARN_FOLDERMANAGMENT_HPP
