//
// Created by pedro on 25/12/23.
//

#include "util/FolderManagment.hpp"

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

    // Organizando apenas para ajudar no desenvolvimento
    if (is_develop) {
        return get_develop_folder();
    } else {
        std::string homeDir = getenv("HOME");
        if (homeDir.empty()) {
            homeDir = getpwuid(getuid())->pw_dir;
        }
        // Nome da pasta oculta
        std::string hiddenFolderName = "Visualisador-Rostos";

        // Caminho completo para a nova pasta oculta
        std::string hiddenFolderPath = homeDir + "/" + hiddenFolderName;
        return hiddenFolderPath;
    }
}

std::string FolderManagment::get_develop_folder() {
    // Obtém o caminho do diretório do executável
    auto currentPath = std::experimental::filesystem::current_path();
    auto projectRootPath = currentPath.parent_path();
    return projectRootPath;
}
