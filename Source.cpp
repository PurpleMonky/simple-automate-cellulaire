#include <iostream>
#include <vector>
#include <string>
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
		index = ligne[(i - 1) % ligne.size()] * 4;
		index += ligne[i] * 2;
		index += ligne[(i + 1) % ligne.size()];
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
	vector <int> ligne{ 1,0,1,0,1,0,1,0,1,0,1,0,1 };
	vector <int> majorite{ 0,0,0,1,0,1,1,1 };

	vector <int> temp{};

	
	readit(ligne);
	cout << endl;
	//Premier Envoie de la fonction
	temp = test(ligne, majorite);
	readit(temp);
	cout << endl;
	for (int i{ 0 }; i < 5; i++)
	{
		//Deuxieme envoie dans une boucle
		temp = test(temp, majorite);

		//lecture dans une boucle
		readit(temp);
		cout <<"\n" << endl;
	}
	return 0;
}
