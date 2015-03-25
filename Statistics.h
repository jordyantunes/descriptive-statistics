#ifndef STATISTICS
#include <cmath>
#include <vector>

#define STATISTICS

namespace statistics
{
	class DescriptiveStatistics{
	
	private:
		bool classIsSet; //whether to use ranges or not
		bool autoAttributes; //if user sets attributes manually, then this is false TO BE IMPLEMENTED
		int classNum;
		double totalAmplitude;
		double classInterval;
		
		//
		bool isUpdated;
	public:
		vector<double> *v;
		DescriptiveStatistics();
		DescriptiveStatistics(int size);
		~DescriptiveStatistics();

		void insertInVector(double val);
		void sortVector();
		int calcClassNum();
		double calcTotalAmplitude();
		double calcClassInterval();

		bool updateAttributes();
		
		//static functions
		static double calcTotalAmplitude(double min, double max);

		//getters and setters
		int getClassNum();
		double getTotalAmplitude();
		double getClassInterval();
	};
}
#endif