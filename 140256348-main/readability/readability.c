#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int count_letters(string text);
int count_words( string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text: ");
    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);

    float L = (float) l/w*100;
    float S = (float) s/w*100;
    float index = .0588 * L - 0.296 * S - 15.8;
    int grade = (int)round(index);


    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", grade);
    }

    return 0;
}

int count_letters( string text){
    int numl=0;
    for(int i=0; i<strlen(text);i++){
        if (isalpha(text[i])){
            numl++;
        }

    }
    return numl;
}

int count_words( string text){
    int numl=1;
    for(int i=0; i<strlen(text);i++){
        if (isspace(text[i])){
            numl++;
        }

    }
    return numl;
}

int count_sentences(string text){
     int numl=0;
     for(int i=0; i<strlen(text);i++){
        if (text[i] == '.' || text[i] == '!' || text[i] == '?'){
            numl++;
        }

    }
    return numl;
}
