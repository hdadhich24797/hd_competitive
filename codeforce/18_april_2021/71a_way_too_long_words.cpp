#include<iostream>
#include<string.h>
using namespace std;

/*
 * Sometimes some words like "localization" or "internationalization" are so long that writing them many times in one text is quite tiresome.
 *
 * Let's consider a word too long, if its length is strictly more than 10 characters. All too long words should be replaced with a special abbreviation.
 *
 * This abbreviation is made like this: we write down the first and the last letter of a word and between them we write the number of letters between the first and the last letters. That number is in decimal system and doesn't contain any leading zeroes.
 *
 * Thus, "localization" will be spelt as "l10n", and "internationalization» will be spelt as "i18n".
 *
 * You are suggested to automatize the process of changing the words with abbreviations. At that all too long words should be replaced by the abbreviation and the words that are not too long should not undergo any changes.
 *
 * Input
 * The first line contains an integer n (1 ≤ n ≤ 100). Each of the following n lines contains one word. All the words consist of lowercase Latin letters and possess the lengths of from 1 to 100 characters.
 *
 * Output
 * Print n lines. The i-th line should contain the result of replacing of the i-th word from the input data.
 */

int number_of_digits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}
void concat_digits_to_word(char *temp, int number, int no_of_digits)
{
    while (no_of_digits >= 1)
    {
        temp[no_of_digits] = (char)((number % 10) + 48);
        no_of_digits--;
        number = number / 10; 
    }

}
int main()
{
    int n = 0;
    int i = 0;
    int count_letters = 0;
    int no_of_digits = 0;
    cin>>n;
    char words[n+1][102];
    /*  n = number of words */
    for (i = 0; i < n; i++)
    {
        cin>>words[i];
    }
    for (i = 0; i < n; i++)
    {
        count_letters = strlen(words[i]);
        if (count_letters <= 10)
        {
            cout<<words[i]<<endl;
        }
        else
        {
            char temp[100];
            temp[0] = words[i][0];
            no_of_digits = number_of_digits(count_letters - 2);
            concat_digits_to_word(temp, count_letters - 2, no_of_digits);
            temp[no_of_digits + 1] = words[i][count_letters - 1];
            temp[no_of_digits + 2] = '\0';
            cout<<temp<<endl;
        }
    }
    return 0;
}
