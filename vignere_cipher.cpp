#include <string.h>
#include <iostream>
using namespace std;

string encryptVigenere(string &msg, string &key)
{
    string cipher = "";
    int keyIndex = 0;

    for (size_t i = 0; i < msg.size(); ++i)
    {
        if (isalpha(msg[i]))
        {
            char base = isupper(msg[i]) ? 'A' : 'a';
            int pVal = msg[i] - base;
            int keyVal = key[keyIndex] - 'A'; // Assuming key is uppercase
            int cVal = (pVal + keyVal) % 26;
            cipher += char(cVal + base);

            keyIndex = (keyIndex + 1) % key.size();
        }
        else
        {
            cipher += msg[i]; // If the character is not an alphabet, leave it unchanged
        }
    }

    return cipher;
}

string decryptVigenere(string &cipher, string &key)
{
    string decryptedMsg = "";
    int keyIndex = 0;

    for (size_t i = 0; i < cipher.size(); ++i)
    {
        if (isalpha(cipher[i]))
        {
            char base = isupper(cipher[i]) ? 'A' : 'a';
            int cVal = cipher[i] - base;
            int keyVal = key[keyIndex] - 'A'; // Assuming key is uppercase
            int pVal = (cVal - keyVal + 26) % 26;
            decryptedMsg += char(pVal + base);

            keyIndex = (keyIndex + 1) % key.size();
        }
        else
        {
            continue;
        }
    }

    return decryptedMsg;
}

void menu()
{
    int ch1;
    cout << "*******Vignere Cipher*******" << endl;
    cout << "Enter choice:\n 1. Encryption\n 2. Decryption\n";
    cin >> ch1;

    if (ch1 == 1)
    {
        string msg;
        string key;
        cout << "Enter Plain Text: ";
        cin.ignore();
        getline(cin, msg);
        cout << "Enter key:";
        cin >> key;
        cout << "Cipher Text: " << encryptVigenere(msg, key);
    }

    if (ch1 == 2)
    {
        string cipher;
        string key;
        cout << "Enter Cipher Text: ";
        cin.ignore();
        getline(cin, cipher);
        cout << "Enter key:";
        cin >> key;
        cout << "Plain Text: " << decryptVigenere(cipher, key);
    }
}

int main()
{
    menu();
    return 0;
}
