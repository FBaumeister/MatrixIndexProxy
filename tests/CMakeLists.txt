# Add tests to build


add_executable(Matrix_Tests
    mat_access_test.cpp
)

target_link_libraries(Matrix_Tests PUBLIC GTest::gtest_main GTest::gtest)
target_link_libraries(Matrix_Tests PUBLIC TemplatedMatrix::Matrix)

add_test(NAME Matrix_Tests COMMAND Matrix_Tests)
