%{
#include "scanner.h"
int cur_line_num = 1;
enum tokenType{
    t_begin = 1, t_if, t_then, t_while, t_do, t_end,
    t_letter_contain_digit, t_digit, t_add, t_subtraction,
    t_mutiply, t_division, t_colon, t_colon_equal, t_less,
    t_quotation, t_less_equal, t_more, t_more_equal, t_equal,
    t_semicolon, t_left_parenthesis, t_right_parenthesis,
};
void init_scanner();
void lex_error(char* msg, int line);
void print_token(int token);
%}

/* Definitions */
INTEGER             ([0-9]+)
LETTER          ([_a-zA-Z][_a-zA-Z0-9]*)

%%

[\n]                { cur_line_num++; /* 忽略换行符 */        }
[ \t\r\a]+          { /* 忽略空格符 */               }
"begin"             {return t_begin;}
"if"                {return t_if;}        
"then"              {return t_then;}    
"while"             {return t_while;}
"do"                {return t_do;}
"end"               {return t_end;}
{LETTER}            {return t_letter_contain_digit;}
{INTEGER}           {return t_digit;}
"+"                 {return t_add;}
"-"                 {return t_subtraction;}   
"*"                 {return t_mutiply;}
"/"                 {return t_division;}
":"                 {return t_colon;}
":+"                {return t_colon_equal;}
"<"                 {return t_less;}
"<>"                {return t_quotation;}
"<="                {return t_less_equal;}
">"                 {return t_more;}
">="                {return t_more_equal;}
"="                 {return t_equal;}
";"                 {return t_semicolon;}
"("                 {return t_left_parenthesis;}
")"                 {return t_right_parenthesis;}
"#"                 {return 0;}

<<EOF>>             { return 0; }

.                   { return -1; /* 不能识别的字符 */}

%%

int main(int argc, char* argv[]) {
    int token;
    init_scanner();
    while ((token = yylex())) {
        // printf("%-20c", token);
        print_token(token);
        puts(yytext);
    }
    return 0;
}

void init_scanner() {
    printf("%-20s%s\n", "TOKEN-TYPE", "TOKEN-VALUE");
    printf("-------------------------------------------------\n");
}

void print_token(int token) {
    char* token_strs[] = {
        "T_Le", "T_Ge", "T_Eq", "T_Ne", "T_And", "T_Or", "T_IntConstant",
        "T_StringConstant", "T_Identifier", "T_Void", "T_Int", "T_While",
        "T_If", "T_Else", "T_Return", "T_Break", "T_Continue", "T_Print",
        "T_ReadInt"
    };

    if (token < 256) {
        printf("%-20c", token);
    } else {
        printf("%-20s", token_strs[token-256]);
    }
}

int yywrap(void) {
    return 1;
}