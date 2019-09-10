/* 
 * Name Surname   : Mesut BUNALDI
 * Student Number : 111044077
 * Homework       : 02
 * Created on September 08, 2017, 8:25 PM
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
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

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
string* move_user(string* board,int size,bool userType,const char &gameType,bool &statementOfUser);
//user move function
int move_computer(string* board,int size);
//computer move function
string* makeBoard(string* ,int size=0);
//make new board function
void showBoard(string* board, int size);
//show board function
char convertLetter(char in);
//convert to small case function
int getColNumber(char columnName);
//get column number function
int runCommand(string columnName,string fileName,string* board,int &size,char typeOfUser,const char &gameType);
//command and fileName
bool play(string* board,int size,char typeOfUser,const char gameType,bool userType);
//overload play function for LOAD Command

/********************************************************************************************/

int main() {

    play();    

    return 0;
}

/********************************************************************************************/
int runCommand(string columnName,string fileName,string* board,int &size,char typeOfUser,const char &gameType){
    
    if(columnName=="SAVE"){
       
            ofstream myfile;
            myfile.open(fileName.c_str());//buraya file name gelecek
            myfile<<size<<endl;//size
            myfile<<typeOfUser<<endl;//player rank
            myfile<<gameType<<endl;//gameType
             for(int i=0;i<=size;i++){
                for(int j=0;j<size;j++)
                  myfile<<board[i][j];                    
                myfile<<endl;
            }
            myfile.close();
            cout<<"Game is saved >> "<<fileName<<endl;
            return 1;    
    }
    if(columnName=="LOAD"){
            cout<<"kaydedilmiş bir oyunu yükleyeceğim"<<endl;
            ifstream myfile;
            char gameType;
            myfile.open(fileName.c_str());     
            myfile>>size; 
            myfile>>typeOfUser;
            myfile>>gameType;
             string* tboard=new string[size+1];
             string tmpstr;
             getline(myfile,tmpstr);
             for(int i=0;i<=size;++i){
               getline(myfile,tboard[i]);
            }
            bool userType;
           play(tboard,size,typeOfUser,gameType,userType);
           myfile.close();
           return 3;
    }
  return 0;
}
/********************************************************************************************/
int checkWin(string* board,int size){
    auto counter=0;
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
                cerr<<"Board is full. You can not move. You can start new game..."<<endl;
                return -1;
            }
    return 0;
}
/********************************************************************************************/
int getColNumber(char columnName){
    int columnNumber=static_cast<int>(convertLetter(columnName))-97;
    return columnNumber;
}
/********************************************************************************************/
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
string* move_user(string* board,int size,bool userType,const char &gameType,int &statementOfUser){
        char checkerType;
        //int columnNumber;
        decltype(1) columnNumber;
        string columnName,fileName,command;
        if(userType==true)
            checkerType='O';
        else
            checkerType='X';        
            do{   
                cout<<"Please give me a column name for move : "<<checkerType<<endl;
                getline(cin,columnName);
                columnNumber=getColNumber(columnName[0]);
                if(columnName.size()>1){ 
                    for(int i=0;i<=3;++i)
                        command=command+columnName[i]; // command 
                    for(int j=5;j<=columnName.size();++j)
                        fileName=fileName+columnName[j];                   
                  statementOfUser=  runCommand(command,fileName,board,size,checkerType,gameType);   
                }              
            }while(columnNumber>=size || columnNumber<0);         
           if(columnName.size()==1 ){
                for(int row=size;row>0;--row){

                    if(board[row][columnNumber]=='.' ){
                        if(userType==false) // eğer user 1 ise
                            board[row][columnNumber]='X';
                        else if(userType==true) // eğer user 2 ise
                            board[row][columnNumber]='O';
                        break;
                    }
                }
            }
        return board;
}
/********************************************************************************************/       
bool play(){
    int statementOfUser=0;
    string temp;
    int size = setBoardSize();
    cout << "Size of Board is  : " << size << " x " << size << endl;
    getline(cin,temp);
    char gameType=chooseGameType();
    cout << "Type of Game is : " << gameType << endl;
    string* tempBoard=new string[size+1];
    makeBoard(tempBoard,size);
    int statementWin=0,mode=0;
    showBoard(tempBoard, size);
     bool userType=false; 
    if(gameType=='P'){  
        while(statementWin==0){               
             if(statementOfUser==1){
                 statementOfUser=0;   
                 if(mode%2==0)
                         userType=false;
                 else
                         userType=true;
                     ++mode;                
            }else{                
            
            if(mode%2==0)
                userType=false;//X
            else
                userType=true;//O            
            ++mode;           
            }
            move_user(tempBoard,size,userType,gameType,statementOfUser);
            statementWin=checkWin(tempBoard,size);  
            showBoard(tempBoard, size);
            if(statementWin==1){
                cout<<"User 1 is winner!"<<endl;
                exit(0);
            }
            else if(statementWin==2){
                cout<<"User 2 is winner"<<endl;
                exit(0);
            }
        }
      }
    else if(gameType=='C')  {
                bool userType=false;
                while(statementWin==0){
                    move_user(tempBoard,size,userType,gameType,statementOfUser);
                    cout<<"sign: <<"<<statementOfUser<<endl;
                    statementWin=checkWin(tempBoard,size); 
                      showBoard(tempBoard, size);
                    if(statementWin==1){
                        cout<<"User kazandı!"<<endl;
                        exit(0);
                    }
                    if(statementWin!=1){    
                        move_computer(tempBoard,size);
                        statementWin=checkWin(tempBoard,size);
                         showBoard(tempBoard, size);
                        if(statementWin==2){
                            cout<<"Computer kazandı!"<<endl;
                            exit(0);
                        }
                    }
                }  
    }    
    return true;
}
/********************************************************************************************/
bool play(string* board,int size,char typeOfUser,const char gameType,bool userType){
    int statementOfUser=0;    
    cout << "Size of Board is  : " << size << " x " << size << endl;   
    cout << "Type of Game is : " << gameType << endl;  
    int statementWin=0,mode=0;    
    showBoard(board, size);  
    if(gameType=='P'){          
        while(statementWin==0){               
             if(statementOfUser==1){
                 statementOfUser=0;   
                 if(mode%2==0)
                         userType=false;
                 else
                         userType=true;
                     ++mode;                
            }else{                
            
            if(mode%2==0)
                userType=false;//X
            else
                userType=true;//O            
            ++mode;           
            }           
            move_user(board,size,userType,gameType,statementOfUser);
            statementWin=checkWin(board,size);  
            showBoard(board, size);
            if(statementWin==1){
                cout<<"User 1 is winner!"<<endl;
                exit(0);
            }
            else if(statementWin==2){
                cout<<"User 2 is winner"<<endl;
                exit(0);
            }     
        }
      }
    else if(gameType=='C')  {        
                bool userType=false;       
                while(statementWin==0){
                    move_user(board,size,userType,gameType,statementOfUser);
                    cout<<"sign: <<"<<statementOfUser<<endl;
                    statementWin=checkWin(board,size); 
                      showBoard(board, size);
                    if(statementWin==1){                      
                        cout<<"User kazandı!"<<endl;
                        exit(0);
                    }
                    if(statementWin!=1){    
                        move_computer(board,size);
                        statementWin=checkWin(board,size);
                         showBoard(board, size);
                        if(statementWin==2){                           
                            cout<<"Computer kazandı!"<<endl;
                            exit(0);
                        }                         
                    }
                } 
    }    
    return true;
}
/********************************************************************************************/
char chooseGameType() {   
    string typeOfGame;//burayı string al ve stringin sıfırıncı elemanını oku   
    do {
        cout << "Hi , can you give me a number for games type?" << endl;
        cout << "P-User versus User" << endl;
        cout << "C-User versus Computer" << endl;
        getline(cin,typeOfGame);
    }while (typeOfGame[0]!='P' && typeOfGame[0]!='C');
    return typeOfGame[0];
}
/********************************************************************************************/
int setBoardSize() {
    int size = 0;
    do{        
       cout << "Can you give me board size ? \nMinimum Size : 20\nMaximum Size : 4" << endl;
       cin>>size;        
    }while (size % 2 != 0 || size > 20 || size < 4 );
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
