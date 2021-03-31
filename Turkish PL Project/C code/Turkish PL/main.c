#include <stdio.h>
#include <stdlib.h>

int additionarray[100];
float fladditionarray[100];

char *charrayptr[200];
int charraycounter=0;
char charrayNames[200][100];
char charrayvalues[200][100];
int charraybounds[200];

int *intarrayptr[200];
int intarraycounter=0;
char intarrayNames[200][100];
int intarraynumbers[200][100];
int intarraybounds[200];

char boolvarNames[200][100];
int *boolptr[200];
int boolvalues[200];
int boolptrcounter=0;

float *flptr[200];
float floatnumbers[200];
char flvarNames[200][100];
int flptrcounter=0;

char characters[200][100];
int chptrcounter=0;
char chvarNames[200][100];
char *chptr[200];

int intptrcounter=0;
char intvarNames[200][100];
int *intptr[200];
int intnumbers[200];

int inthandler;
int condition;
char intKeyword[7] = {'t','a','m','s','a','y','i'};
char ifKeyword[4] = {'e','g','e','r'};
char whileKeyword[4] = {'i','k','e','n'};
char chKeyword[8] = {'k','a','r','a','k','t','e','r'};
char floatKeyword[7]={'o','n','d','a','l','i','k'};
char additionKeyword[5]={'t','o','p','l','a'};
char multiplicationKeyword[4]={'c','a','r','p'};
char substractionKeyword[5]={'c','i','k','a','r'};
char divisionKeyword[3]={'b','o','l'};
char fladditionKeyword[8]={'t','o','p','l','a','o','n','d'};
char assignKeyword[3]={'a','t','a'};
char flmultiplicationKeyword[7]={'c','a','r','p','o','n','d'};
char flsubstractionKeyword[8]={'c','i','k','a','r','o','n','d'};
char fldivisionKeyword[6]={'b','o','l','o','n','d'};
char booleanKeyword[8]={'d','o','g','r','u','l','u','k'};
char booltrueKeyword[5]={'d','o','g','r','u'};
char boolfalseKeyword[6]={'y','a','n','l','i','s'};
char beginKeyword[5]={'b','a','s','l','a'};
char endKeyword[5]={'b','i','t','i','r'};
int beginkey;
int endkey;
int boolfalsekey;
int booltruekey;
int booleankey;
int fldivisionkey;
int flsubstractionkey;
int flmultiplicationkey;
int assignkey;
int fladditionkey;
int divisionkey;
int substractionkey;
int multiplicationkey;
int additionkey;
int floatkey;
int chkey;
int intkey;
int ifkey;
int whilekey;
int charClass;
char lexeme [100];
char nextChar;
int lexLen;
int token;
int nextToken;
char* filename = "c:\\Users\\berkt\\Desktop\\Text.txt";
FILE *in_fp, *fopen();
void addChar();
void getChar();
void getNonBlank();
int lex();
/*variable clases*/
#define LOOP_ICON 444
#define GREATER_SYM 52
#define SMALLER_SYM 53
#define EQUAL_SYM 50
#define NOT_SYM 51
#define BEGIN_KEYWORD 48
#define END_KEYWORD 49
#define END_SEMB 47
#define SQRL_PAREN 43
#define SQRR_PAREN 44
#define POINT 40
#define BOOLTRUE_KEYWORD 41
#define BOOLFALSE_KEYWORD 42
#define FLDIV_KEYWORD 39
#define FLSUB_KEYWORD 38
#define FLMULT_KEYWORD 37
#define ASSIGN_KEYWORD 36
#define FLADD_KEYWORD 35
#define DIV_KEYWORD 34
#define SUB_KEYWORD 32
#define MULT_KEYWORD 33
#define ADD_KEYWORD 31
#define INT_KEYWORD 2
#define CH_KEYWORD 3
#define FLOAT_KEYWORD 4
#define BOOL_KEYWORD 5

#define true 87
#define false 88
/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/* Token codes */
#define COMMA 30
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define IF_KEYWORD 27
#define WHILE_KEYWORD 29
float fladditionop();
int divisionop();
int multiplicationop();
int additionop();
int substractionop();
void error();
int lex();
void ifStatement();
void addChar();
void getChar();
void getNonBlank();
void assignop();
float flmultiplicationop();
float flsubstractionop();
float fldivisionop();
int findthenumber();
void statement();
void expression();
float flfindthenumber();
int loopcounter=true;
void whilestatement();
int cond=false;
void parse();


int main()
{
    if ((in_fp = fopen(filename, "r")) == NULL)
    printf("ERROR - cannot open text file \n");
    else {
    getChar();
    do {

    parse();


    }
    while (nextToken != EOF);

    }

}


int lookup(char ch) {
switch (ch) {
case'&':
addChar();
nextToken=LOOP_ICON;
break;
case '>':
addChar();
nextToken=GREATER_SYM;
break;
case '<':
addChar();
nextToken=SMALLER_SYM;
break;
case '=':
addChar();
nextToken=EQUAL_SYM;
break;
case '!':
addChar();
nextToken= NOT_SYM;
break;
case';':
addChar();
nextToken= END_SEMB;
break;
case '[':
addChar();
nextToken= SQRL_PAREN;
break;
case ']':
addChar();
nextToken= SQRR_PAREN;
break;
case '(':
addChar();
nextToken = LEFT_PAREN;
break;
case ')':
addChar();
nextToken = RIGHT_PAREN;
break;
case '+':
addChar();
nextToken = ADD_OP;
break;
case '-':
addChar();
nextToken = SUB_OP;
break;
case'.':
addChar();
nextToken=POINT;
break;
case',':
addChar();
nextToken= COMMA;
break;
default:
addChar();
nextToken = EOF;
break;
}
return nextToken;
}

void addChar() {
if (lexLen <= 98) {
lexeme[lexLen++] = nextChar;
lexeme[lexLen] = 0;
}
else
printf("Error - lexeme is too long \n");
}

void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
            else if (isdigit(nextChar))
                charClass = DIGIT;
            else charClass = UNKNOWN;
            }
    else
    charClass = EOF;
}

void getNonBlank() {
while (isspace(nextChar))
getChar();
}

int lex() {
lexLen = 0;
getNonBlank();
switch (charClass) {
/* Parse identifiers */
case LETTER:
    condition = false;
    ifkey=0;
    whilekey=0;
    intkey =0;
    chkey=0;
    floatkey=0;
    additionkey=0;
    multiplicationkey=0;
    substractionkey=0;
    divisionkey=0;
    fladditionkey=0;
    assignkey=0;
    flmultiplicationkey=0;
    flsubstractionkey=0;
    fldivisionkey=0;
    booleankey=0;
    booltruekey=0;
    boolfalsekey=0;
    beginkey=0;
    endkey=0;
while (charClass == LETTER || charClass == DIGIT) {
        if(charClass== LETTER ){
                if(endkey<6){
                if(nextChar==endKeyword[endkey]){
                    endkey++;
                    condition = END_KEYWORD;
                    if(endkey<4){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    endkey = 6;
                }
                }
                else{

                        endkey++;

                }
        }
        if(charClass== LETTER ){
                if(beginkey<6){
                if(nextChar==beginKeyword[beginkey]){
                    beginkey++;
                    condition = BEGIN_KEYWORD;
                    if(beginkey<4){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    beginkey = 6;
                }
                }
                else{

                        beginkey++;

                }
        }
        if(charClass== LETTER){
                if(boolfalsekey<7){
                if(nextChar==boolfalseKeyword[boolfalsekey]){
                    boolfalsekey++;
                    condition = BOOLFALSE_KEYWORD;
                    if(boolfalsekey<5){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    boolfalsekey = 7;
                }
                }
                else{

                        boolfalsekey++;

                }
        }

        if(charClass== LETTER){
                if(booleankey<9){
                if(nextChar==booleanKeyword[booleankey]){
                    booleankey++;
                    condition = BOOL_KEYWORD;
                    if(booleankey<7){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    booleankey = 9;
                }
                }
                else{

                        booleankey++;

                }
        }
        if(charClass== LETTER){
                if(booltruekey<6){
                if(nextChar==booltrueKeyword[booltruekey]){
                    booltruekey++;
                    condition = BOOLTRUE_KEYWORD;
                    if(booltruekey<4){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    booltruekey = 6;
                }
                }
                else{

                        booltruekey++;

                }
        }
        if(charClass== LETTER){
                if(fldivisionkey<7){
                if(nextChar==fldivisionKeyword[fldivisionkey]){
                    fldivisionkey++;
                    condition = FLDIV_KEYWORD;
                    if(fldivisionkey<5){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    fldivisionkey = 7;
                }
                }
                else{

                        fldivisionkey++;

                }
        }
        if(charClass== LETTER){
                if(flsubstractionkey<9){
                if(nextChar==flsubstractionKeyword[flsubstractionkey]){
                    flsubstractionkey++;
                    condition = FLSUB_KEYWORD;
                    if(flsubstractionkey<7){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    flsubstractionkey = 9;
                }
                }
                else{

                        flsubstractionkey++;

                }
        }
        if(charClass== LETTER){
                if(flmultiplicationkey<8){
                if(nextChar==flmultiplicationKeyword[flmultiplicationkey]){
                    flmultiplicationkey++;
                    condition = FLMULT_KEYWORD;
                    if(flmultiplicationkey<6){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    flmultiplicationkey = 8;
                }
                }
                else{

                        flmultiplicationkey++;

                }
        }
        if(charClass== LETTER){
                if(assignkey<4){
                if(nextChar==assignKeyword[assignkey]){
                    assignkey++;
                    condition = ASSIGN_KEYWORD;
                    if(assignkey<2){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    assignkey = 4;
                }
                }
                else{

                        assignkey++;

                }
        }
        if(charClass== LETTER){
                if(fladditionkey<9){
                if(nextChar==fladditionKeyword[fladditionkey]){
                    fladditionkey++;
                    condition = FLADD_KEYWORD;
                    if(fladditionkey<7){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    fladditionkey = 9;
                }
                }
                else{

                        fladditionkey++;

                }
        }
        if(charClass== LETTER){
                if(divisionkey<4){
                if(nextChar==divisionKeyword[divisionkey]){
                    divisionkey++;
                    condition = DIV_KEYWORD;
                    if(divisionkey<2){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    divisionkey = 4;
                }
                }
                else{

                        divisionkey++;

                }
        }
        if(charClass== LETTER){
                if(substractionkey<6){
                if(nextChar==substractionKeyword[substractionkey]){
                    substractionkey++;
                    condition = SUB_KEYWORD;
                    if(substractionkey<4){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    substractionkey = 6;
                }
                }
                else{
                        substractionkey++;

                }
        }
        if(charClass== LETTER){
                if(multiplicationkey<5){
                if(nextChar==multiplicationKeyword[multiplicationkey]){
                    multiplicationkey++;
                    condition = MULT_KEYWORD;
                    if(multiplicationkey<3){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    multiplicationkey = 5;
                }
                }
                else{
                        multiplicationkey++;

                }
        }
          if(charClass== LETTER){
                if(additionkey<6){
                if(nextChar==additionKeyword[additionkey]){
                    additionkey++;
                    condition = ADD_KEYWORD;
                    if(additionkey<4){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    additionkey = 6;
                }
                }
                else{
                        additionkey++;

                }
        }
        if(charClass== LETTER){
                if(floatkey<8){
                if(nextChar==floatKeyword[floatkey]){
                    floatkey++;
                    condition = FLOAT_KEYWORD;
                    if(floatkey<6){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    floatkey = 8;
                }
                }
                else{
                        floatkey++;

                }
        }
        if(charClass== LETTER){
                if(chkey<9){
                if(nextChar==chKeyword[chkey]){
                    chkey++;
                    condition = CH_KEYWORD;
                    if(chkey<7){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    chkey = 9;
                }
                }
                else{
                        chkey++;

                }
        }
        if(charClass== LETTER){
                if(intkey<8){
                if(nextChar==intKeyword[intkey]){
                    intkey++;
                    condition = INT_KEYWORD;
                    if(intkey<6){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    intkey = 8;
                }
                }
                else{
                        intkey++;

                }
        }
        if(charClass== LETTER){
                if(ifkey<5){
                if(nextChar==ifKeyword[ifkey]){
                    ifkey++;
                    condition = IF_KEYWORD;
                    if(ifkey<3){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    ifkey = 5;
                }
                }
                else{
                        ifkey++;

                }
        }
        if(charClass== LETTER){
                if(whilekey<5){
                if(nextChar==whileKeyword[whilekey]){
                    whilekey++;
                    condition = WHILE_KEYWORD;
                    if(whilekey<3){
                        condition = false;
                    }
                }
                else{
                    condition = false;
                    whilekey = 5;
                }
                }
                else{
                        whilekey++;

                }
        }

addChar();
getChar();
}
if(condition == false)
nextToken = IDENT;
else
nextToken= condition;
break;
/* Parse integer literals */
case DIGIT:
addChar();
getChar();
while (charClass == DIGIT) {
addChar();
getChar();
}
nextToken = INT_LIT;
break;
/* Parentheses and operators */
case UNKNOWN:
lookup(nextChar);
getChar();
break;
/* EOF */
case EOF:
nextToken = EOF;
lexeme[0] = 'E';
lexeme[1] = 'O';
lexeme[2] = 'F';
lexeme[3] = 0;
break;
} /* End of switch */
if(loopcounter==true){
printf("Next token is: %d, Next lexeme is %s\n",
nextToken, lexeme);
}
return nextToken;
}

void error(){

    printf("\n!!!!!!!AN ERROR OCCURED!!!!!!\n");

}

void whilestatement(){
    if(nextToken==WHILE_KEYWORD){
            printf("\n-inside while statement-\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();
        }
        else{
            lex();
            cond=booleanCon();
            loopcounter=true;
            lex();
            if(nextToken!=RIGHT_PAREN)
                error();
            else{
            lex();
            if(nextToken!=BEGIN_KEYWORD)
                error();
            else{
            lex();
            int whilecond=true;
            while(cond==true){
                        if(whilecond==true){
                            statement();
                            fclose(in_fp);
                            in_fp = fopen(filename, "r");
                            getChar();
                        }
                        loopcounter=false;
                        lex();
                        if(nextToken!=whileKeyword){
                                whilecond =false;
                                whilestatement();
                        }

                    }
                    if(whilecond==false){
                        while(nextToken!=END_KEYWORD){
                            lex();
                        }

                    }

                     loopcounter=true;

                        }
                    }
                }
            }


        }

void ifStatement(){
if(nextToken==IF_KEYWORD){
        printf("\n -inside if statement- \n");
        lex();
    if(nextToken!= LEFT_PAREN)
        error();
    else{
        lex();
        if(booleanCon()==true){
        lex();
        if(nextToken != RIGHT_PAREN){
            error();
        }
        else{
            lex();
            if(nextToken!=BEGIN_KEYWORD){
                error();
            }
            else{

            lex();
            statement();
            if(nextToken!=END_KEYWORD)
                error();
            }

        }


    }
        else{
            while(nextToken!=END_KEYWORD){
                lex();
            }
        }

    }
}

}

void statement(){

    while(nextToken!=END_KEYWORD){
        typeCheck();
        assignop();
        additionop();
        multiplicationop();
        substractionop();
        divisionop();
        fladditionop();
        flsubstractionop();
        flmultiplicationop();
        fldivisionop();
        lex();
    }

}

void typeCheck(){
    int thekvalue;
    int islexed=false;
    int isincounter=0;

    if(nextToken==INT_KEYWORD){
            isincounter++;
        lex();
        if(nextToken != IDENT){
            error();
        }
        else{
            intnumbers[intptrcounter]=1;
            intptr[intptrcounter]= &intnumbers[intptrcounter];
            int i=0;
            while(lexeme[i]!=NULL){
            intvarNames[intptrcounter][i]=lexeme[i];
            intvarNames[intptrcounter][i+1]=NULL;

            intarrayNames[intarraycounter][i]=lexeme[i];
            intarrayNames[intarraycounter][i+1]=NULL;


            i++;

            }
            intptrcounter++;
            lex();
            if(nextToken==SQRL_PAREN){
                islexed=true;
                intptrcounter--;
                *intptr[intptrcounter]=NULL;
                intvarNames[intptrcounter][0]=NULL;
                lex();
                    if(nextToken==INT_LIT){
                        int numb1=0;
                        numb1=findthenumber();
                        if(numb1>100)
                            error();
                        else{
                            for(int z=0;z<numb1;z++){
                                intarraynumbers[intarraycounter][z]=1;
                                intarraynumbers[intarraycounter][z+1]=NULL;
                            }
                            intarrayptr[intarraycounter]=&intarraynumbers[intarraycounter][0];
                            intarraybounds[intarraycounter]=numb1;
                            intarraycounter++;
                            lex();
                            if(nextToken!=SQRR_PAREN)
                                error();
                        }
                    }
                    else if(nextToken==IDENT){

                                       int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int numb1=0;
                        numb1= *intptr[thekvalue];
                        if(numb1>100)
                            error();
                        else{
                            for(int z=0;z<numb1;z++){
                                intarraynumbers[intarraycounter][z]=1;
                                intarraynumbers[intarraycounter][z+1]=NULL;
                            }
                            intarrayptr[intarraycounter]=&intarraynumbers[intarraycounter][0];
                            intarraybounds[intarraycounter]=numb1;
                            intarraycounter++;
                            lex();
                            if(nextToken!=SQRR_PAREN)
                                error();
                        }



                    }
                    else
                        error();

            }
            else
            intarrayNames[intarraycounter][0]=NULL;
        }

    }
    if(nextToken==CH_KEYWORD){
            isincounter++;
        lex();
        if(nextToken != IDENT){
            error();
        }
        else{
            characters[chptrcounter][0]='q';
            chptr[chptrcounter]= &characters[chptrcounter][0];
            int i=0;
            while(lexeme[i]!=NULL){
            chvarNames[chptrcounter][i]=lexeme[i];
            chvarNames[chptrcounter][i+1]=NULL;

            charrayNames[charraycounter][i]=lexeme[i];
            charrayNames[charraycounter][i+1]=NULL;

            i++;

            }
            chptrcounter++;
            lex();
            if(nextToken==SQRL_PAREN){
                islexed=true;
                chptrcounter--;
                *chptr[chptrcounter]=NULL;
                chvarNames[chptrcounter][0]=NULL;
                lex();
                    if(nextToken==INT_LIT){
                        int numb1=0;
                        numb1=findthenumber();
                        if(numb1>100)
                            error();
                        else{
                            for(int z=0;z<numb1;z++){
                                charrayvalues[charraycounter][z]='q';
                                charrayvalues[charraycounter][z+1]=NULL;
                            }
                            charrayptr[charraycounter]=&charrayvalues[charraycounter][0];
                            charraybounds[charraycounter]=numb1;
                            charraycounter++;
                            lex();
                            if(nextToken!=SQRR_PAREN)
                                error();
                        }
                    }
                    else if(nextToken==IDENT){

                                       int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int numb1=0;
                        numb1= *intptr[thekvalue];
                        if(numb1>100)
                            error();
                        else{
                            for(int z=0;z<numb1;z++){
                                intarraynumbers[intarraycounter][z]='q';
                                intarraynumbers[intarraycounter][z+1]=NULL;
                            }
                            charrayptr[charraycounter]=&charrayvalues[charraycounter][0];
                            charraybounds[charraycounter]=numb1;
                            intarraycounter++;
                            lex();
                            if(nextToken!=SQRR_PAREN)
                                error();
                        }



                    }
                    else
                        error();

            }
            else
            charrayNames[charraycounter][0]=NULL;

        }

    }
    if(nextToken==FLOAT_KEYWORD){
            isincounter++;
            islexed=true;

        lex();
        if(nextToken != IDENT){
            error();
        }
        else{
            floatnumbers[flptrcounter]=1;
            flptr[flptrcounter]= &floatnumbers[flptrcounter];
            int i=0;
            while(lexeme[i]!=NULL){
            flvarNames[flptrcounter][i]=lexeme[i];
            flvarNames[flptrcounter][i+1]=NULL;
            i++;

            }
            flptrcounter++;
        }

    }
if(nextToken== BOOL_KEYWORD){
        isincounter++;
        islexed=true;
    lex();
    if(nextToken!= IDENT)
        error();
    else{
            boolvalues[boolptrcounter]=false;
            boolptr[boolptrcounter]=&boolvalues[boolptrcounter];
            int i =0;
            while(lexeme[i]!=NULL){
                boolvarNames[boolptrcounter][i]=lexeme[i];
                boolvarNames[boolptrcounter][i+1]=NULL;
                i++;

            }
            boolptrcounter++;
    }
}
            if(islexed!=false){
                lex();
            }
        if(isincounter!=0){
            if(nextToken!=END_SEMB){
                error();
            }
        }
}
int booleanCon(){

    int term1;
    int thekvalue;
    int thek2value;
    if(nextToken==INT_LIT){
                    term1=findthenumber();
                            lex();
                            if(nextToken==POINT){
                                    lex();
                                float term2=flfindthenumber();
                                float term3=term1;
                                term3=term3+term2;
                                lex();
                            if(nextToken==NOT_SYM){
                                lex();
                                if(nextToken!=EQUAL_SYM){
                                    error();
                                }
                                else{
                                    lex();
                                    if(nextToken==INT_LIT){

                                            float secondint;
                                        secondint=findthenumber();
                                        float thirdint;
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        thirdint=flfindthenumber();
                                        if(term3 != secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term3 != *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                                }
                            }
                            else if(nextToken==EQUAL_SYM){
                                    lex();
                                    if(nextToken==INT_LIT){
                                        float secondint;
                                        secondint=findthenumber();
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        float thirdint;
                                        thirdint= flfindthenumber();
                                        if(term3 == secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term3 == *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                            }
                            else if(nextToken==GREATER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){

                                            float secondint;
                                        secondint=findthenumber();
                                        float thirdint;
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        thirdint=flfindthenumber();
                                        if(term3 > secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term3 > *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                            }
                            else if(nextToken==SMALLER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){

                                            float secondint;
                                        secondint=findthenumber();
                                        float thirdint;
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        thirdint=flfindthenumber();
                                        if(term3 < secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term3 < *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                            }

                            }
                            else if(nextToken==NOT_SYM){
                                lex();
                                if(nextToken!=EQUAL_SYM){
                                    error();
                                }
                                else{
                                    lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(term1!=secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term1 != *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(term1 != *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(term1 != *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();
                                }
                            }
                            else if(nextToken==EQUAL_SYM){
                                    lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(term1 ==secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term1 == *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(term1 == *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(term1 == *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();

                            }
                            else if(nextToken==GREATER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(term1 >secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term1 > *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(term1 > *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(term1 > *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();
                            }
                            else if(nextToken==SMALLER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(term1 <secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(term1 < *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(term1 < *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(term1 < *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();
                            }


    }
    else if(nextToken==IDENT){
                    int cond=0;
                    int cond1=6;
                    int cond2=6;
                    int cond3=6;
                    int cond4=6;
                    int cond5=6;
                    int cond6=6;
                    int key;
                    int j=0;
                    for(int k=0;k<200;k++){
                            cond1=6;
                            cond2=6;
                            cond3=6;
                            cond4=6;
                            cond5=6;
                            cond6=6;
                            j=0;
                        while(1==1){
                            if(lexeme[j]!=NULL){
                            if(intvarNames[k][j]!=NULL){
                                    if(cond1!=0){
                                if(intvarNames[k][j]==lexeme[j]){
                                    cond1=1;
                                }
                                else
                                    cond1=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && intvarNames[k][j]==NULL){

                                }
                                else
                                    cond1=0;
                            }

                            if(flvarNames[k][j]!=NULL){
                                    if(cond2!=0){
                                if(flvarNames[k][j]==lexeme[j]){
                                    cond2=1;
                                }
                                else
                                    cond2=0;
                                    }

                            }
                            else{
                                if(lexeme[j]==NULL && flvarNames[k][j]==NULL){

                                }
                                else
                                    cond2=0;
                            }
                            if(chvarNames[k][j]!=NULL){
                                    if(cond3!=0){
                                if(chvarNames[k][j]==lexeme[j]){
                                    cond3=1;
                                }
                                else
                                    cond3=0;
                                    }
                            }
                            else{
                                if(lexeme[j]==NULL && chvarNames[k][j]==NULL){

                                }
                                else
                                    cond3=0;
                            }
                            if(boolvarNames[k][j]!=NULL){
                                    if(cond4!=0){
                                if(boolvarNames[k][j]==lexeme[j]){
                                    cond4=1;
                                }
                                else
                                    cond4=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && boolvarNames[k][j]==NULL){

                                }
                                else
                                    cond4=0;
                            }
                                if(intarrayNames[k][j]!=NULL){
                                    if(cond5!=0){
                                        if(intarrayNames[k][j]==lexeme[j]){
                                            cond5=1;
                                }
                                else
                                    cond5=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && intarrayNames[k][j]==NULL){

                                }
                                else
                                    cond5=0;
                            }

                            if(charrayNames[k][j]!=NULL){
                                    if(cond6!=0){
                                        if(charrayNames[k][j]==lexeme[j]){
                                            cond6=1;
                                }
                                else
                                    cond6=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && charrayNames[k][j]==NULL){

                                }
                                else
                                    cond6=0;
                            }


                            j++;
                        }
                        else{
                            break;
                        }
                        }
                        if(cond1==1 || cond2==1 || cond3==1 || cond4==1 || cond5==1 || cond6==1 ){
                            key=k;
                            break;
                        }
                    }
                        if(cond1==1){
                            if(intvarNames[key][j]!=NULL){
                                cond=0;
                            }
                            else{
                            cond=1;
                            }
                        }
                        if(cond2==1){
                        if(flvarNames[key][j]!=NULL){
                            cond=0;
                            }
                            else
                            cond=2;
                        }
                        if(cond3==1){
                            if(chvarNames[key][j]!=NULL){
                            cond=0;
                            }
                            else
                            cond=3;
                        }
                        if(cond4==1){
                            if(boolvarNames[key][j]!=NULL){
                            cond=0;
                            }
                            else
                            cond=4;
                        }
                        if(cond5==1){
                            if(intarrayNames[key][j]!=NULL){
                                cond=0;
                            }
                            else{
                                cond=5;
                            }
                        }
                        if(cond6==1){
                            if(charrayNames[key][j]!=NULL){
                                cond=0;
                            }
                            else{
                                cond=6;
                            }
                        }
                        if(cond==1){
                            lex();
                            if(nextToken==NOT_SYM){
                                lex();
                                if(nextToken!=EQUAL_SYM){
                                    error();
                                }
                                else{
                                    lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(*intptr[key]!=secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*intptr[key]!= *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(*intptr[key] != *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(*intptr[key]!= *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();
                                }
                            }
                            else if(nextToken==EQUAL_SYM){
                                    lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(*intptr[key]==secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*intptr[key]== *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(*intptr[key] == *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(*intptr[key] == *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();

                            }
                            else if(nextToken==GREATER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(*intptr[key]>secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*intptr[key]> *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(*intptr[key] > *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(*intptr[key] > *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();
                            }
                            else if(nextToken==SMALLER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){
                                            int secondint;
                                        secondint=findthenumber();
                                        if(*intptr[key]<secondint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*intptr[key]< *intptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                else
                                                    if(found==0){
                                                    found =0;
                                                    l=0;
                                                for(int k=0;k<200;k++){
                                                        l=0;
                                                    found=0;
                                                while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(*intptr[key] < *intarrayptr[number]){
                                                                return true;
                                                            }
                                                            else
                                                                return false;

                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                            l=0;
                                                            found=0;
                                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                        if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                        int number;
                                                        number=*intptr[thek2value];
                                                    if(*intptr[key] < *intarrayptr[number]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }
                                                        }
                                                    }

                                                }

                                                    }

                                            }
                                    else
                                        error();
                            }
                        }
                       else if (cond==3){

                            lex();
                            if(nextToken==NOT_SYM){
                                lex();
                                if(nextToken!=EQUAL_SYM){
                                    error();
                                }
                                else{
                                    lex();
                                    if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || chvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=chvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==chvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                        if(found==1){
                                            int found =0;
                                        int k=0;

                                            while(*(chptr[key]+k) !=NULL || *(chptr[thekvalue]+k) !=NULL){
                                                    if(*(chptr[key]+k) != *(chptr[thekvalue]+k)){
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(*(chptr[key]+k)== *(chptr[thekvalue]+k)){
                                                                found=1;
                                                                k++;

                                                    }

                                                    }
                                                    }


                                            if(found!=1){
                                            return true;
                                                }
                                            else{
                                                return false;
                                                }
                                        }
                                        else{
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || charrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=charrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==charrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){

                                                    lex();
                                                    if(nextToken!=SQRL_PAREN){
                                                        error();
                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(*chptr[key] != *(charrayptr[thekvalue]+number)){
                                                                    lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                                    error();
                                                        }
                                                                return true;
                                                            }
                                                            else{
                                                            lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                                return false;
                                                            }
                                                        }
                                                        else if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                            for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                                        thek2value=NULL;
                                                                        found=0;
                                                                            break;
                                                                                }
                                                                    else{
                                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                        found=1;
                                                                        thek2value=k;
                                                                        l++;

                                                                    }

                                                                }
                                                            }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *chptr[key] != *(charrayptr[thekvalue]+ *intptr[thek2value])){
                                                              lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                                    error();
                                                                }
                                                        return true;
                                                    }
                                                    else{
                                                                lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                                    error();
                                                        }
                                                        return false;
                                                    }
                                                }


                                                        }
                                                        else
                                                            error();
                                                    }
                                                }
                                                else{
                                                    if( *chptr[key] != lexeme[0]){
                                                        return true;
                                                    }
                                                    else{
                                                        return false;
                                                    }
                                                }


                                        }
                                }

                                }
                            }
                            else if(nextToken==EQUAL_SYM){
                                    lex();
                                    if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || chvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=chvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==chvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                        if(found==1){
                                            int found =0;
                                                int k=0;
                                            while( *(chptr[key]+k) != NULL || *(chptr[thekvalue]+k) != NULL ){
                                                    if(*(chptr[key]+k) != *(chptr[thekvalue]+k)){
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if( *(chptr[key]+k) == *(chptr[thekvalue]+k) ){
                                                                found=1;
                                                                k++;

                                                    }

                                                    }
                                                    }

                                            if(found==1){
                                            return true;
                                                }
                                            else{
                                                return false;
                                                }
                                        }
                                        else{
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || charrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=charrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==charrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){

                                                    lex();
                                                    if(nextToken!=SQRL_PAREN){
                                                        error();
                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number;
                                                            number=findthenumber();
                                                            if(*chptr[key] == *(charrayptr[thekvalue]+number)){
                                                                    lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                                    error();
                                                        }
                                                                return true;
                                                            }
                                                            else{
                                                            lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                                return false;
                                                            }
                                                        }
                                                        else if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                            for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                                        thek2value=NULL;
                                                                        found=0;
                                                                            break;
                                                                                }
                                                                    else{
                                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                        found=1;
                                                                        thek2value=k;
                                                                        l++;

                                                                    }

                                                                }
                                                            }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *chptr[key] == *(charrayptr[thekvalue]+ *intptr[thek2value])){
                                                              lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                                    error();
                                                                }
                                                        return true;
                                                    }
                                                    else{
                                                                lex();
                                                            if(nextToken!=SQRR_PAREN){
                                                                    error();
                                                        }
                                                        return false;
                                                    }
                                                }


                                                        }
                                                        else
                                                            error();
                                                    }
                                                }
                                                else{
                                                    if( *chptr[key] == lexeme[0]){
                                                        return true;
                                                    }
                                                    else{
                                                        return false;
                                                    }
                                                }


                                        }
                                }

                            }
                        }
                        else if(cond==2){
                                lex();
                            if(nextToken==NOT_SYM){
                                lex();
                                if(nextToken!=EQUAL_SYM){
                                    error();
                                }
                                else{
                                    lex();
                                    if(nextToken==INT_LIT){

                                            float secondint;
                                        secondint=findthenumber();
                                        float thirdint;
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        thirdint=flfindthenumber();
                                        if(*flptr[key] != secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*flptr[key]!= *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                                }
                            }
                            else if(nextToken==EQUAL_SYM){
                                    lex();
                                    if(nextToken==INT_LIT){
                                        float secondint;
                                        secondint=findthenumber();
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        float thirdint;
                                        thirdint= flfindthenumber();
                                        if(*flptr[key] == secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*flptr[key] == *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                            }
                            else if(nextToken==GREATER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){

                                            float secondint;
                                        secondint=findthenumber();
                                        float thirdint;
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        thirdint=flfindthenumber();
                                        if(*flptr[key] > secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*flptr[key] > *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                            }
                            else if(nextToken==SMALLER_SYM){
                                lex();
                                    if(nextToken==INT_LIT){

                                            float secondint;
                                        secondint=findthenumber();
                                        float thirdint;
                                        lex();
                                        if(nextToken!=POINT){
                                            error();
                                        }
                                        else{
                                        lex();
                                        thirdint=flfindthenumber();
                                        if(*flptr[key] < secondint+thirdint){
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    }
                                    else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || flvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=flvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==flvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*flptr[key] < *flptr[thekvalue]){
                                                        return true;
                                                    }
                                                    else
                                                        return false;
                                                }

                                            }
                                    else
                                        error();
                            }
                        }
                        else if(cond==4){
                            if(*boolptr[key]==true){
                                return true;
                            }
                            else
                                return false;
                        }
                        else if(cond==5){
                            lex();
                            if(nextToken!=SQRL_PAREN)
                                error();
                            else{
                                lex();
                                if(nextToken==INT_LIT){
                                    int number1=findthenumber();
                                    lex();
                                    if(nextToken!=SQRR_PAREN)
                                        error();
                                    else{
                                        lex();
                                        if(nextToken==NOT_SYM){
                                            lex();
                                            if(nextToken!=EQUAL_SYM)
                                                error();
                                            else{
                                                lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) != number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) != *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) != *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) != *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                            }
                                        }
                                        else if(nextToken==EQUAL_SYM){
                                            lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) == number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) == *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) == *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) == *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                        }
                                        else if(nextToken==GREATER_SYM){
                                            lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) > number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) > *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) > *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) > *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                        }
                                        else if(nextToken==SMALLER_SYM){
                                            lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) < number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) < *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) < *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) < *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                        }
                                        else
                                            error();
                                    }
                                }
                                else if(nextToken==IDENT){
                                    int number1;
                                    int found =0;
                                      int l=0;
                                for(int k=0;k<200;k++){
                                l=0;
                                found=0;
                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                 if(lexeme[l]!=intvarNames[k][l]){
                                        thekvalue=NULL;
                                    found=0;
                                    break;
                                                    }
                                else{
                            if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                    thekvalue=k;
                                            l++;

                                            }

                                        }
                                        }
                                        if(found==1){
                                    break;
                                            }
                                        }
                                        if(found==1){
                                        number1 = *intptr[thekvalue];
                                    lex();
                                    if(nextToken!=SQRR_PAREN)
                                        error();
                                    else{
                                        lex();
                                        if(nextToken==NOT_SYM){
                                            lex();
                                            if(nextToken!=EQUAL_SYM)
                                                error();
                                            else{
                                                lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) != number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) != *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) != *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) != *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                            }
                                        }
                                        else if(nextToken==EQUAL_SYM){
                                            lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) == number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) == *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) == *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) == *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                        }
                                        else if(nextToken==GREATER_SYM){
                                            lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) > number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) > *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) > *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) > *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                        }
                                        else if(nextToken==SMALLER_SYM){
                                            lex();
                                                if(nextToken==INT_LIT){
                                                    int number2=findthenumber();
                                                    if(*(intarrayptr[key]+number1) < number2)
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else if(nextToken==IDENT){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if(*(intarrayptr[key]+number1) < *intptr[thekvalue])
                                                        return true;
                                                    else
                                                        return false;

                                                }
                                                else{
                                                    found =0;
                                                     l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intarrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else{
                                                        lex();
                                                        if(nextToken==INT_LIT){
                                                            int number3=findthenumber();
                                                            if( *(intarrayptr[key]+number1) < *(intarrayptr[thekvalue]+number3)){
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return true;
                                                            }
                                                            else{
                                                                lex();
                                                                if(nextToken!=SQRR_PAREN)
                                                                    error();
                                                                else
                                                                    return false;
                                                            }
                                                        }
                                                        if(nextToken==IDENT){
                                                            int found =0;
                                                            int l=0;
                                                        for(int k=0;k<200;k++){
                                                                l=0;
                                                                found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(intarrayptr[key]+number1) < *(intarrayptr[thekvalue] + *intptr[thek2value])){
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN)
                                                            error();
                                                        else
                                                            return true;

                                                    }
                                                    else{
                                                        lex();
                                                        if(nextToken!=SQRR_PAREN){
                                                            error();
                                                        }
                                                        else
                                                            return false;
                                                    }
                                                }
                                                        }
                                                    }
                                                }
                                                }
                                                }
                                        }
                                        else
                                            error();
                                    }
                                }
                                else
                                    error();
                                }
                            }
                        }
                        else if(cond==6){
                            lex();
                            if(nextToken!=SQRL_PAREN)
                                error();
                            else{
                                lex();
                                int number1;
                                if(nextToken==INT_LIT){
                                    number1=findthenumber();
                                }
                                else if(nextToken==IDENT){
                                        int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    number1= *intptr[thekvalue];
                                                }
                                                else
                                                    error();

                                }
                                lex();
                                if(nextToken!=SQRR_PAREN){
                                    error();
                                }
                                else{
                                    lex();
                                    if(nextToken==NOT_SYM){
                                        lex();
                                        if(nextToken!=EQUAL_SYM)
                                            error();
                                        else{
                                            lex();
                                            if(nextToken==IDENT){
                                                int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || chvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=chvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==chvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(charrayptr[key]+number1) != *chptr[thekvalue])
                                                        return true;

                                                    else
                                                        return false;
                                                }
                                                if(found==0){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || charrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=charrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==charrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    int number2;
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN){
                                                        error();
                                                    }
                                                    else{
                                                        lex();
                                                    if(nextToken==INT_LIT){
                                                        number2=findthenumber();
                                                    }
                                                    else if(nextToken==IDENT){
                                                        int found =0;
                                                        int l=0;
                                                        for(int k=0;k<200;k++){
                                                                    l=0;
                                                                    found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                            thek2value=NULL;
                                                            found=0;
                                                                break;
                                                                }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                            }

                                                        }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    number2= *intptr[thek2value];
                                                }
                                                    }
                                                       lex();
                                                       if(nextToken!=SQRR_PAREN)
                                                            error();
                                                       else{
                                                        if(*(charrayptr[key]+number1) != *(charrayptr[thekvalue]+number2))
                                                            return true;
                                                        else
                                                            return false;
                                                       }
                                                    }
                                                }
                                                else{
                                                    if(*(charrayptr[key]+number1) != lexeme[0])
                                                        return true;
                                                    else
                                                        return false;
                                                }
                                                }
                                            }
                                        }
                                    }
                                    else if(nextToken==EQUAL_SYM){
                                        lex();
                                            if(nextToken==IDENT){
                                                int found =0;
                                        int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || chvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=chvarNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==chvarNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    if( *(charrayptr[key]+number1) == *chptr[thekvalue])
                                                        return true;

                                                    else
                                                        return false;
                                                }
                                                if(found==0){
                                                    int found =0;
                                                    int l=0;
                                            for(int k=0;k<200;k++){
                                                l=0;
                                                found=0;
                                            while(lexeme[l]!=NULL || charrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=charrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                        if(lexeme[l]==charrayNames[k][l]){
                                                                found=1;
                                                                thekvalue=k;
                                                                l++;

                                                    }

                                                    }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    int number2;
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN){
                                                        error();
                                                    }
                                                    else{
                                                        lex();
                                                    if(nextToken==INT_LIT){
                                                        number2=findthenumber();
                                                    }
                                                    else if(nextToken==IDENT){
                                                        int found =0;
                                                        int l=0;
                                                        for(int k=0;k<200;k++){
                                                                    l=0;
                                                                    found=0;
                                                while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intvarNames[k][l]){
                                                            thek2value=NULL;
                                                            found=0;
                                                                break;
                                                                }
                                                        else{
                                                        if(lexeme[l]==intvarNames[k][l]){
                                                                found=1;
                                                                thek2value=k;
                                                                l++;

                                                            }

                                                        }
                                                    }
                                                    if(found==1){
                                                        break;
                                                    }
                                                }
                                                if(found==1){
                                                    number2= *intptr[thek2value];
                                                }
                                                    }
                                                       lex();
                                                       if(nextToken!=SQRR_PAREN)
                                                            error();
                                                       else{
                                                        if(*(charrayptr[key]+number1) == *(charrayptr[thekvalue]+number2))
                                                            return true;
                                                        else
                                                            return false;
                                                       }
                                                    }
                                                }
                                                else{
                                                    if(*(charrayptr[key]+number1) == lexeme[0])
                                                        return true;
                                                    else
                                                        return false;
                                                }
                                                }
                                            }
                                    }
                                }
                            }

                        }
                        }
    else if(nextToken==BOOLTRUE_KEYWORD)
        return true;
    else if(nextToken==BOOLFALSE_KEYWORD)
        return false;
    else
        error();
    }

int additionop(){
    int thekvalue;
    int yesident=false;
    int key1;
    int key2;

    int second=0;
    int first=0;
    if(nextToken==ADD_KEYWORD){
        printf("\n-inside addition operation -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();

        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i=0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                        if(lexeme[i]!=intvarNames[k][i]){
                                found=0;
                        break;
                    }
                else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }

                }
                }
                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key1=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key1=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }
                if(found==1){
                    first=*intptr[k];
                    break;
                }
                else
                    first=-9999;
         }

         if(found==-9999){
                if(yesident==false){
                    error();
                }
         }


            }
           else if(nextToken==SUB_OP){
            lex();
            if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                        i++;
                }

                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }
                first=-1*first;



            }
            else
                error();

           }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                        i++;
                }

                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                first=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                first=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                first=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                first=divisionop();
            }
            else
                error();

                lex();

                if(nextToken==SQRL_PAREN && yesident==true){
                    lex();
                    if(nextToken==INT_LIT){
                        int indice1;
                        indice1=findthenumber();
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }

                    }
                    else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice1;
                        indice1= *intptr[thekvalue];
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }


                    }
                    else
                        error();
                }
            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                    if(lexeme[i]!=intvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key2=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key2=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }
                if(found==1){
                    second=*intptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
                if(yesident==false){
                    error();
                }
         }


            }
            else if(nextToken==SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }
                second=-1*second;



            }

            }
           else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                second=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                second=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                second=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                second=divisionop();
            }
            else
                error();
            lex();

            if(nextToken==SQRL_PAREN && yesident==true){
                lex();
                if(nextToken==INT_LIT){
                    int indice2;
                    indice2=findthenumber();

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice2;
                        indice2= *intptr[thekvalue];

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else
                    error();
            }
            if(nextToken!=RIGHT_PAREN){
               error();

            }
            else
                printf("-->RESULT =  %d\n\n",first+second);
                return first+second;



            }
        }

    }
    else
        return NULL;


}
int multiplicationop(){
    int thekvalue;
    int yesident=false;
    int key1;
    int key2;

    int second=0;
    int first=0;
    if(nextToken==MULT_KEYWORD){
        printf("\n-inside multiplication operation -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();
        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                    if(lexeme[i]!=intvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key1=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key1=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }
                if(found==1){
                    first=*intptr[k];
                    break;
                }
                else
                    first=-9999;
         }
         if(first==-9999){
                if(yesident==false){
                error();
                }
         }


            }
            else if(nextToken==SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                        i++;
                }

                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }

                first=-1*first;


            }
            else
                error();

            }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                        i++;
                }

                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                first=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                first=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                first=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                first=divisionop();
            }
            else
                error();

                lex();

                if(nextToken==SQRL_PAREN && yesident==true){
                    lex();

                    if(nextToken==INT_LIT){
                        int indice1;
                        indice1=findthenumber();
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }

                    }
                    else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice1;
                        indice1= *intptr[thekvalue];
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }


                    }
                    else
                        error();
                }

            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                    if(lexeme[i]!=intvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }

                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key2=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key2=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }

                if(found==1){
                    second=*intptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
                if(yesident==false){
                error();
                }
         }

            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }
                second=-1*second;



            }
            else
                error();

            }
          else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                second=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                second=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                second=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                second=divisionop();
            }
            else
                error();
            lex();

            if(nextToken==SQRL_PAREN && yesident==true){
                lex();
                if(nextToken==INT_LIT){
                    int indice2;
                    indice2=findthenumber();

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice2;
                        indice2= *intptr[thekvalue];

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else
                    error();
            }

            if(nextToken!=RIGHT_PAREN){
                error();

            }
            else{
                printf("-->RESULT =  %d\n\n",first*second);
                return first*second;
            }



            }
        }

    }
    else
        return NULL;

}
int substractionop(){
    int thekvalue;
    int yesident=false;
    int key1;
    int key2;

    int second=0;
    int first=0;
    if(nextToken==SUB_KEYWORD){
        printf("\n-inside subtraction operation -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();

        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                    if(lexeme[i]!=intvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key1=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key1=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }
                if(found==1){
                    first=*intptr[k];
                    break;
                }
                else
                    first=-9999;
         }
         if(first==-9999){
                if(yesident==false){
                error();
                }
         }



            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }
                first=-1*first;



            }
            else
                error();
            }
           else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                        i++;
                }

                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                first=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                first=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                first=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                first=divisionop();
            }
            else
                error();

                lex();

                if(nextToken==SQRL_PAREN && yesident==true){
                    lex();
                    if(nextToken==INT_LIT){
                        int indice1;
                        indice1=findthenumber();
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }

                    }
                    else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice1;
                        indice1= *intptr[thekvalue];
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }


                    }
                    else
                        error();
                }

            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                    if(lexeme[i]!=intvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key2=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key2=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }
                if(found==1){
                    second=*intptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
                if(yesident==false){
                    error();
                }
         }


            }
            else if(nextToken==SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }
                second=-1*second;



            }
            else
                error();
            }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                second=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                second=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                second=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                second=divisionop();
            }
            else
                error();
            lex();

            if(nextToken==SQRL_PAREN && yesident==true){
                lex();
                if(nextToken==INT_LIT){
                    int indice2;
                    indice2=findthenumber();

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice2;
                        indice2= *intptr[thekvalue];

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else
                    error();
            }

            if(nextToken!=RIGHT_PAREN){
                error();

            }
            else{
                printf("-->RESULT =  %d\n\n",first-second);
                return first-second;
            }



            }
        }

    }
    else
        return NULL;

}
int divisionop(){
    int thekvalue;
    int yesident=false;
    int key1;
    int key2;

    int second=0;
    int first=0;
    if(nextToken==DIV_KEYWORD){
        printf("\n-inside division operation -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();

        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                    if(lexeme[i]!=intvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key1=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key1=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }
                if(found==1){
                    first=*intptr[k];
                    break;
                }
                else
                    first=-9999;
         }
         if(first==-9999){
                if(yesident==false){
                    error();
                }
         }


            }
            else if(nextToken==SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                        i++;
                }

                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }
                first=-1*first;




            }
            else
                error();

            }
           else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                        i++;
                }

                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                first=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                first=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                first=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                first=divisionop();
            }
            else
                error();

                lex();

                if(nextToken==SQRL_PAREN && yesident==true){
                    lex();
                    if(nextToken==INT_LIT){
                        int indice1;
                        indice1=findthenumber();
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }

                    }
                    else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice1;
                        indice1= *intptr[thekvalue];
                        if(intarraybounds[key1]==NULL || intarraybounds[key1]-1 < indice1)
                            error();
                            else{
                                first= *(intarrayptr[key1]+indice1);
                                yesident=false;
                                lex();
                                if(nextToken!=SQRR_PAREN)
                                    error();
                                else{
                                    lex();
                                }
                            }


                    }
                    else
                        error();
                }

            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                    if(lexeme[i]!=intvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==intvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                i=0;
                while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                    if(lexeme[i]!=intarrayNames[k][i]){
                        yesident=false;
                        key2=NULL;
                        break;
                    }
                    else{
                        if(lexeme[i]==intarrayNames[k][i]){
                            yesident=true;
                            key2=k;
                            i++;
                        }
                    }
                }
                if(yesident==true){
                    break;
                }
                if(found==1){
                    second=*intptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
                if(yesident==false){
                    error();
                }
         }

            }
            else if(nextToken==SUB_OP){
                    lex();
                    if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }
                second=-1*second;



            }
            else
                error();


            }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        additionarray[i]=(int)lexeme[i];
                        additionarray[i]=additionarray[i]-48;
                    i++;
                }
                int stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                        stair=stair*10;
                    }

                    second=second+additionarray[i-1]*stair;
                    stair=1;

                }



            }
            else if(nextToken==ADD_KEYWORD){
                second=additionop();
            }
            else if(nextToken==MULT_KEYWORD){
                second=multiplicationop();
            }
            else if(nextToken==SUB_KEYWORD){
                second=substractionop();
            }
            else if(nextToken==DIV_KEYWORD){
                second=divisionop();
            }
            else
                error();
            lex();

            if(nextToken==SQRL_PAREN && yesident==true){
                lex();
                if(nextToken==INT_LIT){
                    int indice2;
                    indice2=findthenumber();

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                            int indice2;
                        indice2= *intptr[thekvalue];

                    if(intarraybounds[key2]==NULL || intarraybounds[key2]-1 < indice2)
                        error();
                    else{
                        second= *(intarrayptr[key2]+indice2);
                        yesident=false;
                        lex();
                        if(nextToken!=SQRR_PAREN)
                            error();
                        else{
                            lex();
                        }
                    }
                }
                else
                    error();
            }

            if(nextToken!=RIGHT_PAREN){
                error();

            }
            else{
                printf("-->RESULT =  %d\n\n",first/second);
                return first/second;
            }



            }
        }

    }
    else
        return NULL;

}

float fladditionop(){

    float second=0;
    float first=0;

    if(nextToken==FLADD_KEYWORD){
        printf("\n-inside addition operation for floats -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();

        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    first=*flptr[k];
                    break;
                }
                else
                    first=-9999;
         }
         if(first==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }
                first=-1*first;

                }
                }

            }
            else
                error();

            }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }

                }
                }

            }
            else if(nextToken==FLADD_KEYWORD){
                first=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                first=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                first=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                first=fldivisionop();
            }
            else
                error();

                lex();
            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    second=*flptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }
                second=-1*second;


                }

            }
            else
                error();
            }
           else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }


                }

            }
            else if(nextToken==FLADD_KEYWORD){
                second=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                second=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                second=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                second=fldivisionop();
            }
            else
                error();
            lex();
            if(nextToken!=RIGHT_PAREN){
                error();

            }
            else{
                printf("-->RESULT =  %f\n\n",first+second);
                return first+second;
            }



            }
        }

    }
    else
        return 0;

}
float flmultiplicationop(){
    float second=0;
    float first=0;

    if(nextToken==FLMULT_KEYWORD){
        printf("\n-inside multiplication operation for floats -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();

        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    first=*flptr[k];
                    break;
                }
                else
                    first=-9999;
         }
         if(first==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }
                first=-1*first;

                }
                }

            }
            else
                error();

            }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }

                }
                }

            }
            else if(nextToken==FLADD_KEYWORD){
                first=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                first=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                first=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                first=fldivisionop();
            }
            else
                error();

                lex();
            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    second=*flptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }
                second=-1*second;


                }

            }
            else
                error();
            }
           else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }


                }

            }
            else if(nextToken==FLADD_KEYWORD){
                second=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                second=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                second=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                second=fldivisionop();
            }
            else
                error();
            lex();
            if(nextToken!=RIGHT_PAREN){
                error();

            }
            else{
                printf("-->RESULT =  %f\n\n",first*second);
                return first*second;
            }


            }
        }

    }
    else
        return 0;

}
float flsubstractionop(){
    float second=0;
    float first=0;

    if(nextToken==FLSUB_KEYWORD){
        printf("\n-inside subtraction operation for floats -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();

        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    first=*flptr[k];
                    break;
                }
                else
                    first=-9999;
         }
         if(first==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }
                first=-1*first;

                }
                }

            }
            else
                error();

            }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }

                }
                }

            }
            else if(nextToken==FLADD_KEYWORD){
                first=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                first=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                first=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                first=fldivisionop();
            }
            else
                error();

                lex();
            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    second=*flptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }
                second=-1*second;


                }

            }
            else
                error();
            }
           else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }


                }

            }
            else if(nextToken==FLADD_KEYWORD){
                second=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                second=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                second=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                second=fldivisionop();
            }
            else
                error();
            lex();
            if(nextToken!=RIGHT_PAREN){
                error();

            }
            else{
                printf("-->RESULT =  %f\n\n",first-second);
                return first-second;
            }


            }
        }

    }
    else
        return 0;

}
float fldivisionop(){
float second=0;
    float first=0;

    if(nextToken==FLDIV_KEYWORD){
        printf("\n-inside division operation for floats -\n");
        lex();
        if(nextToken!=LEFT_PAREN){
            error();

        }
        else{
            lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    first=*flptr[k];
                    break;
                }
                else
                    first=-9999;
         }
         if(first==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }
                first=-1*first;

                }
                }

            }
            else
                error();

            }
            else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    first=first+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }

                }
                }

            }
            else if(nextToken==FLADD_KEYWORD){
                first=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                first=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                first=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                first=fldivisionop();
            }
            else
                error();

                lex();
            if(nextToken!=COMMA){
                error();
            }
            else{
                lex();

            if(nextToken== IDENT){
                int found =0;
                int i =0;
         for(int k=0;k<200;k++){
                i=0;
                found=0;
                while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                    if(lexeme[i]!=flvarNames[k][i]){

                        found=0;
                        break;
                    }
                    else{
                    if(lexeme[i]==flvarNames[k][i]){

                        found=1;
                        i++;

                    }
                    }

                }
                if(found==1){
                    second=*flptr[k];
                    break;
                }
                else
                    second=-9999;
         }
         if(second==-9999){
           error();
         }


            }
            else if(nextToken== SUB_OP){
                lex();
                if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }
                second=-1*second;


                }

            }
            else
                error();
            }
           else if(nextToken== INT_LIT){
                    int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    second=second+fladditionarray[i-1]*stair;
                    stair=1;

                }
                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;
                    }


                    second=second+fladditionarray[g]*stair;
                    stair=1;

                }


                }

            }
            else if(nextToken==FLADD_KEYWORD){
                second=fladditionop();
            }
            else if(nextToken==FLMULT_KEYWORD){
                second=flmultiplicationop();
            }
            else if(nextToken==FLSUB_KEYWORD){
                second=flsubstractionop();
            }
            else if(nextToken==FLDIV_KEYWORD){
                second=fldivisionop();
            }
            else
                error();
            lex();
            if(nextToken!=RIGHT_PAREN){
                error();

            }
            else{
                printf("-->RESULT =  %f\n\n",first/second);
                return first/second;
            }


            }
        }

    }
    else
        return 0;
}

void assignop(){
    int thekvalue;
    int thek2value;
    int islexed=false;
    int arrayvalue=0;
    int arrayposition=0;
    char arrayvalue2;

    float numb2=0;
    int numb1=0;
    int istrue=false;
    if(nextToken==ASSIGN_KEYWORD){
            printf("\n-inside assign operation-\n");
            lex();
        if(nextToken!=LEFT_PAREN){
            error();
        }
        else{
            lex();
            if(nextToken!= IDENT){
                error();
            }
            else{
                    int cond=0;
                    int cond1=6;
                    int cond2=6;
                    int cond3=6;
                    int cond4=6;
                    int cond5=6;
                    int cond6=6;
                    int key;
                    int j=0;
                    for(int k=0;k<200;k++){
                            cond1=6;
                            cond2=6;
                            cond3=6;
                            cond4=6;
                            cond5=6;
                            cond6=6;
                            j=0;
                        while(1==1){
                            if(lexeme[j]!=NULL){
                            if(intvarNames[k][j]!=NULL){
                                    if(cond1!=0){
                                if(intvarNames[k][j]==lexeme[j]){
                                    cond1=1;
                                }
                                else
                                    cond1=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && intvarNames[k][j]==NULL){

                                }
                                else
                                    cond1=0;
                            }

                            if(flvarNames[k][j]!=NULL){
                                    if(cond2!=0){
                                if(flvarNames[k][j]==lexeme[j]){
                                    cond2=1;
                                }
                                else
                                    cond2=0;
                                    }

                            }
                            else{
                                if(lexeme[j]==NULL && flvarNames[k][j]==NULL){

                                }
                                else
                                    cond2=0;
                            }
                            if(chvarNames[k][j]!=NULL){
                                    if(cond3!=0){
                                if(chvarNames[k][j]==lexeme[j]){
                                    cond3=1;
                                }
                                else
                                    cond3=0;
                                    }
                            }
                            else{
                                if(lexeme[j]==NULL && chvarNames[k][j]==NULL){

                                }
                                else
                                    cond3=0;
                            }
                            if(boolvarNames[k][j]!=NULL){
                                    if(cond4!=0){
                                if(boolvarNames[k][j]==lexeme[j]){
                                    cond4=1;
                                }
                                else
                                    cond4=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && boolvarNames[k][j]==NULL){

                                }
                                else
                                    cond4=0;
                            }
                                if(intarrayNames[k][j]!=NULL){
                                    if(cond5!=0){
                                        if(intarrayNames[k][j]==lexeme[j]){
                                            cond5=1;
                                }
                                else
                                    cond5=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && intarrayNames[k][j]==NULL){

                                }
                                else
                                    cond5=0;
                            }

                            if(charrayNames[k][j]!=NULL){
                                    if(cond6!=0){
                                        if(charrayNames[k][j]==lexeme[j]){
                                            cond6=1;
                                }
                                else
                                    cond6=0;
                                }
                            }
                            else{
                                if(lexeme[j]==NULL && charrayNames[k][j]==NULL){

                                }
                                else
                                    cond6=0;
                            }


                            j++;
                        }
                        else{
                            break;
                        }
                        }
                        if(cond1==1 || cond2==1 || cond3==1 || cond4==1 || cond5==1 || cond6==1 ){
                            key=k;
                            break;
                        }
                    }
                        if(cond1==1){
                            if(intvarNames[key][j]!=NULL){
                                cond=0;
                            }
                            else{
                            cond=1;
                            }
                        }
                        if(cond2==1){
                        if(flvarNames[key][j]!=NULL){
                            cond=0;
                            }
                            else
                            cond=2;
                        }
                        if(cond3==1){
                            if(chvarNames[key][j]!=NULL){
                            cond=0;
                            }
                            else
                            cond=3;
                        }
                        if(cond4==1){
                            if(boolvarNames[key][j]!=NULL){
                            cond=0;
                            }
                            else
                            cond=4;
                        }
                        if(cond5==1){
                            if(intarrayNames[key][j]!=NULL){
                                cond=0;
                            }
                            else{
                                cond=5;
                            }
                        }
                        if(cond6==1){
                            if(charrayNames[key][j]!=NULL){
                                cond=0;
                            }
                            else{
                                cond=6;
                            }
                        }

                        if(cond==1){
                            lex();
                            if(nextToken!=COMMA){
                                error();
                            }
                            else{
                                lex();
                                if(nextToken==INT_LIT){

                                int i=0;
                                while(lexeme[i]!=NULL){
                                additionarray[i]=(int)lexeme[i];
                                additionarray[i]=additionarray[i]-48;
                                i++;
                                }

                                int stair=1;
                                int p=i;

                                for(i;i>0;i--){

                                for(int l=0;l<p-i;l++){

                                stair=stair*10;
                                }

                            numb1=numb1+additionarray[i-1]*stair;
                            stair=1;

                                }
                                *intptr[key]=numb1;


                                }
                              else if(nextToken==IDENT){

                                    int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                            if(lexeme[i]!=intvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==intvarNames[k][i]){
                                found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        *intptr[key]=*intptr[k];
                    break;
                        }
                            }
                                if(found==0){
                                        found =0;
                                        i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                        found=0;
                                    while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                                    if(lexeme[i]!=intarrayNames[k][i]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[i]==intarrayNames[k][i]){
                                found=1;
                                thekvalue=k;
                                i++;

                                }

                            }
                        }
                                if(found==1){
                                        break;
                                            }
                                    }
                                        lex();
                                        islexed=true;
                                        if(nextToken!=SQRL_PAREN && found==1){
                                            error();
                                        }
                                        else{
                                            lex();
                                            if(nextToken==INT_LIT){
                                            arrayvalue=findthenumber();
                                            *intptr[key]=*(intarrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();
                                        }
                                        else if(nextToken==IDENT){
                                                int found =0;
                                                int i=0;
                                                for(int k=0;k<200;k++){
                                                    i=0;
                                                    found=0;
                                                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                                                if(lexeme[i]!=intvarNames[k][i]){
                                                    found=0;
                                                    thek2value=NULL;
                                                    break;
                                                        }
                                                else{
                                                    if(lexeme[i]==intvarNames[k][i]){
                                                        found=1;
                                                        thek2value=k;
                                                        i++;

                                                        }

                                                    }
                                                }
                                                if(found==1){
                                                    break;
                                                    }
                                                }
                                                arrayvalue= *intptr[thek2value];
                                                *intptr[key]=*(intarrayptr[thekvalue]+arrayvalue);
                                                lex();
                                                if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();

                                        }


                                        }

                                }

                                }
                               else if(nextToken==ADD_KEYWORD){
                                    int numberwa;
                                    numberwa=additionop();
                                    *intptr[key]=numberwa;
                                }
                                else if(nextToken==SUB_KEYWORD){
                                    int numberwa;
                                    numberwa=substractionop();
                                    *intptr[key]=numberwa;
                                }
                                else if(nextToken==MULT_KEYWORD){
                                    int numberwa;
                                    numberwa=multiplicationop();
                                    *intptr[key]=numberwa;
                                }
                                else if(nextToken==DIV_KEYWORD){
                                    int numberwa;
                                    numberwa=divisionop();
                                    *intptr[key]=numberwa;
                                }
                                else
                                    error();


                                }
                            }
                           else if(cond==2){
                                    lex();
                                if(nextToken!=COMMA){
                                    error();
                                }
                                else{
                                    lex();
                                    if(nextToken==INT_LIT){
                                        int i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                float stair=1;
                int p=i;

                for(i;i>0;i--){

                    for(int l=0;l<p-i;l++){


                            stair=stair*10;
                    }

                    numb2=numb2+fladditionarray[i-1]*stair;
                    stair=1;

                }

                lex();
                if(nextToken!=POINT){
                    error();
                }
                else{
                lex();

                if(nextToken!= INT_LIT){
                    error();
                }
                else{
                i=0;
                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(float)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    numb2=numb2+fladditionarray[g]*stair;
                    stair=1;

                }
                *flptr[key]=numb2;


                }
                }
                                    }
                                   else if(nextToken==IDENT){

                                    int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || flvarNames[k][i]!=NULL){
                            if(lexeme[i]!=flvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==flvarNames[k][i]){
                                found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        *flptr[key]=*flptr[k];
                    break;
                        }
                            }


                                }
                                   else if(nextToken==FLADD_KEYWORD){
                                            numb2=fladditionop();
                                            *flptr[key]=numb2;
                                    }
                                    else if(nextToken==FLSUB_KEYWORD){
                                        numb2=flsubstractionop();
                                        *flptr[key]=numb2;
                                    }
                                    else if(nextToken==FLMULT_KEYWORD){
                                        numb2=flmultiplicationop();
                                        *flptr[key]=numb2;
                                    }
                                    else if(nextToken==FLDIV_KEYWORD){
                                        numb2=fldivisionop();
                                        *flptr[key]=numb2;
                                    }
                                    else
                                        error();



                                }




                            }
                            else if(cond==3){
                                    lex();
                                    if(nextToken!= COMMA){
                                        error();
                                    }
                                    else{
                                        lex();
                                        if(nextToken!=IDENT){
                                            error();
                                        }
                                        else{
                                    int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || chvarNames[k][i]!=NULL){
                            if(lexeme[i]!=chvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==chvarNames[k][i]){
                                if(lexeme[i+1]==NULL && lexeme[i+1]==chvarNames[k][i+1])
                                    found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        int j=0;
                        while(*(chptr[k]+j)!=NULL){
                            *(chptr[key]+j)= *(chptr[k]+j);
                            j++;
                        }
                    break;
                        }
                        else{
                            *chptr[key]=lexeme[0];
                        }
                            }
                                    if(found==0){

                                        found=0;
                                        i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                        found=0;
                                    while(lexeme[i]!=NULL || charrayNames[k][i]!=NULL){
                                    if(lexeme[i]!=charrayNames[k][i]){
                                        thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[i]==charrayNames[k][i]){
                                found=1;
                                thekvalue=k;
                                i++;

                                        }

                                        }
                                        }
                                        if(found==1){
                                            break;
                                        }
                                        }
                                        if(found==1){
                                            lex();
                                            if(nextToken!=SQRL_PAREN){
                                                    error();
                                            }
                                            else{
                                                lex();
                                                if(nextToken==INT_LIT){
                                                    arrayposition=findthenumber();
                                                    *chptr[key] = *(charrayptr[thekvalue]+arrayposition);

                                                }
                                                else if(nextToken==IDENT){
                                                        found=0;
                                                            i=0;
                                                            for(int k=0;k<200;k++){
                                                                    i=0;
                                                                found=0;
                                                        while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                                                            if(lexeme[i]!=intarrayNames[k][i]){
                                                                thek2value=NULL;
                                                                    found=0;
                                                                        break;
                                                                                }
                                                                    else{
                                                            if(lexeme[i]==intarrayNames[k][i]){
                                                                found=1;
                                                                thek2value=k;
                                                                    i++;

                                                                                }

                                                                    }
                                                                }
                                                        if(found==1){
                                                            break;
                                                            }
                                                        }
                                                        if(found==1){
                                                             arrayposition= *intptr[thek2value];
                                                            *chptr[key]= *(charrayptr[thekvalue]+arrayposition);
                                                        }

                                                }
                                                else
                                                    error();
                                                lex();
                                                if(nextToken!=SQRR_PAREN)
                                                    error();
                                            }
                                        }
                                        lex();
                                        istrue=true;
                                        int i=1;
                                        while(nextToken==ADD_OP){
                                            lex();
                                            if(nextToken==RIGHT_PAREN){
                                                istrue=true;
                                                *(chptr[key]+i)=NULL;
                                                break;
                                            }
                                                  found=0;
                                                  int l=0;
                                                    for(int k=0;k<200;k++){
                                                        l=0;
                                                        found=0;
                                                        while(lexeme[l]!=NULL || charrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=charrayNames[k][l]){
                                                        thekvalue=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                    if(lexeme[l]==charrayNames[k][l]){
                                                        found=1;
                                                        thekvalue=k;
                                                                l++;

                                                    }

                                                                    }
                                                            }
                                                if(found==1){
                                                    break;
                                            }
                                            }
                                            if(found==1){
                                                    lex();
                                                    if(nextToken!=SQRL_PAREN)
                                                        error();
                                                    else
                                                        lex();

                                                    if(nextToken==INT_LIT){
                                                        arrayposition=findthenumber();
                                                    }
                                                    else if(nextToken==IDENT){
                                                            found=0;
                                                            l=0;
                                                    for(int k=0;k<200;k++){
                                                        l=0;
                                                        found=0;
                                                        while(lexeme[l]!=NULL || intarrayNames[k][l]!=NULL){
                                                    if(lexeme[l]!=intarrayNames[k][l]){
                                                        thek2value=NULL;
                                                        found=0;
                                                        break;
                                                            }
                                                    else{
                                                    if(lexeme[l]==intarrayNames[k][l]){
                                                        found=1;
                                                        thek2value=k;
                                                                l++;

                                                    }

                                                                    }
                                                            }
                                                if(found==1){
                                                    break;
                                            }
                                            }
                                                if(found==1){
                                                    arrayposition= *intptr[thek2value];
                                                }

                                                    }

                                                *(chptr[key]+i) = *(charrayptr[thekvalue]+arrayposition);

                                                lex();
                                                if(nextToken!=SQRR_PAREN)
                                                    error();
                                            }
                                            else{
                                                *(chptr[key]+i)=lexeme[0];
                                                *(chptr[key]+i+1)=NULL;

                                            }
                                            i++;
                                            istrue=true;
                                            lex();
                                        }
                                    }




                                        }




                                    }

                            }
                           else if(cond==4){
                            lex();
                            if(nextToken!=COMMA){
                                error();
                            }
                            else{
                                lex();
                                if(nextToken==IDENT){

                                    int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || boolvarNames[k][i]!=NULL){
                            if(lexeme[i]!=boolvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==boolvarNames[k][i]){
                                found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        *boolptr[key]=*boolptr[k];
                    break;
                        }
                            }


                                }
                                else if(nextToken==BOOLTRUE_KEYWORD){
                                    *boolptr[key]=true;
                                }
                                else
                                    error();




                                }
                            }

                            else if(cond==5){
                                lex();
                                if(nextToken!=SQRL_PAREN)
                                    error();
                                else{
                                    lex();

                                if(nextToken==INT_LIT){
                                    arrayposition=findthenumber();
                                    if(intarraybounds[key]==NULL || intarraybounds[key]-1 < arrayposition)
                                        error();
                                    else{
                                        lex();
                                        if(nextToken!=SQRR_PAREN)
                                            error();
                                        else{
                                            lex();
                                            if(nextToken!=COMMA)
                                                error();
                                            else{
                                                lex();
                                                if(nextToken==INT_LIT){
                                                    arrayvalue=findthenumber();
                                                    *(intarrayptr[key]+arrayposition)=arrayvalue;
                                                }
                                    else if(nextToken==IDENT){

                                    int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                            if(lexeme[i]!=intvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==intvarNames[k][i]){
                                found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        *(intarrayptr[key]+arrayposition)=*intptr[k];
                    break;
                        }
                            }
                                if(found==0){
                                        found =0;
                                        i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                        found=0;
                                    while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                                    if(lexeme[i]!=intarrayNames[k][i]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[i]==intarrayNames[k][i]){
                                found=1;
                                thekvalue=k;
                                i++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                                        lex();
                                        islexed=true;
                                        if(nextToken!=SQRL_PAREN && found==1){
                                            error();
                                        }
                                        else{
                                            lex();
                                            if(nextToken==INT_LIT){
                                            arrayvalue=findthenumber();
                                            *(intarrayptr[key]+arrayposition)= *(intarrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();

                                        }
                                        else if(nextToken==IDENT){

                                                found =0;
                                                i=0;
                                            for(int k=0;k<200;k++){
                                                i=0;
                                                found=0;
                                                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                                            if(lexeme[i]!=intvarNames[k][i]){
                                                    thek2value=NULL;
                                                    found=0;
                                                break;
                                            }
                                                else{
                                                    if(lexeme[i]==intvarNames[k][i]){
                                                        found=1;
                                                        thek2value=k;
                                                        i++;

                                                            }

                                                        }
                                                }
                                                if(found==1){
                                                break;
                                                    }
                                                }
                                                if(found==1){
                                            arrayvalue = *intptr[thek2value];
                                            *(intarrayptr[key]+arrayposition)= *(intarrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();
                                        }


                                        }
                                        else
                                            error();

                                        }

                                }




                                }
                               else if(nextToken==ADD_KEYWORD){
                                    int numberwa;
                                    numberwa=additionop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else if(nextToken==SUB_KEYWORD){
                                    int numberwa;
                                    numberwa=substractionop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else if(nextToken==MULT_KEYWORD){
                                    int numberwa;
                                    numberwa=multiplicationop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else if(nextToken==DIV_KEYWORD){
                                    int numberwa;
                                    numberwa=divisionop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else
                                    error();

                                            }
                                        }
                                    }
                                  }
                                  else if(nextToken==IDENT){
                                    int found =0;
                                        int l=0;
                                    for(int k=0;k<200;k++){
                                        l=0;
                                        found=0;
                                    while(lexeme[l]!=NULL || intvarNames[k][l]!=NULL){
                                    if(lexeme[l]!=intvarNames[k][l]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[l]==intvarNames[k][l]){
                                found=1;
                                thekvalue=k;
                                l++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                                arrayposition= *intptr[thekvalue];
                                    if(intarraybounds[key]==NULL || intarraybounds[key]-1 < arrayposition)
                                        error();
                                    else{
                                        lex();
                                        if(nextToken!=SQRR_PAREN)
                                            error();
                                        else{
                                            lex();
                                            if(nextToken!=COMMA)
                                                error();
                                            else{
                                                lex();
                                                if(nextToken==INT_LIT){
                                                    arrayvalue=findthenumber();
                                                    *(intarrayptr[key]+arrayposition)=arrayvalue;
                                                }
                                    else if(nextToken==IDENT){

                                    int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                            if(lexeme[i]!=intvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==intvarNames[k][i]){
                                found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        *(intarrayptr[key]+arrayposition)=*intptr[k];
                    break;
                        }
                            }
                                if(found==0){
                                        found =0;
                                        i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                        found=0;
                                    while(lexeme[i]!=NULL || intarrayNames[k][i]!=NULL){
                                    if(lexeme[i]!=intarrayNames[k][i]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[i]==intarrayNames[k][i]){
                                found=1;
                                thekvalue=k;
                                i++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }
                                        lex();
                                        islexed=true;
                                        if(nextToken!=SQRL_PAREN && found==1){
                                            error();
                                        }
                                        else{
                                            lex();
                                            if(nextToken==INT_LIT){
                                            arrayvalue=findthenumber();
                                            *(intarrayptr[key]+arrayposition)= *(intarrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();

                                        }
                                        else if(nextToken==IDENT){

                                                found =0;
                                                i=0;
                                            for(int k=0;k<200;k++){
                                                i=0;
                                                found=0;
                                                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                                            if(lexeme[i]!=intvarNames[k][i]){
                                                    thek2value=NULL;
                                                    found=0;
                                                break;
                                            }
                                                else{
                                                    if(lexeme[i]==intvarNames[k][i]){
                                                        found=1;
                                                        thek2value=k;
                                                        i++;

                                                            }

                                                        }
                                                }
                                                if(found==1){
                                                break;
                                                    }
                                                }
                                                if(found==1){
                                            arrayvalue = *intptr[thek2value];
                                            *(intarrayptr[key]+arrayposition)= *(intarrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();
                                        }


                                        }

                                        }

                                }




                                }
                               else if(nextToken==ADD_KEYWORD){
                                    int numberwa;
                                    numberwa=additionop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else if(nextToken==SUB_KEYWORD){
                                    int numberwa;
                                    numberwa=substractionop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else if(nextToken==MULT_KEYWORD){
                                    int numberwa;
                                    numberwa=multiplicationop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else if(nextToken==DIV_KEYWORD){
                                    int numberwa;
                                    numberwa=divisionop();
                                    *(intarrayptr[key]+arrayposition)=numberwa;
                                }
                                else
                                    error();

                                            }
                                        }
                                    }
                                  }
                                }
                            }

                            else if(cond==6){
                                lex();
                                if(nextToken!=SQRL_PAREN)
                                    error();
                                else{
                                    lex();
                                if(nextToken==INT_LIT){
                                    arrayposition=findthenumber();
                                    if(charraybounds[key]==NULL || charraybounds[key]-1 < arrayposition)
                                        error();
                                    else{
                                        lex();
                                        if(nextToken!=SQRR_PAREN)
                                            error();
                                        else{
                                            lex();
                                            if(nextToken!=COMMA)
                                                error();
                                            else{
                                                lex();
                                                if(nextToken==IDENT){
                                                        int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || chvarNames[k][i]!=NULL){
                            if(lexeme[i]!=chvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==chvarNames[k][i]){
                                found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        *(charrayptr[key]+arrayposition)= *chptr[k];
                    break;
                        }
                            }
                                if(found==0){
                                        found =0;
                                        i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                        found=0;
                                    while(lexeme[i]!=NULL || charrayNames[k][i]!=NULL){
                                    if(lexeme[i]!=charrayNames[k][i]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[i]==charrayNames[k][i]){
                                found=1;
                                thekvalue=k;
                                i++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }           if(found==0){
                                        arrayvalue2=lexeme[0];
                                        *(charrayptr[key]+arrayposition)=arrayvalue2;
                            }
                                        lex();
                                        islexed=true;

                                        if(nextToken==SQRL_PAREN && found==1){
                                            lex();
                                            if(nextToken==INT_LIT){
                                            arrayvalue=findthenumber();
                                            *(charrayptr[key]+arrayposition)= *(charrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();

                                        }
                                        else if(nextToken==IDENT){

                                                found =0;
                                                i=0;
                                            for(int k=0;k<200;k++){
                                                i=0;
                                                found=0;
                                                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                                            if(lexeme[i]!=intvarNames[k][i]){
                                                    thek2value=NULL;
                                                    found=0;
                                                break;
                                            }
                                                else{
                                                    if(lexeme[i]==intvarNames[k][i]){
                                                        found=1;
                                                        thek2value=k;
                                                        i++;

                                                            }

                                                        }
                                                }
                                                if(found==1){
                                                break;
                                                    }
                                                }
                                                if(found==1){
                                            arrayvalue = *intptr[thek2value];
                                            *(charrayptr[key]+arrayposition)= *(charrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();
                                        }


                                        }
                                        else
                                            error();

                                        }

                                }




                                }


                                                }

                                            }
                                        }
                                    }
                                    else if(nextToken==IDENT){
                                               int found =0;
                                               int i=0;
                                            for(int k=0;k<200;k++){
                                                i=0;
                                                found=0;
                                                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                                            if(lexeme[i]!=intvarNames[k][i]){
                                                    thek2value=NULL;
                                                    found=0;
                                                break;
                                            }
                                                else{
                                                    if(lexeme[i]==intvarNames[k][i]){
                                                        found=1;
                                                        thek2value=k;
                                                        i++;

                                                            }

                                                        }
                                                }
                                                if(found==1){
                                                break;
                                                    }
                                                }
                                                arrayposition= *intptr[thek2value];
                                    if(charraybounds[key]==NULL || charraybounds[key]-1 < arrayposition)
                                        error();
                                    else{
                                        lex();
                                        if(nextToken!=SQRR_PAREN)
                                            error();
                                        else{
                                            lex();
                                            if(nextToken!=COMMA)
                                                error();
                                            else{
                                                lex();
                                                if(nextToken==IDENT){
                                                        int found =0;
                                    int i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                    found=0;
                            while(lexeme[i]!=NULL || chvarNames[k][i]!=NULL){
                            if(lexeme[i]!=chvarNames[k][i]){
                                    found=0;
                                    break;
                                        }
                            else{
                            if(lexeme[i]==chvarNames[k][i]){
                                found=1;

                                i++;

                                }

                            }
                        }
                if(found==1){
                        *(charrayptr[key]+arrayposition)= *chptr[k];
                    break;
                        }
                            }
                                if(found==0){
                                        found =0;
                                        i=0;
                                    for(int k=0;k<200;k++){
                                        i=0;
                                        found=0;
                                    while(lexeme[i]!=NULL || charrayNames[k][i]!=NULL){
                                    if(lexeme[i]!=charrayNames[k][i]){
                                            thekvalue=NULL;
                                    found=0;
                                    break;
                                            }
                                else{
                                if(lexeme[i]==charrayNames[k][i]){
                                found=1;
                                thekvalue=k;
                                i++;

                                }

                            }
                        }
                if(found==1){
                    break;
                        }
                            }           if(found==0){
                                        arrayvalue2=lexeme[0];
                                        *(charrayptr[key]+arrayposition)=arrayvalue2;
                            }
                                        lex();
                                        islexed=true;
                                        if(nextToken!=SQRL_PAREN && found==1){
                                            error();
                                        }
                                        else{
                                            lex();
                                            if(nextToken==INT_LIT){
                                            arrayvalue=findthenumber();
                                            *(charrayptr[key]+arrayposition)= *(charrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();

                                        }
                                        else if(nextToken==IDENT){

                                                found =0;
                                                i=0;
                                            for(int k=0;k<200;k++){
                                                i=0;
                                                found=0;
                                                while(lexeme[i]!=NULL || intvarNames[k][i]!=NULL){
                                            if(lexeme[i]!=intvarNames[k][i]){
                                                    thek2value=NULL;
                                                    found=0;
                                                break;
                                            }
                                                else{
                                                    if(lexeme[i]==intvarNames[k][i]){
                                                        found=1;
                                                        thek2value=k;
                                                        i++;

                                                            }

                                                        }
                                                }
                                                if(found==1){
                                                break;
                                                    }
                                                }
                                                if(found==1){
                                            arrayvalue = *intptr[thek2value];
                                            *(charrayptr[key]+arrayposition)= *(charrayptr[thekvalue]+arrayvalue);
                                            lex();
                                            if(nextToken!=SQRR_PAREN)
                                                error();
                                                else
                                                    lex();
                                        }


                                        }
                                        else
                                            error();

                                        }

                                }




                                }


                                                }

                                            }
                                        }


                                    }
                                    else
                                        error();
                                  }

                                }

                            else{
                                error();
                            }

                            if(istrue==false && islexed==false){
                            lex();
                            }


                            if(nextToken!=RIGHT_PAREN){
                                error();
                            }

                        }

                    }

            }
        }

int findthenumber(){




                                    int numb1=0;
                                    int j=0;
                                    while(lexeme[j]!=NULL){
                                    additionarray[j]=(int)lexeme[j];
                                    additionarray[j]=additionarray[j]-48;
                                    j++;
                                    }

                                int stair=1;
                                int p=j;

                                for(j;j>0;j--){

                                for(int l=0;l<p-j;l++){


                                    stair=stair*10;
                                    }

                                        numb1=numb1+additionarray[j-1]*stair;
                                        stair=1;
                                }
                                return numb1;
}

float flfindthenumber(){
                    int i=0;
                 float first=0;
                 float stair=0;

                while(lexeme[i]!=NULL){
                        fladditionarray[i]=(int)lexeme[i];
                        fladditionarray[i]=fladditionarray[i]-48;
                        i++;
                }


                stair=1;


                for(int g=0;g<i;g++){

                    for(int l=0;l<g+1;l++){


                            stair=stair/10;


                    }


                    first=first+fladditionarray[g]*stair;
                    stair=1;

                }
                return first;
}

void parse(){
    printf("\n");
    additionop();
    multiplicationop();
    substractionop();
    divisionop();
    fladditionop();
    flmultiplicationop();
    flsubstractionop();
    fldivisionop();
    ifStatement();
    typeCheck();
    assignop();
    lex();
    typeCheck();
    assignop();
    ifStatement();
    whilestatement();
}
