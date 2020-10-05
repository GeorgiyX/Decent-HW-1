#include <getopt.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Utils.h"

#define FILE_ARG_RETURN 'f'
#define TICKET_COUNT_ARG_RETURN 'n'
#define PERMUTATION_ARG_RETURN 'p'
#define UNDEFINED_RETURN '?'
#define SHORT_ARGS "f:n:p:"

#define FILE_ARG "file"
#define TICKET_COUNT_ARG "numbilets"
#define PERMUTATION_ARG "parameter"

namespace HW1 {

    void parseArgs(int argc, char **argv, ProgramArgs &programArgs) {
        opterr = 0;
        int retCode;
        option options[] = {{FILE_ARG,         required_argument, nullptr, FILE_ARG_RETURN},
                            {TICKET_COUNT_ARG, required_argument, nullptr, TICKET_COUNT_ARG_RETURN},
                            {PERMUTATION_ARG,  required_argument, nullptr, PERMUTATION_ARG_RETURN},
                            {nullptr, 0,                          nullptr, 0}};
        while ((retCode = getopt_long(argc, argv, SHORT_ARGS, options, nullptr)) != -1) {
            switch (retCode) {
                case FILE_ARG_RETURN:
                    programArgs.filePath = std::string(optarg);
                    break;
                case TICKET_COUNT_ARG_RETURN:
                    programArgs.ticketsCount = std::stoi(optarg);
                    break;
                case PERMUTATION_ARG_RETURN:
                    programArgs.permutationParam = std::stoi(optarg);
                    break;
                case UNDEFINED_RETURN:
                    throw std::runtime_error("Не известный параметр: " + std::string(*(argv + optind - 1)));
                default:
                    break;
            }

        }
    }

    size_t getTicketNo(std::string &studentName, size_t ticketCount, int permutationParam) {
        static std::hash<std::string> hash;
        return hash(studentName + std::to_string(ticketCount) + std::to_string(permutationParam)) % ticketCount;
    }

    void printStudentsTickets(ProgramArgs &programArgs) {
        std::fstream inFile(programArgs.filePath);
        if (!inFile.is_open()) {
            throw std::runtime_error(std::string("Can't open file: ") + programArgs.filePath);
        }
        std::string currentStudent;
        while (std::getline(inFile, currentStudent)) {
            std::cout << currentStudent << " "
                      << getTicketNo(currentStudent, programArgs.ticketsCount, programArgs.permutationParam)
                      << std::endl;
        }
    }

}  // namespace HW1
