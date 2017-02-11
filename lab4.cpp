#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

void XORcipher(string, string);

string cifradoCesar(string);

string Vigenere(string, string);

int main()
{
	string palabra, clave;
	
	cout << "Ingrese la palabra a cifrar: ";
	//cin >> palabra;
	getline(cin, palabra);

	cout << "Ingrese la clave para usar en el cifrado: ";
	cin >> clave;

	cout << "Cifrado Vigenere: "
	<< Vigenere(clave, palabra) << endl;
	
	cout << "Cifrado de Cesar: "
	<< cifradoCesar(palabra) << endl;
	
	cout << "Cifrado XOR: ";
	XORcipher(palabra, clave);
	

	cout << endl << "Triple cifrado: ";
	XORcipher(cifradoCesar(Vigenere(clave, palabra)), clave);

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

string cifradoCesar(string texto)
{
	char textoCifrado[texto.size() + 1];
	string textoCifradostr = "";
	for(int i = 0; i < texto.size(); i++)
	{
		if(texto[i] + 13 > 122)
			//textoCifrado[i] = ((texto[i] + 13) - 122) + 97;
			textoCifradostr += ((texto[i] + 13) - 122) + 97;
		else
			//textoCifrado[i] = texto[i] + 13;
			textoCifradostr = texto[i] + 13;

	}
	//cout << textoCifrado << endl;
	return textoCifradostr;
}

string Vigenere(string clave, string texto){
	char matriz[26][26];
	int y2 =97;
	for(int i =0; i<26; i++){
	        y2 = i + 97;
	        for(int j = 0; j<26; j++){
	                if(y2 > 122){
	                        y2 = 97;
	                }
	                matriz[i][j] = y2;
	                //cout << "[" << matriz[i][j] << "]";
	                ++y2;
	
	        }//cout << endl;
	}
	
	string abc = "abcdefghijklmnopqrstuvwxyz";	

	int cont = 0;

	string cifrado = "";
	for(int i = 0; i< texto.size(); i++){

		if(texto[i] == ' '){
			cifrado += " ";

		}else{
			int fil, col;
	
			col = abc.find(clave[cont]);
			fil = abc.find(texto[i]);
			
			cifrado += matriz[fil][col];
			
	
			cont++;
			if(cont==clave.length()){
				cont = 0;	
			}
		}

	}
	

	//cout << cifrado << endl;
	
	return cifrado;
}
