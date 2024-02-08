/*A phrase is a palindrome if, after converting all uppercase letters 
 * into lowercase letters and removing all non-alphanumeric characters, 
 * it reads the same forward and backward. Alphanumeric characters 
 * include letters and numbers.
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * Example 1:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * Constraints:
 * 1 <= s.length <= 2 * 105
 * s consists only of printable ASCII characters.*/

/*Solution: Use two pointers*/

bool isChar(char a)
{
    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSame(char a, char b)
{
    if(a>='A'&&a<='Z'){
        a=a+32;
    }
    if(b>='A'&&b<='Z'){
        b=b+32;
    }
    printf("%c %c", a,b);
    return a==b;
}

bool isPalindrome(char* s) {
    int32_t length=0;
    while(s[length]!='\0')
    {
        length++;
    }
    for(int32_t i=0, j=length-1;i<j;i++,j--){
        while(i<j && !isChar(s[i]))
        {
            i++;
        }

        while(j>i && !isChar(s[j]))
        {
            j--;
        }
        printf("hey %d %c %d %c \n", i, s[i], j, s[j]);
        if(!isSame(s[i],s[j]))
        {
            return false;
        }
    }
    return true;
}
