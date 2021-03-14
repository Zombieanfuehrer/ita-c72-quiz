###---Version 1.0---DATE-2021-03-12-#########################################
###---Autor---David-A.-Haufe--(david.haufe90@gmail.com)---###################
###---CMakeLists-fuer-PruefungsQuiz-Applikation-C72--########################

###-----Ausfuehrbare Datei erstellen----------------#########################
add_executable(${MAIN} 

    "${PROJECT_SOURCE_DIR}/app/main.c" 
   
)
target_link_libraries(
    ${MAIN} PRIVATE 
        ${_C_MENU_LIB}
        ${_C_72_GENERATOR}

)
#---------------------------------------------------------------------------#