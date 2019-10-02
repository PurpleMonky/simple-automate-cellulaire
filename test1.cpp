#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm> 
using namespace std;

vector <int> fillit(int tour, int taille)
{
	vector <int> temp;
	while(tour != 0)
	{
		temp.push_back(tour%2); 
		tour /= 2;
	}
	if(temp.size() != taille)
	{
		temp.insert(temp.end(), taille - temp.size(),0);
	}
	reverse(temp.begin(),temp.end());
	
	return temp;
}

int main()
{
	for(int i{0}; i < 256; i++)
	{
		for(auto n: fillit(i, 8))
		{
			cout << n << " ";
		}
		cout << endl;
	}
	return 0;
}

