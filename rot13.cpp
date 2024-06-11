// ROT-13 cipher is caesar cipher with shift value 3

#include <iostream>
#include <string.h>
using namespace std;

string encryptROT(string &plainText, int shiftVal)
{
    string cipherText = "";

    for (int i = 0; i < plainText.size(); i++)
    {
        if (isupper(plainText[i]))
            cipherText += (((int(plainText[i]) - 65) + shiftVal) % 26 + 65);

        else if (islower(plainText[i]))
            cipherText += (((int(plainText[i]) - 97) + shiftVal) % 26 + 97);
        else if (isspace(plainText[i]))
            cipherText += " ";
    }
    return cipherText;
}

string decryptROT(string &cipherText, int shiftVal)
{
    string plainText = "";

    for (int i = 0; i < cipherText.size(); i++)
    {
        if (isupper(cipherText[i]))
            plainText += (((int(cipherText[i]) - 65) - shiftVal) % 26 + 65);
        else if (islower(cipherText[i]))
            plainText += (((int(cipherText[i]) - 97) - shiftVal) % 26 + 97);
        else if (isspace(cipherText[i]))
            plainText += " ";
    }
    return plainText;
}

void menu()
{
    int ch;
    cout << "**********ROT-13**********" << endl;
    cout << "1. Encryption\n2.Decryption" << endl;
    cout << "Enter choice: ";
    cin >> ch;

    if (ch == 1)
    {
        int shiftVal;
        string plainText;
        cout << "Enter shift value: ";
        cin >> shiftVal;
        cout << "Enter Plain Text: ";
        cin.ignore();
        getline(cin, plainText);
        cout << "Cipher text: " << encryptROT(plainText, shiftVal) << endl;
    }

    if (ch == 2)
    {
        int shiftVal;
        string cipherText;
        cout << "Enter shift value: ";
        cin >> shiftVal;
        cout << "Enter Cipher Text: ";
        cin.ignore();
        getline(cin, cipherText);
        cout << "Plain text: " << decryptROT(cipherText, shiftVal) << endl;
    }

    else
    {
        cout << "Invalid choice" << endl;
    }
}

int main()
{
    menu();
    return 0;
}