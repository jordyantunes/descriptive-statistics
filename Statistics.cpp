using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include "Statistics.h"

namespace statistics
{
	DescriptiveStatistics::DescriptiveStatistics(){
		v = new vector<double>();
	}

	DescriptiveStatistics::DescriptiveStatistics(int size)
	{
		v = new vector<double>(size);
	}

	DescriptiveStatistics::~DescriptiveStatistics()
	{
		delete v;
	}

	void DescriptiveStatistics::insertInVector(double val)
	{
		this->v->push_back(val);
	}

	void DescriptiveStatistics::sortVector()
	{
		sort(this->v->begin(), this->v->begin() + this->v->size());
	}

	int DescriptiveStatistics::classNum()
	{
		return round(1 + (3.32 * log10((double) this->v->size())));
	}

	double DescriptiveStatistics::totalAmplitude()
	{
		return this->v->at(this->v->size() - 1) - this->v->at(0);
	}

	double DescriptiveStatistics::totalAmplitude(double min, double max){
		return max - min;
	}

	double DescriptiveStatistics::classInterval()
	{
		return (this->totalAmplitude() / this->classNum());
	}
	
}