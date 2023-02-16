#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <cstring>
#include<bits/stdc++.h> 
#include <sys/resource.h>
#include <unistd.h>
#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX=500;
typedef string lista[MAX];


int getAllocatedMemory()
{

    unsigned long long NSpid; 
    string str="NSpid";
    string l[MAX];
    int VmPeak;



    ifstream input;
    input.open("/proc/self/status");
    int i=0,n;
    while (!input.eof()){ 
        input >> l[i];
        i++;
    }
    n=i;
    for(i=0;i<n;i++){
        if(l[i]=="VmPeak:"){
            VmPeak=stoi(l[i+1]);
            cout<<"VmPeak is equal to: "<<l[i+1]<<"kB\n";
        }
    }
    input.close();
	return VmPeak;
}


int main () 
{
	
    int initial_value = getAllocatedMemory();
    int* p = new int[1000000];
    for (int i = 0; i < 1000000; i++) {
       p[i] = 10 * (i + 1);
    }
    int final_value = getAllocatedMemory();  
    return 0;
}
