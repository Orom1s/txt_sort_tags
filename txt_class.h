#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

namespace txt {
	using tags = std::unordered_set<std::string>;
	using num_tags = std::unordered_map<int, tags>;
	class Tags {
	public:
		void Add(std::string& tag);
		tags& Get();
		tags& At(const int id);
		size_t Size() const;
	private:
		num_tags file_tags;
		int number = 0;
	};

	tags SplitLine(std::string& line);
	void Load(std::string& input, Tags& file);
	void DownLoad(Tags& file, std::ofstream& out);
}


