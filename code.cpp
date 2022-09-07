#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define MAX 1000
int main(){
    
    /*Initialize A and x*/
    int A[MAX][MAX], x[MAX], y[MAX];
    for(int i = 0; i < MAX; i++){
        x[i] = i+1;
        y[i] = 0;
        for(int j = 0; j < MAX; j++)
            A[i][j] = i+j;
    }
    //First pair of loops
    cout << "Pass" << endl;
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i]+= A[i][j]*x[j];
    auto stop1 = high_resolution_clock::now();
    //Second pair of loops
    auto start2 = high_resolution_clock::now();
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i]+= A[i][j]*x[j];
    auto stop2 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Duration 1 " << duration1.count() << endl;
    cout << "Duration 2 " << duration2.count() << endl;
}
