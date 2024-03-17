#include "MeetConstraint.h"

#include<iostream>

using namespace std;

MeetConstraint::MeetConstraint(Activity f, Activity s) {
	this->_first = f;
	this->_second = s;
}

Activity MeetConstraint::_getFirst() {

	return this->_first;
}

Activity MeetConstraint::_getSecond() {

	return this->_second;
}

bool MeetConstraint::isSatisfied(int d1, int d2) {

	if (d2 > d1) {
		return true;
	}
	else {

		return false;
	}

}
