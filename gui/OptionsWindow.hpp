//
// Created by pedro on 21/12/23.
//

#ifndef OPENCV_LEARN_OPTIONSWINDOW_HPP
#define OPENCV_LEARN_OPTIONSWINDOW_HPP

#include <gtkmm.h>
#include <iostream>

class OptionsWindow : public Gtk::Window {
    Gtk::Box m_box;
    Gtk::Label m_label_folder, m_label_model;
    Gtk::Entry m_entry_folder, m_entry_model;
    Gtk::Button m_button_browse_folder, m_button_select_model, m_button_apply;
public:
    OptionsWindow();

private:
    void set_hierarchy();
    void draw_widgets();
    void on_button_browse_folder_clicked();
    void on_button_select_model_clicked();
    void on_button_apply_clicked();


};


#endif //OPENCV_LEARN_OPTIONSWINDOW_HPP
