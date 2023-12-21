//
// Created by pedro on 21/12/23.
//

#include "Config.hpp"

std::map<std::string, std::map<std::string, std::string>> Config::read_config(const std::string& nomeArquivo) {
    std::map<std::string, std::map<std::string, std::string>> configuracao;
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de configuracao." << std::endl;
        return configuracao;
    }

    std::string linha;
    std::string secaoAtual;

    while (std::getline(arquivo, linha)) {
        if (linha.empty() || linha[0] == ';') {
            // Linha vazia ou comentário (início com ';')
            continue;
        }

        if (linha[0] == '[' && linha.back() == ']') {
            // Nova seção
            secaoAtual = linha.substr(1, linha.size() - 2);
            continue;
        }

        size_t posSeparador = linha.find('=');
        if (posSeparador != std::string::npos) {
            // Chave e valor
            std::string chave = linha.substr(0, posSeparador);
            std::string valor = linha.substr(posSeparador + 1);
            configuracao[secaoAtual][chave] = valor;
        }
    }

    arquivo.close();
    return configuracao;
}

void Config::edit_config(std::map<std::string, std::map<std::string, std::string>>& configuracao,
                         const std::string& secao, const std::string& chave, const std::string& novoValor) {
    configuracao[secao][chave] = novoValor;
}

void Config::save_config(const std::string& nomeArquivo, const std::map<std::string, std::map<std::string, std::string>>& configuracao) {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de configuracao para escrita." << std::endl;
        return;
    }

    for (const auto& secao : configuracao) {
        arquivo << "[" << secao.first << "]\n";

        for (const auto& par : secao.second) {
            arquivo << par.first << "=" << par.second << "\n";
        }

        arquivo << "\n";
    }

    arquivo.close();
}


