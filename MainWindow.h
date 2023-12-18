//
// Created by pedro on 18/12/23.
//

#ifndef OPENCV_LEARN_MAINWINDOW_H
#define OPENCV_LEARN_MAINWINDOW_H

#include <gtkmm.h>
#include <iostream>

class MainWindow : public Gtk::Window {
    Gtk::Fixed m_fixed;
    Gtk::Box m_box;
    Gtk::Button m_button1, m_button2, m_button3;
    Gtk::Frame m_frame;
    Gtk::LinkButton m_link_button;

public:
    MainWindow();
    // ~MainWindow() override;
    void set_hierarchy();
    void draw_widgets();

protected:
    void on_button_read_faces_in_folder();
    void on_button_read_face();
    void options();

};


#endif //OPENCV_LEARN_MAINWINDOW_H
