#include<iostream>
#include"Activity.h"
#include"PrecedenceConstraint.h"
#include"MeetConstraint.h"
#include"TopologicalSorter.h"
#include<unordered_map>


using namespace std;
void affGn(Activity* atc, PrecedenceConstraint* cntrt, Activity* resultat, Activity* resultat2, TopologicalSorter ord, TopologicalSorter ord2, unordered_map<int, Activity> sechedule, int numAct, int numCnt, int startTime);

int main(int agrc, char** agrv) {

	// Exemple 1

	cout << "Exemple 1" << endl;
	cout << "------------ " << endl;

	Activity atc[6] = {

	// Ajouter des activites 
	 Activity("Se Lever", 1),
	 Activity("Aller au travail", 15),
	 Activity("Prendre une douche", 10),
	 Activity("Se brosser les dents", 3),
	 Activity("S'Habiller", 2),
	 Activity("Prendre un petit dejeuner", 15)

	};

	// Ajouter des contraintes de precendence

	PrecedenceConstraint cntrt[8] = {
			PrecedenceConstraint(atc[0],atc[5]),
			PrecedenceConstraint(atc[0],atc[4]),
			PrecedenceConstraint(atc[5],atc[3]),
			PrecedenceConstraint(atc[2],atc[4]),
			PrecedenceConstraint(atc[3],atc[1]),
			PrecedenceConstraint(atc[4],atc[1]),
			PrecedenceConstraint(atc[0],atc[2]),
			PrecedenceConstraint(atc[5],atc[1])

	};

	// Allocation de memoire des resultat;
	Activity* resultat = new Activity[6];
	Activity* resultat2 = new Activity[6];

	// Declaration d'une map ou d'un dictionnaire
	unordered_map<int, Activity> sechedule;

	int numAct = 6;
	int numCnt = 8;
	int startTime = 500;

	// instaciation des objets de TopologicalSorter
	TopologicalSorter ord;
	TopologicalSorter ord2;
	//appel de la fonction d'affichage 
	affGn(atc, cntrt, resultat, resultat2, ord, ord2, sechedule, numAct, numCnt, startTime);
	
	// Exemple 2

	cout << endl;
	cout << "Exemple 2" << endl;
	cout << "------------ " << endl;

	int nA(3), nC(3);

	Activity* res = new Activity[nA];
	Activity* res2 = new Activity[nA];

	unordered_map <int, Activity>calendrier;

	Activity atc2[3] = {

		// Ajouter des activites 
		 Activity("Prendre connaissance du sujet d'examen", 30),
		 Activity("Reviser", 300),
		 Activity("Entrer dans la salle d'examen", 8),
	
	};

	// Ajouter des contraintes de precendence

	PrecedenceConstraint cntrt2[3] = {
			PrecedenceConstraint(atc2[1],atc2[2]),
			PrecedenceConstraint(atc2[2],atc2[0]),
			PrecedenceConstraint(atc2[0],atc2[1]),
	
	};

	TopologicalSorter ordenance;
	TopologicalSorter ordenance1;

	affGn(atc2, cntrt2, res, res2, ordenance, ordenance1, calendrier, nA, nC, startTime);

	
	return 0;
	
}

void affGn(Activity* atc, PrecedenceConstraint* cntrt, Activity* resultat, Activity* resultat2, TopologicalSorter ord, TopologicalSorter ord2, unordered_map<int, Activity> sechedule, int numAct, int numCnt, int startTime) {

	// appel de la fonction bruteForceSorte qui retourne un bool
	bool vb = ord.bruteForceSorte(atc, cntrt, resultat, numAct, numCnt);

	// test de valeur de retour et objet modifier  

	if (vb)
	{
		if (resultat == NULL) {
			cout << "Ordenance Impossible " << endl;
		}
		else
		{
			cout << "\t\tOrdennance" << endl;
			cout << endl;
			// Affichage de l'ordenance
			for (int i = 0; i < numAct; ++i) {
				cout << "Activite " << i + 1 << ": Description : " << resultat[i]._getDescription() << ", Dure : " << resultat[i]._getDuration() << " min" << endl;
			}

			cout << endl;


			// appel de la fonction sechedule qui retourne une map 

			sechedule = ord2.sechedule(atc, cntrt, resultat2, startTime, numAct, numCnt);
			
			// test de la map retourner

			if (sechedule.empty())
			{

				cout << "Plannification Impossible" << endl;
			}
			else
			{


				cout << "\t\tEmplois du Temps" << endl;
				cout << endl;
				cout << "Temps de debut \tActivite \t Duree" << endl;
				cout << "-------------------------------------------" << endl;
				//Affichage de la map ou le dictionnaire
				for (unordered_map<int, Activity>::iterator it = sechedule.begin(); it != sechedule.end(); ++it)
				{
					cout << " " << it->first << "\t\t" << it->second._getDescription() << " \t" << it->second._getDuration() << " min" << endl;
				}
			}

		}
	}
	else {
		cout << "Ordenance Impossible et Plannification Impossible " << endl;
	}


}