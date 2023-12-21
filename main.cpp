#include <gtkmm.h>
#include "gui/MainWindow.h"
#include "options/ReaderFacesInFolder.h++"

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
    // ReaderFacesFolder::ReaderFacesInFolder::read_faces_in_folder(true);
    auto app = Gtk::Application::create(argc, argv, "org.pedro.gtkmm");
    MainWindow mainWindow;
    return app->run(mainWindow);
}