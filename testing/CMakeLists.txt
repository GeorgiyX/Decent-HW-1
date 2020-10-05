include_directories(include ../project/include)
add_executable(hw-1-test src/main.cpp src/TestUtils.cpp ../project/src/Utils.cpp)
target_link_libraries(hw-1-test stdc++fs)