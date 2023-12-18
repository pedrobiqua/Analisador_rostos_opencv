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
}

void MainWindow::draw_widgets() {
    set_title("Leitor de rostos");
    set_default_size(300, 400);

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
