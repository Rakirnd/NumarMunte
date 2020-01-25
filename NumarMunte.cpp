#include <iostream>

#define ASC 0
#define DESC 1

using namespace std;

int numarMunte(int n)
{

    int cifre_n[10];
    int cifre_index = 0;
    int direction = ASC;

    for (int i = 0; i < 10; i++)
        cifre_n[i] = 0;

    while (n > 0)
    {

        cifre_n[cifre_index++] = n % 10;
        n = n / 10;

    }

    //cout << "Cifrele lui n sunt: ";
    //for (int i = 0; i < cifre_index; i++)
    //    cout << cifre_n[i] << " ";
    //cout << endl;

    if ((cifre_n[0] >= cifre_n[1]) || (cifre_n[cifre_index - 2] <= cifre_n[cifre_index - 1]))
        return 0;

    for (int i = 1; i < cifre_index; i++)
    {

        if (cifre_n[i - 1] == cifre_n[i])
            return 0;

        if (cifre_n[i - 1] > cifre_n[i] && direction == ASC)
            direction = DESC;

        if (cifre_n[i - 1] < cifre_n[i] && direction == DESC)
            return 0;

    }

    return 1;

}

int main()
{

    int n;
    int input_arr[10];

    cout << "Introduceti n: ";
    cin >> n;
    cout << endl;

    cout << "Introduceti numerele de intrare: ";
    for (int i = 0; i < n; i++)
        cin >> input_arr[i];
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if(input_arr[i] < 100 || input_arr[i] > 2000000000)
            cout << "Numarul este in afara intervalului specificat\n";
        else
            cout << numarMunte(input_arr[i]) << endl;

    }
        

    return 0;

}