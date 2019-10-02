#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <math.h>
#include <algorithm> 
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
//2^8 = 256 regle possible

//test des valeurs d'un automate non-cyclique

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
		if (i == 0)
		{
			index = 0 * 4;
		}
		else
		{
			index = ligne[(i - 1) % ligne.size()] * 4;
		}

		index += ligne[i] * 2;

		if (i == ligne.size())
		{
			index += 0;
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
vector<int> randomvec(int taille)
{

	vector <int> temp;
	for (int i{ 0 }; i < taille; i++)
	{
		temp.push_back(rand() % 2);
	}
	return temp;
}

vector <int> fillit(int tour, int taille)
{
	vector <int> temp;
	for(int i{0}; tour != 0; i++)
	{
		temp.push_back(tour%2); 
		tour /= 2;
	}
	if(temp.size() != taille)
	{
		temp.insert(temp.begin(), taille - temp.size(),0);
	}
	
	reverse(temp.begin(),temp.end());
	
	return temp;
}

int main()
{
	//Variables
	vector <int> ligne{ 0,0,0,0,0,0,0,0};
	vector <int> majorite{ 0,0,0,1,0,1,1,1 };
	vector <vector <int> > allvector;
	int taille{ int(pow(2.0, ligne.size())) };
	vector <vector <int> > vectorstat;
	vector <int> temp{};

	int stat{ 0 };
	srand(time(NULL));
	//On lance la génération

	for (int i{ 0 }; i < taille; i++)
	{

		allvector = {};

		cout << i + 1 << "/" << taille << endl;

		ligne = fillit(i, ligne.size());
		temp = test(ligne, majorite);

		for (int j{ 0 }; j < 15; j++)
		{
			//On fait passer les cycles
			temp = test(temp, majorite);
			allvector.push_back(temp);

		}
		//Si les deux derniers sont égaux, alors c'est forcement stationaire
		if(allvector[allvector.size() - 1] == allvector[allvector.size() - 2])
		{

			stat++;
		}
		else
		{
			vectorstat.push_back(ligne);
		}

	}

	//CONCLUSION
	cout << "sur " << taille << " automates regis par la regle de majorité\n" << stat << "/" << taille << endl;
	cout << "montre des comportement stationaire." << endl;
	cout << "Valeur initiale ne montrent pas de comportement stationaire:" << endl;
	for (auto i : vectorstat)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
