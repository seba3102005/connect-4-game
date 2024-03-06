// Program: subtract a square game

//name:seba ibraheem ezzat mohamed

// Version: 1.1

// Date:   1/3/2024

#include<iostream>
#include<cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    char way;
    int n_coins,choice;
    float value;
    //the welcome status
    cout<<"Welcome to Subtract a Square number Game"<<endl;
    // display the 2 ways that are availabe for the user to use to set the n_coins
    cout<<"   :Please choose any way do you want: \nA)set the number of coins by yourself\nB)set a random number by the computer"<<endl;
    cout<<"Choose A/B"<<endl;
    cin>>way;
    while(toupper(way)!='A' && toupper(way)!='B')
    {
        cout<<"please enter a valid character"<<endl;
        cin>>way;
    }
    if(toupper(way)=='A')
    {
// set the number of the coins in the pile
        cout<<"Please enter the number of coins that you will subtract from: "<<endl;
        cin>>n_coins;
//validate if the the number of coins is suitable or not
        while(n_coins<=0)
        {
            cout<<"Please enter a valid number of coins that you will subtract from: "<<endl;
            cin>>n_coins;
        }
        cout<<"the number of coins is "<<n_coins<<endl;
    }
    else if(toupper(way)=='B')
    {
        srand(static_cast<unsigned int>(time(0)));
        n_coins = rand() % 100 + 1;
        cout<<"the number of coins is "<<n_coins<<endl;
    }
//the game starts
    while(n_coins>0)
    {
//player 1 plays
        cout<<"player 1: please enter a square number: "<<endl;
        cin>>choice;
//validate if the number positive or not
        if(choice<0)
        {
            cout<<"player 1: please enter a valid square number: "<<endl;
            cin>>choice;
        }
        value=sqrt(choice);

        while(ceil(value)!=floor(value) || choice==0 || choice>n_coins)
        {
            cout<<"player 1: please enter a valid square number: "<<endl;
            cin>>choice;
            value=sqrt(choice);
        }
        n_coins-=choice;
        cout<<"Now the number of coins is "<<n_coins<<endl;
        if(n_coins==0)
        {
            cout<<"======Player 1 is the Winner======"<<endl;
            break;
        }
//player 2 plays
        cout<<"player 2: please enter a square number: "<<endl;
        cin>>choice;
// validate if the number positive or not
        if(choice<0)
        {
            cout<<"player 2: please enter a valid square number: "<<endl;
            cin>>choice;
        }
        value=sqrt(choice);

        while(ceil(value)!=floor(value) || choice==0 || choice>n_coins)
        {
            cout<<"player 2: please enter a valid square number: "<<endl;
            cin>>choice;
            value=sqrt(choice);
        }
        n_coins-=choice;
        cout<<"Now the number of coins is"<<n_coins<<endl;
        if(n_coins==0)
        {
            cout<<"======Player 2 is the Winner======"<<endl;
            break;
        }
    }
    cout<<"BYE BYE"<<endl;

}
