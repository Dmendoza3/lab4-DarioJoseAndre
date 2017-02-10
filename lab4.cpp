#include <iostream>
#include <vector>

using namespace std;

void Vigenere(string, string);



int main(){





	return 0;
}


void Vigenere(string clave, string texto){




	char matriz[26][26];
	int y2 =97;
	for(int i =0; i<26; i++){
	        y2 = i + 97;
	        for(int j = 0; j<26; j++){
	                if(y2 > 122){
	                        y2 = 97;
	                }
	                matriz[i][j] = y2;
	                cout << "[" << matriz[i][j] << "]";
	                ++y2;
	
	        }cout << endl;
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
	

	cout << cifrado << endl;

}
