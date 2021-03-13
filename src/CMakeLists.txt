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
