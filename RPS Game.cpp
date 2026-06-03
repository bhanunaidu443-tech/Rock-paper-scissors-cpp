#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
class RPS {
private:
        int userscore;
        int compscore;
public:
       RPS(){
       userscore=0;
       compscore=0;
       }
       int  user_input()
       {
       int user;
       do{cout<<"\n1.Rock 2.Paper 3.scissor\n";
       cout<<"\nEnter your option:";
       cin>>user;
       if(user<1 || user>3)
       cout<<"\nInvalid option! Choose 1 to 3 options only!\n";
       }while(user<1 || user>3);
       return user;
       }
       int comp_option()
       {
       return rand()%3+1;
       }
       int decide_winner(int user,int comp)
       { 
       if(user==comp)
       return 0;
       else if((user==1&&comp==3)||(user==2&&comp==1)||(user==3&&comp==2))
       return 1;
       else
       return -1;
       
       }
       void update_score(int result){
       if(result==1)
       userscore++;
       else if(result==-1)
       compscore++;
       }
       void display_score()
       {
       cout<<"\nYour score:"<<userscore;
       cout<<"\ncomputer score:"<<compscore<<endl;
       if(userscore==compscore)
       cout<<"Draw!";
       else if(userscore>compscore)
       cout<<"You won!";
       else
       cout<<"You lost! Better luck next time!";
       }
};
int main()
{
 RPS r;
 int user,comp;
 srand(time(0));
 for(int i=0;i<3;i++){
 cout<<"\nRound:"<<i+1<<endl;
 user=r.user_input();
 comp=r.comp_option();
 if(comp==1)
 cout<<"\ncomputer option is: 1.Rock";
 else if(comp==2)
 cout<<"\ncomputer option is: 2.Paper";
 else
 cout<<"\ncomputer option is: 3.scissor";
 int result=r.decide_winner(user,comp);
 r.update_score(result);
 if (result==0)
 cout<<"\n\nDraw!\n";
 else if(result==1)
 cout<<"\n\nYou Won!\n";
 else
 cout<<"\n\nYou lost!\n";
 }
 r.display_score();
 return 0;
}