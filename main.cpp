#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

class PersonEmail {
public:
    string Email;
    PersonEmail() {
        Email = "USER";
    }

    void setEmail(const string& e) {
        Email = e;
    }

    string getEmail() const {
        return Email;
    }
};

int main() {
    PersonEmail p1;
    char userChoice;
    string np1;
    vector<string> newSet;

    cout << "Do you want to enter an email? (y/n): ";
    cin >> userChoice;

    if (userChoice == 'y' || userChoice == 'Y') {
        cout << "Enter email: ";
        cin >> np1;
        p1.setEmail(np1);

        ofstream outputFile("newfile.text", ios::app);
        if (!outputFile) {
            cout << "Failed to open the file." << endl;
            return -1;
        }
        outputFile << p1.getEmail() << "\n";
        outputFile.close();
    } else {
        bool state = true;
        ifstream readfile("newfile.text");
        string newE;
        while(state){
            cout << "What is your Email?: ";
            cin >> newE;
            if (!readfile) {
                cout << "Failed to open the file." << endl;
                return -1;
            } else {
                string line;
                bool emailFound = false;
                while (getline(readfile, line)) {
                    if (newE == line) {
                        emailFound = true;
                        state = false;
                        break;
                    }
                }

                if (emailFound) {
                    cout << "Login Success!" << endl;
                } else {
                    cout << "Email not found." << endl;
                }
        }
        }
        readfile.close();
    }

    return 0;
}
