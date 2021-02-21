#include<iostream>
#include<math.h>
#include<string>
#pragma warning(disable:4996)
int variable;
using namespace std;
char** truth(string str) {
	char** table;
	string temp, t;
	int x, row, y;
	size_t index = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'T')
			str[i] = '1';
		else if (str[i] == 'F')
			str[i] = '0';
		else if (str[i] >= 97 && str[i] <= 122 && temp.find(str[i], 0) == string::npos)
			temp.push_back(str[i]);
	}
	variable = temp.length();
	for (int i = 0; i < temp.length() - 1; i++)
		for (int j = i + 1; j < temp.length(); j++)
			if (temp[i]>temp[j]) {
				char tt = temp[i];
				temp[i] = temp[j];
				temp[j] = tt;
			}
	row = pow(2, variable);
	table = new char*[row];
	for (int i = 0; i < row; i++)
		table[i] = new char[variable + 1];
	for (int j = 0; j < variable; j++) {
		row /= 2;
		x = 0;
		y = 0;
		for (int i = 0; i < pow(2, variable); i++) {
			if (x == row) {
				x = 0;
				y++;
			}// if
			if (y % 2 == 0)
				table[i][j] = '0';
			else
				table[i][j] = '1';
			x++;
		}// for row
	}// for column
	for (int i = 0; i < pow(2, variable); i++) {
		t = "";
		for (int j = 0; j < str.length(); j++) {
			if (temp.find(str[j], 0) != string::npos)
				t.push_back(table[i][temp.find(str[j], 0)]);
			else
				t.push_back(str[j]);
		}// for assign
		while (t.length() != 1) {
			while (1) {
				index = t.find("(~0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 4, "1");
			} // (~0)
			index = 0;
			while (1) {
				index = t.find("(~1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 4, "0");
			}// (~1)
			index = 0;
			while (1) {
				index = t.find("(0/\\0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "0");
			}// (0/\0)
			index = 0;
			while (1) {
				index = t.find("(0/\\1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "0");
			}// (0/\1)
			index = 0;
			while (1) {
				index = t.find("(1/\\0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "0");
			}// (1/\0)
			index = 0;
			while (1) {
				index = t.find("(1/\\1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "1");
			}// (1/\1)
			index = 0;
			while (1) {
				index = t.find("(0\\/0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "0");
			}// (0\/0)
			index = 0;
			while (1) {
				index = t.find("(1\\/0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "1");
			}// (1\/0)
			index = 0;
			while (1) {
				index = t.find("(0\\/1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "1");
			}// (0\/1)
			index = 0;
			while (1) {
				index = t.find("(1\\/1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "1");
			}// (1\/1)
			index = 0;
			while (1) {
				index = t.find("(0->0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "1");
			}// (0->0)
			index = 0;
			while (1) {
				index = t.find("(0->1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "1");
			}// (0->1)
			index = 0;
			while (1) {
				index = t.find("(1->0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "0");
			}// (1->0)
			index = 0;
			while (1) {
				index = t.find("(1->1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 6, "1");
			}// (1->1)
			index = 0;
			while (1) {
				index = t.find("(0<->0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 7, "1");
			}// (0<->0)
			index = 0;
			while (1) {
				index = t.find("(1<->0)", index);
				if (index == std::string::npos) break;
				t.replace(index, 7, "0");
			}// (1<->0)
			index = 0;
			while (1) {
				index = t.find("(0<->1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 7, "0");
			}// (0<->1)
			index = 0;
			while (1) {
				index = t.find("(1<->1)", index);
				if (index == std::string::npos) break;
				t.replace(index, 7, "1");
			}// (1<->1)
			index = 0;
		}// while(t.lengh() != 1)
		table[i][variable] = t[0];
	}// for row
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '1')
			str[i] = 'T';
		else if (str[i] == '0')
			str[i] = 'F';
	cout << endl << endl;
	for (int i = 0; i < temp.length(); i++)
		cout << temp[i] << "   ";
	cout << str << endl;
	x = temp.length() + (temp.length() * 3) + str.length();
	for (int i = 0; i < x; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < pow(2, variable); i++) {
		for (int j = 0; j < variable; j++)
			cout << table[i][j] << "   ";
		cout << "   " << table[i][variable] << endl;
	}
	return table;
}
int main() {
	string str;
	getline(cin, str);
	char** result = truth(str);
	for (int i = 0; i < pow(2, variable); i++)
		delete[] result[i];
	delete[] result;
}// main