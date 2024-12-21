#include <iostream>
#include <locale>
#include <string>
#include <cctype>
#define NOMINMAX
#include <Windows.h>
using namespace std;

const int MAX = 1000;
int sayac = 0;

struct kişiler {
	string name;
	unsigned long long tel;
};

kişiler rehber[MAX];

void göster() {
	for (int i = 0; i < sayac - 1; i++) {
		for (int j = 0; j < sayac - i - 1; j++) {
			// İki stringi karşılaştırırken tolower kullanarak alfabetik kontrol
			string a = rehber[j].name, b = rehber[j + 1].name;
			for (char& c : a) c = tolower(c); // Tüm harfleri küçük yap
			for (char& c : b) c = tolower(c);

			if (a > b) { // Eğer j, j+1'den büyükse yer değiştir
				kişiler temp = rehber[j];
				rehber[j] = rehber[j + 1];
				rehber[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < sayac; i++) {
		cout << i + 1 << " " << rehber[i].name << " " << "0" << rehber[i].tel << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Turkish");
	SetConsoleOutputCP(1254);
	SetConsoleCP(1254);
	while (true) {
		system("CLS");
		göster();
		cout << "Düzenlemek(1) Silmek(2) Eklemek(3) Çıkmak(0) : ";
		int a;
		string _a;
		while (true) {
			cin >> _a;
			if (_a.length() > 1) {
				cout << "Tekrar dene: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi temizle continue; 
				continue;
			}
			if (!isdigit(_a[0])) {
				cout << "Tekrar dene: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi temizle continue; 
				continue;
			}
			a = stoi(_a);
			if ((sayac == 0) && (a == 1 || a == 2)) {
				cout << "Henüz listelenmiş kişi bulunmamaktadır. Tekrar deneyiniz: ";
				continue;
			}
			if (1 <= a && a <= 3) {
				break;
			}
			else if (a == 0) {
				return 0;
			}
			else {
				cout << "Tekrar dene: ";
			}
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (a == 1) {
			cout << "Değiştirmek istediğin kişi: ";
			int kişi;
			string _kişi;
			while (true) {
				cin >> _kişi;
				if (_kişi.length() != 1) {
					cout << "Tekrar dene: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi atla
					continue;
				}
				if (!isdigit(_kişi[0])) {
					cout << "Tekrar dene: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi temizle continue; 
					continue;
				}
				kişi = stoi(_kişi);
				if (1 <= kişi && kişi <= sayac) {
					break;
				}
				else {
					cout << "Tekrar dene: ";
				}
			}
			while (true) {
				cout << "İsim değiştirmek(1) Numara değiştirmek(2) Geri dönmek(0) : ";
				int işlem;
				string _işlem;
				while (true) {
					cin >> _işlem;
					if (_işlem.length() != 1) {
						cout << "Tekrar dene: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi atla
						continue;
					}
					if (!isdigit(_işlem[0])) {
						cout << "Tekrar dene: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi atla
						continue;
					}
					işlem = stoi(_işlem);
					if (işlem == 1) {
						cout << "Yeni isim: ";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						string yenisim;
						getline(cin, yenisim);
						rehber[kişi - 1].name = yenisim;
						break;
					}
					else if (işlem == 2) {
						cout << "Yeni tel: 0";
						unsigned long long yenitel;
						while (true) {
							cin >> yenitel;
							if (to_string(yenitel).length() != 10) {
								cout << "Tekrar dene: 0";
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								continue;
							}
							else if (cin.fail()) {
								cout << "Tekrar dene: 0";
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								continue;
							}
							else {
								break;
							}
						}
						rehber[kişi - 1].tel = yenitel;
						break;
					}
					else if (işlem == 0) {
						break;
					}
					else {
						cout << "Tekrar dene: ";
						cin >> işlem;
					}
				}
				if (işlem == 0)
					break;
			}
		}
		else if (a == 2) {
			int sil;
			string _sil;
			cout << "Silmek istediğin kişi : ";
			while (true) {
				cin >> _sil;
				if (_sil.length() != 1) {
					cout << "Tekrar dene: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi atla
					continue;
				}
				if (!isdigit(_sil[0])) {
					cout << "Tekrar dene: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girişi atla
					continue;
				}
				sil = stoi(_sil);
				if (1 <= sil && sil <= sayac) {
					rehber[sil - 1].name = "";
					rehber[sil - 1].tel = 0;
					for (int i = sil - 1; i < sayac; i++) {
						rehber[i].name = rehber[i + 1].name;
						rehber[i].tel = rehber[i + 1].tel;
					}
					sayac--;
					break;
				}
				else {
					cout << "Tekrar dene: ";
				}
			}
		}
		else if (a == 3) {
			cout << "İsim: ";
			string _isim;
			getline(cin, _isim);
			cout << "Tel: 0";
			unsigned long long _tel;
			while (true) {
				cin >> _tel;
				if (to_string(_tel).length() != 10) {
					cout << "Tekrar dene: 0";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				else if (cin.fail()) {
					cout << "Tekrar dene: 0";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				else {
					break;
				}
			}
			rehber[sayac].name = _isim;
			rehber[sayac].tel = _tel;
			sayac++;

		}
	}
}
