/* 
 * Name Surname   : Mesut BUNALDI
 * Student Number : 111044077
 * Homework       : 01
 * Created on September 18, 2017, 8:25 PM
 * 
 * 
 * 
 * "X" is User1 , "O" is User2  or Computer, " . " is Empty
 * Board size is maximum : 20 x 20
 * Board size is minimum : 4 x 4
 * 
 * 
 * 
 * 
 * compile and run commands:
 * 
 * 1-open the terminal
 * 2-open your project folder (cd .. )
 * 3-enter the commands : 
 *   -make
 *   -make run 
 * 
 * 
 * 
 */



#include <iostream>
#include <string>
using namespace std;
/********************************************************************************************/
char chooseGameType(); 
//P-)user vs user or C-)computer vs user
int setBoardSize(); //
//set game board size
bool play();
//play function
int checkWin(string* board,int size); 
//winner check function
string* move_user(string* board,int size,bool userType);
//user move function
int move_computer(string* board,int size);
//computer move function
string* makeBoard(string* ,int size);
//make new board function
void showBoard(string* board, int size);
//show board function
char convertLetter(char in);
//convert to small case function
int getColNumber(char columnName);
//get column number function

/********************************************************************************************/



int main() {

    play();


    return 0;
}

/********************************************************************************************/
int checkWin(string* board,int size){
    
    int counter=0;
    for(int row=1;row<=size;++row){
        for(int col=0;col<size;++col){
            if(board[row][col]=='.')
                ++counter;
            
                
            if((row<size-2 && row>0)&& board[row][col]=='X' && board[row+1][col]=='X'&& board[row+2][col]=='X'&& board[row+3][col]=='X'){
                board[row][col]='x' ;
                board[row+1][col]='x';
                board[row+2][col]='x';
                board[row+3][col]='x';
                // showBoard(board,size);
             // cout<<"user1 kazandı!" <<endl;
              return 1;  
            }
            if((col<size-3 && col>=0) && (board[row][col]=='X' && board[row][col+1]=='X'&& board[row][col+2]=='X'&& board[row][col+3]=='X')){
                board[row][col]='x';
                board[row][col+1]='x'; 
                board[row][col+2]='x';
                board[row][col+3]='x';
               // showBoard(board,size);
               //  cout<<"user1 kazandı!" <<endl;
                 return 1;  
            }
            
            if(( col>=3 && row<size-2) && (board[row][col]=='X' && board[row+1][col-1]=='X' && board[row+2][col-2]=='X')&& board[row+3][col-3]=='X'){
                board[row][col]='x';
                board[row+1][col-1]='x' ;
                board[row+2][col-2]='x';
                board[row+3][col-3]='x';
                 //showBoard(board,size);
                //cout<<"user1 kazandı!" <<endl;
                return 1;  
            }
             if((col<size-3 && row<size-2) && (board[row][col]=='X' && board[row+1][col+1]=='X' && board[row+2][col+2]=='X')&& board[row+3][col+3]=='X'){
                 board[row][col]='x' ;
                 board[row+1][col+1]='x' ;
                 board[row+2][col+2]='x';
                 board[row+3][col+3]='x';
                  //showBoard(board,size);
                //cout<<"user1 kazandı!" <<endl;
                return 1;  
            }      
            
            
            if((row<size-2 && row>0)&& board[row][col]=='O' && board[row+1][col]=='O'&& board[row+2][col]=='O'&& board[row+3][col]=='O'){
                board[row][col]='o' ;
                board[row+1][col]='o';
                board[row+2][col]='o';
                board[row+3][col]='o';
                // showBoard(board,size);
              //cout<<"user2 kazandı!" <<endl;
              return 2;  
            }
            if((col<size-3 && col>=0) && (board[row][col]=='O' && board[row][col+1]=='O'&& board[row][col+2]=='O'&& board[row][col+3]=='O')){
                board[row][col]='o' ;
                board[row][col+1]='o';
                board[row][col+2]='o';
                board[row][col+3]='o';
                 // showBoard(board,size);
                 //cout<<"user2 kazandı!" <<endl;
                 return 2;  
            }
            
            if(( col>=3 && row<size-2) && (board[row][col]=='O' && board[row+1][col-1]=='O' && board[row+2][col-2]=='O')&& board[row+3][col-3]=='O'){
                board[row][col]='o';
                board[row+1][col-1]='o';
                board[row+2][col-2]='o';
                board[row+3][col-3]='o';
                // showBoard(board,size);
               // cout<<"user2 kazandı!" <<endl;
                return 2;  
            }
             if((col<size-3 && row<size-2) && (board[row][col]=='O' && board[row+1][col+1]=='O' && board[row+2][col+2]=='O')&& board[row+3][col+3]=='O'){
                 board[row][col]='o';
                 board[row+1][col+1]='o'; 
                 board[row+2][col+2]='o';
                 board[row+3][col+3]='o';
                  //showBoard(board,size);
                //cout<<"user2 kazandı!" <<endl;
                return 2 ;  
            }
            
           
        }
        
    }
     if(counter==0){
                cout<<"Board is full. You can not move. You can start new game..."<<endl;
                return -1;
            }
  
    return 0;
}
int getColNumber(char columnName){
    int columnNumber=static_cast<int>(convertLetter(columnName))-97;
    return columnNumber;
}
char convertLetter(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
} 

/********************************************************************************************/

int move_computer(string* board,int size){

    
    for(int row=size;row>=1;--row){
        for(int col=0;col<size;++col){
            
            if(board[row][col]=='.' ){
                board[row][col]='O';
                cout<<"Computer move is : "<<static_cast<char>(col+97)<<row<<endl;
                return 1;
            }
            
        }
    }
    return 0;
}
/********************************************************************************************/
string* move_user(string* board,int size,bool userType){
    
        char columnName,checkerType;
        if(userType==true)
            checkerType='O';
        else
            checkerType='X';
        cout<<"Please give me a column name for move : "<<checkerType<<endl;
        cin>>columnName;
        
        int columnNumber=getColNumber(columnName);
        
            while(columnNumber>=size || columnNumber<0){
                cout<<"Invalid value, please try again : "<<endl;
                cin>>columnName;
                columnNumber=getColNumber(columnName);

            }
        
            for(int row=size;row>0;--row){
                
                if(board[row][columnNumber]=='.' ){
                    if(userType==false) // eğer user 1 ise
                        board[row][columnNumber]='X';
                    else if(userType==true) // eğer user 2 ise
                        board[row][columnNumber]='O';
                    break;
                }
            }
    
       
       // showBoard(board,size);
       
        return board;
}

/********************************************************************************************/
         
bool play(){
    
    int size = setBoardSize();
    cout << "Size of Board is  : " << size << " x " << size << endl;
    char gameType=chooseGameType();
    cout << "Type of Game is : " << gameType << endl;
    string* tempBoard=new string[size+1];
    makeBoard(tempBoard,size);
    int statementWin=0,sign=0;
  
    showBoard(tempBoard, size);
      
    
      
        
    if(gameType=='P'){  
        cout<<"Game is User 1 vs User 2."<<endl; 
        while(statementWin==0){////eğer user vs user ise                  
            bool userType=false; //user 1 başlıyor
            move_user(tempBoard,size,userType);
            statementWin=checkWin(tempBoard,size);  
            showBoard(tempBoard, size);
            if(statementWin==1){//user1 win
                sign=1;
                cout<<"User 1 kazandı!"<<endl;
                
            }
            if(sign==0){//if user 1 and user 2 are not winner
                userType=true;//user 2 oynasın diye user Type ı değiştriyoruz.
                move_user(tempBoard,size,userType);
                statementWin=checkWin(tempBoard,size);
                showBoard(tempBoard, size);
                if(statementWin==2){
                    cout<<"User 2 kazandı!"<<endl;
                }
                
            }
        }
      }
    else if(gameType=='C')  {
        
                bool userType=false;
       
                while(statementWin==0){
                    move_user(tempBoard,size,userType);
                    statementWin=checkWin(tempBoard,size); 
                      showBoard(tempBoard, size);
                    if(statementWin==1){
                      
                        cout<<"User kazandı!"<<endl;
                    }
                    if(statementWin!=1){    
                        move_computer(tempBoard,size);
                        statementWin=checkWin(tempBoard,size);
                         showBoard(tempBoard, size);
                        if(statementWin==2){
                           
                            cout<<"Computer kazandı!"<<endl;
                        }
                         
                    }
                }
                
                
    }    
   
    return true;

}
/********************************************************************************************/
char chooseGameType() {
    cout << "Hi , can you give me a number for games type?" << endl;
    cout << "P-User versus User" << endl;
    cout << "C-User versus Computer" << endl;
    char typeOfGame;
    cin>>typeOfGame;
    while (typeOfGame!='P' && typeOfGame!='C') {
        cout << "This value is invalid.Please try again : " << endl;
        cin>>typeOfGame;
    }
    return typeOfGame;
}

/********************************************************************************************/
int setBoardSize() {
    cout << "Can you give me board size ? \nMinimum Size : 20\nMaximum Size : 4" << endl;
    int size = 0;
    cin>>size;
   
    while (size % 2 != 0 || size > 20 || size < 4 ) {
        
        cout << "This value is invalid.Please try again : " << endl;
        cin>>size;
        
        
    }
    return size;
}

/*********************************************************************************************/

string* makeBoard(string* board,int size) {   
    for(int row=0;row<=size;row++){
        for(int col=0;col<size;col++){
            if(row==0){
                board[row]+=col+97;
            }
            else{
                board[row]+='.';
            }           
        }       
    }
    return board;
}   

/**********************************************************************************************/
void showBoard(string* board, int size) {
    for(int i=0;i<=size;i++){
        for(int j=0;j<size;j++)
           cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
/***********************************************************************************************/
