#include <getopt.h>
#include <iostream>
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

    bool parseArgs(int argc, char **argv, ProgramArgs &programArgs) {
        opterr = 0;
        bool isError = false;
        int retCode = 0;
        option options[] = {{FILE_ARG,         required_argument, nullptr, FILE_ARG_RETURN},
                            {TICKET_COUNT_ARG, required_argument, nullptr, TICKET_COUNT_ARG_RETURN},
                            {PERMUTATION_ARG,  required_argument, nullptr, PERMUTATION_ARG_RETURN},
                            {nullptr,   0,          nullptr, 0}};
        while ((retCode = getopt_long(argc, argv, SHORT_ARGS, options, nullptr)) != -1 && !isError) {
            switch (retCode) {
                case FILE_ARG_RETURN:
                    std::cout << "file: " << optarg << std::endl;
                    break;
                case TICKET_COUNT_ARG_RETURN:
                    std::cout << "ticket cnt: " << optarg << std::endl;
                    break;
                case PERMUTATION_ARG_RETURN:
                    std::cout << "permutation: " << optarg << std::endl;
                    break;
                case UNDEFINED_RETURN:
                    std::cout << "Не известный параметр: " << *(argv + optind - 1) << std::endl;
                    isError = true;
                    break;
                default:
                    break;
            }

        }
        return isError;
    }
}  // namespace HW1
