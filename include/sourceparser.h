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

#ifndef PYMUTEST_SOURCEPARSER_H
#define PYMUTEST_SOURCEPARSER_H

#include <string>
#include <vector>

class SourceParser {
public:
    std::vector<std::string> testFiles;
    std::vector<std::string> sourceFiles;
    void parseTestFiles(std::string);
    void parseSourceFiles(std::string);

private:
    bool is_dir(const char*);
    bool hasEnding(std::string const &, std::string const &);
};


#endif
