
set(TARGET_NAME Matrix)

set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src/${TARGET_NAME})
set(INCLUDE_DIR_ROOT ${CMAKE_CURRENT_LIST_DIR}/src)


# Source Files
set(SOURCE_FILES
    ${SRC_DIR}/Matrix.hpp
    ${SRC_DIR}/Matrix.cpp
    #...
)

# Create the target (alias target for referencing in other parts of the project)
add_library(${TARGET_NAME} STATIC ${SOURCE_FILES})
add_library(${CMAKE_PROJECT_NAME}::${TARGET_NAME} ALIAS ${TARGET_NAME})



#######################################################################################################################
# Target's own include directories
# Separate Header Placement
#######################################################################################################################
target_include_directories(${TARGET_NAME} PUBLIC
                           $<BUILD_INTERFACE:${INCLUDE_DIR_ROOT}>
                           $<INSTALL_INTERFACE:src>)
#######################################################################################################################


#######################################################################################################################
# Targets Dependencies
#######################################################################################################################
# ...
#######################################################################################################################
