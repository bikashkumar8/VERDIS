#include <bits/stdc++.h>
using namespace std;
vector<int> use(10);

struct node
{
	char c;
	int v;
};

int check(node* nodearray, const int count, string str1, string str2, string str3)
{
	int V1 = 0, V2 = 0, V3 = 0, m = 1, j, i;

	for (i = str1.length() - 1; i >= 0; i--)
	{
		char ch = str1[i];
		for (j = 0; j < count; j++)
			if (nodearray[j].c == ch)
				break;

		V1 += m * nodearray[j].v;
		m *= 10;
	}
	m = 1;

	for (i = str2.length() - 1; i >= 0; i--)
	{
		char ch = str2[i];
		for (j = 0; j < count; j++)
			if (nodearray[j].c == ch)
				break;

		V2 += m * nodearray[j].v;
		m *= 10;
	}
	m = 1;

	for (i = str3.length() - 1; i >= 0; i--)
	{
		char ch = str3[i];
		for (j = 0; j < count; j++)
			if (nodearray[j].c == ch)
				break;

		V3 += m * nodearray[j].v;
		m *= 10;
	}

	if (V3 == (V1 + V2))
		return 1;
	    return 0;
}
bool modification(const int count, node* nodearray, int n, string str1, string str2, string str3)
{
	if (n == count - 1)
	{
		for (int i = 0; i < 10; i++)
		{
			if (use[i] == 0)
			{
				nodearray[n].v = i;
				if (check(nodearray, count, str1, str2, str3) == 1)
				{
					cout << "\nSOLUTION IS FOUND: ";
					for (int j = 0; j < count; j++)
						cout << " " << nodearray[j].c << " = "
							<< nodearray[j].v;
					return true;
				}
			}
		}
		return false;
	}

	for (int i = 0; i < 10; i++)
	{	
		if (use[i] == 0)
		{			
			nodearray[n].v = i;			
			use[i] = 1;
			
			if (modification(count, nodearray, n + 1, str1, str2, str3))
				return true;		
			use[i] = 0;
		}
	}
	return false;
}
bool Verdis(string str1, string str2, string str3)
{	
	int count = 0;
	int l1 = str1.length();
	int l2 = str2.length();
	int l3 = str3.length();

	vector<int> freq(26);

	for (int i = 0; i < l1; i++)
		++freq[str1[i] - 'A'];

	for (int i = 0; i < l2; i++)
		++freq[str2[i] - 'A'];

	for (int i = 0; i < l3; i++)
		++freq[str3[i] - 'A'];
	
	for (int i = 0; i < 26; i++)
		if (freq[i] > 0)
			count++;

	if (count > 10)
	{
		cout << "STRINGS IS INVALID";
		return 0;
	}	
	node nodearray[count];	
	for (int i = 0, j = 0; i < 26; i++)
	{
		if (freq[i] > 0)
		{
			nodearray[j].c = char(i + 'A');
			j++;
		}
	}
	return modification(count, nodearray, 0, str1, str2, str3);
}
int main()
{
	string str1 = "SEND";
	string str2 = "MORE";
	string str3 = "MONEY";

	if (Verdis(str1, str2, str3) == false)
		cout << "NO SOLUTION";
	return 0;
}
