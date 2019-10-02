#include <iostream>
#include <vector>

using namespace std;



int main()
{
	string chiffre{"CHIFFRE DE CESAR"};
	string temp{""};
	string temp2{""};
	int val{0};
	int cle{50};
	for(int i{0}; i < chiffre.size(); i++)
	{
		if((chiffre[i] + cle) > 126)
		{
			val = ((chiffre[i] + cle) % 127) + 32;
		temp.push_back(char(val));
		}
		else
		{
			temp.push_back(char(chiffre[i] + cle));
		}
	}
	cout << chiffre << endl;
	cout << temp << endl;
	
	for(int i{0}; i < temp.size(); i++)
	{
		if((temp[i] - cle) < 32)
		{
			val = (95 + (temp[i] - cle));
			while(val < 32)
			{
			val = (95 + (val));
			}
			if(val < 0)
			{
			val = val * -1;
			temp2.push_back(char(val));
			}
			else
			{
			temp2.push_back(char(val));
			}
		}
		else
		{
			temp2.push_back(char(temp[i] - cle));
		}
	}
	cout << temp2 << endl;
	for(auto n: temp2)
	{
		cout << n + 0 << " ";
	}
	
return 0;
}
