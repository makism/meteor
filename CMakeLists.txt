cmake_minimum_required (VERSION 2.6) 
project (meteor)
set(CMAKE_BUILD_TYPE "Debug")

# configure_file (
#     "${PROJECT_SOURCE_DIR}/src/meteor/Macros.hpp.in"
#     "${PROJECT_SOURCE_DIR}/src/meteor/Macros.hpp"
# )

include_directories (${meteor_SOURCE_DIR}/../
                        ${meteor_SOURCE_DIR}/../headers)

set(source_files
    src/Map.cpp
    src/Node.cpp
)

add_library (Meteor ${LIB_TYPE} ${source_files})
set_target_properties(Meteor PROPERTIES VERSION 0.9.999 SOVERSION 1)
target_link_libraries(Meteor ${LIBS})
