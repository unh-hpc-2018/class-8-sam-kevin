
cmake_minimum_required (VERSION 3.1)
project (LinearAlgebra)

set (CMAKE_CXX_STANDARD 11)

add_library(linalg
  vector.cxx vector_dot.cxx vector_add.cxx
  matrix.cxx matrix_vector_mul.cxx matrix_matrix_mul.cxx
  )

add_executable(test_vector_add test_vector_add.cxx)
target_link_libraries(test_vector_add linalg)

add_executable(test_vector_dot test_vector_dot.cxx)
target_link_libraries(test_vector_dot linalg)

add_executable(test_matrix_vector_mul test_matrix_vector_mul.cxx)
target_link_libraries(test_matrix_vector_mul linalg)

add_executable(test_matrix_matrix_mul test_matrix_matrix_mul.cxx)
target_link_libraries(test_matrix_matrix_mul linalg)


