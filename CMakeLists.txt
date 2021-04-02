cmake_minimum_required(VERSION 3.12)
#Projektdefinition
set(PROJEKT "PruefungsQuiz")
project("${PROJEKT}" VERSION 1.0.0 LANGUAGES C)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
#Applikation / Exectable definieren
set(MAIN "${PROJEKT}_Executable")

#Libraries definieren
set(_C_MENU_LIB "Hauptmenu")
set(_C_72_GENERATOR "Quiz_Fragen_Gen")
set(_C_72_SAVE_FRAGENKATALOG "Quiz_Fragen_save")
set(_C_INDEX_LIB "Saved_Data_Index")
set(_C_72_LOAD_FRAGENKATALOG "Quiz_Fragen_load")
set(_C_72_START_QUIZ "Quiz_staten")

#Unterverzeichnisse einbinden 
add_subdirectory("${PROJECT_SOURCE_DIR}/cmake/")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/")
add_subdirectory("${PROJECT_SOURCE_DIR}/app/")

