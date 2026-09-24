#include <stdio.h>
#include <string.h>
char input[11]={0};//输入的字符串
double price[3]={3.50, 0.50, 6.00};//价格数组
int number[3]={0};//数量数组//通过数组实现了对多个变量的操控
int id=0;
char password[6]={0};
char name[3][10]={"Cola", "Lollipop", "Noodles"};//商品名称数组
 void  f(int a){
            printf("%-10s% .2f\n", name[a], price[a]);//格式对齐
            number[a]++;
        }
 void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // 把当前行剩余字符读走丢掉
    }
}   
int main(void)
 

{
   printf("Welcome to the Pos-system!\nPlease enter the password:\n");
   while(1){
    scanf("%5s", password);
    clear_input();
   if(strcmp(password, "1037") == 0)
    {
    printf("Password correct!\nPlease enter the command:\n");
    break;
    }
    else
    {   
        printf("Error: Incorrect password\nPlease enter the password again:\n");
    }
   }//密码系统

     while(1)
    {   scanf("%10s", input);
        clear_input(); 
        if(strcmp(input, "exit") == 0|| strcmp(input, "quit") == 0)
        {printf("Thank you for using the Pos-system!\n");
            break;
        }
        else  if(input[0] == '0' && input[1] == '0' && strlen(input) == 3)//先讨论输入形式为00x
        {if(input[2] >= '1' && input[2] <= '3')
            {id = input[2] - '1';//将输入的字符转换为对应的数组下标
            f(id);
            }
            else printf("Error: Item not found\n");}
        else if(strcmp(input,"prices") == 0)//考虑输入的是其他指令
        {   printf("Item      No.        Pri.\n");
            printf("Cola      001        %.2f\n", price[0]);
            printf("Lollipop  002        %.2f\n", price[1]);
            printf("Noodles   003        %.2f\n", price[2]);
        }//表格打印
        else printf("Error: Invalid input\n");//无效指令
      } 
      return 0;
} 