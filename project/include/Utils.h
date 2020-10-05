#ifndef HW_1_UTILS_H
#define HW_1_UTILS_H

#include <string>

namespace HW1 {
    struct ProgramArgs {
        std::string filePath;
        size_t ticketsCount;
        int permutationParam;
    };
    bool parseArgs(int argc, char **argv, struct ProgramArgs &programArgs);
    size_t getTicketNo(std::string studentName, size_t ticketCount, size_t permutationParam);

}  // namespace HW1

#endif  // HW_1_UTILS_H
