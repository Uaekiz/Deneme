#include<iostream>
#include<cmath>
#include<locale>
#include<string>
#define M_PI 3.14159265358979323846
using namespace std;
double r;

void sonuçlar(double cevap)
{
	cout << "Cevabınız: "<<cevap<<endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish"); 
	double a, b, c, radyan;
	cout << "Hoşgeldiniz! Lütfen işleminizi seçiniz(+,-,*,/,^,^/,PI,Q): ";
	string işlem;
	cin >> işlem;
	while (true)
	{
		if (işlem != "+" && işlem != "-" && işlem != "*" && işlem != "/" && işlem != "^" && işlem != "^/" && işlem != "PI" && işlem != "Q")
		{
			cout << "Yanlış karakter girişi! Lütfen tekrar deneyiniz ";
			cin >> işlem;
		}
		else
		{
			break;
		}
	}
	if (işlem == "+")
	{
		cout << "İlk sayınızı giriniz: ";
		cin >> a;
		cout << "İkinci sayıyı giriniz: ";
		cin >> b;
		sonuçlar(a + b);
	}
	if (işlem == "-")
	{
		cout << "İlk sayınızı giriniz: ";
		cin >> a;
		cout << "İkinci sayıyı giriniz: ";
		cin >> b;
		sonuçlar(a - b);
	}
	if (işlem == "*")
	{
		cout << "İlk sayınızı giriniz: ";
		cin >> a;
		cout << "İkinci sayıyı giriniz: ";
		cin >> b;
		sonuçlar(a * b);
	}
	if (işlem == "/")
	{
		cout << "İlk sayınızı giriniz: ";
		cin >> a;
		cout << "İkinci sayıyı giriniz: ";
		cin >> b;
		sonuçlar(a / b);
	}
	if (işlem == "^")
	{
		cout << "İlk sayınızı giriniz: ";
		cin >> a;
		cout << "İkinci sayıyı giriniz: ";
		cin >> b;
		sonuçlar(pow(a,b));
	}
	if (işlem == "^/")
	{
		cout << "İşlem a ^ b/c formatındadır." << endl;
		cout << "İlk sayınızı giriniz: ";
		cin >> a;
		cout << "İkinci sayıyı giriniz ";
		cin >> b;
		cout << "Üçüncü sayıyı da giriniz: ";
		cin >> c;
		sonuçlar(pow(a,b/c));
	}
	if (işlem == "PI")
	{
		cout << "Lütfen yarıçapını giriniz: ";
		cin >> a;
		sonuçlar(2 * M_PI * a);
	}
	if (işlem == "Q")
	{
		cout << "Lütfen açıyı giriniz: ";
		cin >> a;
		cout<<"lütfen işlem türünü seçiniz(cos,sin,tan): ";
		string açı;
		cin >> açı;
		radyan =  a * M_PI / 180.0;
		while (true)
		{
			if (açı != "cos" && açı != "sin" && açı != "tan")
			{
				cout << "Yanlış karakter girişi! Lütfen tekrar deneyiniz ";
				cin >> açı;
			}
			else
			{
				break;
			}
		}
		if (açı == "cos")
		{			
			sonuçlar(cos(radyan));
		}
		if (açı == "sin")
		{
			sonuçlar(sin(radyan));
		}
		if (açı == "tan")
		{
			if (a == 90 || a == 270 || a == -90 || a == -270)
			{
				cout << "Tanımsız";
			}
			else
			{
				sonuçlar(tan(radyan));
			}
		}
	}
        
	return 0;
}
