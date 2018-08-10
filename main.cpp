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

std::string getCommand() {
    #if defined(_WIN32)
    return "pymutest.exe";
    #else
    return  "pymutest";
    #endif
}

void printHelp() {
    std::cout << "usage: " << getCommand() << " [-h] test_dir source_dir" << std::endl;
    std::cout << std::endl << "Mutation testing for python programs." << std::endl;
    std::cout << std::endl << "positional arguments:" << std::endl << "tests_dir   folder with unit tests" << std::endl;
    std::cout << "source_dir  folder with source code" << std::endl;
    std::cout << std::endl << "optional arguments:" << std::endl << "-h, --help  show this help message and exit" << std::endl;
}

int main(int argc, char** argv) {
    if (argc == 1)
        std::cout << "Specify arguments. For more information: " << getCommand() << " --help" << std::endl;
    else if (strcmp(argv[1], "-h") == 0 or strcmp(argv[1], "--help") == 0)
        printHelp();
    else if (argc == 2)
        std::cout << "Specify source dir. For more information: " << getCommand() << " --help" << std::endl;
    return 0;
}