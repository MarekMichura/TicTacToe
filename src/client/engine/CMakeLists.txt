target_include_directories(${PROJECT_NAME}-Client PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_sources(${PROJECT_NAME}-Client PRIVATE "${CMAKE_CURRENT_LIST_DIR}/engine.cpp")
target_sources(${PROJECT_NAME}-Client PRIVATE "${CMAKE_CURRENT_LIST_DIR}/engineParam.h")
