// ...

#include<bits/stdc++.h>
using namespace std;

inline void guts() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}


map<string, string> ids, cg_marks, fds_marks, oop_marks, dm_marks, deld_marks;
multimap<int, string> tot_marks;
vector<string> sts;

class Subject
{
    ifstream fin;
    string st_no, name, mks, temp;
    int len;

public:
    void input_names();
    void input_marks();
    void display_names();
    void display_marks();
};

void Subject :: input_names() {
    fin.open("ID_NAMES.txt");
    len = 123;
    while (len--) {
        fin >> st_no;
        name = "";
        fin >> temp;
        name += temp;
        while (temp.substr(0, 1) != "7") {
            fin >> temp;
            name += " ";
            name += temp;
        }
        ids[st_no] = name;
    }
    fin.close();
}

void Subject :: display_names() {
    for (auto i : ids) {
        cout << i.first << " " << i.second << endl;
    }
}


void Subject :: input_marks() {
    fin.open("CG_MKS.txt");
    len = 61;
    while (len--) {
        fin >> st_no >> mks;
        cg_marks[st_no] = mks;
        sts.push_back(st_no);
    }
    fin.close();
    fin.open("FDS_MKS.txt");
    len = 61;
    while (len--) {
        fin >> st_no >> mks;
        fds_marks[st_no] = mks;
    }
    fin.close();
    fin.open("DELD_MKS.txt");
    len = 61;
    while (len--) {
        fin >> st_no >> mks;
        deld_marks[st_no] = mks;
    }
    fin.close();
    fin.open("DM_MKS.txt");
    len = 61;
    while (len--) {
        fin >> st_no >> mks;
        dm_marks[st_no] = mks;
    }
    fin.close();
    fin.open("OOP_MKS.txt");
    len = 61;
    while (len--) {
        fin >> st_no >> mks;
        oop_marks[st_no] = mks;
    }
    fin.close();
}

void Subject :: display_marks() {
    cout << endl;
    for (auto i : cg_marks) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    for (auto i : fds_marks) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    for (auto i : dm_marks) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    for (auto i : deld_marks) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    for (auto i : oop_marks) {
        cout << i.first << " " << i.second << endl;
    }
}

class Marks
{
public:

    string getName(string id) {
        string temp = ids[id];
        int cnt = 0;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == ' ') {
                cnt++;
                if (cnt == 2) {
                    return temp.substr(0, i + 1);
                }
            }
        }
        return "";
    }

    void display_marks() {
        cout << "\nName          CG      FDS     DELD    OOP     DM\n\n";
        for (auto i : sts) {
            string name = getName(i);
            cout << name << "\t\t" << cg_marks[i] << "\t\t" << fds_marks[i] << "\t\t" << deld_marks[i] << "\t\t" << oop_marks[i] << "\t\t" << dm_marks[i] << "\n\n";
        }
    }

    void display_topper() {
        int mx = LLONG_MIN;
        string ii;

        for (auto i : sts) {
            int tot = stoi(cg_marks[i]) + stoi(oop_marks[i]) + stoi(deld_marks[i]) + stoi(dm_marks[i]) + stoi(fds_marks[i]);
            tot_marks.insert({tot, i});
            if (tot >= mx) {
                mx = tot;
                ii = i;
            }
        }
    }

    void display_rank() {
        for (auto i = tot_marks.rbegin(); i != tot_marks.rend(); i++) {
            cout << getName(i->second) << " " << i->first << endl;
        }
    }

    void sub_rank() {
        multimap<int, string> mp;
        for (auto i : oop_marks) {
            int x = stoll(i.second);
            mp.insert({x, i.first});
        }

        for (auto i = mp.rbegin(); i != mp.rend(); i++) {
            cout << getName(i->second) << " " << i->first << endl;
        }
    }

};

int main() {

    guts();

    Subject a;
    Marks b;
    a.input_names();
    // a.display_names();
    a.input_marks();
    // a.display_marks();
    // b.display_marks();
    b.display_topper();
    // b.display_rank();
    b.sub_rank();

    return 0;
}