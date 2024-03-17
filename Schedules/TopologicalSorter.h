#ifndef TOPOLOGICALSORTER_H
#define TOPOLOGICALSORTER_H

#include<iostream>
#include"Activity.h"
#include"PrecedenceConstraint.h"

#include<unordered_map>

class TopologicalSorter{
public:
		
	void affCntAct(Activity activities[], PrecedenceConstraint constraint[]);
	bool bruteForceSorte(Activity*,PrecedenceConstraint *, Activity* Resultat, int nbact, int nbcnt);
	bool auxiliary(Activity *atc, Activity *resultat, PrecedenceConstraint *constraint, int &nbrAct, int &nbreCont,Activity &activite, int nbrRst);
    std::unordered_map <int, Activity> sechedule(Activity* activities, PrecedenceConstraint* constraints, Activity* resultat, int startTime,int nbA,int nbC);
private:
	void removeActivitie(Activity* activities, int& nbrAct, Activity activite);
	bool containts(Activity* resultat, Activity first, int nbreAc);
};


#endif // !TOPOLOGICALSORTER_H


