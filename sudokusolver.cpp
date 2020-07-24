#include<bits/stdc++.h>
using namespace std;
bool isPossible(int mat[][99],int row,int col,int n,int number){



  for(int i=0;i<n;i++){

    if(mat[i][col]==number or mat[row][i]==number){

      return false;

    }

  }



  int x = (row/3)*3;

  int y = (col/3)*3;



  for(int i=x;i<x+3;i++){

    for(int j=y;j<y+3;j++){



      if(mat[i][j]==number){

        return false;

      }



    }

  }



  return true;

}

bool sudokuSolver(int mat[][99],int row,int col,int n){

  if(row==n){

    for(int i=0;i<n;i++){

      for(int j=0;j<n;j++){

        cout<<mat[i][j]<<" ";

      }

      cout<<endl;

    }

    cout<<endl;

    return true;

  }



  if(col==n){

    return sudokuSolver(mat,row+1,0,n);

  }



  if(mat[row][col]!=0){

    return sudokuSolver(mat,row,col+1,n);

  }



  for(int options = 1;options<=9;options++){

    if(isPossible(mat,row,col,n,options)){



      mat[row][col] = options;



      bool rest_of_the_sudoku = sudokuSolver(mat,row,col+1,n);

      if(rest_of_the_sudoku){

        return true;

      }



      // mat[row][col] = 0;



    }

  }

  

   mat[row][col] = 0;



  return false;

}
int main()
{
  int n;
  cin>>n;

  int sudoku[99][99];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>sudoku[i][j];
    }
  }

  sudokuSolver(sudoku,0,0,n);
  
  
  


    
  return 0;
}