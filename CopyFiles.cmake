# CopyFiles.cmake

# Função para copiar os arquivos para o diretório desejado
function(copy_files_to_destination)
    # Obtém o caminho para o diretório home do usuário
    execute_process(
            COMMAND sh -c "echo $HOME"
            OUTPUT_VARIABLE HOME_DIR
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # Nome da pasta oculta
    set(HIDDEN_FOLDER_NAME ".visualisador-rostos")

    # Caminho completo para a nova pasta oculta
    set(HIDDEN_FOLDER_PATH "${HOME_DIR}/${HIDDEN_FOLDER_NAME}")

    # Nomes das subpastas
    set(MODEL_FOLDER "model")
    set(IMG_FOLDER "img")

    # Caminhos completos para as subpastas dentro de .visualisador-rostos
    set(MODEL_FOLDER_PATH "${HIDDEN_FOLDER_PATH}/${MODEL_FOLDER}")
    set(IMG_FOLDER_PATH "${HIDDEN_FOLDER_PATH}/${IMG_FOLDER}")

    # Caminho completo para o arquivo config.ini dentro de .visualisador-rostos
    set(CONFIG_FILE "${HIDDEN_FOLDER_PATH}/config.ini")
    set(IMAGE_FILE "${HIDDEN_FOLDER_PATH}/id-do-rosto.ico")

    # Verifica se a pasta oculta já existe
    file(MAKE_DIRECTORY ${HIDDEN_FOLDER_PATH} EXIST_OK ERROR_VARIABLE MAKE_DIRECTORY_ERROR)

    if (MAKE_DIRECTORY_ERROR)
        message(WARNING "Erro ao criar a pasta oculta: ${MAKE_DIRECTORY_ERROR}")
    else()
        # Copia as pastas 'model' e 'img' para o diretório desejado
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${MODEL_FOLDER} DESTINATION ${HIDDEN_FOLDER_PATH})
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${IMG_FOLDER} DESTINATION ${HIDDEN_FOLDER_PATH})

        # Copia o arquivo config.ini para o diretório desejado
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.ini "${CONFIG_FILE}" COPYONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/id-do-rosto.ico "${IMAGE_FILE}" COPYONLY)

        message(STATUS "Subpastas 'model' e 'img' copiadas para: ${HIDDEN_FOLDER_PATH}")
        message(STATUS "Arquivo 'config.ini' copiado para: ${HIDDEN_FOLDER_PATH}")
        message(STATUS "Arquivo 'id-do-rosto.ico' copiado para: ${HIDDEN_FOLDER_PATH}")
    endif()
endfunction()