#include "txt_class.h"


namespace txt {

	void Tags::Add(std::string& tag) {
		if (file_tags[number].size() == 10) {
			++number;
		}
		file_tags[number].insert(tag);
	}



	tags& Tags::Get() {
		if (file_tags[number].size() >= 10) {
			++number;
		}
		return file_tags[number];
		
	}

	tags& Tags::At(const int id) {
		return file_tags[id];
	}

	size_t Tags::Size() const {
		return number;
	}

	


	tags SplitLine(std::string& line) {
		tags words;
		std::string word;
		for (const char c : line) {
			if (c == ',') {
				if (!word.empty()) {
					words.insert(word);
					word.clear();
				}
			}
			else {
				word += c;
			}
		}
		if (!word.empty()) {
			words.insert(word);
		}
		return words;
	}

	void Load(std::string& line, Tags& file) {
		tags* words = nullptr;
		auto last_num = line.find_last_of(':');
		line = line.substr(last_num+1);
		words = &file.Get();
		tags tag_words = SplitLine(line);
		words->insert(tag_words.begin(), tag_words.end());
	}

	void DownLoad(Tags& file, std::ofstream& out) {
		for (int id = 0; id < file.Size(); ++id) {
			for (auto word : file.At(id)) {
				out << "#" << word;
			}
			out << std::endl;
		}
	}
}