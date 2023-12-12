#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include "ReaderFilesInFolder.h"
#include <gtk-2.0/gtk/gtk.h>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::cout << "Major version: " << CV_MAJOR_VERSION << std::endl;
    std::cout << "Minor version: " << CV_MINOR_VERSION << std::endl;
    std::cout << "GTK: " << WITH_GTK << std::endl;

    string folder_img_path = "../img";
    string classifier_path = "../model/haarcascade_frontalface_default.xml";
    auto files = reader_files::ReaderFilesInFolder::read_files_in_folder(folder_img_path);

    auto classifier = new CascadeClassifier();
    classifier->load(classifier_path);

    for(auto& file : files){
        string image_path = folder_img_path + "/";
        image_path.append(file);

        // Carregando a imagem
        Mat img = imread(image_path);

        vector<Rect> detections;
        classifier->detectMultiScale(img, detections);

        for(auto &faces : detections) {
            rectangle(img, faces, cv::Scalar(255, 0, 0), 2);
            // cout << faces << "\n";
        }

        // Especifica a largura máxima desejada para a imagem
        int maxWidth = 500;
        int maxHeight = 1200;

        // Avalia se a escala é necessária
        if (img.cols > maxWidth || img.rows > maxHeight) {
            // Fator de escala para redimensionar a imagem
            double scale = 0.4;
            if (img.cols >= 3024 || img.rows >= 4032)
                scale = 0.2;

            // Calcule as novas dimensões da imagem
            cv::Size newSize(static_cast<int>(img.cols * scale), static_cast<int>(img.rows * scale));

            // Redimensione a imagem
            cv::Mat resizedImage;
            cv::resize(img, resizedImage, newSize);

            cv::imshow("Detections", resizedImage);
            int k = waitKey(0); // Wait for a keystroke in the window
        } else {
            cv::imshow("Detections", img);
            int k = waitKey(0); // Wait for a keystroke in the window
        }
    }

    delete classifier;
    return 0;

}
