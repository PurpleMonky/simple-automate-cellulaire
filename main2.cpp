#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*majorité
000 = 0
001 = 0
010 = 0
011 = 1
100 = 0
101 = 1
110 = 1
111 = 1
*/

vector<int> test(vector <int> ligne, vector <int> rule)
{
	vector <int> temp{};
	for(int i{0}; i < ligne.size(); i++)
	{
		temp.push_back(0);
	}
	int index{0};
	
	for(int i{0}; i < ligne.size(); i++)
	{
		index = ligne[(i-1)%ligne.size()] * 4;
		index += ligne[i%ligne.size()] * 2;
		index += ligne[(i+1)%ligne.size()] ;
		
		temp[i] = rule[index];

	}
	
	
 return temp;
}

int main()
{
	
	vector <int> ligne {1,1,0,1,0,0,0,1,0,1,0,0};
	vector <int> majorite{0,0,0,1,0,1,1,1};
	
	vector <int> temp{};
	

	for(auto n: ligne)
	{
		cout << n << " ";
	}
	cout << endl;
	
	for(int i{0}; i < 10; i++)
	{
		      
		temp = test(ligne, majorite);
	
		for(auto n: temp)
		{
			cout << n << " ";
		}
		cout << endl;
	}
return 0;
}
