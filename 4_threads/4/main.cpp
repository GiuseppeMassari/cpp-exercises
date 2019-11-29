#include <iostream>
#include <list>
#include <thread>
#include <cstdlib>

using namespace std;

void print_progress_bar(unsigned int perc, unsigned int maxlen) 
{
	unsigned int nr_bars = (maxlen * perc) / 100;
	for (unsigned int i = 0; i < nr_bars; ++i) {
		//fprintf(stderr, "|");
		cerr <<  "|";
		this_thread::sleep_for(chrono::milliseconds(50));
	}
}

int main(int argc, char **argv)
{
	unsigned int maxlen = 100;
	
	// Serial
	print_progress_bar(100, maxlen);
	cout << endl;

	// Parallel
	list<thread> workers; 
	workers.emplace_back(print_progress_bar, 25, maxlen);
	workers.emplace_back(print_progress_bar, 25, maxlen);
	workers.emplace_back(print_progress_bar, 25, maxlen);
	workers.emplace_back(print_progress_bar, 25, maxlen);

	for (auto & t: workers)
		t.join();
	cout << endl;

	return 0;
}
