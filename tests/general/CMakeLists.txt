project(fclib_gtest)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c*" "*.h") 
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC 
  gtest_main  
  fclib
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Tests")  
install(TARGETS ${PROJECT_NAME} CONFIGURATIONS ${CMAKE_BUILD_TYPE} RUNTIME DESTINATION ${NF_INSTALL_DIR_BIN})
