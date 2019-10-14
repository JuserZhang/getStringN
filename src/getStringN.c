#include<stdio.h>
#include<stdlib.h>

int str_len(char* buff)
{
    char *p = buff;
    int i = 0;
    while ((*p != '\n') && (*p != '\r') && (*p != ' ') && (*p != '\0') )
    {
        p++;
        i++;
    }
    return i;
}

int main(int argc, char **argv)
{
    char *file_name;
    char *save_name;
    int count;
    char buff[128];
    int string_len=0;
    int i = 0 , j = 0;

    FILE *fp, *fp_save;

    if(argc != 4)
    {
       printf("Usage: %s [src] [dest] [count]\n",argv[0]);
       return 0;
    }

    file_name=argv[1];
    save_name=argv[2];
    count=atoi(argv[3]);
    if (count <= 0)
    {
        printf("The fourth argument must be an integer greater than 0\n");
        return -1;
    }

    fp = fopen(file_name, "r");
    if (fp == NULL )
    {
        printf("open file fail\n");
        return -1;
    }

    fp_save = fopen(save_name, "w");
    if(fp_save == NULL)
    {
        printf("File already exist, choose another\n");
		return 1;
    }

    printf("-------begin---------\n");
    while(!feof(fp) && !ferror(fp))
    {
        i++;
        fgets(buff,sizeof(buff),fp);
        string_len = str_len(buff);
        if(string_len >= count)
        {
            j++;
            fputs(buff,fp_save);
            //printf("%d %s",string_len, buff);
        }
    }
    printf("total: %d\n",i);
    printf("gether than %d: %d\n",count,j);
    printf("---------end---------\n");
    fclose(fp);
    fclose(fp_save);

    return 0;
}
