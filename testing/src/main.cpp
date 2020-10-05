#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <TestUtils.h>

#include "Utils.h"

#define TICKET_CNT_10 10
#define TICKET_CNT_20 20
#define TICKET_CNT_5 5
namespace fs = std::experimental::filesystem;
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Требуется указать путь до директории с файлами" << std::endl;
        return 1;
    }
    fs::path testDataDir(argv[1]);
    for (auto &file : fs::directory_iterator(testDataDir)) {
        auto filePath = file.path().string();
        testCase(filePath, TICKET_CNT_5, 11);
        testCase(filePath, TICKET_CNT_10, 20);
        testCase(filePath, TICKET_CNT_20, 777);
    }
    return 0;
}

