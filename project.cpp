#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>

using namespace std;
class Bank{
   public:
   string f_name,l_name,p_no,address,cnic;
   int amount = 0;
   void info()
   {
    cout<<"Please enter your first name:";
    cin.ignore();
    getline(cin, f_name);
    cout<<"Please enter your last name:";
    cin>>this->l_name;
    cout<<"Please enter your Phone number:";
    cin>>this->p_no;
    cout<<"Please enter your address:";
    cin.ignore();
    getline(cin, address);
    cout<<"Please enter your cnic:";
    cin>>this->cnic;
    
   }
   void welcome()
   {
        cout<<"\t\t\t\t\t\tMy Banking System!\t\t\t\t\t\t\n"<<endl;
    }
   void option()
    {
        cout<<"1. Account Open."<<endl;
        cout<<"2. Deposit Amount."<<endl;
        cout<<"3. Withdraw Amount."<<endl;
        cout<<"4. Check Balance."<<endl;
        cout<<"5. UPdate Record."<<endl;
        cout<<"6. Delete Record."<<endl;
        cout<<"7. Search Record."<<endl;
        cout<<"8. Exit."<<endl;
    }
   void display()  
    {
        
        cout<<"Your first name:"<<f_name<<endl;
        cout<<"Your last name:"<<l_name<<endl;
        cout<<"Your phone name:"<<p_no<<endl;
        cout<<"Your address:"<<address<<endl;
        cout<<"Your cnic:"<<cnic<<endl;
        cout<<"your amount is amount:"<<amount<<endl;
        
    }
   void mean(){
      cout<<"to update first name(press f) \n to update last name(press l) \n to update phone number(press p) \n to update address(press a)\n to update cnic(press cn)"<<endl;
   }


};
int main(){
   int key;
   Bank b;
   do
   {
       b.welcome();
       cout<<endl;
       cout<<"please select one option from below menu "<<endl;
  z:    b.option();
   
       cin>>key;
       if(key == 1)
       {
         b.info();
         ofstream f("Reg_user.dat",ios::app);
         f.write((char*)&b,sizeof(b));
         f.close();
         b.display();
         Sleep(3000);
         system("cls");

       }
       else if(key == 2)
       {
          string nam;
          int amount,cnt = 0;
          cout<<"please enter your first name:";
          cin>>nam;
          
          ifstream r("Reg_user.dat");
          while(r.read((char*)&b,sizeof(b)))
          {
             if( nam == b.f_name)
             {
                ofstream f("Reg_user1.dat",ios::app);
               cout<<"name of account holder is:"<<b.f_name<<" "<<b.l_name<<endl;
               cout<<"Current amount is:"<<b.amount<<endl;
                cout<<"please enter new amount:";cin>>amount;
                b.amount+= amount;
                cout<<"name of account holder is:"<<b.f_name<<" "<<b.l_name<<endl;
               cout<<"Current amount is:"<<b.amount<<endl;
               f.write((char*)&b,sizeof(b));
                ifstream r("Reg_user.dat");
                while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                }
                f.close();
                cnt++;
             }
               
             else{
                cout<<"computer is either searching or wasn`t able to find your record.\n";
             }
          } 
          Sleep(3000);
          system("cls");
          r.close();
          if(cnt != 0)
          {
          remove("Reg_user.dat");
          rename("Reg_user1.dat","Reg_user.dat");
          }
            
       }
       else if(key == 3){
         string nam;
          int amount,cnt = 0;
          cout<<"please enter your first name:";
          cin>>nam;
          
          ifstream r("Reg_user.dat");
          while(r.read((char*)&b,sizeof(b)))
          {
             if( nam == b.f_name)
             {
                ofstream f("Reg_user1.dat",ios::app);
               cout<<"name of account holder is:"<<b.f_name<<" "<<b.l_name<<endl;
               cout<<"Current amount is:"<<b.amount<<endl;
      a:          cout<<"please enter new amount:";cin>>amount;
                if(amount<b.amount){

                b.amount-= amount;
                }
                else{
                  cout<<"Amount bein withdrawn is more then amount avaiable in the acount"<<endl;
                  goto a;
                }
                cout<<"name of account holder is:"<<b.f_name<<" "<<b.l_name<<endl;
               cout<<"Current amount is:"<<b.amount<<endl;
               f.write((char*)&b,sizeof(b));
                ifstream r("Reg_user.dat");
                while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                }
                f.close();
                cnt++;
             }
               
             else{
                cout<<"computer is either searching or wasn`t able to find your record.\n";
             }
          } 
          Sleep(3000);
          system("cls");
          r.close();
          if(cnt !=0){
         remove("Reg_user.dat");
         rename("Reg_user1.dat","Reg_user.dat");
          }
       }
       else if(key == 4)
       {
          string nam;
         
          cout<<"please enter your first name:";
          cin>>nam;
          
          ifstream r("Reg_user.dat");
          while(r.read((char*)&b,sizeof(b)))
          {
             if( nam == b.f_name)
             {
                
               cout<<"name of account holder is:"<<b.f_name<<" "<<b.l_name<<endl;
               cout<<"Current amount is:"<<b.amount<<endl;       
               
             }
             else{
                cout<<"computer is either searching or wasn`t able to find your record.\n";
             }
          } 
          Sleep(3000);
          system("cls");
          r.close();
       }
        else if (key == 5)
        {
           string nam;
         int cnt = 0;
         char opt;
          cout<<"please enter your first name:";
          cin>>nam;
          char ch;
          ifstream r("Reg_user.dat");
          while(r.read((char*)&b,sizeof(b)))
          {
             if( nam == b.f_name)
             {
               b.display();
               cout<<"=========================================================="<<endl;
                ofstream f("Reg_user1.dat",ios::app);
      x:          b.mean();
                cin>>ch;

               if(ch == 'f'){
                  cout<<"enter your new first name:";cin>>b.f_name;
               f.write((char*)&b,sizeof(b));
                ifstream r("Reg_user.dat");

                while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                }
               }


               else if(ch == 'l')
                 {
                  cout<<"enter your new last name:";cin>>b.l_name;
               f.write((char*)&b,sizeof(b));
                ifstream r("Reg_user.dat");

                while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                 }
               
             }
               
               else if(ch == 'p')
                 {
                  cout<<"enter your new phone number:";cin>>b.p_no;
               f.write((char*)&b,sizeof(b));
                ifstream r("Reg_user.dat");

                while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                 }
               
             }

             else if(ch == 'a')
                 {
                  cout<<"enter your new address:";cin>>b.address;
               f.write((char*)&b,sizeof(b));
                ifstream r("Reg_user.dat");

                while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                 }
               
             }

             else if(ch == 'c')
                 {
                  cout<<"enter your new cnic:";cin>>b.cnic;
               f.write((char*)&b,sizeof(b));
                ifstream r("Reg_user.dat");

                while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                 }
                
             }
             cout<<"do you want to update record again?(y/n):";
             cin>>opt;
             if(opt == 'y'){
               goto x;
             }
             else{
             
              f.close();
                cnt++;
               }
             }
             else{
                cout<<"computer is either searching or wasn`t able to find your record.\n";
             }
          
          }
          Sleep(5000);
          system("cls");
          r.close();
          if(cnt != 0)
          {
          remove("Reg_user.dat");
          rename("Reg_user1.dat","Reg_user.dat");
          }
        }
        else if(key == 6){
          string nam;
          int cnt = 0;
          char ch;
          cout<<"please enter your first name:";
          cin>>nam;
          
          ifstream r("Reg_user.dat");
          while(r.read((char*)&b,sizeof(b)))
          {
             if( nam == b.f_name)
             {
                ofstream f("Reg_user1.dat",ios::app);
     
                cout<<"name of account holder is:"<<b.f_name<<" "<<b.l_name<<endl;
               cout<<"Current amount is:"<<b.amount<<endl;
                cout<<"do you realy want to delete the record ?(y/n):";
                cin>>ch;
                if(ch == 'y'){
                  ifstream r("Reg_user.dat");
                  while(r.read((char*)&b,sizeof(b)))
                {
                    if(nam !=b.f_name){
                     f.write((char*)&b,sizeof(b));
                    }
                }
                }
                else{
                  goto z;
                }
                f.close();
                cnt++;
             }
               
             else{
                cout<<"computer is either searching or wasn`t able to find your record.\n";
             }
          } 
          Sleep(5000);
          system("cls");
          r.close();
          if(cnt !=0){
         remove("Reg_user.dat");
         rename("Reg_user1.dat","Reg_user.dat");
          }
        }
       else if(key == 7){
             string nam;
         
          cout<<"please enter your first name:";
          cin>>nam;
          
          ifstream r("Reg_user.dat");
          while(r.read((char*)&b,sizeof(b)))
          {
             if( nam == b.f_name)
             {
                
              b.display();       
               
             }
             else{
                cout<<"computer is either searching or wasn`t able to find your record.\n";
             }
          } 
          Sleep(5000);
          system("cls");
          r.close();
       }
   
   }
   while(key != 8);
   system("cls");
   b.welcome();
   cout<<"\t\t\t\t\tThank you for visiting our bank.\t\t\t\t\t\t"<<endl;
}
