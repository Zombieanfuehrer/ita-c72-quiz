cmake_minimum_required(VERSION 3.12)
#Projektdefinition
set(PROJEKT "PruefungsQuiz")
project("${PROJEKT}" VERSION 1.0.0 LANGUAGES C)

#Libraries definieren
set(_C_MENU_LIB "Hauptmenu")

#Unterverzeichnisse einbinden 
add_subdirectory("${PROJECT_SOURCE_DIR}/cmake/")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/")
add_subdirectory("${PROJECT_SOURCE_DIR}/app/")