#include <gtkmm.h>
#include "gui/MainWindow.h"
#include "options/ReaderFacesInFolder.h++"
#include "util/Config.hpp"
#include "util/FolderManagment.hpp"
// #include <boost/filesystem.hpp>
// #include <iostream>

#ifdef _WIN32
    #define OS_NAME "Windows"
#elif __linux__
    // Usando a lib GTK-3.0
    #include <gtk-3.0/gtk/gtk.h>
    #define OS_NAME "Linux"
#else
    #error "Sistema operacional não suportado"
#endif

int main(int argc, char* argv[]) {
    Config config;
    // Next feature: Configura o arquivo de configurações, porem ele faz isso toda hora, a proxima feature deve
    // ser feito para alterar apenas uma vez, apenas na primeira execução.

    std::map<std::string, std::map<std::string, std::string>> config_att = config.read_config(FolderManagment::get_config_file());
    config.edit_config(config_att, "Images", "Folder_path", FolderManagment::get_img_folder());
    config.edit_config(config_att, "Model", "Model_name", FolderManagment::get_model_folder() + "/haarcascade_frontalface_default.xml");

    auto app = Gtk::Application::create(argc, argv, "org.pedro.gtkmm");
    MainWindow mainWindow;
    return app->run(mainWindow);
}