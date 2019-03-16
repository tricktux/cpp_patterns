/// @file main.hpp
/// @brief Header for main.cpp
/// @author Reinaldo Molina
/// @version  0.0
/// @date Mar 10 2019

#ifndef MAIN_H_
#define MAIN_H_

class Journal {
  std::string title;
  std::vector<std::string> entries;

public:
  explicit Journal(const std::string &title) : title(title) {
    entries.reserve(32);
  }

  void add_entry(const std::string &entry) {
    if (entry.empty())
      return;

    static int count = 1;
    entries.push_back(std::to_string(count++) + ": " + entry);
  }

  void print_entries() const {
    for (const std::string &entry : entries) {
      std::cout << entry << '\n';
    }
  }

  const std::vector<std::string>& get_entries() const { return entries; }
};

class PersistanceManager {

public:
	static void save(const Journal &journal, const std::string &filename) {
		if (filename.empty())
			return;

		std::ofstream ofs(filename);
		for (const auto &entry : journal.get_entries())
			ofs << entry << '\n';
	}
};

#endif
