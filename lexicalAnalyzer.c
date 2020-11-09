#include <iostream>
#include <stdio.h>
/*包含库所用的某些宏和变量*/
#include <stdlib.h>
/*包含库*/
#include <string.h>
/*包含字符串处理库*/
#define _KEY_WORD_END "waiting for your expanding"/*定义关键字结束标志*/
/*拼接
typedef struct
/*单词二元组的结构，可以根据需要继续扩充*/
typedef struct {
    int typenum;
    char * word;
}WORD;

char input[255];
/*输入换缓冲区*/
char token[255]="";
/*单词缓冲区*/
int p_input;
/*输入换缓冲区指针*/
int p_token;
/*单词缓冲区指针*/
char ch;
/*当前读入字符*/
char * rwtab[]={"begin","if","then”，＂while","do","end", ＿KEY_WORD_END};
/*可扩充的关键字数组*/
/*词法扫描函数，获得一个单词*/
int
WORD* scaner();
void main()
1
int over=1;
/*
WORD * oneword=new WORD;
耳
printf("Enter Your words (end with #):");
scanf("[#]s",input);
/*读入源程序字符串到缓冲区，以＃结束，允许多行输入*/
p_input=0;
printf("Your words:\ng s \n",input);
while(over<1000&&over!=-1){
/*对源程序进行分析，直至结束符＃
*/
oneword=scaner();
/*获得一个新单词*/
if(oneword->typenum<1000)
printf("(% d,s s)",oneword->typenum,oneword->word);
/*打印种别码和单词自身的值*/
over=oneword->typenum;
printf("npress #to exit:");
/*按＃退出程序*/
scanf(".[#]s",input);
/*需要用到的自编函数参考实现*/
/*从输入缓冲区读取一个字符到ch中*/
char m_getch(){
ch=input[p_input];
（
f
1


p-inbuc=b_1nput +1;
return(ch);
附录C 编译程序实验
（
/*去掉空白符号*/
void getbc(){
while(ch==''|lch==10){
ch=input[p_input];
p_input=p_input +1;
一
标志*/
/*拼接单词*/
void concat(){
token[p_token]=ch;
p_token=p_token+1;
token [p_token]='0';
/*判断是否字母*/
int letter(){
if(ch>='a'&&ch<='z' |lch>='A'&&ch<='Z')return 1;
else return 0;
/*判断是否数字*/
int digit(){
if(ch>='0'&&ch<='9')return 1;
else return 0;
/*检索关键字表格*/
int reserve(){
人*/
int i=0;
while(strcmp(rwtab[i],_KEY_WORD_END)){
0010391
if(!strcmp(rwtab[i],token)){
31W8 9819
return i+1;
i=i+1;
return 10;
/*回退一个字符*/
void retract(){
p_input=p_input-1;
/*数字转换成二进制，请读者自己补全*/
char* dtb(){
return NULL;
1
｛
｛
1
（
1
｛
（


编译原理（第4版）
词法扫描程序：
WORD* scaner(){
WORD* myword=new WORD;
myword->typenum =10;
myword->word=";
p_token=0;
m_getch();
getbc();
if(letter()){
while(letter()lldigit()){
concat();
m_getch();
｛
retract();
myword->typenum =reserve();
290Ja1 201
myword->word=token;
return(myword);
｛
else if(digit()){
＊细餐
while(digit()){
01131925 101
concat();
32'01-<0)11
eLmn1:
m_getch();
0.nzode:9ate
｛
retract();
myword->typenum=20;
myword->word=token;
return(myword);
｛
else switch(ch){
取等
case'=':
m_getch();
if (ch=='='){
myword->typenum=39;
myword->word="==";
return(myword);
retract();
myword->typenum=21;
myword->word="=";
return(myword);
break;
case'+':
myword->typenum=22;
myword->word="+”；
｛


附录C 编译程序实验
return(myword);
break;
case '_':
myword->typenum=23;
myword->word="_";
return(myword);
break;
case'*':
myword->typenum=24;
myword->word="*";
return(myword);
break;
case '/':
myword->typenum=25;
myword->word="/;
return(myword);
和结构
break;
case ' (':
myword->typenum=26;
myword->word="(";
return (myword);
break;
case ')':
myword->typenum=27;
myword->word=")";
return (myword);
break;
case'[':
myword->typenum=28;
myword->word="[";
return(myword);
break;
case'1':
myword->typenum=29;
myword->word="]”；
return(myword);
break;
case '{':
myword->typenum=30;
myword->word="{";
return(myword);
break;
case'}':
myword->typenum=31;
myword->word="y";
return(myword);
break;
case
myword->typenum=32;
myword->word=",";
return(myword);
break;
myword->typenum=33;
case
217


编译原理（第4版）
myword->word=":";
return (myword);
break;
case';':
myword->typenum=34;
myword->word=";";
return (myword) ;
break;
case'>':
m_getch();
if (ch=='='){
myword->typenum=37;
C.2.1
实验
myword->word=">=";
return (myword);
编制一个
1
分析。
retract();
myword->typenum=35;
C.2.2
实
myword->word=">";
利用C语
return(myword);
break;
1.待分
case'<':
m_getch();
用扩充的
if(ch=='='){
（1)<程
myword->typenum=38;
（2)<语
myword->word="<=";
（3)语
return(myword);
（4)<赋
（5)<表
retract();
myword->typenum=36;
（6)<项
myword->word="<";
（7)<因
return(myword);
2.实验
break;
输入单
case'!':
m_getch();
cess",否则
if (ch=='='){
例如：
myword->typenum=40;
输
myword->word="!=";
输
return(myword);
｛
retract();
myword->typenum=-1;
C.2.3
myword->word="ERROR";
return(myword);
（1)
break;
（2)
case'0':
myword->typenum=1000;
（3)
myword->word="OVER";
（4)
return(myword);
图C.8、
辅
1

附录C 编译程序实验
break;
default:
myword->typenum=-1;
警号C
myword->word ="ERROR";
return(myword);
｛
C.2
语法分析
C.2.1
实验目的
编制一个递归下降分析程序，实现对词法分析程序所提供的单词序列的语法检查和结构
析。
2.2
实验要求
利用C语言编制递归下降分析程序，并对简单语言进行语法分析。
1.待分析的简单语言的语法
用扩充的 BNF 表示如下：
（1)<程序＞：：＝begin<语句串＞end
（2)<语句串＞：：＝＜语句＞｛；＜语句＞｝
（3)<语句＞：：＝＜赋值语句＞
（4)<赋值语句＞：：＝ID:=<表达式＞
（5)<表达式＞：：＝＜项＞｛＋＜项＞｜－＜项＞｝
（6)<项＞：：＝＜因子＞｛＊＜因子＞｜／＜因子＞｝
（7)<因子＞：：＝IDI NUMI(<表达式＞）
2. 实验要求说明
输入单词串，以“＃”结束，如果是文法正确的句子，则输出成功信息，打印“suc-
ss”，否则输出＂error”。
例如：
输入 begin a:=9;x:=2*3;b:=a+x end #
）

