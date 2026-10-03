#include <bits/stdc++.h>
using namespace std;

static string readFile(const string& path) {
    ifstream f(path, ios::binary);
    if (!f) return "<cannot open>";
    return string((istreambuf_iterator<char>(f)),
                   istreambuf_iterator<char>());
}

int main(int argc, char** argv) {
    int MAX_SEED = (argc > 1) ? atoi(argv[1]) : 3000;

    const string GEN = "gen.exe";
    const string MY  = "my.exe";
    const string REF = "ref.exe";

    for (int seed = 0; seed <= MAX_SEED; seed++) {
        string cmdGen = GEN + " " + to_string(seed) + " > in.txt";
        if (system(cmdGen.c_str()) != 0) {
            cerr << "gen failed at seed=" << seed << "\n";
            return 1;
        }

        system((MY  + " < in.txt > out_my.txt").c_str());
        system((REF + " < in.txt > out_ref.txt").c_str());

        string oMy  = readFile("out_my.txt");
        string oRef = readFile("out_ref.txt");

        if (oMy != oRef) {
            cout << "===== seed=" << seed << " : mismatch =====\n";
            cout << "---- input ----\n"  << readFile("in.txt");
            cout << "---- my output ----\n"  << oMy;
            cout << "---- ref output ----\n" << oRef;
            return 0;
        }

        if (seed % 500 == 0) cout << "seed " << seed << " ok\n";
    }
    cout << "all " << (MAX_SEED + 1) << " tests passed\n";
    return 0;
}