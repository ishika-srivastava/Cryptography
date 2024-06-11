#include <iostream>
#include <string.h>
using namespace std;

string encryptCaesar(string &msg, int key)
{
    string cipher = "";
    for (int i = 0; i < msg.size(); i++)
    {
        if (isupper(msg[i]))
            cipher += (((int(msg[i]) - 65) + key) % 26 + 65);

        else if (islower(msg[i]))
            cipher += (((int(msg[i]) - 97) + key) % 26 + 97);
        else if (isspace(msg[i]))
            cipher += " ";
    }
    return cipher;
}

string decryptCaesar(string &cipher, int key)
{
    string msg = "";
    for (int i = 0; i < cipher.size(); i++)
    {
        if (isupper(cipher[i]))
            msg += (((int(cipher[i]) - 65) - key + 26) % 26 + 65);

        else if (islower(cipher[i]))
            msg += (((int(cipher[i]) - 97) - key + 26) % 26 + 97);
        else if (isspace(cipher[i]))
            msg += " ";
    }
    return msg;
}

void menu()
{
    cout << "-------------------- Caesar Cipher --------------------" << endl;
    int ch;
    cout << "1. Encryption\n2. Decryption\n";
    cout << "Enter choice: ";
    cin >> ch;

    if (ch == 1)
    {
        string msg;
        int key;
        cout << "Enter Plain Text: ";
        cin.ignore();
        getline(cin, msg); // allows input separated by spaces as well
        cout << "Enter key:";
        cin >> key;
        cout << "Cipher Text: " << encryptCaesar(msg, key); // calls encryptCaesar function amd prints the value returned by it
    }

    if (ch == 2)
    {
        string cipher;
        int key;
        cout << "Enter Cipher Text: ";
        cin.ignore();
        getline(cin, cipher); // allows input separated by spaces as well
        cout << "Enter key:";
        cin >> key;
        cout << "Plain Text: " << decryptCaesar(cipher, key); // calls decryptCaesar function amd prints the value returned by it
    }
}

int main()
{
    menu(); // calls menu function
    return 0;
}
