//
// Created by pedro on 21/12/23.
//

#ifndef OPENCV_LEARN_CONFIG_HPP
#define OPENCV_LEARN_CONFIG_HPP

#include <string>
#include <fstream>
#include <map>
#include <iostream>

class Config {
public:
    std::map<std::string, std::map<std::string, std::string>> read_config(const std::string& nomeArquivo);
    void edit_config(std::map<std::string, std::map<std::string, std::string>>& configuracao,
                     const std::string& secao, const std::string& chave, const std::string& novoValor);
    void save_config(const std::string& nomeArquivo, const std::map<std::string, std::map<std::string, std::string>>& configuracao);
};


#endif //OPENCV_LEARN_CONFIG_HPP
