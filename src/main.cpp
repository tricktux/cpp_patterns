/// @file main.cpp
/// @brief Udemy C++ Patterns
/// @author Reinaldo Molina
/// @version  0.0
/// @date Mar 05 2019
// Copyright © 2019 Reinaldo Molina

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http:www.gnu.org/licenses/>.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "main.hpp"

int main(int argc, const char *argv[]) {

	Journal journal{"wiki"};

	journal.add_entry("cpp");
	journal.add_entry("ssh");
	journal.add_entry("scp");
	journal.add_entry("fd");
	journal.add_entry("ripgrep");

	journal.print_entries();

	PersistanceManager::save(journal, "journal.log");

  return 0;
}
