include_directories(include ../project/include)
add_executable(hw1-test src/main.cpp src/TestUtils.cpp ../project/src/Utils.cpp)
target_link_libraries(hw1-test stdc++fs)