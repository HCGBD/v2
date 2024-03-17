#pragma once
#ifndef PRECEDENCECONSTRAINT_H
#define PRECEDENCECONSTRAINT_H

#include<iostream>
#include"Activity.h"

class PrecedenceConstraint {

public:

	PrecedenceConstraint(Activity, Activity);
	Activity _getFirst();
	Activity _getSecond();
	bool isSatisfied(int, int);

private:
	Activity _first;
	Activity _second;
};

#endif // !PRECEDENCECONSTRAINT_H



