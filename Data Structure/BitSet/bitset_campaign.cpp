#include<bits/stdc++.h>
#define ll long long
#define MAX_N 5000
#define MAX_D 365
using namespace std;

bitset<MAX_D> person[MAX_N];

bool checkPossiblePair(bitset<MAX_D> person1, bitset<MAX_D> person2) {
    return ((person1 | person2).count() == MAX_D);
}

bool checkSingleCarry(bitset<MAX_D> person) {
    return (person.count() == MAX_D);
}

int main() {
    int N, D, K;
    unsigned long long int day;

    freopen("input.txt", "r", stdin);

    cin >> N >> D;

    for(int i = 0; i < N; i++) {
        cin >> K;
        for(int j = 0; j < K; j++) {
            cin >> day;
            day--;
            person[i].set(day);
        }
    }

    string ans = "IMPOSSIBLE";

    // case 1 person
    for(int i = 0; i < N; i++) {
        if(checkSingleCarry(person[i])) {
            ans = "POSSIBLE";
        }
    }

    // case 2 person
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(checkPossiblePair(person[i], person[j])) {
                ans = "POSSIBLE";
            }
        }
    }

    cout << ans << endl;

    return 0;
}

