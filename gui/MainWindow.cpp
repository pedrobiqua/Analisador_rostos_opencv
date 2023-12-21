//
// Created by pedro on 18/12/23.
//

#include "MainWindow.h"

MainWindow::MainWindow() : m_box{Gtk::Orientation::ORIENTATION_VERTICAL}, m_frame{"Opções"}
{
    set_hierarchy();
    draw_widgets();
    show_all_children();
}

void MainWindow::set_hierarchy() {
    // Window
    add(m_fixed);

    // Fixed
    m_fixed.add(m_frame);
    m_fixed.move(m_frame, 10, 10);

    // Frame
    m_frame.add(m_box);

    // Box
    m_box.pack_start(m_button1, true, true, 0);
    m_box.pack_start(m_button2, true, true, 0);
    m_box.pack_start(m_button3, true, true, 0);
    // Por enquanto não vou usar.
    // m_box.pack_start(m_button4, true, true, 0);

    m_button1.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_read_faces_in_folder));
    m_button2.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_read_face));
    m_button3.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::open_options));
}

void MainWindow::draw_widgets() {
    set_title("Leitor de rostos");
    set_default_size(300, 400);

    const std::string icon_path = "../id-do-rosto.ico";
    set_icon_from_file(icon_path);

    // Fixed
    m_fixed.set_size_request(300, 400);

    // Box
    m_box.set_spacing(10);
    m_box.set_halign(Gtk::ALIGN_CENTER);
    m_box.set_valign(Gtk::ALIGN_CENTER);

    // Frame
    m_frame.set_size_request(280, 280);
    m_frame.set_shadow_type(Gtk::ShadowType::SHADOW_ETCHED_IN);

    // Button 1
    m_button1.set_label("Visualizar imagem de uma pasta");
    m_button1.set_can_focus(false);

    // Button 2
    m_button2.set_label("Visualizar apenas uma imagem");
    m_button2.set_can_focus(false);

    // Button 3
    m_button3.set_label("Opções");
    m_button3.set_can_focus(false);

    // Button 4
    // m_button4.set_label("Botão 4");
    // m_button4.set_can_focus(false);
}

void MainWindow::on_button_read_faces_in_folder() {
    ReaderFacesFolder::ReaderFacesInFolder::read_faces_in_folder(true);
}

void MainWindow::on_button_read_face() {
    std::vector<std::string> image_filters = {"*.png", "*.jpg", "*.jpeg"};
    std::string file_path = open_file_dialog("Selecione um arquivo", Gtk::FILE_CHOOSER_ACTION_OPEN, image_filters);
    if (!file_path.empty()) {
        std::cout << "Arquivo selecionado: " << file_path << std::endl;
        ReaderFacesFolder::ReaderFacesInFolder::read_faces_in_folder(file_path, true);
    }
}

void MainWindow::open_options() {
    m_options_window.show();
}

std::string MainWindow::open_file_dialog(const std::string &title, Gtk::FileChooserAction action, const std::vector<std::string> &image_filters)
{
    Gtk::FileChooserDialog dialog(title, action);
    dialog.set_transient_for(*this);
    dialog.add_button("_Cancelar", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Abrir", Gtk::RESPONSE_OK);

    // Adicionar filtros para arquivos de imagem
    if (!image_filters.empty())
    {
        for (const auto &filter : image_filters)
        {
            auto filter_obj = Gtk::FileFilter::create();
            filter_obj->set_name(filter);
            filter_obj->add_pattern(filter);
            dialog.add_filter(filter_obj);
        }
    }

    int result = dialog.run();
    if (result == Gtk::RESPONSE_OK)
    {
        return dialog.get_filename();
    }

    return ""; // Retorna uma string vazia se a operação for cancelada
}