#ifndef ACTIVITY_H
#define ACTIVITY_H

#include<iostream>

class Activity {

public:

	Activity();
	Activity(std::string, int);
	std::string _getDescription();
	int _getDuration();

	bool isEmpty() const {

		if (this->_description.empty() && this->_Duration == 0) {
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool operator==(const Activity& other) const {


		return _description == other._description && _Duration == other._Duration;
	}
	
	bool cmpAct(Activity act1, Activity act2);

private:
	std::string _description;
	int _Duration;

};

#endif // !ACTIVITY_H




