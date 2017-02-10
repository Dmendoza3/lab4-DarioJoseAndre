#include <iostream>

using namespace std;

void cifradoCesar(string);

int main()
{
	return 0;
}

void cifradoCesar(string texto)
{
	char textoCifrado[texto.size()];
	for(int i = 0; i < texto.size(); i++)
	{
		if(texto[i] + 13 > 122)
			textoCifrado[i] = ((texto[i] + 13) - 122) + 97;
		else
			textoCifrado[i] = texto[i] + 13;
	}
	cout << textoCifrado << endl;
}
