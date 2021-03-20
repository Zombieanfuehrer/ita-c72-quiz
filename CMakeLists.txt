cmake_minimum_required(VERSION 3.12)
#Projektdefinition
set(PROJEKT "PruefungsQuiz")
project("${PROJEKT}" VERSION 1.0.0 LANGUAGES C)

#Applikation / Exectable definieren
set(MAIN "${PROJEKT}_Executable")

#Libraries definieren
set(_C_MENU_LIB "Hauptmenu")
set(_C_72_GENERATOR "Quiz_Fragen_Gen")
set(_C_72_SAVE_FRAGENKATALOG "Quiz_Fragen_save")

#Unterverzeichnisse einbinden 
add_subdirectory("${PROJECT_SOURCE_DIR}/cmake/")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/")
add_subdirectory("${PROJECT_SOURCE_DIR}/app/")