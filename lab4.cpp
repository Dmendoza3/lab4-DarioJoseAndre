#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void XORcipher(string, string);

int main()
{
	string palabra, clave;
	
	cout << "Ingrese la palabra a cifrar: ";
	cin >> palabra;

	cout << "Ingrese la clave para usar en el cifrado: ";
	cin >> clave;

	cout << "Cifrado Vigenere: ";
	Vigenere(clave, palabra);
	
	cout << "Cifrado de Cesar: ";
	cifradoCesar(palabra);
	
	cout << "Cifrado XOR: ";
	XORcipher(palabra, clave);
	
	return 0;
}

string stringTobit(string txt)
{
	string bits = "";
	for(int i = 0; i < txt.size(); i++)
	{
		short shortChar = txt.at(i);
		bitset<16> bitChar(shortChar);
		string bitString = bitChar.to_string();
		
		bits += bitString.substr(8);
	}

	return bits;
}

void XORcipher(string palabra, string clave)
{	
	//255 char max
	bitset<2040> bitPalabra(stringTobit(palabra));
	bitset<2040> bitClave(stringTobit(clave));

	/*cout << "palabra: " <<bitPalabra
									.to_string()
												.substr
												(
														bitPalabra.to_string().find("1") //No muestra los cero antes del primer 1
												)
	<< endl
	<< "clave: " << bitClave
							.to_string()
										.substr
										(
											bitClave.to_string().find("1")
										);*/
	
	bitset<2040> bitCipher = (bitPalabra^=bitClave); //XOR
	string cipherStr = 	bitCipher.to_string().substr(bitCipher.to_string().find("1"));

	for(int i = 0; i < 8 - (cipherStr.size() % 8); i++) //Agregar 0s al inicio del binario
		cipherStr.insert(0,"0");	
	
	//cout << endl  << "Cifrado(binario): " << cipherStr << endl;
	
	//cout << "Cifrado(Decimal): ";

	for(int i = 0; i <= cipherStr.size() / 8; i++) //Separar el binario
	{
		bitset<8> charBit(cipherStr.substr(i * 8,8));
		cout << charBit.to_ulong() << " ";
	}
	
	cout << endl;
}
