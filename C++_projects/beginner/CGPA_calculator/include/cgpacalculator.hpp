#pragma once
#include <iostream>
#include <string>


class CGPACalculator {
	public:
		CGPACalculator();
		CGPACalculator(CGPACalculator &&) = default;
		CGPACalculator(const CGPACalculator &) = default;
		CGPACalculator &operator=(CGPACalculator &&) = default;
		CGPACalculator &operator=(const CGPACalculator &) = default;
		~CGPACalculator();
		void parse(void);
	private:
		float	credit_hours;	
		float	quality_points;	
		float		average;
};

