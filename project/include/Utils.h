#ifndef HW_1_UTILS_H
#define HW_1_UTILS_H

#include <string>

namespace HW1 {
    /**
     * @brief Хранит переданные при запуске параметры*/
    struct ProgramArgs {
        std::string filePath;  ///< путь до файла со списком студентов
        size_t ticketsCount;   ///< количество билетов
        int permutationParam;  ///< параметр, вляющий на генерацию номера билета
    };
    /**
     * @brief Разбирает аргументы запуска и сохраняет их в programArgs
     * @param argc argc из main'a (количество параметров)
     * @param argv argv из main'a (массив параметров)
     * @param programArgs контейнер для аргументов
     * @throw runtime_error если параметр не распознан
     * */
    void parseArgs(int argc, char **argv, struct ProgramArgs &programArgs);
    /**
     * @brief На основе трех входных параметров определяет номер билета.
     * На деле считает std::hash от строки с тремя параметрами
     * @param studentName имя студента (строка из файла)
     * @param ticketCount количество билетов
     * @param permutationParam параметр влияющий на генерацию
     * @return номер билета
     * */
    size_t getTicketNo(std::string &studentName, size_t ticketCount, int permutationParam);
    /**
     * @brief Читает "список студентов" из файла и определяет "номер билета" для этой строки
     * @param programArgs аргументы запуска
     * @throw runtime_error если файл не открылся
     * */
    void printStudentsTickets(struct ProgramArgs &programArgs);

}  // namespace HW1

#endif  // HW_1_UTILS_H
