//
// Created by pedro on 21/12/23.
//

#include "ReaderFacesInFolder.h++"

namespace ReaderFacesFolder {
    void ReaderFacesInFolder:: read_faces_in_folder(bool debug_mode) {
        // Especifica a largura máxima desejada para a imagem
        // PADRÃO
        int maxWidth = 500;
        int maxHeight = 1200;

        string folder_img_path = "../img";
        string classifier_path = "../model/haarcascade_frontalface_default.xml";
        bool debugMode = debug_mode;

        if(debugMode){
            // Mostra quais configs estão sendo usadas.
            std::cout << "OpenCV version: " << CV_VERSION << std::endl;
            std::cout << "Major version: " << CV_MAJOR_VERSION << std::endl;
            std::cout << "Minor version: " << CV_MINOR_VERSION << std::endl;
            // Por enquanto só no linux
            // if (strcmp(OS_NAME, "Linux") == 0)
            //     std::cout << "GTK: " << WITH_GTK << std::endl;
        }

        auto files = reader_files::ReaderFilesInFolder::read_files_in_folder(folder_img_path);
        auto classifier = new CascadeClassifier();
        classifier->load(classifier_path);
        vector<Mat> readed_images;

        // Fazendo a leitura das imagens
        for(auto& file : files){
            string image_path = folder_img_path + "/";
            image_path.append(file);

            // Carregar a imagem
            Mat img = cv::imread(image_path);

            vector<Rect> detections;
            // classifier->detectMultiScale(img, detections);
            classifier->detectMultiScale(img, detections);

            for(auto &faces : detections) {
                // rectangle(img, faces, cv::Scalar(255, 0, 0), 2);
                rectangle(img, faces, cv::Scalar(255, 0, 0), 2);
                if(debugMode) cout << faces << "\n";
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
                // cv::Mat* resizedImage;
                cv::resize(img, img, newSize);
            }
            readed_images.push_back(img);
        }

        // Mostra as imagens
        for(auto& img : readed_images){
            cv::imshow("Detections", img);
            waitKey(0); // Wait for a keystroke in the window
        }

        delete classifier;
    }

    void ReaderFacesInFolder:: read_faces_in_folder(const string& path_file, bool debug_mode) {
        // Especifica a largura máxima desejada para a imagem
        // PADRÃO
        int maxWidth = 500;
        int maxHeight = 1200;
        bool debugMode = debug_mode;
        string path_file_img = path_file;
        string classifier_path = "../model/haarcascade_frontalface_default.xml";

        if(debugMode){
            // Mostra quais configs estão sendo usadas.
            std::cout << "OpenCV version: " << CV_VERSION << std::endl;
            std::cout << "Major version: " << CV_MAJOR_VERSION << std::endl;
            std::cout << "Minor version: " << CV_MINOR_VERSION << std::endl;
            // Por enquanto só no linux
            // if (strcmp(OS_NAME, "Linux") == 0)
            //     std::cout << "GTK: " << WITH_GTK << std::endl;
        }

        auto classifier = new CascadeClassifier();
        classifier->load(classifier_path);
        vector<Mat> readed_images;

        // Fazendo a leitura da imagem
        // Carregar a imagem
        Mat img = cv::imread(path_file_img);

        vector<Rect> detections;
        // classifier->detectMultiScale(img, detections);
        classifier->detectMultiScale(img, detections);

        for(auto &faces : detections) {
            // rectangle(img, faces, cv::Scalar(255, 0, 0), 2);
            rectangle(img, faces, cv::Scalar(255, 0, 0), 2);
            if(debugMode) cout << faces << "\n";
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
            // cv::Mat* resizedImage;
            cv::resize(img, img, newSize);
        }


        cv::imshow("Detections", img);
        waitKey(0); // Wait for a keystroke in the window


        delete classifier;
    }
} // ReaderFacesFolder