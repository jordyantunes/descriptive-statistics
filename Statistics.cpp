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
		this->isUpdated = false;
		this->v->push_back(val);
	}

	void DescriptiveStatistics::sortVector()
	{
		this->isUpdated = false;
		sort(this->v->begin(), this->v->begin() + this->v->size());
	}

	int DescriptiveStatistics::calcClassNum()
	{
		return round(1 + (3.32 * log10((double) this->v->size())));
	}

	double DescriptiveStatistics::calcTotalAmplitude()
	{
		return this->v->at(this->v->size() - 1) - this->v->at(0);
	}

	double DescriptiveStatistics::calcTotalAmplitude(double min, double max){
		return max - min;
	}

	double DescriptiveStatistics::calcClassInterval()
	{
		return (this->getTotalAmplitude() / this->getClassNum());
	}
	
	
	int DescriptiveStatistics::getClassNum()
	{
		return (this->isUpdated)? this->classNum : this->classNum = this->calcClassNum();
	}

	double DescriptiveStatistics::getTotalAmplitude()
	{
		return (this->isUpdated)? this->totalAmplitude : this->totalAmplitude = this->calcTotalAmplitude();
	}

	double DescriptiveStatistics::getClassInterval()
	{
		return (this->isUpdated)? this->classInterval : this->classInterval = this->calcClassInterval();
	}
	
}