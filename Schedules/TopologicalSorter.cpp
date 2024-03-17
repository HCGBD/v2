#include "TopologicalSorter.h"
#include<iostream>
#include"Activity.h"
#include"PrecedenceConstraint.h"
#include<unordered_map>


using namespace std;



void TopologicalSorter::affCntAct(Activity activities[], PrecedenceConstraint constraints []) {

	cout << "La liste des Activites" << endl;
	// Affichez les activités ajoutées
	for (int i = 0; i < 6; ++i) {
		cout << "Activite " << i + 1 << ": Description : " << activities[i]._getDescription() << ", Dure : " << activities[i]._getDuration() << " min" << endl;
	}

	cout << endl;


	cout << endl;
	cout << "La liste des contraintes " << endl;

	for (size_t i = 0; i < 8; i++)
	{
		cout << "Contraintes " << i + 1 << "  I :" << constraints[i]._getFirst()._getDescription() << " Et II :" << constraints[i]._getSecond()._getDescription() << endl;
	}


 }


bool TopologicalSorter::bruteForceSorte(Activity *activities, PrecedenceConstraint *constraints, Activity *resultat ,int nbact , int nbcnt) {
	

	int nbrRstl = 0;

	Activity *act = new Activity [nbact];


	//cout << "Nombre activite : " << nbact << endl;
	//cout << "Nombre contrainte : " << nbcnt << endl;

	Activity activite;
	// copie de activities dans act
	for (int  i = 0; i < nbact; i++)
	{
		act[i] = activities[i];
	}
	
	while (nbact!=0)
	{
		int vrAc = auxiliary(act, resultat, constraints, nbact, nbcnt, activite, nbrRstl);

		if (activite==Activity())
		{
			return false;
		}

		if (vrAc) {
			resultat[nbrRstl++] = activite;
			removeActivitie(act, nbact, activite);
		}
	
		
	}

	int vR = 0;

	for (int i = 0; i < nbact; i++)
	{
		if (resultat[i] == Activity()) {
			vR = true;
		}
	}

	if (!vR)
	{
		return true;
		//delete act;
	}

	return false;
}


bool TopologicalSorter::auxiliary(Activity *atc, Activity *resultat, PrecedenceConstraint *constraint,int &nbrAct, int &nbreCont,Activity &aci, int nbrRst) {
	
//  	cout << "Entrez dans auxiliary" << endl;
	for (int i = 0; i < nbrAct; i++)
	{

		// cout << "Activite selectionner : " << atc[i]._getDescription() << endl;
		bool ok = true;
		for (int j = 0; j < nbreCont; j++)
		{

			//cout << "Contraintes " << j + 1 << "  I :" << constraint[j]._getFirst()._getDescription() << " Et II :" << constraint[j]._getSecond()._getDescription() << endl;
			
			if (constraint[j]._getSecond()==atc[i] && !containts(resultat,constraint[j]._getFirst(),nbrRst))
			{
				//cout << "Il n'est pas present " << endl;
				ok = false;
				break;
			}

			
		}
		
		if (ok)
		{
			aci = atc[i];

			return true;
		}
		
	}



	return false;
}

 bool TopologicalSorter:: containts (Activity* resultat, Activity first, int nbreAc) {

	bool verif = false;
	for (int  i = 0; i < nbreAc; i++)
	{
		if (resultat[i] == first) {
			verif = true;
			//cout << "Trouver c'est pas bon " << endl;
		}
		else
		{
			//cout << "Pas Trouver c'est bon " << endl;
		}
	}

	return verif;
}

 void TopologicalSorter::removeActivitie (Activity* activities, int& nbrAct, Activity activite) {
	
	int trouv = 0;
	int index;
	for (int i = 0; i < nbrAct; i++)
	{
		if (activities[i] == activite) {
			trouv = 1;
			index = i;
		}
	}

	if (trouv)
	{
		//cout << "index : " << index << endl;
		for (int i = index; i < nbrAct-1; i++)
		{
			activities[i] = activities[i + 1];
		}

		nbrAct = nbrAct - 1;
		//cout << "Nombre Acts " << nbrAct << endl;
	}

}




 unordered_map<int, Activity> TopologicalSorter::sechedule(Activity* activities, PrecedenceConstraint* constraints, Activity* resultat, int startTime,int nbA, int nbC) {

	 TopologicalSorter sch;
	 bool vrf = sch.bruteForceSorte(activities, constraints, resultat,nbA,nbC);
	 if (vrf)
	 {
		 if (resultat != NULL) {

			 unordered_map<int, Activity> calendrier;
			 int curentTime = startTime;

			 for (int i = 0; i < nbA; i++)
			 {
				 calendrier[curentTime] = resultat[i];
				 curentTime += resultat[i]._getDuration();
			 }



			// for (unordered_map<int, Activity>::iterator it = calendrier.begin(); it != calendrier.end(); ++it)
			// {
			//	 cout << "Temps de debut " << it->first << "Description " << it->second._getDescription() << "Duree " << it->second._getDuration() << endl;
			// }
			 return calendrier;
		 }

	 }

 }
