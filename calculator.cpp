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
	cout << "Hoşgeldiniz! ";
        basaal:
        cout<<"Lütfen işleminizi seçiniz(+,-,*,/,^,^/,PI,Q): ";
	string işlem;
	getline(cin,işlem);
	while (true)
	{
		if (işlem != "+" && işlem != "-" && işlem != "*" && işlem != "/" && işlem != "^" && işlem != "^/" && işlem != "PI" && işlem != "Q" && işlem != "q" && işlem != "pi")
		{
			cout << "Yanlış karakter girişi! Lütfen tekrar deneyiniz ";
			getline(cin,işlem);
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
	if (işlem == "PI" || işlem == "pi")
	{
		cout << "Lütfen yarıçapını giriniz: ";
		cin >> a;
		sonuçlar(2 * M_PI * a);
	}
	if (işlem == "Q" || işlem == "q")
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
                        double result = cos(radyan);
                        if(abs(result) < 1e-9)
                        {
                           sonuçlar(0);
                        }
                        else
                        {		
			sonuçlar(cos(radyan));
                        }
		}
		if (açı == "sin")
		{
			double result = sin(radyan);
                        if(abs(result) < 1e-9)
                        {
                           sonuçlar(0);
                        }
                        else
                        {
                        sonuçlar(sin(radyan));
                        }
		}
		if (açı == "tan")
		{
			if ((a-90)/180 == static_cast<int>((a-90)/180))
			{
				cout << "Tanımsız..."<<endl;
			}

                        else 
                        {
                                double result = tan(radyan);
                                if(abs(result) < 1e-9)
                                {
                                    sonuçlar(0);
                                }
                                else
                                {
                                    sonuçlar(tan(radyan));
                                }
                        }
		}
	}

        string x;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
                        cout << "Devam etmek istermisiniz(e/h)? ";
                        getline(cin,x);
	                if (x.length() != 1 || (x[0] != 'h' && x[0] != 'H' && x[0] != 'e' && x[0] != 'E'))
	                {
		        cout << "Yanlış karakter girişi! Lütfen tekrar deneyiniz ";
	                }
	                else if (x[0] == 'h' || x[0] == 'H')
	                {
		        cout << "Çıkış yapılıyor..."<<endl;
		        return 0;
	                }
	                else
		        goto basaal;
                        }
}
