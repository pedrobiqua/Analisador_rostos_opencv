//
// Created by pedro on 12/12/23.
//

#include "util/ReaderFilesInFolder.h"

namespace reader_files {
    std::vector<std::string> ReaderFilesInFolder::read_files_in_folder(const std::string &folder_path) {

        vector<string> files_in_folder_img = {};
        // Leitura da pasta onde está as imagens
        try {
            // Itera sobre todos os arquivos no diretório
            for (const auto& entry : fs::directory_iterator(folder_path)) {
                // Obtém o nome do arquivo a partir do caminho completo
                string filename = entry.path().filename().string();
                files_in_folder_img.push_back(filename);
            }
            return files_in_folder_img;
        } catch (const std::exception& e) {
            std::cerr << "Erro ao acessar a pasta: " << e.what() << std::endl;
            return files_in_folder_img;
        }
    }
} // reader_files