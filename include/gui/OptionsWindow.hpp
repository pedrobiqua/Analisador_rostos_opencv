//
// Created by pedro on 21/12/23.
//

#ifndef OPENCV_LEARN_OPTIONSWINDOW_HPP
#define OPENCV_LEARN_OPTIONSWINDOW_HPP

#include <gtkmm.h>
#include <iostream>
#include "util/ReaderFilesInFolder.h"
#include "util/Config.hpp"
#include "util/FolderManagment.hpp"

class OptionsWindow : public Gtk::Window {
    Gtk::Fixed m_fixed;
    Gtk::Frame m_frame;
    Gtk::Box m_box;
    Gtk::Label m_label_folder, m_label_model;
    Gtk::Entry m_entry_folder;
    Gtk::ComboBoxText m_combo_model;
    Gtk::Button m_button_browse_folder, m_button_apply;

public:
    OptionsWindow();

private:
    void set_hierarchy();
    void draw_widgets();
    void on_button_browse_folder_clicked();
    void on_button_apply_clicked();
    bool show_yes_no_dialog(const Glib::ustring& message, Gtk::Window& parent);


};


#endif //OPENCV_LEARN_OPTIONSWINDOW_HPP
