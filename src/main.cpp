#include <gtkmm.h>
#include "gui/MainWindow.hpp"
#include "util/Config.hpp"
#include "util/FolderManagment.hpp"

#ifdef _WIN32
    #define OS_NAME "Windows"
#elif __linux__
    // Usando a lib GTK-3.0
    #include <gtk-3.0/gtk/gtk.h>
    #define OS_NAME "Linux"
#else
    #error "Sistema operacional não suportado"
#endif

// Obs:
// Next feature: Configura o arquivo de configurações, porem ele faz isso toda hora, a proxima feature deve
// ser feito para alterar apenas uma vez, apenas na primeira execução.
bool FolderManagment::is_develop = true;

int main(int argc, char* argv[]) {
    // TODO: SETAR ISSO DE ACORDO COM OS ARGUMENTOS NA EXECUÇÃO DO PROGRAMA
    Config config;
    std::map<std::string, std::map<std::string, std::string>> config_att = config.read_config(FolderManagment::get_config_file());
    config.edit_config(config_att, "Images", "Folder_path", FolderManagment::get_img_folder());
    config.edit_config(config_att, "Model", "Model_name", FolderManagment::get_model_folder() + "/haarcascade_frontalface_default.xml");
    config.edit_config(config_att, "Model", "Model_name", "haarcascade_frontalface_default.xml");
    config.save_config(FolderManagment::get_config_file(), config_att);

    // ReaderFacesFolder::ReaderFacesInFolder::read_faces_in_folder();

    auto app = Gtk::Application::create(argc, argv, "org.pedro.gtkmm");
    MainWindow mainWindow;
    return app->run(mainWindow);
    return 0;
}