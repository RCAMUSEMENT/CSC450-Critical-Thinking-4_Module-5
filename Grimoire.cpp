#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

// Fantasy text-scroll animation with a deliberate timing cadence
void scrollManaText(const string& text, int delayMs = 20) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

void appendUserTextInput(const string& filename);
void reverseFileContent(const string& sourceFilename, const string& targetFilename);

int main() {
    const string originalFile = "CSC450_CT5_mod5.txt";
    const string reversedFile = "CSC450-mod5-reverse.txt";

    // Switch terminal font color to bright cyan/blue for an ethereal aura aesthetic
    cout << "\033[1;36m";
    cout << "=====================================================================" << endl;
    cout << " [MANA_LINK] SACRED RUNIC GRIMOIRE — WORLD TRANSIT RECONSTITUTION    " << endl;
    cout << "=====================================================================" << endl;

    scrollManaText("[!] ALERT: Soul displacement matrix confirmed. Welcome to the New Continent.\n");
    scrollManaText("[!] Main Inscription Archive: " + originalFile + "\n\n");

    // Task 1: Ingest input string from keyboard buffer and append it without truncation
    appendUserTextInput(originalFile);

    cout << "\n";
    scrollManaText("[*] CHANNELING SPIRITUAL CORE: RUNNING RETROGRADE TEMPORAL REVERSAL...\n");
    scrollManaText("[*] Inverting all runic syllables within the record array to stabilize mana...\n");
    this_thread::sleep_for(chrono::seconds(1)); // Dramatic immersion pause

    // Task 2: Reverse file characters and write output to the designated target file
    reverseFileContent(originalFile, reversedFile);

    cout << "\n=====================================================================" << endl;
    cout << " [STABILIZED] COUNTER-CURSE INSCRIBED // GRIMOIRE CONCLUDED         " << endl;
    cout << "=====================================================================" << endl;
    cout << "\033[0m"; // Reset terminal font properties back to system default

    return 0;
}

void appendUserTextInput(const string& filename) {
    // Open stream in explicit APPEND mode to protect lines 1-3 from getting deleted
    ofstream outFile(filename, ios::app);

    if (!outFile) {
        cerr << "\n[!] ERROR: The grimoire spine for " << filename << " is locked by high-tier magic.\n";
        return;
    }

    string userInput;
    scrollManaText("[>] Inscribe your custom hero blessing to append to the historical record:\n> ");

    // FIXED: Captures manual keyboard data input cleanly, preventing exe path injections
    getline(cin, userInput);

    // Commit payload text into the file array safely
    outFile << userInput << endl;
    outFile.close();

    scrollManaText("[+] SUCCESS: Sacred incantation permanently added to the ledger without data loss.\n");
}

void reverseFileContent(const string& sourceFilename, const string& targetFilename) {
    ifstream inFile(sourceFilename);
    if (!inFile) {
        cerr << "\n[!] ERROR: Ingestion stream channel interrupted for " << sourceFilename << "\n";
        return;
    }

    string fileContents;
    string line;
    // Sequential character extraction from historical file lines
    while (getline(inFile, line)) {
        fileContents += line + "\n";
    }
    inFile.close();

    // Remove the trailing newline tracking marker to preserve structural boundaries
    if (!fileContents.empty()) {
        fileContents.pop_back();
    }

    // In-place dual-pointer sequence reversal algorithm
    reverse(fileContents.begin(), fileContents.end());

    // Initialize clean write paths and wipe old reverse file states via truncation mode
    ofstream outFile(targetFilename, ios::trunc);
    if (!outFile) {
        cerr << "\n[!] ERROR: Crystal lens mirror destination unavailable: " << targetFilename << "\n";
        return;
    }

    outFile << fileContents;
    outFile.close();

    scrollManaText("[+] SUCCESS: Chrono-reversed mirror reflection completely forged at " + targetFilename + "\n");
}