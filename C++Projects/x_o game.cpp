#include <bits/stdc++.h>
#include<string>
#define ll long long
using namespace std;

int main()
{
int arr[100][100] = {0};

int SIZE; cin>>SIZE;
int trun = 0;


int v = 0;
int rs[100] , cs[100] , dr[100] , dc[100];

for(int i = 0 ; i<SIZE ; i++)
    rs[v] = i , cs[v] = 0 , dr[v] = 0 , dc[v++] = 1 ;

for(int i = 0 ; i<SIZE ; i++)
    rs[v] = 0 , cs[v] = i , dr[v] = 1 , dc[v++] = 0 ;


rs[v] = 0 , cs[v] = 0 , dr[v] = 1 , dc[v++] = 1 ;

rs[v] = 0 , cs[v] = SIZE-1 , dr[v] = 1 , dc[v++] = -1 ;

int steps = 0;
while(true){

    if(steps == SIZE*SIZE){cout<<"tie"; break;}
    char sym = 'x';

    //enter the position
    int r_player , c_player;
    if(trun == 1) sym = 'o';
    cout<<sym<<" trun , inter position in row an col\n";   cin>>r_player>>c_player;   r_player--; c_player--;

    //check if position is empty
    if(arr[r_player][c_player] != 0 || r_player < 0 || r_player >= SIZE || c_player < 0 || c_player >= SIZE){
        cout<<"invalid val , try again\n";
        continue;
    }

    //enter the val in matrix
    int val = trun + 1 ;
    arr[r_player][c_player] = val;


    //print the matrix
    for(int row = 0 ; row < SIZE ; row++){
        for(int col = 0 ; col < SIZE ; col++){
            char changer = '-';
            if(arr[row][col] == 1)changer = 'x';
            else if(arr[row][col] == 2)changer = 'o';
            cout<<changer<<" ";
        }
        cout<<endl;
    }

    //the journey to find the winner
/*
    rs : 0 1 2 0 0 0
    cs : 0 0 0 0 1 2
    dr : 0 0 0 1 1 1
    dc : 1 1 1 0 0 0
*/

    for(int check = 0 ; check < v ; ++check){
        int r = rs[check] , c = cs[check] ,rd = dr[check] , cd = dc[check] ;
        int frist = arr[r][c];
        int coun=0;

        if(frist == 0)
            continue;

        for(int step = 0 ; step < SIZE ; ++step , r+=rd , c+=cd)
            coun += arr[r][c] == frist;

        if (coun == SIZE) {
            cout << "Player " << sym << " won\n";
            return 0;
        }

    }

    //change the trun
    trun = !trun;
    steps++;
}
return 0;
}
/*


*/
