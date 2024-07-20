#include <iostream>
#include<string>
using namespace std;

int age[5] , salary[5]  , n = -1 ;
string name[5] ; char gender[5];

void add_em() {
    n++;
    cout<<"enter name: "; cin>>name[n];
    cout<<"enter age: "; cin>>age[n];
    cout<<"enter salary: "; cin>>salary[n];
    cout<<"enter gender: "; cin>>gender[n];
}
//==============================================

void print_em(){
    for(int i = 0 ; i<=n ; i++){
        cout<<"name: "<<name[i]<<"  age: "<<age[i]<<"  salary: "<<salary[i]<<"  gender: "<<gender[i]<<endl;
    }
}
//==============================================

void delet_em(){
int f , s;
cout<<"enter start and end age: "; cin>>f>>s;

for(int i = 0 ; i<=n ; i++){
    if(age[i] >= f && age[i] <= s){
        for(int y = i ; y<=n ; y++){
            name[y] = name[y+1];
            age[y] = age[y+1];
            salary[y] = salary[y+1];
            gender[y] = gender[y+1];
        }
        i--;
        n--;
    }
}

}
//==============================================
void update_salary_em(){
    string em_name;
    cout<<"enter employee name: "; cin>>em_name;
    int em_salary;
    bool flag = false;
    for(int i = 0 ; i <= n ; i++){
        if(name[i] == em_name){
            cout<<"enter new salary: "; cin>>em_salary;
            salary[i] = em_salary;
            flag = true;
        }
    }
    if(!flag)cout<<"wrong name";
}

//==============================================
int menu() {
    int choise = -1 ;

    while(choise == -1){
        cout<<"\n1) Add new employee\n" ;
        cout<<"2) Print all eployees\n" ;
        cout<<"3) Delete by age\n" ;
        cout<<"4) Update salary by name\n" ;
        cin>>choise;

        if(!(choise >= 1 && choise <= 4)) { cout<<"invalid value , try again"; choise = -1;}

        else
            return choise ;
    }
}
//==============================================

void fact_system(){
    while(true){
        int choise = menu();
        if(choise == 1) add_em();
        if(choise == 2) print_em();
        if(choise == 3) delet_em();
        if(choise == 4) update_salary_em();
    }
}

int main()
{

    fact_system();
    return 0;

}


/*

mohamed 20 8000 m

mona 35 25000 f

ahlam 32 22000 f

*/
