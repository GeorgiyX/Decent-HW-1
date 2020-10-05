#include <iostream>
#include "Utils.h"

int main(int argc, char **argv) {
    try {
        HW1::ProgramArgs programArgs;
        HW1::parseArgs(argc, argv, programArgs);
        HW1::printStudentsTickets(programArgs);
    } catch (std::runtime_error &runtimeError) {
        std::cout << "Error: " << runtimeError.what() << std::endl;
    } catch (...) {
        std::cout << "Some error" << std::endl;
    }
    return 0;
}
