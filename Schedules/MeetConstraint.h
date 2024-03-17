#ifndef MEETCONSTRAINT_H
#define MEETCONSTRAINT_H

#include<iostream>
#include"Activity.h"

class MeetConstraint{
public:
	MeetConstraint(Activity, Activity);
	Activity _getFirst();
	Activity _getSecond();
	bool isSatisfied(int, int);

private:
	Activity _first;
	Activity _second;
};

#endif // !MEETCONSTRAINT_H



