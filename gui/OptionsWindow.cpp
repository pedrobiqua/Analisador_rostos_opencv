//
// Created by pedro on 21/12/23.
//

#include "OptionsWindow.hpp"

OptionsWindow::OptionsWindow() : m_box(Gtk::Orientation::ORIENTATION_VERTICAL),
                                 m_label_folder("Pasta de Leitura:"),
                                 m_label_model("Modelo Selecionado:"),
                                 m_button_browse_folder("Procurar..."),
                                 m_button_select_model("Selecionar..."),
                                 m_button_apply("Aplicar")
{
    set_hierarchy();
    draw_widgets();
    show_all_children();
}

void OptionsWindow::set_hierarchy(){
    add(m_box);
    m_box.pack_start(m_label_folder, Gtk::PACK_SHRINK);
    m_box.pack_start(m_entry_folder, Gtk::PACK_EXPAND_WIDGET);
    m_box.pack_start(m_button_browse_folder, Gtk::PACK_SHRINK);
    m_box.pack_start(m_label_model, Gtk::PACK_SHRINK);
    m_box.pack_start(m_entry_model, Gtk::PACK_EXPAND_WIDGET);
    m_box.pack_start(m_button_select_model, Gtk::PACK_SHRINK);
    m_box.pack_start(m_button_apply, Gtk::PACK_SHRINK);

    m_button_browse_folder.signal_clicked().connect(sigc::mem_fun(*this, &OptionsWindow::on_button_browse_folder_clicked));
    m_button_select_model.signal_clicked().connect(sigc::mem_fun(*this, &OptionsWindow::on_button_select_model_clicked));
    m_button_apply.signal_clicked().connect(sigc::mem_fun(*this, &OptionsWindow::on_button_apply_clicked));
}

void OptionsWindow::draw_widgets() {
    set_title("Opções");
    set_default_size(400, 200);
}

void OptionsWindow::on_button_browse_folder_clicked() {
    Gtk::FileChooserDialog dialog("Selecione uma pasta", Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
    dialog.set_transient_for(*this);
    dialog.add_button("_Cancelar", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Selecionar", Gtk::RESPONSE_OK);

    int result = dialog.run();
    if (result == Gtk::RESPONSE_OK)
    {
        m_entry_folder.set_text(dialog.get_filename());
    }
}

void OptionsWindow::on_button_select_model_clicked() {
    std::cout << "Seleção do modelo" << std::endl;
}

void OptionsWindow::on_button_apply_clicked() {
    // Adicione aqui o código para aplicar as opções
    std::cout << "Pasta Selecionada: " << m_entry_folder.get_text() << std::endl;
    std::cout << "Modelo Selecionado: " << m_entry_model.get_text() << std::endl;
}
