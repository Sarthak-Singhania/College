#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int correctAnswerCheck (char array[]){
    int j=0, quesN, answer, correctAnswer=0, answerOutput, value=0;
    char ch;
    int len = strlen(array);
    printf("%d\n", len);
    for(int i = 0; i < len; i++){
        if(array[i]=='Q' && array[i+1]=='U' && array[i+2]=='E' && array[i+3]=='S' && array[i+4]==':'){
            j=i;
            while(ch!='?'){
                ch = array[j];
                j++;
            }
            for(int question = i; question < j; question++)
                printf("%c", array[question]);
            answer = j;
            while(ch!='0'){
                ch = array[answer];
                answer++;
            }
            printf("\n");
            correctAnswer = 0;
            for(answerOutput = j; answerOutput < answer - 2; answerOutput++){
                ch = getchar();
                if (ch=='\n') break;
                if(ch==array[answerOutput]){
                    correctAnswer++;
                }
            }
            float z = (((answer - 2) - j)*4/7);
            if(correctAnswer >= z){
                printf("Correct %d %f\n", correctAnswer, z);
                value++;
            }
            else {
                printf("False %d %f\n", correctAnswer, z);
            }
        }
    }
    return value;
}


int main(){
    int correct;
    char ch, array[]= "QUES: What is your name?Sarthak 0";
    correct=correctAnswerCheck(array);
    if (correct) printf("YES!\n");
    else printf("NO\n");
}