#include <iostream>
#include <fstream>

int d[22][22];
using namespace std;

void Load()
{
	ifstream p;
	p.open("data.txt");

	for (int i = 1; i < 21; i++){
		for (int j = 1; j < 21; j++) p >> d[j][i];
	}
	p.close();
}
void Step()
{

	int h_d[22][22];
	for (int y = 1; y < 21; y++){
		for (int x = 1; x < 21; x++)
		{
			int n = 0;
			n = d[x - 1][y - 1] + d[x][y - 1] + d[x + 1][y - 1] + d[x - 1][y] + d[x + 1][y] + d[x - 1][y + 1] + d[x][y + 1] + d[x + 1][y + 1];
			if (n == 3) h_d[x][y] = 1;
			else if (n == 2 && d[x][y] == 1) h_d[x][y] = 1;
			else h_d[x][y] = 0;
			
		}
	
	}
	for (int i = 1; i < 21; i++){
		for (int j = 1; j < 21; j++) d[j][i] = h_d[j][i];
	}

}
void Draw()
{
	cout << "\n";
	for (int i = 1; i < 21; i++){
		for (int j = 1; j < 21; j++) cout << d[j][i];
		cout << "\n";
	}
}

int main()
{
	for (int i = 0; i < 21; i++){
		d[i][0] = 0;
		d[i][21] = 0;
		d[0][i] = 0;
		d[21][i] = 0;
	}
	Load();
	cout << "Steps Number: ";
	int s;
	cin >> s;
	while (s>0)
	{
		Step();
		Draw();
		s--;
	}
}