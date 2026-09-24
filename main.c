#include <stdio.h>
#include <string.h>
int main()
{
    char input[11]={0};
    while(1)
    {
        scanf("%10s", input);
        if(strcmp(input, "exit") == 0)
        {
            break;
        }
        else if(strcmp(input, "001") == 0)
        {
            printf("Cola     3.50\n");
        }
        
        else if(strcmp(input, "002") == 0)
        {
            printf("Lollipop    0.50\n");
        }
        else if(strcmp(input, "003") == 0)
        {
            printf("Noodles    6.00\n");
        }
        else if(strcmp(input,"prices") == 0)
        {   printf("Item      No.        Pri.\n");
            printf("Cola      001        3.50\n");
            printf("Lollipop  002        0.50\n");
            printf("Noodles   003        6.00\n");
        }
        else if(input[0] == '0' && input[1] == '0' && strlen(input) == 3)
        {
            printf("Error: Item not found\n");
        }
        else
        {
            printf("Error: Invalid input\n");
}
    }
    return 0;
}