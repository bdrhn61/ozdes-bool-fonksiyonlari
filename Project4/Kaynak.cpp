// Your First C++ Program

#include <iostream>
#include <string>  
using namespace std;
const int satir = 5;
const int sutun = 3;
string metrik(int dizi[][sutun]);
void ikilikTaban(int sayi, int satir);
void ikilikTaban2(int sayi, int satir);
void degerAl();
bool kontrol();
void bulVeAcikla();
void ozdesMi();
void metrikYaz();
void metrikYaz2();

void swap(char* first, char* second);
void stringPermutasyon(string& word, int current, int length);
void stringPermutasyon(string& word);
int fx[5];
string gx;
string olasigx[1000];
int vecf[4] = { 0,0,0,0 };
int vecg[4] = { 0,0,0,0 };
int dizi[satir][sutun];
int dizi2[satir][sutun];

int main() {

	degerAl();
	for(int i=0;i<5;i++)
	ikilikTaban(fx[i],i);
	
	for (int i = 0; i < 5; i++)
	ikilikTaban2(int(gx[i]-48), i);
	
	ozdesMi();
	/*cout << endl;
	cout << gx;*/

	stringPermutasyon(gx);
	for (int i = 0; i < 120; i++){
		
		for (int j = 0; j < 5; j++) {
			//cout << int(olasigx[i][j]) << endl;
			ikilikTaban2(int(olasigx[i][j]-48), j);
			
			
		}
		
		if (kontrol()==true)
			break;
		
	}
	

	
	cout << "f(x) : "<< endl;
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			cout << dizi[i][j] << "\t";
		}
		cout << endl;
	}
	string hmu = metrik(dizi);
	reverse(hmu.begin(), hmu.end());
	cout << endl <<"f(x) icin hamming uzakligi :"<< endl << hmu <<endl;
	cout <<endl<< "f(x)' in metrik vektoru : " <<endl;
	metrikYaz();

	cout << endl << "---------------------------------------------------" << endl;
	cout << "g(x) : "<< endl;
	
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			cout << dizi2[i][j] << "\t";
		}
		cout << endl;
	}
	  hmu = metrik(dizi2);
	 reverse(hmu.begin(), hmu.end());
	 cout << endl << "g(x) icin hamming uzakligi :" << endl << hmu <<endl;
	 cout<<endl << "g(x)' in metrik vektoru  :"<<endl;
	 metrikYaz2();

	 cout << endl; cout << endl;
	 bulVeAcikla();
	 cout << endl; cout << endl;
    return 0;
}
void metrikYaz() {
	for (int i = 0; i < 4; i++) {
		if(vecf[i]!=0)
		cout<<" - " << vecf[i]<<" - ";
	}
}
void metrikYaz2() {
	for (int i = 0; i < 4; i++) {
		if (vecg[i] != 0)
			cout << " - " << vecg[i] << " - ";
	}
}
void ozdesMi() {
	bool esitmi = true;
	string sayi = { "0123"};
	 
	
	string metrik1 = metrik(dizi);
	string metrik2 = metrik(dizi2);
	

	for (int i = 0; i < 10; i++) {
		if (metrik1[i] == sayi[0])
			vecf[0]++;
		if (metrik1[i] == sayi[1])
			vecf[1]++;
		if (metrik1[i] == sayi[2])
			vecf[2]++;
		if (metrik1[i] == sayi[3])
			vecf[3]++;


		if (metrik2[i] == sayi[0])
			vecg[0]++;
		if (metrik2[i] == sayi[1])
			vecg[1]++;
		if (metrik2[i] == sayi[2])
			vecg[2]++;
		if (metrik2[i] == sayi[3])
			vecg[3]++;

		 
	}

	for (int i = 0; i < 4; i++) {
		

		if (vecf[i] != vecg[i]) {
			esitmi = false;
			break;
		}
	}
	if (esitmi == false)
		cout<< "Fonksiyonlar ozdes degil"<<endl << endl;
	else 
		cout<< "Fonksiyonlar ozdes" << endl << endl;

}
void bulVeAcikla() {
	string temp[3] = { "","","" };
	string tempters[3] = { "","","" };
	string temp2 = "";
	string aciklama = "";
	for (int i = 0; i < sutun; i++) {

		for (int j = 0; j < satir; j++) {

			temp[i] = to_string(dizi[j][i]) + temp[i];
			tempters[i] = to_string(abs(dizi[j][i]-1)) + tempters[i];
		}
	}
	for (int i = 0; i < sutun; i++) {
		temp2 = "";
		for (int j = 0; j < satir; j++) {
			temp2 = to_string(dizi2[j][i]) + temp2;

		}
		//cout << temp2 << "  temp2" << endl;
		for (int k = 0; k < 3; k++) {
			if (temp[k] == temp2) {
				aciklama = aciklama + to_string(i + 1) + ".sutun  x" + to_string(k + 1)+"    --    ";
			}
		}
	}


	for (int i = 0; i < sutun; i++) {
		temp2 = "";
		for (int j = 0; j < satir; j++) {
			temp2 = to_string(dizi2[j][i]) + temp2;

		}
		//cout << temp2 << "  temp2" << endl;
		for (int k = 0; k < 3; k++) {
			if (tempters[k] == temp2) {
				aciklama = aciklama + to_string(i + 1) + ".sutun  x" + to_string(k + 1)+"'un tersi    --    ";
			}
		}
	}
	cout << aciklama ;
}

bool kontrol() {
	bool deger = true;
	for (int i = 0; i < 10; i++) {
		if (metrik(dizi) ==  metrik(dizi2)) {
			 deger = true;
		}
		else {
			return false;
		}
		
	}
	return deger;
	
}

void degerAl() {
	string temp="";
	string virgul=",";

	cout << "f(x) gir :" << endl;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ".  ";

		cin >> fx[i];
	}
	cout << endl << "fx(";
	for (int i = 0; i < 5; i++) {
		if (i == 4)
			virgul = "";
		cout << fx[i] << virgul;
	}
		
	cout << ")" << endl << "---------" << endl<< endl;

	cout << "g(x) gir :" << endl;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ".  ";

		cin >> temp;
		gx = gx+ temp;
	}
	virgul = ",";
	cout << endl << "gx(";
	for (int i = 0; i < 5; i++){
		if (i == 4)
			virgul = "";
		cout << gx[i] << virgul;
	}
	
	cout << ")" << endl << "---------" << endl<< endl;

}
void ikilikTaban(int sayi, int satir) {
	int  s = 0, i = 0, basamak; 
	
	while (sayi > 0) {
		// Çevirme iþleminin yapýlmasý   
		basamak = (int)((sayi % 2) * pow(10, i));
		i++;
		sayi = sayi / 2;
		s = s + basamak;
		
	}
	string temp = to_string(s);
	if (temp.length() == 1) {
		temp = "00" + temp;
	}
	else if (temp.length() == 2) {
		temp = "0" + temp;
	}
	else if (temp.length() == 0) {
		cout << "hata binary bos";
	}
	//cout << temp << endl;  // Çevrilen sayýnýn ekrana yazdýrýlmasý
	dizi[satir][0] = int(temp[0] - 48);
	dizi[satir][1] = int(temp[1] - 48);
	dizi[satir][2] = int(temp[2] - 48);
	/*cout << (temp[0]) <<"*" << endl;
	cout << (temp[1]) << "*" << endl;
	cout << (temp[2]) << "*" << endl;*/
}
void ikilikTaban2(int sayi, int satir) {
	int  s = 0, i = 0, basamak;

	while (sayi > 0) {
		// Çevirme iþleminin yapýlmasý   
		basamak = (int)((sayi % 2) * pow(10, i));
		i++;
		sayi = sayi / 2;
		s = s + basamak;

	}
	string temp = to_string(s);
	if (temp.length() == 1) {
		temp = "00" + temp;
	}
	else if (temp.length() == 2) {
		temp = "0" + temp;
	}
	else if (temp.length() == 0) {
		cout << "hata binary bos";
	}
	//cout << temp << endl;  // Çevrilen sayýnýn ekrana yazdýrýlmasý
	dizi2[satir][0] = int(temp[0] - 48);
	dizi2[satir][1] = int(temp[1] - 48);
	dizi2[satir][2] = int(temp[2] - 48);
	
}

string metrik(int dizi[][sutun]) {
	string don = "";
	int hammingVec[10];
	int hamming = 0;
	int k = 0;

	for (int j = 0; j < satir - 1; j++) {
		for (int i = j + 1; i < satir; i++) {
			hamming = abs(dizi[j][0] - dizi[i][0]) + abs(dizi[j][1] - dizi[i][1]) + abs(dizi[j][2] - dizi[i][2]);
			hammingVec[k] = hamming;
			k++;

		}
	}

	for (int i = 0; i < 10; i++) {
		don = to_string(hammingVec[i]) +don;
		
	}
	/*cout << endl;
	cout << "------------------------------"<< endl;*/

	return don;
}

void swap(char* first, char* second)
{
	char temp = *first;
	*first = *second;
	*second = temp;
}


int l = 0;
void stringPermutasyon(string& word, int current, int length)
{
	if (current == length - 1){
		//cout << word << endl;
		olasigx[l]= word;
		l++;
	}
	else
	{
		for (int i = current; i < length; i++)
		{
			swap(&word[current], &word[i]);
			stringPermutasyon(word, current + 1, length);
			swap(&word[current], &word[i]);
		}
	}
}

void stringPermutasyon(string& str)
{
	string word = str;
	int length = word.length();
	int curr = 0;
	stringPermutasyon(word, curr, length);
}