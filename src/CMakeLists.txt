###---Version 1.0---DATE-2021-03-12-#########################################
###---Autor---David-A.-Haufe--(david.haufe90@gmail.com)---###################
###---CMakeLists-fuer-eigene-Libraries---####################################

###-----MENUE----------------#####################################
add_library(${_C_MENU_LIB} OBJECT

    "${PROJECT_SOURCE_DIR}/src/menue.c"

)
target_include_directories(${_C_MENU_LIB} PUBLIC

    "${PROJECT_SOURCE_DIR}/include/"
)
###-----SAVE_FAGENKATALOG----------------#########################
add_library(${_C_72_SAVE_FRAGENKATALOG} OBJECT

    "${PROJECT_SOURCE_DIR}/src/save_fragenfeld.c"

)
target_include_directories(${_C_72_SAVE_FRAGENKATALOG} PUBLIC

    "${PROJECT_SOURCE_DIR}/include/"
)
###-----GENERATOR----------------#################################
add_library(${_C_72_GENERATOR} OBJECT

    "${PROJECT_SOURCE_DIR}/src/generator.c"

)
target_include_directories(${_C_72_GENERATOR} PRIVATE

    "${PROJECT_SOURCE_DIR}/include/"
)
target_link_libraries(${_C_72_GENERATOR} PUBLIC

    ${_C_72_SAVE_FRAGENKATALOG}
)


