#include<iostream>
using namespace std;
char check(char str[][3])
{
	cout<<"---------"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<str[i][j]<<" |";
		}
		cout<<endl;
		cout<<"---------"<<endl;
	}
	int count1=0,count2=0;
	//Diagonal1
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{	
			if(i==j && str[i][j]=='X')
			{
				count1++;
			}
			if(i==j && str[i][j]=='0')
			{
				count2++;
			}
		}
	}
	int c1=0,c2=0,x=2;
	//Diagonal2
	for(int i=0;i<3;i++)
	{	
			if(str[i][x]=='X')
			{
				c1++;
			}
			if(str[i][x]=='0')
			{
				c2++;
			}
			x--;
	}
	int r1=0,r2=0;
	//row1
	for(int i=0;i<3;i++)
	{	
			if(str[i][0]=='X')
			{
				r1++;
			}
			if(str[i][0]=='0')
			{
				r2++;
			}
	}
	int l1=0,l2=0;
	//lastrow
	for(int i=0;i<3;i++)
	{	
			if(str[i][2]=='X')
			{
				l1++;
			}
			if(str[i][2]=='0')
			{
				l2++;
			}
	}
	int cl1=0,cl2=0;
	//column1
	for(int i=0;i<3;i++)
	{	
			if(str[0][i]=='X')
			{
				cl1++;
			}
			if(str[0][i]=='0')
			{
				cl2++;
			}
	}
	int lc1=0,lc2=0;
	//lastcolumn
	for(int i=0;i<3;i++)
	{	
			if(str[2][i]=='X')
			{
				lc1++;
			}
			if(str[2][i]=='0')
			{
				lc2++;
			}
	}
	if(count1==3||c1==3 || l1==3 ||r1==3 ||cl1==3 ||lc1==3)
	{
		return 'X';
	}
	if(count2==3||c2==3 ||l2==3 ||r2==3 || cl2==3 ||lc2==3)
	{
		return '0';
	}
	else
	{
		return 'o';
	}
}
int main()
{
	int p1,p2;
	char c1,c2;
	//Assign the character to the players
	cout<<"Choose X or 0 :"<<endl;
	cout<<"Player1 choose:";
	cin>>c1;
	c2=c1=='X'?'0':'X';
	cout<<"Player2 you will get "<<c2<<""<<endl<<endl<<endl;
	
	
	int a[3][3];
	char s[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			s[i][j]=' ';
		}
	}
	int pos1,pos2,count=1;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			a[i][j]=count++;
		}
	}	
	//start the game
	//
	//Player1
	cout<<"Hint:)"<<endl;
	cout<<"You have to enter the position like the 2d array element:"<<endl<<endl;
	cout<<"Initially player1 will start the game:"<<endl<<endl;
	int count1=0,count2=0;
	for(int k=0;k<=(9/2);k++)
	{
		x:
		//player1 time to enter the position
		cout<<"Player1 enter the position you want to insert:";
		cin>>pos1;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(a[i][j]==pos1 && a[i][j]!=0)
				{
					s[i][j]=c1;
					a[i][j]=0;
					count1=1;
					break;
				}
			}
		}
		if(count1==0)
		{
			cout<<"This position is already filled, Please choose another position:"<<endl<<endl;
			goto x;
		}
		char res;
		res=check(s);
		if(res=='X')
		{
			cout<<"Player1 wins the game:)";
			return 0;
		}
		if(res=='0')
		{
			cout<<"Player2 wins the game:)";
			return 0;
		}
		
			
		//player 2
		if(k==9/2)
		{
			break;
		}
		y:
		count2=0;
		cout<<"Player2 enter the position you want to insert:";
		cin>>pos2;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(a[i][j]==pos2 && a[i][j]!=0)
				{
					
					s[i][j]=c2;
					a[i][j]=0;
					count2=1;
					break;
				}
			}
		}
		if(count2==0)
		{
			cout<<"This position is already filled, Please choose another position:"<<endl<<endl;
			goto y;
		}
		char res1;
		res1=check(s);
		if(res1=='X')
		{
			cout<<"Player1 wins the game:)";
			return 0;
		}
		if(res1=='0')
		{
			cout<<"Player2 wins the game:)";
			return 0;
		}
	}
	cout<<"Match is draw:)"<<endl;
	cout<<"You want to play another game just close the compiler and run them again:)"<<endl;
}

