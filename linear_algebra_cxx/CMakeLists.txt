
cmake_minimum_required (VERSION 3.1)
project (LinearAlgebra)

set (CMAKE_CXX_STANDARD 11)

add_library(linalg
  vector.c vector_dot.c vector_add.c
  matrix.c matrix_vector_mul.c matrix_matrix_mul.c
  )

add_executable(test_vector_add test_vector_add.c)
target_link_libraries(test_vector_add linalg)

add_executable(test_vector_dot test_vector_dot.c)
target_link_libraries(test_vector_dot linalg)

add_executable(test_matrix_vector_mul test_matrix_vector_mul.c)
target_link_libraries(test_matrix_vector_mul linalg)

add_executable(test_matrix_matrix_mul test_matrix_matrix_mul.c)
target_link_libraries(test_matrix_matrix_mul linalg)


