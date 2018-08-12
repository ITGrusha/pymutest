/*
 * Copyright (C) 2018 Nikita S., All Rights Reserved
 * https://github.com/Nekit10/pymutest/
 *
 * This file is part of pymutest.
 *
 * Pymutest is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Pymutest is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Pymutest.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <cstring>
#include <experimental/filesystem>
#include "include/sourceparser.h"

void printHelp(const std::string &command) {
    std::cout << "usage: " << command << " [-h] test_dir source_dir" << std::endl;
    std::cout << std::endl << "Mutation testing for python programs." << std::endl;
    std::cout << std::endl << "positional arguments:" << std::endl << "tests_dir   folder with unit tests" << std::endl;
    std::cout << "source_dir  folder with source code" << std::endl;
    std::cout << std::endl << "optional arguments:" << std::endl << "-h, --help  show this help message and exit" << std::endl;
}

int main(int argc, char** argv) {
    std::string command = argv[0];
    if (argc == 1)
        std::cout << "Specify arguments. For more information: " << command << " --help" << std::endl;
    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        printHelp(command);
    else if (argc == 2)
        std::cout << "Specify source dir. For more information: " << command << " --help" << std::endl;
    else {
        if (strstr(argv[1], argv[2]) == nullptr) {
            std::cout << "Your project is not compatible. Pymutest supports only projects where tests dir is inside source dir." << std::endl;
            exit(0);
        }

        std::string sourceRoot = std::experimental::filesystem::temp_directory_path().string() + "/source/";
        std::experimental::filesystem::remove_all(sourceRoot);
        std::experimental::filesystem::copy(argv[2], sourceRoot, std::experimental::filesystem::copy_options::recursive);

        std::string testRoot = argv[1];
        testRoot.replace(testRoot.find(argv[2]), strlen(argv[2]), sourceRoot);

        SourceParser sourceParser = SourceParser();
        std::cout << "Collecting list of unit tests" << std::endl;
        sourceParser.parseTestFiles(testRoot);
        std::cout << "Collecting list of source files" << std::endl;
        sourceParser.parseSourceFiles(sourceRoot);
    }
    return 0;
}