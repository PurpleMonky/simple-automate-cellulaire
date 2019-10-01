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
//2^8 = 256 regle possible


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
vector<int> randomvec(int taille)
{

	vector <int> temp;
	for(int i{0}; i < taille; i++)
	{
		temp.push_back(rand() % 2);
	}
	return temp;
}
vector <int> fillit(vector <int> temp,int tour)
{
	vector <int> a;
	vector <int> bin1;
	for(int i{0}; i != 0; i++)
	{
		a[i]=tour%2;
		tour/=2; 
	}
	for(int i{0}; i < a.size(); i++)
	{
	temp.pop_back();
	}
	for(int i{0}; i < a.size(); i++)
	{
	temp.push_back(a[i]);
	}
	return temp;
}

int main()
{
	//Variables
	vector <int> ligne{ 0,0,0,0,0,0,0,0 };
	vector <int> majorite{ 0,0,0,1,0,1,1,1 };
	
	vector <vector <int> > allvector;
	vector <vector <int> > vectorstat;
	allvector.push_back(ligne);
	vector <int> temp{};
	bool stationaire = false;
	int stat{0};
	srand (time(NULL));
	
	for(int i{0}; i < 256; i++)
	{
		temp = fillit(ligne, i);
		for(auto n: temp)
		{
			cout << n << " ";
		}
		cout << "\n";
		/*stationaire = false;
		cout << i << "/256" << endl;

		ligne = fillit(ligne, i);
		temp = test(ligne, majorite);
	for (int j{ 0 }; j < 30; j++)
	{
		temp = fillit(temp, i);
		temp = test(temp, majorite);
		
		allvector.push_back(temp);
	}
	for(int j{1}; j < allvector.size() - 1; j++)
	{
		if(equal(allvector[j].begin(), allvector[j].end(), allvector[j+1].begin()))
		{
			stationaire = true;
		}
	}
	if(stationaire == true)
	{
		stat++;
		vectorstat.push_back(ligne);
	}*/
	
	}
	cout << "sur 256 automate regis par la regle de majorité\n" << stat<< "/256 on montre des comportement stationaire." << endl; 
	return 0;
}
