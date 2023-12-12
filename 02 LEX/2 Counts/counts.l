%{
    #include<stdio.h>
    int lc=0,sc=0,tc=0,ch=0,wc=0;  
%}
 
%%
[\n] { lc++; ch+=yyleng; }
[ \t] { sc++; ch+=yyleng; }
[^\t\n ]+ { wc++;  ch+=yyleng; } 
%%
 
int yywrap(){ 
	return 1;    
}
 
int main(){
    printf("Enter the Sentence  (press Ctrl+D to get output) :  ");
    yylex();
    printf("No of lines = %d\n",lc);
    printf("No of spaces = %d\n",sc);
    printf("No of words = %d\n",wc);
    printf("No of characters = %d\n",ch);
	
    return 0;
}
