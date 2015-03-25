using namespace std;
#include "Statistics.h"
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
	statistics::DescriptiveStatistics stats;

	double N;
	
	while (cin >> N)
	{
		stats.insertInVector(N);
	}

	stats.sortVector();

	cout.precision(2);
	cout << "Num de classes : " << stats.classNum() << "\n";
	cout << "Amplitude Total : " << stats.totalAmplitude() << "\n";
	cout << "Intervalo de Classes : " << stats.classInterval() << "\n";

	
}