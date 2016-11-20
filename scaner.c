#include "scaner.h"

int ligne_number = 0;

void append(char* s, char c)
{
    int len  = strlen(s);
    s[len]   = c;
    s[len+1] = '\0';
}

void read_char(FILE* file)
{
    current_char = fgetc(file);
    //printf("current --> %c\n", current_char);
}

void read_word()
{
    while(isalnum(current_char))
    {
        append(current_token.name, current_char);
        read_char(file);
    }

    token_code_t unlex = IsKeyWord(current_token.name);

    if(unlex != ERROR_TOKEN)                  current_token.code = unlex;
    else if(IsIdentifier(current_token.name)) current_token.code = ID_TOKEN;
    else                                      current_token.code = ERROR_TOKEN;
}

void read_number()
{
    while(isalnum(current_char))
    {
        append(current_token.name, current_char);
        read_char(file);
    }

    if(IsNumber(current_token.name)) current_token.code = NUMBER_TOKEN;
    else                             current_token.code = ERROR_TOKEN;
}

void read_special_symbol()
{
    append(current_token.name, current_char);
    switch(current_char)
    {
        case '+': current_token.code = PLUS_TOKEN;  read_char(file);         break;
        case '-': current_token.code = MOINS_TOKEN; read_char(file);         break;
        case '*': current_token.code = MULT_TOKEN;  read_char(file);         break;
        case ',': current_token.code = VIR_TOKEN;   read_char(file);         break;
        case ';': current_token.code = PV_TOKEN;    read_char(file);         break;
        case '/': current_token.code = DIV_TOKEN;   read_char(file);         break;
        case '(': current_token.code = PO_TOKEN;    read_char(file);         break;
        case ')': current_token.code = PF_TOKEN;    read_char(file);         break;
        case '=': current_token.code = EG_TOKEN;    read_char(file);         break;
        case '.': current_token.code = PT_TOKEN;    read_char(file);         break;
        case '<': read_char(file);
            switch(current_char)
            {
                case '=': append(current_token.name, current_char); current_token.code = INFEG_TOKEN; read_char(file); break;
                case '>': append(current_token.name, current_char); current_token.code = DIFF_TOKEN;  read_char(file); break;
                default : current_token.code = INF_TOKEN;                    break;
            }
       break;
       case '>': read_char(file);
            switch(current_char){
                case '=': append(current_token.name, current_char); current_token.code = SUPEG_TOKEN; read_char(file); break;
                default : current_token.code = SUP_TOKEN;                    break;
            }
       break;
       case ':': read_char(file);
            switch(current_char)
            {
                case '=': append(current_token.name, current_char); current_token.code = AFF_TOKEN; read_char(file);   break;
                default : current_token.code = ERROR_TOKEN;                  break;
            }
       break;
       default : current_token.code = ERROR_TOKEN;                           break;
    }
}

void read_comment()
{
    int fin_comment = 0 ;
    char previous_char ;
    read_char(file);
    if(current_char == '*')
    {
        previous_char = current_char ;
        read_char(file);
        while( fin_comment == 0 && current_char != EOF )
        {
            previous_char = current_char ;
            read_char(file);
            if( previous_char == '*' && current_char == '}')
                fin_comment = 1 ;
                read_char(file);
        }
        if ( fin_comment == 0 )
            current_token.code = ERROR_COMMENT_INCOMPLET ;
    }
    else
    {
        current_token.code = ERROR_TOKEN;
    }
}

bool isComment(char s)
{
    if(s == '{') return true;
    return false;
}

bool isEmpty(char s)
{
    if(s == '\n') ligne_number++;
    if(s == ' ' || s == '\n' || s == '\t') return true;
    return false;
}

bool isSpecial(char s)
{
    if(s == ':' ||
            s == '=' ||
            s == '<' ||
            s == '>' ||
            s == '+' ||
            s == '-' ||
            s == '/' ||
            s == '*' ||
            s == ',' ||
            s == ';' ||
            s == '.' ||
            s == '(' ||
            s == ')') return true;
    return false;
}

void setCurrent_token_NULL()
{
    current_token.name[0] = '\0';
    current_token.code    = EMPTY_TOKEN;
}

void read_empty()
{
    do{
        read_char(file);
    } while(isEmpty(current_char));
}

void scaning()
{

    setCurrent_token_NULL();

    if      (isEmpty  (current_char))    { read_empty();         }
    else if (isalpha  (current_char))    { read_word();          }
    else if (isdigit  (current_char))    { read_number();        }
    else if (isSpecial(current_char))    { read_special_symbol();}
    else if (isComment(current_char))    { read_comment();       }
    else if (current_char == EOF )
    {
        current_token.code =  FIN_TOKEN;
    }
    else
    {
        current_token.name[0] = current_char ;
        current_token.code = ERROR_INDEFINED_TOKEN;
    }
}
