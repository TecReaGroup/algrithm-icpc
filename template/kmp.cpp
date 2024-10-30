#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int ne[N] = {0};
char s1[N], s2[N];

int main(){
    cin >> s1+1 >> s2+1;
    int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);

    // preprocess ne
    for (int i = 2, j = 0; i <= len2; i++){  // j: prepared char & index of s2
        while (j && s2[j + 1] != s2[i]) j = ne[j];
        if (s2[j + 1] == s2[i]) j++;
        ne[i] = j;
    }

    // process problem
    for (int i = 1, j = 0; i <= len1; i++){
        while (j && s2[j + 1] != s1[i]) j = ne[j];
        if (s2[j + 1] == s1[i]) j++;
        if (j == len2){
            cout << i - len2 + 1;
            j = ne[j];
            cout << endl;
        }
    }

    // cout ne
    for (int i = 1; i <= len2; i++){
        cout << ne[i] << " ";
    }

    return 0;
}
