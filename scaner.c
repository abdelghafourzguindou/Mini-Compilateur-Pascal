#include "scaner.h"

void append(char* s, char c)
{
    int len  = strlen(s);
    s[len]   = c;
    s[len+1] = '\0';
}

void read_char(FILE* file)
{
    current_char = fgetc(file);
}

void read_word()
{
    while(isalpha(current_char))
    {
        append(current_token.name, current_char);
        read_char(file);
    }

    token_code_t unlex = IsKeyWord(current_token.name);

    if(unlex != ERROR_TOKEN)                  current_token.code = unlex;
    else if(IsIdentifier(current_token.name)) current_token.code = IDENTIFIER;
    else                                      current_token.code = ERROR_TOKEN;
}

void read_number()
{
    while(isdigit(current_char) || isalpha(current_char))
    {
        append(current_token.name, current_char);
        read_char(file);
    }

    if(IsNumber(current_token.name)) current_token.code = NUMBER;
    else                             current_token.code = ERROR_TOKEN;
}

void read_special_symbol()
{
    char c1 = current_char;
    append(current_token.name, c1);
    read_char(file);
    char c2 = current_char;

    if(( c1 == ':' && c2 == '=') ||
       ( c1 == '<' && c2 == '>') ||
       ((c1 == '<' || c1 == '>') && c2 == '='))
    {
        append(current_token.name, c2);
        getSpecialSymbol(current_token.name);
    }
    else
    {
        ungetc(current_char, file);
        getSpecialSymbol(current_token.name);
    }
}

void read_comment()
{
    append(current_token.name, current_char);
    read_char(file);
    append(current_token.name, current_char);
    if(current_char == '*')
    {
        read_char(file);
        append(current_token.name, current_char);
        while(current_char != '*')
        {
            read_char(file);
            append(current_token.name, current_char);
            if(current_char == '{') read_comment();
        }
        read_char(file);
        append(current_token.name, current_char);
        if(current_char == "}") setCurrent_token_NULL();
        else
        {
            current_token.code = ERROR_TOKEN;
        }
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

void getSpecialSymbol(char* str)
{
    token_code_t unlex = isSpeacialSymbol(str);

    if(unlex != ERROR_TOKEN)
    {
        current_token.code = unlex;
    }
    else
    {
        current_token.code  = ERROR_TOKEN;
    }
}

void setCurrent_token_NULL()
{
    current_token.name[0] = '\0';
    current_token.code    = EMPTY_TOKEN;
}

void scaning()
{

    read_char(file);

    if      (isEmpty  (current_char))    { setCurrent_token_NULL(); return;               }
    else if (isalpha  (current_char))    { setCurrent_token_NULL(); read_word();          }
    else if (isdigit  (current_char))    { setCurrent_token_NULL(); read_number();        }
    else if (isSpecial(current_char))    { setCurrent_token_NULL(); read_special_symbol();}
    else if (isComment(current_char))    { read_comment();};

    /*if(current_char == EOF)
    {
        setCurrent_token_NULL();
        current_token.name[0] = EOF;
        current_token.code    = FIN_TOKEN;
    }*/
}
