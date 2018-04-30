#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string kullu[1000];


int myHash(string s){
	int i_ka_nunnu=0;

	for (int i = 0; i <s.length() ; i++)
	{
		if(int(s[i])<91 && int(s[i])>64)
			s[i]=s[i]+32;
		if(s[i]==',' || s[i]=='.')
			break;
		i_ka_nunnu=i_ka_nunnu+(i+1)*int(s[i]);

	}
	i_ka_nunnu=i_ka_nunnu%499;
	return i_ka_nunnu;
}


int main(){

	

string s[100]={};
int word_freq[1000]={0},thre;
cout<<"Enter the threshould: ";
cin>>thre;
cout<<"Words which have frequency greater than threshould are: "<<endl;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif


for (int i = 0; i < 100; i++){
	cin>>s[i];
	int temp=s[i].length();
	if(s[i][temp-1]==',' || s[i][temp-1]=='.')
	{
		s[i]=s[i].substr(0,temp-1);
	}
	if(s[i]!=""){
	word_freq[myHash(s[i])]++;
	kullu[myHash(s[i])]=s[i];
}
}

int l,j;
	string munnu;

	for (int i = 0; i < 1000; i++)
	{
		l=word_freq[i];
		munnu=kullu[i];
		for (j=i-1;j>=0 && l<word_freq[j]; j--)
		{
			word_freq[j+1]=word_freq[j];
			kullu[j+1]=kullu[j];
		}
		word_freq[j+1]=l;
		kullu[j+1]=munnu;
	}

for (int i = 999; i>=0; i--){
	if(word_freq[i]>=thre)
	cout<<kullu[i]<<":"<<word_freq[i]<<endl;
}
cout<<"Your paragraph:"<<endl;
for (int i = 0; i < 100; i++){
	cout<<s[i]<<" ";
}



    return 0;
}
