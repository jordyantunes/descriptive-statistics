using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Statistics.h"

#define DEBUG 1

namespace statistics
{
	DescriptiveStatistics::DescriptiveStatistics(){
		this->classIsSet = false;
		this->size = 0;
	}

	void DescriptiveStatistics::insertInVector(double val)
	{
		this->isUpdated = false;

		if (this->map.count(val) != 0)
		{
			this->map.at(val)++;
		}
		else
		{
			this->map.insert(std::pair<double, int>(val, 1));
		}
		size++;
	}

	DescriptiveStatistics::~DescriptiveStatistics(){

	}

	int DescriptiveStatistics::calcClassNum()
	{
		return round(1 + (3.32 * log10(this->size)));
	}

	double DescriptiveStatistics::calcTotalAmplitude()
	{
		return (--this->map.end())->first - this->map.begin()->first;
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

	void DescriptiveStatistics::setClassIsSet(bool val)
	{
		this->classIsSet = val;
	}
	
	int DescriptiveStatistics::getFrequencyOfVal(double n)
	{
		return (this->map.count(n) != 0) ? this->map.at(n) : -1;
	}

}