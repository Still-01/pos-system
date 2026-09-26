#include <stdio.h>
#include <string.h>
char input[11]={0};//输入的字符串
double price[3]={3.50, 0.50, 6.00};//价格数组
int number[3]={0};//数量数组//通过数组实现了对多个变量的操控
int id=0;
int sign=1;//sign为1表示增加，-1表示减少,由此避开定义两个函数的麻烦
int sale=0;
char password[6]={0};
char name[3][10]={"Cola", "Lollipop", "Noodles"};//商品名称数组
  void item(int a){
          if(sign == 1) number[a]++; 
          else if(sign == -1 && number[a] > 0) number[a]--;
          printf("%-10s %.2f*%d   =%.2f\n", name[a], price[a], number[a], price[a] * number[a]);
          //计算价格并展示
        }
        //商品记价函数
 void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // 把当前行剩余字符读走丢掉
    }}
    //清除输入缓冲区函数
  void clear_item(void) {
    for (int i = 0; i < 3; i++) {
        number[i] = 0;
    }
    }
    //清除商品数量函数
    void print_bill(void) {
        sign=0;
            for(int i=0; i<3; i++)
            {if(number[i] > 0)
                item(i);
            }
           printf("--------------------------\n");
           printf("Total               =%.2f\n", price[0]*number[0]+price[1]*number[1]+price[2]*number[2]);
           }  
            //打印小票函数
int main(void)
 

{   FILE *fp=fopen("sales.txt","a");
    fprintf(fp, "New sale:\n\n");
    fclose(fp);
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
   }
   //密码系统

     while(1)
    {   sign=1; 
        scanf("%10s", input);
        clear_input(); 
        if(strcmp(input, "exit") == 0|| strcmp(input, "quit") == 0)
        {printf("Thank you for using the Pos-system!\n");
            break;
        }
        //退出指令
        if(input[0]=='-')
        {sign = -1;
            if(input[1] == '0' && input[2] == '0' && strlen(input) == 4)//讨论输入形式为-00x
            {if(input[3] >= '1' && input[3] <= '3')
                {id = input[3] - '1';//将输入的字符转换为对应的数组下标
                item(id);
                }
                else printf("Error: Item not found\n");}
              else printf("Error: Invalid input\n");//无效指令
              sign = 1;//将sign恢复为1，避免影响下一次输入  
        }
        else  if(input[0] == '0' && input[1] == '0' && strlen(input) == 3)//再讨论输入形式为00x
        {if(input[2] >= '1' && input[2] <= '3')
            {id = input[2] - '1';//将输入的字符转换为对应的数组下标
            item(id);
            }
            else printf("Error: Item not found\n");}
        //记录商品
        else if(strcmp(input,"prices") == 0)//考虑输入的是其他指令
        {   printf("Item      No.        Pri.\n");
            printf("----------------------------\n");
            printf("Cola      001        %.2f\n", price[0]);
            printf("Lollipop  002        %.2f\n", price[1]);
            printf("Noodles   003        %.2f\n", price[2]);
        }
        //表格打印
        else if (strcmp(input,"print") == 0&&(number[0] > 0 || number[1] > 0 || number[2] > 0))
        {   print_bill();
        }
        else if(strcmp(input,"print") == 0&&(number[0] == 0 && number[1] == 0 && number[2] == 0))
        {
            printf("Error: No items to print\n");
        }
        //打印小票
        else if(strcmp(input,"drop") == 0) 
        {clear_item();
        }
        else if(strcmp(input,"checkout") == 0&&(number[0] > 0 || number[1] > 0 || number[2] > 0))
        {printf("Receipt:\n");
            printf("Item       Pri. Qty Amount\n");
         printf("--------------------------\n");
          print_bill();
           fp=fopen("sales.txt","a");
           fprintf(fp, "No.     Items        Amount\n");
          sale++;
           fprintf(fp,"%d",sale); 
            if(number[0] > 0)
            fprintf(fp,"       %-10s   %.2f\n", name[0], price[0]*number[0]);
            if(number[1] > 0)
            fprintf(fp,"        %-10s   %.2f\n", name[1], price[1]*number[1]);
            if(number[2] > 0)
            fprintf(fp,"        %-10s   %.2f\n", name[2], price[2]*number[2]);
            fprintf(fp,"--------------------------\n");
            fprintf(fp,"Total:               %.2f\n\n", price[0]*number[0]+price[1]*number[1]+price[2]*number[2]);
            clear_item();
            fclose(fp);
    }
         else if(strcmp(input,"checkout") == 0&&(number[0] == 0 && number[1] == 0 && number[2] == 0))
        {
            printf("Error: No items to checkout\n");
        }
        else if(strcmp(input, "sales") == 0) {
        fp = fopen("sales.txt", "r");
        char line[200];
        printf("Sales Records:\n");
        while (fgets(line, sizeof(line), fp) != NULL)
         {
            printf("%s", line);  
    }
   fclose(fp);
}
        else printf("Error: Invalid input\n");//无效指令
      } 
      
      return 0;
} 