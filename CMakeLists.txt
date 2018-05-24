cmake_minimum_required(VERSION 2.8.3)
project(dependency_solver)

include_directories(include 
                    ${Boost_INCLUDE_DIRS})

find_package(Boost COMPONENTS graph)

# sources of libdependeny_solver
set(LIB_DEPENDENCY_SOLVER_SOURCES
    src/dependency_solver.cpp)
set(LIB_DEPENDENCY_SOLVER_HEADERS
    include/dependency_solver.h)

# sources of dependeny_solver_test
set(DEPENDENCY_SOLVER_TEST_SOURCES
    src/dependency_solver_test.cpp
    )
add_library(dependency_solver
  ${LIB_DEPENDENCY_SOLVER_SOURCES}
  ${LIB_DEPENDENCY_SOLVER_HEADERS}
)

add_executable(dependency_solver_test 
  ${DEPENDENCY_SOLVER_TEST_SOURCES})

target_link_libraries(dependency_solver
  ${Boost_LIBRARIES}
)

target_link_libraries(dependency_solver_test
  dependency_solver
  ${Boost_LIBRARIES}
)