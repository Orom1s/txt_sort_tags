#include <fstream>
#include "txt_class.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	txt::Tags accs;
	std::ifstream in;
	std::string line;
	in.open("Acc_filter.txt");
	if (in.is_open()) {
		while (in >> line) {
			Load(line, accs);
		}
	}
	in.close();
	std::ofstream out;
	out.open("sorted_accs.txt");
	if (out.is_open()) {
		txt::DownLoad(accs, out);
	}
	out.close();
}