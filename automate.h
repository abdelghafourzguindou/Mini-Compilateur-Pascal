#ifndef AUTOMATE_H
#define AUTOMATE_H

#define MAX_CARACTER 256

int **Trans_Tab;

void filling_Number_Automata();
void filling_Identifier_Automata();
void filling_Operator_Automata();

int IsNumber(char*);
int IsIdentifier(char*);
int IsOperator(char*);

#endif // AUTOMATE_H
