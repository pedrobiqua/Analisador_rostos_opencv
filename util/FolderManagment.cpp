//
// Created by pedro on 25/12/23.
//

#include "FolderManagment.hpp"

std::string FolderManagment::get_model_folder() {
    auto home_folder = get_home_folder();
    return home_folder + "/model";
}

std::string FolderManagment::get_img_folder() {
    auto home_folder = get_home_folder();
    return home_folder + "/img";
}

std::string FolderManagment::get_config_file() {
    auto home_folder = get_home_folder();
    return home_folder + "/config.ini";
}

std::string FolderManagment::get_image_ico() {
    auto home_folder = get_home_folder();
    return home_folder + "/id-do-rosto.ico";
}

std::string FolderManagment::get_home_folder() {
    std::string homeDir = getenv("HOME");

    if (homeDir.empty()) {
        homeDir = getpwuid(getuid())->pw_dir;
    }

    // Nome da pasta oculta
    std::string hiddenFolderName = ".visualisador-rostos";

    // Caminho completo para a nova pasta oculta
    std::string hiddenFolderPath = homeDir + "/" + hiddenFolderName;
    return hiddenFolderPath;
}
