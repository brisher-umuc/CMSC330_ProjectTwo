#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

vector<int> shell_sort(vector<int> vec) {
	/*
		http://rosettacode.org/wiki/Sorting_algorithms/Shell_sort#Python
		I didn't actually understand the code for the C++ version of the algorithm for shell sort
		from rosetta code, so I took the python version and wrote it in C++.
	*/
	int inc = floor(vec.size() / 2);
	int element;

	while (inc) {
		for (int i = 0; i < vec.size(); ++i) {
			element = vec.at(i);
			while (i >= inc && vec.at(i - inc) > element) {
				vec.at(i) = vec.at(i - inc);
				i -= inc;
			}
			vec.at(i) = element;
		}
		if (inc == 2) {
			inc = 1;
		}
		else {
			inc = floor(inc * 5.0 / 11);
		}
	}

	return vec;
}

vector<int> insertion_sort(vector<int> vec) {
	/*
		http://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort#Python
		I didn't actually understand the code for the C++ version of the algorithm for insertion sort 
		from rosetta code, so I took the python version and wrote it in C++.  
	*/
	int j, key;

	for (int i = 1; i < vec.size(); ++i) {
		j = i - 1;
		key = vec.at(i);
		while (j >= 0 && vec.at(j) > key) {
			vec.at(j + 1) = vec.at(j);
			j -= 1;
		}
		vec.at(j + 1) = key;
	}
	return vec;
}

bool is_sorted(vector<int> vec) {
	int tmp = vec.at(0);
	bool sentry = true;

	for (int i = 1; i < vec.size(); ++i) {
		if (!vec.at(i) > tmp) {
			sentry = false;
			break;
		}
		else {
			tmp = vec.at(i);
		}
	}

	return sentry;

}

int main() {
	vector<int> v;
	string line;
	ifstream ifs("array3Random.txt");

	if (ifs.is_open()) {
		getline(ifs, line);
	}
	ifs.close();

	istringstream iss(line);
	vector<string> sv{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	for (int i = 0; i < sv.size(); ++i) {
		int num;
		if ((istringstream(sv.at(i)) >> num)) {
			v.push_back(num);
		}
	}

	
	vector<int> nv = insertion_sort(v);

	cout << std::boolalpha << "nv is sorted? " << is_sorted(nv) << endl;

	getchar();
	return 0;
}