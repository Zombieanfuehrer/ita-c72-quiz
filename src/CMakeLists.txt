###---Version 1.0---DATE-2021-03-12-#########################################
###---Autor---David-A.-Haufe--(david.haufe90@gmail.com)---###################
###---CMakeLists-fuer-eigene-Libraries---####################################

###-----MENUE----------------################################################
add_library(${_C_MENU_LIB} OBJECT

    "${PROJECT_SOURCE_DIR}/src/menue.c"

)
target_include_directories(${_C_MENU_LIB} PUBLIC

    "${PROJECT_SOURCE_DIR}/include/"
)
#---------------------------------------------------------------------------#

###-----Quiz_staten-----------------#########################################
add_library(${_C_72_START_QUIZ} OBJECT

    "${PROJECT_SOURCE_DIR}/src/start_quiz.c"
)
target_include_directories(${_C_72_START_QUIZ} PUBLIC

    "${PROJECT_SOURCE_DIR}/include/"
)
#---------------------------------------------------------------------------#

###-----Saved_Data_Index-----------------####################################
add_library(${_C_INDEX_LIB} OBJECT

    "${PROJECT_SOURCE_DIR}/src/file_index.c"
)
target_include_directories(${_C_INDEX_LIB} PUBLIC

    "${PROJECT_SOURCE_DIR}/include/"
)
#---------------------------------------------------------------------------#

###-----SAVE_FAGENKATALOG----------------####################################
add_library(${_C_72_SAVE_FRAGENKATALOG} OBJECT

    "${PROJECT_SOURCE_DIR}/src/save_fragenfeld.c"

)
target_include_directories(${_C_72_SAVE_FRAGENKATALOG} PUBLIC

    "${PROJECT_SOURCE_DIR}/include/"
)
target_link_libraries(${_C_72_SAVE_FRAGENKATALOG} PUBLIC

    ${_C_INDEX_LIB}
)
#---------------------------------------------------------------------------#

###-----LOAD_FAGENKATALOG----------------####################################
add_library(${_C_72_LOAD_FRAGENKATALOG} OBJECT

    "${PROJECT_SOURCE_DIR}/src/load_fragenfeld.c"

)
target_include_directories(${_C_72_LOAD_FRAGENKATALOG} PUBLIC

    "${PROJECT_SOURCE_DIR}/include/"
)
target_link_libraries(${_C_72_LOAD_FRAGENKATALOG} PUBLIC

    ${_C_INDEX_LIB}
)
#---------------------------------------------------------------------------#

###-----GENERATOR----------------############################################
add_library(${_C_72_GENERATOR} OBJECT

    "${PROJECT_SOURCE_DIR}/src/generator.c"

)
target_include_directories(${_C_72_GENERATOR} PRIVATE

    "${PROJECT_SOURCE_DIR}/include/"
)
target_link_libraries(${_C_72_GENERATOR} PUBLIC

    ${_C_72_SAVE_FRAGENKATALOG}
)
#---------------------------------------------------------------------------#

