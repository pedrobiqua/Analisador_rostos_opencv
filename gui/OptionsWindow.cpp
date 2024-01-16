//
// Created by pedro on 21/12/23.
//

#include "gui/OptionsWindow.hpp"

OptionsWindow::OptionsWindow() : m_box(Gtk::Orientation::ORIENTATION_VERTICAL),
                                 m_label_folder("Pasta de Leitura:"),
                                 m_label_model("Modelo Selecionado:"),
                                 m_button_browse_folder("Procurar..."),
                                 m_button_apply("Aplicar")
{
    set_hierarchy();
    draw_widgets();
    show_all_children();
}

void OptionsWindow::set_hierarchy(){

    // Window
    add(m_fixed);

    // Fixed
    m_fixed.add(m_frame);

    // Frame
    m_frame.add(m_box);

    // Box
    m_box.pack_start(m_label_folder, Gtk::PACK_SHRINK);
    m_box.pack_start(m_entry_folder, Gtk::PACK_EXPAND_WIDGET);
    m_box.pack_start(m_button_browse_folder, Gtk::PACK_SHRINK);

    m_box.pack_start(m_label_model, Gtk::PACK_SHRINK);
    m_box.pack_start(m_combo_model, Gtk::PACK_SHRINK);

    m_box.pack_start(m_button_apply, Gtk::PACK_SHRINK);

    // Posicionamento
    m_fixed.move(m_frame, 10, 10);

    m_button_browse_folder.signal_clicked().connect(sigc::mem_fun(*this, &OptionsWindow::on_button_browse_folder_clicked));
    m_button_apply.signal_clicked().connect(sigc::mem_fun(*this, &OptionsWindow::on_button_apply_clicked));
}

void OptionsWindow::draw_widgets() {
    Config config;
    auto configurations = config.read_config(FolderManagment::get_config_file());

    set_title("Opções");
    set_default_size(600, 400);

    // Frame
    m_frame.set_size_request(580, 380);
    m_frame.set_shadow_type(Gtk::ShadowType::SHADOW_ETCHED_IN);

    // Box
    m_box.set_spacing(10);
    m_box.set_halign(Gtk::ALIGN_CENTER);
    m_box.set_valign(Gtk::ALIGN_CENTER);

    // Entry
    m_entry_folder.set_editable(false);
    m_entry_folder.set_visible(true);
    m_entry_folder.set_can_focus(true);
    // m_entry_folder.set_placeholder_text("Selecione uma pasta");
    m_entry_folder.set_text(configurations["Images"]["Folder_path"]);

    // Combo Model
    m_combo_model.set_visible(true);
    m_combo_model.set_can_focus(true);
    auto model_folder_path = FolderManagment::get_model_folder();
    auto files = reader_files::ReaderFilesInFolder::read_files_in_folder(model_folder_path);
    for(auto& file : files){
        m_combo_model.append(file);
    }

    // Especifica o nome do arquivo que você deseja pré-selecionar
    Glib::ustring file_selected = configurations["Model"]["Model_name"];

    // Procura o índice do arquivo na lista
    int index = -1;
    for (size_t i = 0; i < files.size(); ++i) {
        if (files[i] == file_selected) {
            index = static_cast<int>(i);
            break;
        }
    }

    // Se encontrado, define o índice como ativo
    if (index != -1) {
        m_combo_model.set_active(index);
    }

    // Button Browse Folder
    m_button_browse_folder.set_visible(true);
    m_button_browse_folder.set_can_focus(true);

    // Label Folder
    m_label_folder.set_visible(true);
    m_label_folder.set_can_focus(true);

    // Label Model
    m_label_model.set_visible(true);
    m_label_model.set_can_focus(true);

    // Button Apply
    m_button_apply.set_visible(true);
    m_button_apply.set_can_focus(true);
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

void OptionsWindow::on_button_apply_clicked() {
    Glib::ustring folder_selected = m_entry_folder.get_text();
    Glib::ustring active_text = m_combo_model.get_active_text();

    std::cout << "Pasta Selecionada: " << folder_selected << std::endl;
    std::cout << "Model Selecionado: " << active_text << std::endl;

    if (show_yes_no_dialog("Você deseja continuar?", *this)) {
        std::cout << "Usuário clicou em Sim." << std::endl;
        Config config;
        std::string nomeArquivo = FolderManagment::get_config_file();
        std::map<std::string, std::map<std::string, std::string>> configuracao = config.read_config(nomeArquivo);
        config.edit_config(configuracao, "Images", "Folder_path", folder_selected);
        config.edit_config(configuracao, "Model", "Model_name", active_text);
        config.save_config(nomeArquivo, configuracao);

        close();
    }
}

bool OptionsWindow::show_yes_no_dialog(const Glib::ustring &message, Gtk::Window &parent) {

    Gtk::MessageDialog dialog(message, false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO, true);
    dialog.set_transient_for(parent);

    int result = dialog.run();
    return (result == Gtk::RESPONSE_YES);

}
