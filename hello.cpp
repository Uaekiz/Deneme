#include <iostream>
#include <locale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Turkish");
    cout << "Merhaba, Dünya!"<<endl;
    return 0;
}
