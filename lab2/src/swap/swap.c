void Swap(char *left, char *right) 
{
 char buff; 
 char buff2;
 buff = *right;
 buff2 = *left; 
 *left = buff;
 *right = buff2; 
}
