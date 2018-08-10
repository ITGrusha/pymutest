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

void printHelp() {
    std::string command;

    #if defined(_WIN32)
    command = "pymutest.exe";
    #else
    command = "pymutest";
    #endif

    std::cout << "usage: " << command << " [-h] test_dir source_dir" << std::endl;
    std::cout << std::endl << "Mutation testing for python programs." << std::endl;
    std::cout << std::endl << "positional arguments:" << std::endl << "tests_dir   folder with unit tests" << std::endl;
    std::cout << "source_dir  folder with source code" << std::endl;
    std::cout << std::endl << "optional arguments:" << std::endl << "-h, --help  show this help message and exit" << std::endl;
}

int main() {
    return 0;
}