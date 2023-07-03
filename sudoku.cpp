

//HEADER FILE USED AND DFINING THE CONSTANT USING #DEFINE

#include<iostream>
using namespace std;
#define misplaced 0
#define N 9


//FUNCTIONS DEFINED


bool misplacedlocation(int sudoku[N][N],int& row, int& col);
bool check(int sudoku[N][N], int row,int col, int num);
bool solve (int sudoku[N][N]);


//FUNCTION DEFINITION


//Function to begin the solution of sudoku
//In this function firstly, it will be checked that cell is empty or not
// If the cell is empty then it will enter a number range from 1 to 9 in that cell


bool Solve(int sudoku[N][N])
{
	int row, col;
	if (!misplacedlocation(sudoku, row, col))
        {
           return true;
        }

    for (int num=1;num<=9;num++)
	{
		if (check(sudoku, row, col, num))
		{
			sudoku[row][col] = num;

			   if (Solve(sudoku))
				   {
				       return true;
				   }
			sudoku[row][col] = misplaced;
        }
	}

	return false;
}

//FUNCTION to check that cell of sudoku matrix empty or not.

//Here, empty cell means that cell has a value 0.

bool misplacedlocation(int sudoku[N][N],int& row, int& col)
{

	for (row = 0; row < N; row++)
        {
            for (col = 0; col < N; col++)
                 {
                        if (sudoku[row][col] == misplaced)
                            {
                                return true;

                            }
                 }
        }

	return false;
}

//FUNCTION to check that entered number is applicable in that particular row.

bool Checkrow(int sudoku[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
        {
            if (sudoku[row][col] == num)
                {
                    return true;
                }
        }
	return false;
}

//FUNCTION to check that entered number is applicable in that particular column.

bool Checkcol(int sudoku[N][N], int col, int num)
{

	for (int row = 0; row < N; row++)
		{
            if (sudoku[row][col] == num)
                {
                    return true;
                }
		}

	return false;

}


bool Checkbox(int sudoku[N][N], int boxStartRow,int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		 {
		     for (int col = 0; col < 3; col++)
			      {
			          if (sudoku[row + boxStartRow][col + boxStartCol]==num)
                      {
                        return true;
                      }
			      }
		 }
	return false;
}


//FUNCTION to check that inputed number is applicable in that cell , row and column

bool check(int sudoku[N][N], int row,int col, int num)
{
	return !Checkrow(sudoku, row, num)
		&& !Checkcol(sudoku, col, num)
		&& !Checkbox(sudoku, row - row % 3,col - col % 3, num)
		&& sudoku[row][col] == misplaced;
}

//FUNCTION to print the sudoku

void printsudoku(int sudoku[N][N])
{
    cout << "==========================================================================================="<<endl<<endl;

    cout << "------------------------------------SUDOKU SOLUTION--------------------------------------: "<<endl;

	for (int row=0;row<N;row++)
	{
		for (int col=0;col<N;col++)
			{

                cout<<sudoku[row][col]<<" ";

			}
		cout << endl;
	}

}
void SudokuRules()
{
cout<<"\n\n\t\t RULES FOR PLAYING THE GAME:-\n\n\n"<<endl;
cout<<"1. Enter numbers in 9x9 sudoku matrix."<<endl;
cout<<"2. Insert '0' for all the misplaced elements."<<endl;
cout<<"3. Each row must contain the numbers from 1 to 9, without repetitions."<<endl;
cout<<"4. Each column must contain the numbers from 1 to 9, without repetitions."<<endl;
cout<<"5. The digits can only occur once per block (nonet)."<<endl;
cout<<"6. The sum of every single row, column and nonet must equal 45.\n\n"<<endl;


}

//DRIVER PROGRAM

void sudokuSolver()
{
    cout<<"----------------------------------------------------SUDOKU SOLVER-------------------------------------------------------";

    cout<<endl;

    cout<<"Please Enter the sudoku matrix you want to solve:"<<endl;

	cout<<"Note: Enter the misplaced element as 0... "<<endl;

	int sudoku[N][N];

	for(int i = 0;i < N;i++)
       {
           for(int j = 0;j < N;j++)
           {
               cin >> sudoku[i][j];
           }
       }

	if (Solve(sudoku) == true)
        {
            printsudoku(sudoku);
        }

	else
      {
          cout<<"OOPS! NO SOLUTION FOUND"<< endl;
      }
}


void credits()
{
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"||                             SUDOKU SOLVER                                ||"<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"\n";
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"||                     SOLVE PROBLEMS ON YOUR FINGERTIPS                    ||"<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"------------------------------DEMO DEVELOPED BY:--------------------------\n\n\n";
    cout<<"\t\tENROLLMENT NUMBER\t      NAME\n";
    cout<<"\t\t9920103162\t\tMANAV MALHOTRA\n";
    cout<<"\t\t9920103177\t\tSHASHWAT SINGH CHAUHAN\n\n";
}

int main()
{
    test:
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"||                             SUDOKU SOLVER                                ||"<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"\n";
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"||                     SOLVE PROBLEMS ON YOUR FINGERTIPS                    ||"<<endl;
    cout<<"=============================================================================="<<endl;

    cout<<"\n\t\t\t       1. RULES  \n";
    cout<<"\t\t\t       2. SOLVE  \n";
    cout<<"\t\t\t       3. CREDITS     \n";
    cout<<"\t\t\t       4. EXIT     \n";

    cout<<"\n\nEnter Your Choice:   ";
    int choice;
    cin>>choice;
    if(choice == 1)
    {
        system("cls");
        SudokuRules();
        goto test;
    }
    else if(choice == 2)
    {
        system("cls");
        sudokuSolver();
        goto test;
    }
    else if(choice == 3)
    {
        system("cls");
        credits();
        goto test;
    }
    else if(choice == 4)
    {
        system("cls");
        cout<<"Press any key to exit.";
        //getch();
       exit(0);
       system("exit");
    }

    else
    {
        cout<<"\nInvalid Choice!\n\n";
        system("exit");
        goto test;
    }


    return 0;

}
