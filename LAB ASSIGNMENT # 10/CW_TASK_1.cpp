#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class StringEncryptor {
private:
    string originalText;
    string encryptedText;
    string decryptedText;
    const string filename = "encrypted.txt";

    string encrypt(string text) {
        string result = "";
        for (int i = 0; i < text.length(); i++) {
            char c = text[i] + (i + 1);
            result += c;
        }
        return result;
    }
    string decrypt(string text) {
        string result = "";
        for (int i = 0; i < text.length(); i++) {
            char c = text[i] - (i + 1);
            result += c;
        }
        return result;
    }
public:
    void setText(string text) {
        originalText = text;
    }
    void encryptAndWriteToFile() {
        encryptedText = encrypt(originalText);
        
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << encryptedText;
            outFile.close();
            cout << "Encrypted text inserted in file\n" << encryptedText << endl;
        } else {
            cerr << "Unable to open file for writing!" << endl;
        }
    }
    void readAndDecryptFromFile() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            getline(inFile, encryptedText);
            inFile.close();
            
            decryptedText = decrypt(encryptedText);
            cout << "Decrypted text read then decoded from file\n" << decryptedText << endl;
        } else {
            cerr << "Unable to open file for reading!" << endl;
        }
    }
};
int main() {
    StringEncryptor encryptor;
    string userInput;
    cout << "Enter String = ";
    getline(cin, userInput);
    cout << "Normal Text: " << userInput << endl;

    encryptor.setText(userInput);
    encryptor.encryptAndWriteToFile();
    encryptor.readAndDecryptFromFile();
    return 0;
}