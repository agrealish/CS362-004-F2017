#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // generate a random ASCII character between low (32 = space) nad high (126 = ~)

    int low = 32;
    int high = 126;
    char c = low + (rand()%(high-low+1));
    return c;
}

char *inputString()
{
    // generate a random ASCII string using lowercase alphabet values (97-122)

    int low = 97; // lowecase a
    int high = 122; // lowercase z
    int strLen = 6; // length of string we want to generate
    int i; // counter variable for loop
    char* str = malloc(strLen); // allocate space for string

    for (i=0; i<(strLen-1); i++) {
        str[i] = low + (rand()%(high-low+1));
    }

    str[strLen-1] = '\0'; // end string
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
