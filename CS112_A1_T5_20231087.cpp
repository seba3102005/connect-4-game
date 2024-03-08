// File:Subtract a Square
// Purpose:connect-4 game: The first player to connect 4 symbols horizontally, vertically or diagonally wins.
// Author: Seba Ibraheem Ezzat Mohamed
// ID: 20231087

#include<iostream>
using namespace std;

int validation_x(int x)
{
    while(x>5 || x<0)
    {
        cout<<"Invalid row"<<endl;
        cout<<"player 1 please choose a row from 1 to 6:";
        cin>>x;
        x=6-x;
    }
    return x;
}

int validation_y(int y)
{
    while(y>6 || y<0)
    {
        cout<<"Invalid Column"<<endl;
        cout<<"player 1 please choose a column from 1 to 7:";
        cin>>y;
        y=y-1;
    }
    return y;
}

void initialization(char arr[6][7])
{

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            arr[i][j] = '_';
        }
    }

}

int check_diagonals_vertical( char arr[6][7],char value1,char value2)
{

    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if(arr[i][j] == arr[i+1][j+1] && arr[i+1][j+1] == arr[i+2][j+2] && arr[i+2][j+2] == arr[i+3][j+3] && arr[i][j]!='_')
            {
                if(arr[i][j]==value1)
                {
                    return 8;
                }
                if(arr[i][j]==value2)
                {
                    return 9;
                }

            }
            if(arr[i][j] == arr[i+1][j] && arr[i+1][j] == arr[i+2][j] && arr[i+2][j] == arr[i+3][j] && arr[i][j]!='_')
            {
                if(arr[i][j]==value1)
                {
                    return 8;
                }
                if(arr[i][j]==value2)
                {
                    return 9;
                }
            }
        }
    }
    return 0;
}
int check_diagonals_horizontal(char arr[6][7],char value1, char value2)
{
    for(int i=5;i>=3;i--)
    {
        for(int j=0;j<=3;j++)
        {
            if(arr[i][j] == arr[i-1][j+1] && arr[i-1][j+1] == arr[i-2][j+2] && arr[i-2][j+2] == arr[i-3][j+3] && arr[i][j]!='_')
            {
                if(arr[i][j]==value1)
                {
                    return 8;
                }
                if(arr[i][j]==value2)
                {
                    return 9;
                }
            }
            if(arr[i][j] == arr[i][j+1] && arr[i][j+1] == arr[i][j+2] && arr[i][j+2] == arr[i][j+3] && arr[i][j]!='_')
            {
                if(arr[i][j]==value1)
                {
                    return 8;
                }
                if(arr[i][j]==value2)
                {
                    return 9;
                }
            }
        }
    }
    return 0;
}
int main()
{
    cout<<"            Welcome to connect-4 game"<<endl;
    cout<<"@ Instructions:"<<endl;
    cout<<"Firstly, Every player chooses the character that he will play with "<<endl;
    cout<<"The first player to connect 4 symbols horizontally, vertically or diagonally wins."<<endl;
    cout<<"let's start the game"<<endl<<endl;
    int x,y;
    char arr[6][7],value1,value2;
    initialization( arr);
    int indicator=0;
    while(check_diagonals_vertical( arr,value1,value2)!=8 && check_diagonals_vertical(  arr,value1,value2)!=9 && check_diagonals_horizontal(arr,value1,value2)!=8 && check_diagonals_horizontal(arr,value1,value2)!=9)
    {

        if(indicator%2==0)
        {
            if(indicator==0)
            {
                cout<<"Player 1:please choose your character from X or O:";
                cin>>value1;
                while(value1!='X' && value1!='O')
                {
                    cout<<"Invalid character\nplease enter X or O:";
                    cin>>value1;
                }
            }
            cout<<"player 1 please enter the row (1:6):";
            cin>>x;
            x=6-x;
            x=validation_x(x);

            cout<<"player 1 please enter the column(1:7):";
            cin>>y;
            y=y-1;
            y=validation_y(y);


            while(arr[x][y]!='_')
            {
                cout<<"please enter a non-taken position"<<endl;
                cout<<"player 1:enter a row:";
                cin>>x;
                x=6-x;
                x=validation_x(x);
                cout<<"player 1:enter a column:";
                cin>>y;
                y=y-1;
                y=validation_y(y);

            }


            arr[x][y]=value1;

        }
        else if(indicator%2==1)
        {
            if(indicator==1)
            {
                if(value1=='X')
                {
                    value2='O';
                }
                if(value1=='O')
                {
                    value2='X';
                }
                cout<<"player 2 your character is "<<value2<<endl;
            }
            cout<<"player 2 please enter the row:";
            cin>>x;
            x=6-x;
            x=validation_x(x);

            cout<<"player 2 please enter the column:";
            cin>>y;
            y=y-1;
            y=validation_y(y);




            while(arr[x][y]!='_')
            {
                cout<<"please enter a non-taken position"<<endl;
                cout<<"player 2:enter a row:";
                cin>>x;
                x=6-x;
                x=validation_x(x);
                cout<<"player 2:enter a column:";
                cin>>y;
                y=y-1;
                y=validation_y(y);

            }

            arr[x][y]=value2;

        }
        indicator++;

        //DISPLAY THE BOARD
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<7;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }


    }
    if(check_diagonals_vertical( arr,value1,value2)==8 || check_diagonals_horizontal(arr,value1,value2)==8)
    {
        cout<<"============Player 1 is the winner================"<<endl;
    }
    else if(check_diagonals_vertical( arr,value1,value2)==9 || check_diagonals_horizontal(arr,value1,value2)==9)
    {
        cout<<"============Player 2 is the winner================"<<endl;
    }
    cout<<"Quitting the game BYE BYE";
}
