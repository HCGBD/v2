#include "PrecedenceConstraint.h"
#include<iostream>
#include "Activity.h"

using namespace std;



PrecedenceConstraint::PrecedenceConstraint(Activity f, Activity s) {
	this->_first = f;
	this->_second = s;
}

Activity PrecedenceConstraint::_getFirst() {

	return this->_first;
}

Activity PrecedenceConstraint::_getSecond() {

	return this->_second;
}

bool PrecedenceConstraint::isSatisfied(int startFirstActivity, int startSecondActivity) {
		
	int tmp = startFirstActivity + this->_getFirst()._getDuration();

	if (tmp <= startSecondActivity) {

		return true;
	}
	else
	{
		return false;
	}

	

}
