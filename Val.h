//
// Created by Ar-Gas on 2024/01/25.
//
#include<bits/stdc++.h>
using namespace std;
#define INT 0
#define DOU 1
#define STR 2
#define BOOL 3
#define LIST 4
#define DICT 5

#ifndef TINYJSON_VAL_H
#define TINYJSON_VAL_H

class Val {
public:
    int INT_VAL;
    double DOU_VAL;
    string STR_VAL;
    bool BOOL_VAL;
    vector<Val>List;
    map<Val, Val>dict;

    int type;

    void del() {
        if (type == STR)STR_VAL.clear();
        if (type == LIST)List.clear();
        if (type == DICT)dict.clear();
    }
    Val() {}
    ~Val() {
        del();
    }
    Val(const int &x) {
        del();
        INT_VAL = x;
        type = INT;
    }

    Val(const double & x) {
        del();
        DOU_VAL = x;
        type = DOU;
    }

    Val(const string & x) {
        del();
        STR_VAL = x;
        type = STR;
    }

    Val(const char *x) {
        del();
        type = STR;
        STR_VAL = string(x);
    }

    Val(const bool & x) {
        del();
        BOOL_VAL = x;
        type = BOOL;
    }

    Val(initializer_list<Val> l) {
        del();
        type = LIST;
        for (Val x : l)List.push_back(x);
    }

    void add(Val x) {
        if (type == LIST)List.push_back(x);
    }

    void put(Val key, Val val) {
        if (type == DICT)dict[key] = val;
    }

    Val& operator [](Val i) {
        if (type == LIST)return List[i.INT_VAL];
        else return dict[i];
    }

    string str();
};

#endif //TINYJSON_VAL_H
