#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
/*Regle de majorité
0 000 = 0
1 001 = 0
2 010 = 0
3 011 = 1
4 100 = 0
5 101 = 1
6 110 = 1
7 111 = 1 
*/
/*deplacement
0 000 = 0
1 001 = 0
2 010 = 0
3 011 = 1
4 100 = 1
5 101 = 1
6 110 = 0
7 111 = 1 
*/


//Fonction testant les cases soumis a des règle
//Renvoyant un vecteur
vector<int> test(vector <int> ligne, vector <int> rule)
{
	//Variables
	vector <int> temp{};
	temp.assign(ligne.size(), 0);
	int index{ 0 };

	for (int i{ 0 }; i < ligne.size(); i++)
	{
		//On prend la valeur des trois cases (%ligne.size() pour éviter le Out_Of_Bounds)
		if(i == 0)
		{
			index = ligne.back() * 4;
		}
		else
		{
			index = ligne[(i - 1) % ligne.size()] * 4;
		}
		
		index += ligne[i] * 2;
		
		if(i == ligne.size())
		{
			index += ligne.front();
		}
		else
		{
			index += ligne[(i + 1) % ligne.size()];
		}
		
		//^ On le convertie en base10 
		temp[i] = rule[index];

	}
	return temp;
}
void readit(vector <int> temp)
{
	//Fonctions simplifiant la lecture d'un vecteur
	for (auto n : temp)
	{
		cout << n << " ";
	}
}

int main()
{
	//Variables
	vector <int> ligne{ 0,1,1,0,0,0,0,0 };
	vector <int> majorite{ 0,0,0,1,0,1,1,1 };
	vector <int> deplacement{ 0,0,0,1,1,1,0,1 };
	vector <vector <int> > allvector;
	
	allvector.push_back(ligne);
	vector <int> temp{};
	bool stationaire = false;
	
	vector <int> regle {majorite};
	readit(ligne);
	cout << endl;
	
	
	//Premier Envoie de la fonction
	temp = test(ligne, regle);
	readit(temp);
	cout << endl;
	for (int i{ 0 }; i < 15; i++)
	{
		//Deuxieme envoie dans une boucle
		temp = test(temp, regle);
		allvector.push_back(temp);
		
		//lecture dans une boucle
		readit(temp);
		cout << endl;
	}
	for(int i{1}; i < allvector.size() - 1; i++)
	{
		if(allvector[i] == allvector[i+1])
		{
			stationaire = true;
		}
	}
	if(stationaire == true)
	{
	cout << "L'automate celluraire rencontre un etat de stationarite" << endl;
	}
	return 0;
}
