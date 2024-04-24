add_executable(${PROJECT_NAME}-client main.cpp)
target_compile_options(${PROJECT_NAME}-client PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME}-client PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME}-client Qt${QT_VERSION_MAJOR}::Core)