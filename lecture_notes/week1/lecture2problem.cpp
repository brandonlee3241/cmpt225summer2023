#include <iostream>

using namespace std;

void solution(){
    const int N = 3000;

    int arr[N];

    for(int i =0; i < N; i++){
        if(i%3 == 0)arr[i] = 4;
        else if (i%3 == 1)arr[i] = 5;
        else if (i%3 == 2)arr[i] = 9;

    }
    for(int i =0; i < N; i++){
        cout << "arr[" << i << "] = " << arr[i] <<endl;
    }
}
