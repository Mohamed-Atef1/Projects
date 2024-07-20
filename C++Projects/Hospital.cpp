#include <bits/stdc++.h>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

int queue_length[MAX_SPECIALIZATION+1]={0};
int status[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
string names[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
//===========================
int menu(){

int choise = -1;
while(choise==-1){
cout<<"\nEnter your choise:\n";
cout<<"1) Add new patient\n";
cout<<"2) Print specialization\n";
cout<<"3) Get next patient\n";
cout<<"4) Print all patient\n";
cout<<"5) delete\n";
cout<<"6) change\n";
cout<<"7) exit\n";
cin>>choise;
if(!(choise>=1 && choise<=7)){cout<<"Invalid choice. Try again\n"; choise=-1;}
}
return choise;
}
//============================
void shift_right(int spec , string names_sp[] , int st_sp[]){
int len = queue_length[spec];
for(int i=len-1 ; i>=0 ; --i){
    names_sp[i+1]=names_sp[i];
    st_sp[i+1]=st_sp[i];
}
queue_length[spec]++;
}
//============================
void shift_lift(int spec , string names_sp[] , int st_sp[]){
int len = queue_length[spec];
for(int i=1 ; i<len ; ++i){//  ah ma
    names_sp[i-1]=names_sp[i];// 0 0
    st_sp[i-1]=st_sp[i];
}
queue_length[spec]--;
}
//============================
bool add_patient(){
int spec;
string name;
int st;

cout<<"Enter specialization, name, statis: ";
cin>>spec>>name>>st;

int pos = queue_length[spec];
if(pos>=MAX_QUEUE){
    cout<<"Sorry we can't add more patients for this specialization\n";
    return false;
}

if(st==0){
    names[spec][pos] = name;
    status[spec][pos] = st;
    queue_length[spec]++;
}
else {
    shift_right(spec , names[spec] , status[spec]);
    names[spec][0] = name;
    status[spec][0] = st;
}
return true;
}
//============================
void call_patient(){
int spec;
cout<<"\nEnter the specialization: ";
cin>>spec;
int len = queue_length[spec];
if( len == 0){
    cout<<"\nNo patients at the moment. Have rest, Dr\n";
    return;
    }
else {
    cout<<endl<<names[spec][0]<<" please go to the Dr\n";
    shift_lift(spec, names[spec] , status[spec]);
}
}
//============================
int print_spec(){
cout<<"\nEnter the specialization: ";
int spec; cin>>spec;
int len = queue_length[spec];
if(len==0){cout<<"no patients in this specialization \n"; return 0; }
else{
cout<<"*************************************\n";
for(int i=0 ; i<len ; i++){
    cout<<i+1<<") "<<names[spec][i]<<" ";

    if(status[spec][i])
        cout<<"urgent\n";
    else
        cout << "regular\n";

}
cout<<"*************************************\n";
}
return spec;
}
//============================
bool DELETE(){
int spec = print_spec();
int len=queue_length[spec];
bool flag=1;
if(len==0){flag=0;return flag ;}
cout<<"enter the patient's number: ";
int pos; cin>>pos;
for(int i=pos-1 ; i<=len ; i++){
    names[spec][i]=names[spec][i+1];
    status[spec][i]=status[spec][i+1];
}
queue_length[spec]--;
return flag;
}
//============================
void change(){
bool flag=DELETE();
if(flag==false)return;
add_patient();
}
//============================
void print_All(int spec , string names_sp[] , int st_sp[]){
int len = queue_length[spec];
if(len == 0) return;
cout<<"*************************************\n";

cout<<"there are "<<len<<" patients in specialization "<<spec<<"\n\n";

for(int i=0 ; i<len ; i++){
    cout<<i+1<<") "<<names_sp[i]<<" ";
    if(st_sp[i])
        cout<<"urgent\n";
    else
        cout << "regular\n";
}
}
//============================
void print_all(){
for(int i=0 ; i<MAX_SPECIALIZATION ; i++){
    print_All(i , names[i] , status[i]);
}
}
//============================
void Hosptal_system(){
while(true){
int choies = menu();
if(choies == 1) add_patient();
else if(choies == 2) print_spec();
else if(choies == 3) call_patient();
else if(choies == 4) print_all();
else if(choies == 5 ) DELETE();
else if(choies == 6 ) change() ;
else if(choies == 7 ) return ;

}

}


int main()
{
   Hosptal_system();
return 0;
}
