#include <iostream>
#include <string>
using namespace std;


int stringlen(char *str)
{
	int t = 0;
	while (str[t] != '\0')
		t++;
	return t;
}


/*-------------1------------*/
char* StringNCopy(char *sub, char *str, int n)
{
	int t = stringlen(str);
	if (n > t) n = t;
	for (int i = 0; i <= n; i++)
		sub[i] = str[i];
	return sub;
}

void CopySubString(char *dest, char*src, int StartPos, int numChars)
{
	StringNCopy(dest, src + StartPos, numChars);
	dest[numChars] = '\0';
}


/*-------------2------------*/
char* StringCopy(char *sub, char *str)
{
	int t = stringlen(str);
	for (int i = 0; i <= t; i++)
		sub[i] = str[i];
	return sub;
}

void InsertSubString(char *str, char *substr, int StartPos)
{
	int length = stringlen(str);
	int sublength = stringlen(substr);
	char *temp;
	if (StartPos > length) StartPos = length;
	if (StartPos < length)
	{
		temp = new char[length - StartPos + 1];
		StringCopy(temp, str + StartPos);
		StringCopy(str + StartPos, substr);
		StringCopy(str + StartPos + sublength, temp);
		delete[] temp;
	}
	else StringCopy(str + StartPos, substr);
}


/*-------------3------------*/
void DeleteSubString(char *&str, int Startpos, int n)
{
	int t = stringlen(str);
	if (Startpos > t) Startpos = t;
	if (n > t - Startpos) n = t - Startpos;
	char *temp = new char[t - n];
	for (int i = 0; i < Startpos; i++)
		temp[i] = str[i];
	for (int i = Startpos; i <= t; i++)
		temp[i] = str[i + n];
	delete[] str;
	str = temp;
}


/*-------------4------------*/
int kt(char *str, char* sub, int p)
{
	int t = stringlen(sub);
	int i = 0;
	while (i < t)
	{
		if (str[i] == sub[i]) i++;
		else return -1;
	}
	return p;
}

int FindSubString(char *str, char *sub, int p)
{
	int t1 = stringlen(str);
	int t2 = stringlen(sub);
	int result;
	for (int i = p; i <= t1 - t2; i++)
	{
		result = kt(str + i, sub, i);
		if (result != -1) return result;
	}
	return -1;

}


/*-------------5------------*/
bool IsSubString(char *str, char *sub)
{
	if (FindSubString(str, sub, 0) == -1) return false;
	else return true;
}


/*-------------6------------*/
int CountMatches(char *str, char *sub)
{
	int t = stringlen(str);
	int result = 0;
	for (int i = 0; i < t; i++)
	if (kt(str + i, sub, i) != -1) result++;
	return result;
}


void main()
{
	const int Max = 50;
	char *str = new char[Max];
	cout << "Moi nhap xau: " << endl;
	gets(str);

	char *examp1 = new char[Max];
	int *u = new int, *v = new int;
	cout << "Moi nhap vi tri va so ki tu can copy: " << endl;
	cin >> *u; cin >> *v;
	CopySubString(examp1, str, *u, *v);
	cout << examp1 << endl;
	delete[] examp1;
	delete u;
	delete v;

	char *examp2 = new char[Max];
	int *p = new int;
	cout << "Nhap xau can them vao va vi tri chen: " << endl;
	cin.ignore();
	gets(examp2);
	cin >> *p;
	InsertSubString(str, examp2, *p);
	cout << str << endl;
	delete[] examp2;
	delete p;

	int *Startpos = new int;
	int *n = new int;
	cout << "Nhap vao vi tri bat dau va so luong ki tu can xoa:" << endl;
	cin >> *Startpos;
	cin >> *n;
	DeleteSubString(str, *Startpos, *n);
	cout << str << endl;
	delete Startpos;
	delete n;

	char *examp3 = new char[Max];
	int *pos = new int;
	cout << "Nhap vao xau con can tim va vi tri bat dau tim:" << endl;
	cin.ignore();
	gets(examp3);
	cin >> *pos;
	cout << "Chuoi con xuat hien tu vi tri: ";
	cout << FindSubString(str, examp3, *pos) << endl;
	delete[] examp3;
	delete pos;

	char *examp4 = new char[Max];
	cout << "Nhap vao chuoi con can kiem tra:" << endl;
	cin.ignore();
	gets(examp4);
	if (!IsSubString(str, examp4)) cout << "Chuoi can tim khong nam trong xau" << endl;
	else cout << "Chuoi con can tim co trong xau" << endl;
	delete[] examp4;

	char *examp5 = new char[Max];
	cout << "Nhap vao chuoi can dem trong xau" << endl;
	gets(examp5);
	int *result = new int;
	*result = CountMatches(str, examp5);
	cout << "Chuoi con xuat hien " << *result << " lan trong xau " << endl;
	delete[] examp5;
	delete result;

	system("pause");
}