#ifndef _HEADER_
#define _HEADER_
#include <iostream>
#include<string>
#include<vector>

bool Unique(std::string& str)
{	
	unsigned int count[4] {};
	for (int i = 0; i < str.size(); ++i)
	{
		str[i] = toupper(str[i]);
		if (count[str[i]%4] & 1 << (str[i]/4))
		{
			return false;
		}
			count[str[i]%4] |= 1 << str[i]/4;
	}
		return true;	
}

bool Two_string(std::string& str1, std::string& str2)
{
	unsigned int count1[4]{};
	unsigned int count2[4]{};
	if (str1.size() != str2.size())
	{
		return false;
	}
	for (int i = 0; i < str1.size(); ++i)
	{
		str1[i] = toupper(str1[i]);
		str2[i] = toupper(str2[i]);
		if (count1[str1[i] % 4] & 1 << (str1[i] / 4))count1[str1[i] % 4] ^= 1 << (str1[i] / 4);
		else count1[str1[i] % 4] |= 1 << (str1[i] / 4);
		if (count2[str2[i] % 4] & 1 << (str2[i] / 4))count2[str2[i] % 4] ^= 1 << (str2[i] / 4);
		else count2[str2[i] % 4] |= 1 << (str2[i] / 4);
	}
	for (int i = 0; i < 4; ++i) 
	{
		if (count1[i] != count2[i]) { return false; }
	}
	return true;
}

std::string Add_20(std::string & str)
{
	int p = 0;
	while (str[str.size() - 1] == ' ') { str.pop_back(); }
	while (p>=0)
	{
		p = str.find(' ');
		if (p == -1) { break; }
		str.replace(p, 1, "%20");
	}
	return str;
}

bool Palindrom(std::string& str)
{
	unsigned int count[4]{};
	for (int i = 0; i < str.size(); ++i)
	{
		str[i] = toupper(str[i]);
		if(str[i]==' ')
		{
			i++;
		}
		if (count[str[i] % 4] & 1 << (str[i] / 4)) { count[str[i] % 4] ^= 1 << (str[i] / 4); }
		else { count[str[i] % 4] |= 1 << (str[i] / 4); }
	}
	int q=0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < sizeof(int)*8; ++j)
		{
			if (count[i] & (1 << j))
			{
				q++;
			}
		}
	}
	std::cout << q<<std::endl;
	if (q > 1) { return false; }
	return true;
}

bool One_away(std::string& str1, std::string& str2)
{
	int a = str1.size();
	int b = str2.size();
	if (std::abs(a - b) > 1)
	{
		return false;
	}
	int count = 0;
	int i = 0;
	int j = 0;
	while (i < a && j < b)
	{
		str1[i] = toupper(str1[i]);
		str2[j] = toupper(str2[j]);
		if (str1[i] != str2[j])
		{
			if (a > b) { i++; }
			else if (a < b) { j++; }
			else{ i++; j++; }
			count++;
		}
		else{ i++; j++; }
	}
	if (count > 1)
	{
		return false;
	}
	else return true;
}

std::string Compression(std::string& str)
{
	std::string new_str;
	int count = 1;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == str[i + 1])
		{
			count++;
		}
		else 
		{
			new_str.push_back(str[i]);
			new_str+= std::to_string(count);
			count = 1;
		}
	}
	return new_str;
}

void Rotate_matrix(std::vector< std::vector<int>>& vec)
{
	std::vector<std::vector<int>> new_vec(vec.size());
	for (int i = 0; i < vec.size(); ++i)
	{
		new_vec[i].resize(vec.size());
	}
	for (int i = 0; i < vec.size() ; ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			new_vec[j][vec.size() - i - 1] = vec[i][j];
		}
	}
	vec = new_vec;
}

void Zero(std::vector<std::vector<int>>& vec)
{
	std::vector<std::pair<int, int>> ind;
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			if (vec[i][j] == 0)
			{
				ind.push_back(std::make_pair(i, j));
			}
		}
	}
	for (int p = 0; p < ind.size(); ++p)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			for (int j = 0; j < vec[i].size(); ++j)
			{
				if (i == ind[p].first && j==ind[p].second)
				{
					for (int j = 0; j < vec[i].size(); ++j)
					{
						vec[i][j] = 0;
					}
					for (int i=0; i < vec.size(); ++i)
					{
						vec[i][ind[p].second] = 0;
					}
				}

			}
		}
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << std::endl;
		for (int j = 0; j < vec[i].size(); ++j)
		{
			std::cout << vec[i][j];
		}
	}
}

bool String_Rotation(std::string& str, std::string& comp)
{
	if (str.size() != comp.size()) { return false; }
	for (int i = 0; i < str.size(); ++i)
	{
		str.push_back(str[0]);
		str.erase(0, 1);
		if (str == comp) { return true; }
	}
	return false;
}

#endif // !_HEADER_