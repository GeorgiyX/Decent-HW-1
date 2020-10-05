#include <fstream>
#include <iostream>
#include <vector>
#include "TestUtils.h"

size_t assignTickets(std::vector<size_t> &arr, std::string &path, size_t ticketCount, int param) {
    std::fstream inFile(path);
    std::string row;
    size_t rowCount = 0;
    while (std::getline(inFile, row)) {
        arr[HW1::getTicketNo(row, ticketCount, param)] +=1;
        rowCount++;
    }
    return rowCount;
}

void testCase(std::string &fileCasePath, size_t ticketCount, int param) {
    std::cout << "\n\nTESTING: " << fileCasePath << " Ticket count: " << ticketCount << " Param: " << param << std::endl;
    std::vector<size_t> ticketDistribution(ticketCount);
    auto rowCount = assignTickets(ticketDistribution, fileCasePath, ticketCount, param);
    std::cout << "Ticket " << "\tCount" << "\tPercent" << std::endl;
    for (size_t ticketNo = 0; ticketNo < ticketCount; ticketNo++) {
        std::cout << ticketNo << "\t\t" << ticketDistribution[ticketNo] << "\t\t"
                  << static_cast<double>(ticketDistribution[ticketNo] * 100) / rowCount << std::endl;
    }
    std::cout << "Total row: " << rowCount << std::endl;
}
