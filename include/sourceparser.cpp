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

#include <string>
#include <experimental/filesystem>
#include <sys/stat.h>
#include <algorithm>
#include "sourceparser.h"

void SourceParser::parseTestFiles(std::string path) {
    for (auto & p : std::experimental::filesystem::directory_iterator(path)) {
        std::string file = p.path().string();
        if (is_dir(file.c_str()))
            parseTestFiles(file);
        else
            if (hasEnding(file, ".py"))
                testFiles.push_back(file);
    }
}

void SourceParser::parseSourceFiles(std::string path) {
    for (auto & p : std::experimental::filesystem::directory_iterator(path)) {
        std::string file = p.path().string();
        if (is_dir(file.c_str()))
            parseSourceFiles(file);
        else
        if (hasEnding(file, ".py") && std::find(testFiles.begin(), testFiles.end(), file) == testFiles.end())
            sourceFiles.push_back(file);
    }

}

bool SourceParser::is_dir(const char * path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

bool SourceParser::hasEnding(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

