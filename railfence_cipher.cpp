#include <iostream>
#include <string.h>
using namespace std;

string encryptRailFence(string &plaintext, int rails)
{
    string ciphertext, fence[rails];
    int rail = 0;
    bool directionDown = false;

    for (char ch : plaintext)
    {
        fence[rail] += ch;

        if (rail == 0 || rail == rails - 1)
            directionDown = !directionDown;

        rail += directionDown ? 1 : -1;
    }

    for (string &row : fence)
    {
        ciphertext += row;
    }

    return ciphertext;
}

string decryptRailFence(string &ciphertext, int rails)
{
    string plaintext, fence[rails];
    int index = 0, direction = 1;

    for (char ch : ciphertext)
    {
        fence[index] += ch;
        index += direction;
        if (index == 0 || index == rails - 1)
            direction = -direction;
    }
    // Construct the plaintext from the fence
    for (int i = 0; i < rails; ++i)
    {
        plaintext += fence[i];
    }
    return plaintext;
}

void menu()
{
    int ch;
    cout << "*******Rail Fence Cipher*******" << endl;
    cout << "Enter choice:\n 1. Encryption\n 2. Decryption\n";
    cin >> ch;
    if (ch == 1)
    {
        string msg;
        int rails;
        cout << "Enter Plain Text: ";
        cin.ignore();
        getline(cin, msg);
        cout << "Enter number of rails:";
        cin >> rails;
        cout << "Cipher Text: " << encryptRailFence(msg, rails);
    }

    if (ch == 2)
    {
        string cipher;
        int rails;
        cout << "Enter Cipher Text: ";
        cin.ignore();
        getline(cin, cipher);
        cout << "Enter number of rails:";
        cin >> rails;
        cout << "Plain Text: " << decryptRailFence(cipher, rails);
    }

    else
    {
        cout << "Invalid choice";
    }
}
int main()
{
    menu();
    return 0;
}
