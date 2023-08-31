#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;

void findCombinations(vector<char> keypad[],
                      int input[], string res, int index, int n ,string comb[], int& count)
{
    if (index == n) {
        comb[count] = res;
        count +=1;
        return;
    }
    
    int digit = input[index];
 
    
    int len = keypad[digit].size();


  
    for (int i = 0; i < len; i++) {
        findCombinations(keypad, input, res + keypad[digit][i], index + 1, n ,comb, count);
    }
}


int main() {

ifstream fin("yawl.txt");
ofstream fout("output.txt");


string words[10000];
int count=0;
string word;

if(!fin.is_open()) {
      cout << "File not found." <<  endl;
      return 1;
   }
 
while(!fin.eof()) {
  fin >> word;
  if((word.length()==3) || (word.length()==4)) {
    words[count]=word;
    count+=1;
  }
}


  
  
string number;
cin >> number;
if(number.at(3)!= '-'){
    cout << "Invalid phone number" << endl;
    return -99;
  }
if(number.length() != 8) {
    cout << "Invalid phone number" << endl;
    return -9;
  }
for(int i=0; i< number.length(); i++) {
  if(i!=3){
  if((number.at(i) == '0') || (number.at(i) == '1')) {
    cout << "Invalid phone number" << endl;
    return -999;
    }
  if(!isdigit(number.at(i))) {
   cout << "Invalid phone number" << endl;
    return -99; 
  }
  }
}
  

int threedigit[3];
int fourdigit[4];

for(int i=0; i<3;i++){
    threedigit[i] = (int)number.at(i)-48;
}
int j=0;
for(int i=4; i <8 ;i++){
    fourdigit[j] = (int)number.at(i)-48;
    j++;
}

    vector<char> keypad[] =
    {
        {}, {},
        { 'A', 'B', 'C' },
        { 'D', 'E', 'F' },
        { 'G', 'H', 'I' },
        { 'J', 'K', 'L' },
        { 'M', 'N', 'O' },
        { 'P', 'Q', 'R', 'S'},
        { 'T', 'U', 'V' },
        { 'W', 'X', 'Y', 'Z'}
    };

  string combthree[1000];
  int countthree =0;
  int n = sizeof(threedigit)/sizeof(threedigit[0]);

    findCombinations(keypad, threedigit, string(""), 0, n, combthree, countthree);


string combfour[1000];
int countfour=0;
int k = sizeof(fourdigit)/sizeof(fourdigit[0]);
    
  findCombinations(keypad, fourdigit, string(""), 0, k, combfour, countfour);


string newthreelist[100];
int newthreecount=0;
for(int i=0; i<countthree; i++) {
  for(int a=0; a<count; a++) {
    if(combthree[i] == words[a]) {
      newthreelist[newthreecount]=combthree[i];
      newthreecount+=1;
    }
  }
}

string newfourlist[100];
int newfourcount=0;
for(int i=0; i<countfour; i++) {
  for(int a=0; a<count; a++) {
    if(combfour[i] == words[a]) {
      newfourlist[newfourcount]=combfour[i];
      newfourcount+=1;
    }
  }
}
for(int i=0; i<newthreecount; i++) {
  for(int a=0; a<newfourcount; a++) {
    fout << newthreelist[i] << '-' << newfourlist[a] << endl;
    }
  }

fin.close();
fout.close();


return 0;
}