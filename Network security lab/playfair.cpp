#include<bits/stdc++.h>
using namespace std;

int main()
{
    int key, ciphercode;
    string plaintext, spaceRemovePlain = "", ciphertext, mainCipher, PlainText = "", mainPlaintext = "";

    // 5x5 Playfair key table for lowercase and uppercase letters
    char p[5][5] = {{'l', 'g', 'd', 'b', 'a'}, {'q', 'm', 'h', 'e', 'c'}, {'u', 'r', 'n', 'i', 'f'}, {'x', 'v', 's', 'o', 'k'}, {'z', 'y', 'w', 't', 'p'}};
    char c[5][5] = {{'L', 'G', 'D', 'B', 'A'}, {'Q', 'M', 'H', 'E', 'C'}, {'U', 'R', 'N', 'I', 'F'}, {'X', 'V', 'S', 'O', 'K'}, {'Z', 'Y', 'W', 'T', 'P'}};

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    int len = plaintext.length();

    // Remove spaces from plaintext
    for (int i = 0; i < len; i++) {
        if (plaintext[i] != ' ') {
            spaceRemovePlain += plaintext[i];
        }
    }

    cout << "After removing spaces, the plaintext is: " << spaceRemovePlain << endl;

    // Pair two characters
    for (int i = 0; i < spaceRemovePlain.length(); i++) {
        if (spaceRemovePlain[i] == spaceRemovePlain[i + 1]) {
            PlainText += spaceRemovePlain[i];
            PlainText += 'x'; // Insert 'x' between repeated letters
        } else {
            PlainText += spaceRemovePlain[i];
            if (spaceRemovePlain[i + 1] == '\0') // Add a space or an extra character to make a complete pair
                PlainText += ' ';
            else
                PlainText += spaceRemovePlain[i + 1];
            i++; // Skip the next letter since it's already paired
        }
    }

    int length = PlainText.length();

    if (length % 2 == 0 && PlainText[length - 1] == ' ') {
        PlainText[length - 1] = 'x'; // If even length but last character is space, replace it with 'x'
    } else if (length % 2 != 0 && PlainText[length - 1] == ' ') {
        PlainText.pop_back(); // If odd length and last character is space, remove it
    } else if (length % 2 != 0 && PlainText[length - 1] != ' ') {
        PlainText.push_back('x'); // If odd length and last character is not space, add 'x' to make a full pair
    }

    cout << "Final processed plaintext for encryption: " << PlainText << endl;

    // Encryption
    int x1, x2, y1, y2;

    for (int l = 0; l < PlainText.length(); l += 2) {
        // Find the position of the first letter
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (PlainText[l] == p[i][j]) {
                    x1 = i; y1 = j; break;
                }
            }
        }

        // Find the position of the second letter
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (PlainText[l+1] == p[i][j]) {
                    x2 = i; y2 = j; break;
                }
            }
        }

        // Encryption logic based on Playfair cipher rules
        // If both letters are in the same row
        if (x1 == x2) {
            ciphertext += c[x1][(y1 + 1) % 5];
            ciphertext += c[x2][(y2 + 1) % 5];
        }
        // If both letters are in the same column
        else if (y1 == y2) {
            ciphertext += c[(x1 + 1) % 5][y1];
            ciphertext += c[(x2 + 1) % 5][y2];
        }
        // If the letters form a rectangle
        else {
            ciphertext += c[x1][y2];
            ciphertext += c[x2][y1];
        }
    }

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
