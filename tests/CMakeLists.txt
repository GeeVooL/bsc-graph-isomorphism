find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(GraphIsomorphismTests test_main.cc GraphIsomorphismTests.cc ${PROJECT_SOURCE_DIR}/src/Graph.cc)
target_link_libraries(GraphIsomorphismTests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(boostUnitTestsRun GraphIsomorphismTests)

if (CMAKE_CONFIGURATION_TYPES)
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
            --force-new-ctest-process --output-on-failure
            --build-config "$<CONFIGURATION>"
            DEPENDS GraphIsomorphismTests)
else()
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
            --force-new-ctest-process --output-on-failure
            DEPENDS GraphIsomorphismTests)
endif()