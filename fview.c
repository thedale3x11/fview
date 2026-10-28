#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct show_config
{
    int show_chars_count;
    int show_lines_count;
    int show_content;
};

int check_input(int);

void get_show_config(struct show_config *,char *);

int main(int argc, char **argv)
{

    if (check_input(argc) > 0)
    {
        exit(1);
    }

    // 1 create file variable
    FILE *of;

    // 2 open file
    if ((of = fopen(argv[2], "r")) == NULL)
    {

        printf("This file does not exist\n");
        exit(1);
    }

    int c, count_chars, count_lines;

    count_chars = 0;
    count_lines = 1;
    struct show_config *p_sc=malloc(sizeof(struct show_config));
    printf("sc address(0): %d\n",p_sc);

    get_show_config(p_sc, argv[1]);
    printf("sc address(1): %d\n",p_sc);

    // 3 read file string by string
    while ((c = fgetc(of)) != EOF)
    {
        // 4 print string
        if (c == '\n')
        {
            count_lines++;
        }
        else
        {
            count_chars++;
        }
        if(p_sc->show_content==1){
            fputc(c, stdout);
        }
    }
    
    if(p_sc->show_content==1){
        fputc('\n',stdout);
    }

    if(p_sc->show_lines_count==1){
        printf("lines count: %d\n", count_lines);
    }

    if(p_sc->show_chars_count==1){
        printf("chars count: %d\n", count_chars);
    }

    free(p_sc);
    
    // 5 close the file
    fclose(of);

    return 0;
}

int check_input(int argc)
{
    if (argc < 2)
    {
        printf("Usage: hitxt filename");
        return 1;
    }
    return 0;
}

void get_show_config(struct show_config *p_sc,char *argv)
{   
    p_sc->show_chars_count=0;
    p_sc->show_content=0;
    p_sc->show_lines_count=0;


    printf("sc address (in function): %d\n",p_sc);

    int i;

    for (i = 0; i < strlen(argv); i++)
    {
        if (argv[i] == 'v')
        {
            p_sc->show_content=1;
        }

        if (argv[i] == 'c')
        {
            p_sc->show_chars_count=1;
        }

        if (argv[i] == 'l')
        {
            p_sc->show_lines_count=1;
        }
    }
}