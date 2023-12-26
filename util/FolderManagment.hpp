//
// Created by pedro on 25/12/23.
//

#ifndef OPENCV_LEARN_FOLDERMANAGMENT_HPP
#define OPENCV_LEARN_FOLDERMANAGMENT_HPP

#include <string>
#include <unistd.h>
#include <pwd.h>


class FolderManagment {
public:
    static std::string get_model_folder();
    static std::string get_img_folder();
    static std::string get_config_file();
    static std::string get_home_folder();
};


#endif //OPENCV_LEARN_FOLDERMANAGMENT_HPP
