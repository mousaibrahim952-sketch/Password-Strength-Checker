
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;

    cout << "===== Password Strength Checker =====\n";
    cout << "Enter your password: ";
    getline(cin, password);

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char ch : password) {
        if (isupper((unsigned char)ch))
            hasUpper = true;
        else if (islower((unsigned char)ch))
            hasLower = true;
        else if (isdigit((unsigned char)ch))
            hasDigit = true;
        else
            hasSpecial = true;
    }

    int score = 0;

    if (password.length() >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    cout << "\n===== Password Analysis =====\n";

    cout << "Length: " << password.length() << endl;
    cout << "Uppercase: " << (hasUpper ? "Yes" : "No") << endl;
    cout << "Lowercase: " << (hasLower ? "Yes" : "No") << endl;
    cout << "Numbers: " << (hasDigit ? "Yes" : "No") << endl;
    cout << "Special Characters: " << (hasSpecial ? "Yes" : "No") << endl;

    cout << "\nPassword Strength: ";

    if (score <= 2)
        cout << "WEAK";
    else if (score <= 4)
        cout << "MEDIUM";
    else
        cout << "STRONG";

    cout << "\nScore: " << score << "/5\n";

    return 0;
}
