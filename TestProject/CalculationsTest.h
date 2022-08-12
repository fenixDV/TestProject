#pragma once
#include "Calculations.h"

class CalculationsTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		calc1.setVect(1.890, 2, 0.39);
		calc2.setVect(20156.09, -30.675, 40.678);
		calc3.setVect(0.000018, -46.355, 98.19);
	}

protected:
	Calculations calc1;
	Calculations calc2;
	Calculations calc3;
};