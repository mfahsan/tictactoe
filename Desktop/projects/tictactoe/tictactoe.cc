#include <iostream>
#include <string.h>
using namespace std;



bool checkWin(string board[9], string pl, string X) {
  if (X == "NW") {
    if ((board[1] == pl) && (board[2] == pl)) return true;
    if ((board[3] == pl) && (board[6] == pl)) return true;
    if ((board[4] == pl) && (board[8] == pl)) return true;
    return false;
  }
  if (X == "NE") {
    if ((board[1] == pl) && (board[0] == pl)) return true;
    if ((board[5] == pl) && (board[8] == pl)) return true;
    if ((board[4] == pl) && (board[6] == pl)) return true;
    return false;
  }
 if (X == "C") {
   if ((board[1] == pl) && (board[7] == pl)) return true;
   if ((board[3] == pl) && (board[5] == pl)) return true;
   return false;
 }
 if (X == "N") {
   if ((board[4] == pl) && (board[7] == pl)) return true;
   if ((board[0] == pl) && (board[2] == pl)) return true;
   return false;
 } 
 if (X == "S") {
   if ((board[4] == pl) && (board[1] == pl)) return true;
   if ((board[6] == pl) && (board[8] == pl)) return true;
   return false;
 } 
 if (X == "E") {
   if ((board[4] == pl) && (board[3] == pl)) return true;
   if ((board[2] == pl) && (board[8] == pl)) return true;
   return false;
 } 
 if (X == "W") {
   if ((board[0] == pl) && (board[6] == pl)) return true;
   if ((board[4] == pl) && (board[5] == pl)) return true;
   return false;
 } 
 if (X == "SW") {
    if ((board[7] == pl) && (board[8] == pl)) return true;
    if ((board[3] == pl) && (board[0] == pl)) return true;
    if ((board[4] == pl) && (board[2] == pl)) return true;
    return false;
  }
if (X == "SE") {
    if ((board[7] == pl) && (board[6] == pl)) return true;
    if ((board[5] == pl) && (board[2] == pl)) return true;
    if ((board[4] == pl) && (board[0] == pl)) return true;
    return false; 
  }
return false;
}


bool enterForPlayer(string board[9], string X, string pl) {
 
 if (X == "NW") {
  if (board[0] == " ") {
  board[0] = pl;
  return true;
 }
 cout << "Thats taken!";
 return false; 
  }
  else if (X == "N") {
   if (board[1] == " ") {
   board[1] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;
  }
  else if (X == "NE") {
     if (board[2] == " ") {
   board[2] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;
    
  }
  else if (X == "W") {
   if (board[3] == " ") {
   board[3] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;
  }
  else if (X == "C") {
   if (board[4] == " ") {
   board[4] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;

  }
  else if (X == "E") {

  if (board[5] == " ") {
   board[5] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;
  }
  else if (X == "SW") {
   if (board[6] == " ") {
   board[6] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;
    
  }
  else if (X == "S") {
  if (board[7] == " ") {
   board[7] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;
    
  }
  else if (X == "SE"){
   if (board[8] == " ") {
   board[8] = pl;
    return true;
  }
  cout << "Thats taken!";
  return false;
  }
  else {
    cout << "Invalid Command!";
    return false;
  }
}


 void printboard(string board[9]) {
  cout << "         ";
  cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
  cout << "         ";
  cout << "-----" << endl;
  cout << "         ";
  cout << board[3]  << "|" << board[4]  << "|" << board[5]  << endl;
  cout << "         ";
  cout << "-----" << endl;
  cout << "         ";
  cout << board[6]  << "|" << board[7]  << "|" << board[8]  << endl;
}


int main () {
 
string board[9] = {" ", " "," ", " "," ", " "," ", " "," "};
 cout << endl;
 cout << "*********************" << endl;
 cout << "Welcome to tictactoe!!" << endl;
 cout << "*********************" << endl;
 cout << endl;
 cout << "Commands are: NW, N, NE, W, C, E, SW, S, SE, quit" << endl;
 int cc = 0;
 
 while (cc < 9) {
  cout << "X's move" << endl;
  

  string X;
  

  while(1) {
    cin >> X;
    if (X == "quit") break;
    if (enterForPlayer(board, X, "X")) break;
    else {
    cout << endl;
    cout << "Enter another" << endl;
    }
  }
  if (X == "quit") break;
  
  cc++; 
  printboard(board);
  if (checkWin(board, "X", X)) {
    cout << "X wins!" << endl;
    cc++;
    break;
  }
  
  if (cc == 9) break;
  cout << endl;
  cout << "O's move" << endl;
  string Y;
  
  while(1) {
    cin >> Y;
    if (Y == "quit") break;
    if (enterForPlayer(board, Y, "O")) break;
    else {
    cout << "Enter another" << endl;
    }
  }
  if (Y == "quit") break;


  printboard(board);
  if (checkWin(board, "O", Y)) {
    cout << "O wins!" << endl;
    cc++;
    break;
  }
  cc ++;
 }
 if (cc == 9) {
  cout << "It's a draw!" << endl;
 }

} 

