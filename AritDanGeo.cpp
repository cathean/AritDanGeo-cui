/////////////////////////////////////////////////
/// Buatan IVAN
///
/// Compiler MinGW
/// Aritematika dan Geometri
///
/// *Masih sedikit bug :P*
/// *ZIG-ZAG-ZIG-ZAG-ZOW*
/////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

//Enumerasi
enum Temp {TidakAda};

//Prototipe fungsi
string is_aritmetika(float arr[], int n);
string is_geometri(float arr[], int n);
float geometri_rasio(float arr[], int n);
float suku_ke_n(float a, float b, int n);
float suku_ke_n_geometri(float a, int n, float r);
float suku_tengah(int banyak_suku, float bilangan[]);
char show_menu(int banyak_suku, float bilangang[], float a, float b, float r);


//Definisi fungsi
string is_aritmetika(float arr[], int n) //Check apakah bilangan / deret itu aritematika
{
    float temp_b1 = 0;
    float temp_b2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(i < n - 1)
        {
            temp_b1 = arr[i + 1] - arr[i];
        }

        if(i < (n - 2))
        {
            temp_b2 = arr[i + 2] - arr[i + 1];
        }

        if(temp_b1 != temp_b2)
        {
            return "TIDAK";
        }
    }

    return "YA";
}

string is_geometri(float arr[], int n) //Check apakah deret itu geometri
{
    float temp_b1 = 0;
    float temp_b2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(i < n - 1)
        {
            temp_b1 = arr[i + 1] / arr[i];
        }

        if(i < (n - 2))
        {
            temp_b2 = arr[i + 2] / arr[i + 1];
        }

        if(temp_b1 != temp_b2)
        {
            return "TIDAK";
        }
    }

    return "YA";
}

float geometri_rasio(float arr[], int n) //Cari geometri
{
    float temp_b1 = 0;
    float temp_b2 = 0;
    Temp msg = TidakAda;

    for(int i = 0; i < n; i++)
    {
        if(i < n - 1)
        {
            temp_b1 = arr[i + 1] / arr[i];
        }

        if(i < (n - 2))
        {
            temp_b2 = arr[i + 2] / arr[i + 1];
        }

        if(temp_b1 != temp_b2)
        {
            return msg;
        }
    }

    return temp_b1;
}

float suku_ke_n(float a, float b, int n) //Cari nilai pada suku ke-n
{
    float jawab;
    jawab = a + (n - 1) * b;

    return jawab;
}

float suku_ke_n_geometri(float a, int n, float r) //Cari nilai pada suku ke-n di geometri
{
    int jawab = a * pow(r, n - 1);

    return jawab;
}

float suku_tengah(int banyak_suku, float bilangan[]) //Cari nilai pada suku ke tengah
{
    float jawab = (float)(bilangan[0] + bilangan[banyak_suku - 1]) / 2.0;

    return jawab;
}

char show_menu(int banyak_suku, float bilangan[], float a, float b, float r) //Show menu
{
    char pilih;
    int n;

    //####################################################
    //Perlihatkan menu
    //####################################################
    cout << "==========" <<endl;
    cout << "Menu" <<endl;
    cout << "==========" <<endl;
    cout << "a)Cari nilai suku ke-n pada deret aritmetika" <<endl;;
    cout << "b)Cari nilai suku ke-n pada deret geometri" <<endl;
    cout << "c)Cari suku tengah" <<endl;
    cout << "d)Ganti bilangan/deret" <<endl;
    cout << "q)Exit" <<endl;
    cout << "==========" <<endl;
    cout << "Pilih : ";
    cin >> pilih;

    if(pilih == 'd')
    {
        return pilih;
    }
    else if(pilih == 'q')
    {
        system("cls");

        cout << "Bye." <<endl;

        system("pause");
        return 0;
    }

    switch(pilih)
    {
    case 'a' :
        system("cls");

        cout << "Pesan : Mencari nilai suku ke-n pada barisan/deret bilangan dan aritmetika" <<endl;
        cout << "==========" <<endl;
        cout << "Masukkan suku n : ";
        cin >> n;
        cout << "Jawab : Nilai pada suku ke-" << n << " adalah = " << suku_ke_n(a, b, n) <<endl;

        system("pause");
        system("cls");
        return pilih;
        break;
    case 'b' :
        system("cls");

        //Out bila r = 0
        if(r == 0)
        {
            cout << "Barisan/Deret bukan geometri" <<endl;
            system("pause");
            system("cls");
            return pilih;
            break;
        }

        cout << "Pesan : Mencari nilai suku ke-n pada deret geometri" <<endl;
        cout << "==========" <<endl;
        cout << "Masukkan suku n : ";
        cin >> n;
        cout << "Jawab : Nilai pada suku ke-" << n << " adalah = " << suku_ke_n_geometri(a, n, r) <<endl;;

        system("pause");
        system("cls");
        return pilih;
        break;
    case 'c' :
        system("cls");

        cout << "Pesan : Mencari suku tengah" <<endl;
        cout << "==========" <<endl;
        cout << "Suku tengah = " << suku_tengah(banyak_suku, bilangan) <<endl;

        system("pause");
        system("cls");
        return pilih;
        break;

    default :
        pilih = 'z';
        return pilih;
        break;
    }
}

int main() //Main
{
    char option;

    do
    {
        system("cls");

        //####################################################
        //Input bilangan
        //####################################################
        int banyak_suku;

        //Cari banyak suku yang diketahui
        cout << "Banyak suku yang diketahui : ";
        cin >> banyak_suku;

        float bilangan[banyak_suku];

        //Cari bilangan
        cout << "Masukkan bilangan : ";

        for(int i = 0; i < banyak_suku; i++)
        {
            cin >> bilangan[i];
        }

        system("cls");

        //####################################################
        //Perlihatkan info
        //####################################################
        do
        {
        cout << "==========" <<endl;
        cout << "Info" <<endl;
        cout << "==========" <<endl;

        //Banyak Suku
        cout << "Banyak suku : " << banyak_suku <<endl;

        //Perlihatkan barisan bilangan & deret bilangan
        //-Barisan
        cout << "Barisan bilangan : ";

        for(int i = 0; i < banyak_suku - 1; i++)
        {
            cout << bilangan[i] << ", ";
        }

        cout << bilangan[banyak_suku - 1] <<endl;
        //-Deret
        cout << "Deret bilangan : ";

        for(int i = 0; i < banyak_suku - 1; i++)
        {
            cout << bilangan[i] << " + ";
        }

        cout << bilangan[banyak_suku - 1] <<endl;

        //awal(a), beda(b), rasio(r)
        float a = bilangan[0];
        float b = bilangan[1] - bilangan[0];
        float r = geometri_rasio(bilangan, banyak_suku);

        cout << "Awal (a) = " << a <<endl;
        cout << "Beda (b) = " << b <<endl;

        //Check apakah aritmaatik
        cout << "Aritmetika (?) = " << is_aritmetika(bilangan, banyak_suku) <<endl;

        //Check apakah geometri dan perlihatkan rasionya
        cout << "Geometri (?) = " << is_geometri(bilangan, banyak_suku) <<endl;
        //Check apakah rasionya 0 jika tidak perlihatkan rasionya
        if(r == 0)
        {
            cout << "Rasio geometri = Barisan/Deret bukan geometri" <<endl <<endl;
        }
        else
        {
            cout << "Rasio geometri = " << r <<endl <<endl;
        }

        //####################################################
        //Perlihatkan menu
        //####################################################
        option = show_menu(banyak_suku, bilangan, a, b, r);

        if(option == 'a' || option == 'b' || option == 'c' || option == 'z')
        {
            system("cls");
        }

        }while(option == 'a' || option == 'b' || option == 'c' || option == 'z');
    }while(option == 'd');

    return 0;
}
