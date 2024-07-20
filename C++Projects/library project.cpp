#include<iostream>
#include<cstdlib>
#include<cmath>
#include <algorithm>
using namespace std;

struct book{
    int id , total_quan;
    string name;

//============================================================

    void print_book(){
        cout<<"id: "<< id<<" name: "<<name<<" total quantaty: "<<total_quan<<endl;
    }

//============================================================

    void read_book(){

        cout<<"enter the book info : \n";
        cin>>id>>name>>total_quan;

        if(id <=0 || total_quan < 0)
            cout<<"invalid value , try again \n";

    }

//============================================================



};
//============================================================

struct user{
    int id;
    string name;
    int n_books;
    int books_ids[3] ={0};

//============================================================

 user(){
    name ="";
    id = 0;
    n_books = 0;
}

//============================================================

    void read_user(){
        cout<<"enter the user info : \n";
        cin>>id>>name;
        if(id <=0)
            cout<<"invalid value , try again \n";
    }

//============================================================

    void print_user(){
        cout<<"name: "<<name<<" , user id: "<< id<< " , borrowed books ids : ";
        for(int i=0 ; i<n_books ; i++)
            cout<<books_ids[i]<<" ";
        cout<<endl;
    }
};

//============================================================

bool compare_id(book& a, book& b) {
    return a.id < b.id;
}

//============================================================

bool compare_name(book &a , book &b){
    return a.name < b.name;
}

//============================================================

struct admin{

    book books_info[100];
    int nob =0;

    user users_info[100];
    int nou =0;

//============================================================

    void add_book(){
        books_info[nob++].read_book();
    }

//============================================================

     void add_user(){
        users_info[nou++].read_user();
     }

//============================================================


    void print_by_id(){
        if(nob == 0){
            cout<<"no book yet \n";
            return;
        }
       sort(books_info , books_info+nob , compare_id);

        for(int i =0 ; i<nob ; i++)
            books_info[i].print_book();
    }

//============================================================

    void print_by_name(){
        if(nob == 0){
            cout<<"no book yet \n";
            return;
        }
        sort(books_info , books_info+nob , compare_name);
        for(int i =0 ; i<nob ; i++)
            books_info[i].print_book();
    }

//============================================================

    void user_borrow_book(){
        cout<<"enter user name and book name : ";

        string user_name , book_name;  cin>>user_name>>book_name;
        bool book_found = false , user_found = false;
        int book_id;

        for(int i = 0 ; i<nob ; i++)
            if(book_name == books_info[i].name && books_info[i].total_quan > 0){
                 book_found = true;
                 books_info[i].total_quan--;
                 book_id = books_info[i].id ;
            }

        if(!book_found)
            cout<<"unfound book , try again \n";


        for(int i = 0 ; i<nou ; i++)
            if(user_name == users_info[i].name && users_info[i].n_books < 4 && book_found){
                 user_found = true;
                 int n_book = users_info[i].n_books++;
                 users_info[i].books_ids[n_book] = book_id;
        }

        if(!user_found)
            cout<<"unfound user or user have 3 books , try again \n";

    }

//============================================================

    void print_users(){
        if(nou == 0){
            cout<<"no user yet \n";
            return;
        }

        for(int i =0 ; i<nou ; i++)
            users_info[i].print_user();
    }

//============================================================


    int menu(){
    cout<<"\nlibrary menu : \n";
    cout<<"1) add_book \n";
    cout<<"4) print library by id \n";
    cout<<"5) print library by name \n";
    cout<<"6)add user \n";
    cout<<"7) user borrow book \n";
    cout<<"9) print users \n";

    int choise ; cin>>choise;

    return choise;
}

//============================================================

    void library_system(){
        while(true){
            int choise = menu();
            if(choise == 1) add_book();
            if(choise == 4) print_by_id();
            if(choise == 5) print_by_name();
            if(choise == 6) add_user();
            if(choise == 7) user_borrow_book();
            if(choise == 9) print_users();

        }
    }


};

//==================================================
//==================================================

int main()
{
    admin ad1;
    ad1.library_system();
}
