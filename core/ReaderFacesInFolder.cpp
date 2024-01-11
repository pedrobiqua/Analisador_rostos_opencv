//
// Created by pedro on 21/12/23.
//

#include "core/ReaderFacesInFolder.hpp"

namespace ReaderFacesFolder {
    void ReaderFacesInFolder:: read_faces_in_folder(bool debug_mode) {
        bool debugMode = debug_mode;
        Config config;
        auto config_file = FolderManagment::get_config_file();
        std::map<std::string, std::map<std::string, std::string>> readConfig = config.read_config(config_file);
        show_configs_libs(debugMode);

        // Paths
        string folder_img_path = FolderManagment::get_img_folder();
        string classifier_path = FolderManagment::get_model_folder() + "/";

        if (readConfig["Images"]["Folder_path"].find('/') == 0) {
            // Pegando pela raiz do cliente
            folder_img_path = readConfig["Images"]["Folder_path"];
        } else {
            // Apenas o nome da pasta padrão
            folder_img_path = folder_img_path + readConfig["Images"]["Folder_path"];
        }

        if (readConfig["Model"]["Model_name"].empty()){
            classifier_path = classifier_path + readConfig["Model"]["Model_name"];
        } else {
            classifier_path = classifier_path + "haarcascade_frontalface_default.xml";
        }

        /*
         * TODO: TROCAR ISSO, POIS VAMOS IMPLEMENTAR O TENSORFLOW
         *  E SEUS ARQUIVOS (SAVEDMODEL, USAR O MODULO DNN)
         */
        auto files = reader_files::ReaderFilesInFolder::read_files_in_folder(folder_img_path);
        vector<Mat> readedImages;

        // Lendo imagens da pasta
        for(auto& file : files){
            Mat img_detections;
            string image_path = folder_img_path + "/";
            image_path.append(file);
            // Carrega a imagem e faz as detecções
            if (!isSavedfile(readConfig["Model"]["Model_name"])){
                img_detections = detected_images(image_path, classifier_path);
            } else {
                // img_detections = detected_images_tensorflow(image_path, classifier_path);
                cout << "Ainda não foi implementado" << endl;
            }
            readedImages.push_back(img_detections);
        }

        // Mostra as imagens dentro da lista
        for(auto& img : readedImages){
            cv::imshow("Detections", img);
            waitKey(0); // Wait for a keystroke in the window
        }
    }

    void ReaderFacesInFolder:: read_faces_in_folder(const string& path_file, bool debug_mode) {
        // Especifica a largura máxima desejada para a imagem
        // PADRÃO
        Config config;
        auto configurations = config.read_config(FolderManagment::get_config_file());
        bool debugMode = debug_mode;
        show_configs_libs(debugMode);

        string classifier_path = FolderManagment::get_model_folder() + "/";
        if (configurations["Model"]["Model_name"].empty()){
            classifier_path = classifier_path + configurations["Model"]["Model_name"];
        } else {
            classifier_path = classifier_path + "haarcascade_frontalface_default.xml";
        }
        auto img_detection = detected_images(path_file, classifier_path);

        cv::imshow("Detections", img_detection);
        waitKey(0); // Wait for a keystroke in the window
    }

    Mat ReaderFacesInFolder::detected_images(const string& image_path, const string& classifier_path){

        int maxWidth = 500;
        int maxHeight = 1200;
        auto classifier = new CascadeClassifier();
        classifier->load(classifier_path);

        Mat img = cv::imread(image_path);
        vector<Rect> detections;
        classifier->detectMultiScale(img, detections);

        for(auto &faces : detections) {
            rectangle(img, faces, cv::Scalar(255, 0, 0), 2);
        }

        // Avalia se a escala é necessária
        if (img.cols > maxWidth || img.rows > maxHeight) {
            // Fator de escala para redimensionar a imagem
            double scale = 0.4;
            if (img.cols >= 3024 || img.rows >= 4032)
                scale = 0.2;

            // Calcule as novas dimensões da imagem
            cv::Size newSize(static_cast<int>(img.cols * scale), static_cast<int>(img.rows * scale));

            // Redimensione a imagem
            cv::resize(img, img, newSize);
        }
        delete classifier;

        return img;
    }

    // TODO: Estudar mais como funciona a integração do tensorflow com o opencv, pois os input de dados não estavam de acordo
    // Mat ReaderFacesInFolder::detected_images_tensorflow(const string& image_path, const string& savedfile_path){
        // Carregue o modelo SavedModel
        // Obtenha o bitmask dos backends disponíveis

        // Estudar melhor a lib do opencv juntamente com o tensorflow
        // cv::Mat image = cv::imread(image_path);
        /*
        auto net = cv::dnn::readNetFromTensorflow(savedfile_path);
        // Leia uma imagem de entrada
        cv::Mat image = cv::imread(image_path);

        // Pré-processamento da imagem conforme necessário pelo modelo
        cv::Mat blob = cv::dnn::blobFromImage(image, 1.0, cv::Size(300, 300), cv::Scalar(127.5, 127.5, 127.5), true, false);

        // Defina a entrada da rede neural
        net.setInput(blob);

        // Faça a inferência
        cv::Mat detections = net.forward();

        // Itere sobre as detecções e faça algo com os resultados

        for (int i = 0; i < detections.size[2]; ++i) {
            float confidence = detections.at<float>(0, 0, i, 2);
            if (confidence > 0.5) {  // Ajuste o limiar de confiança conforme necessário
                int startX = static_cast<int>(detections.at<float>(0, 0, i, 3) * image.cols);
                int startY = static_cast<int>(detections.at<float>(0, 0, i, 4) * image.rows);
                int endX = static_cast<int>(detections.at<float>(0, 0, i, 5) * image.cols);
                int endY = static_cast<int>(detections.at<float>(0, 0, i, 6) * image.rows);

                cv::rectangle(image, cv::Point(startX, startY), cv::Point(endX, endY), cv::Scalar(0, 255, 0), 2);
            }
        }


        // Mostre a imagem com as detecções
        cv::imshow("Output", image);
        cv::waitKey(0);
        */

        // return image;
    //}

    void ReaderFacesInFolder::show_configs_libs(bool debugMode){
        if(debugMode){
            // Mostra quais configs estão sendo usadas.
            std::cout << "OpenCV version: " << CV_VERSION << std::endl;
            std::cout << "Major version: " << CV_MAJOR_VERSION << std::endl;
            std::cout << "Minor version: " << CV_MINOR_VERSION << std::endl;
        }
    }

    bool ReaderFacesInFolder::isSavedfile(const string& str) {
        // const std::string& extensao
        string extensao = ".pb";
        if (str.length() >= extensao.length()) {
            return (str.compare(str.length() - extensao.length(), extensao.length(), extensao) == 0);
        } else {
            return false;
        }

    }

} // ReaderFacesFolder