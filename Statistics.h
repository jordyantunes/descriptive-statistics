#ifndef STATISTICS
#include <cmath>
#include <vector>

#define STATISTICS

namespace statistics
{
	class DescriptiveStatistics{

	public:
		vector<double> *v;
		DescriptiveStatistics();
		DescriptiveStatistics(int size);
		~DescriptiveStatistics();

		void insertInVector(double val);
		void sortVector();
		int classNum();
		double totalAmplitude();
		double classInterval();

		//static functions
		static double totalAmplitude(double min, double max);

	};
}
#endif