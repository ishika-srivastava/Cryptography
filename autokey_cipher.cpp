#include <string.h>
#include <iostream>
using namespace std;

string encryptAutoKey(string &msg, int key)
{
    string cipher = "";
    int base = 0;

    for (int i = 0; i < msg.size(); i++)
    {
        if (isalpha(msg[i]))
        {
            base = isupper(msg[i]) ? 'A' : 'a';
            int pVal = msg[i] - base;
            int keyVal = (i == 0) ? key : (msg[i - 1] - base);
            int cVal = (pVal + keyVal) % 26;
            cipher += char(cVal + base);
        }
        else
            continue;
    }
    return cipher;
}

string decryptAutoKey(string &cipher, int key)
{
    string msg = "";
    int base = 0;

    for (int i = 0; i < cipher.size(); i++)
    {
        if (isalpha(cipher[i]))
        {
            base = isupper(cipher[i]) ? 'A' : 'a';
            int cVal = cipher[i] - base;
            int keyVal = (i == 0) ? key : (msg[i - 1] - base);
            int pVal = (cVal - keyVal + 26) % 26;
            msg += char(pVal + base);
        }
        else
            continue;
    }
    return msg;
}

void menu()
{
    int ch;
    cout << "**********Auto Key Cryptography**********" << endl;
    cout << "Enter choice:\n 1. Encryption \n 2. Decryption\n";
    cin >> ch;
    if (ch == 1)
    {
        string msg;
        int key;
        cout << "Enter Plain Text: ";
        cin.ignore();
        getline(cin, msg);
        cout << "Enter key:";
        cin >> key;
        cout << "Cipher Text: " << encryptAutoKey(msg, key);
    }

    if (ch == 2)
    {
        string cipher;
        int key;
        cout << "Enter Cipher Text: ";
        cin.ignore();
        getline(cin, cipher);
        cout << "Enter key:";
        cin >> key;
        cout << "Plain Text: " << decryptAutoKey(cipher, key);
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
