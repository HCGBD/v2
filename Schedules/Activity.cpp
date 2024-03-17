#include "Activity.h"
#include<iostream>

using namespace std;

Activity::Activity(string desc,int ti) {
	this-> _description = desc;
	this-> _Duration = ti;
}

Activity::Activity() {
	this->_description = "";
	this->_Duration = 0;
}
string Activity::_getDescription() {

	return this->_description;
}

int Activity::_getDuration() {

	return this->_Duration;
}


