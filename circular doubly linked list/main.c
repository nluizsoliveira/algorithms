#include<stdio.h>
#include<readline.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<game.h>
#include<catalog.h>

int main (){
    char csv_filepath[10]= "CSV.csv";
    char mode[1] = "r";

    FILE* csv = fopen(csv_filepath, mode);

    char ghost_byte;

    fscanf(csv,"%c", &ghost_byte);
    fscanf(csv,"%c", &ghost_byte);
    fscanf(csv,"%c", &ghost_byte);
    
    char* line;
    int is_line_valid = true;
    char* name;
    char* year;
    char* company;
    
    Catalog* catalog = new_Catalog();

    while(is_line_valid){
        line = read_line_from_file(csv);
        is_line_valid = strlen(line);

        if(is_line_valid){
            name = (char*) malloc(sizeof(char) * strlen(line));
            year = (char*) malloc(sizeof(char) *strlen(line));
            company = (char*) malloc(sizeof(char) *strlen(line));
            sscanf(line, "%[^;];%[^;];%[^;]", name, year, company);
            Game* game = new_Game(name, year, company);
            add_Game_to_Catalog(game, catalog);
        }
    }

    int is_there_input = true;

    while (is_there_input) {
        char * input = read_line();

        is_there_input = strlen(input);
        if (!is_there_input) {
            return 0;
        }

        if (input[0] == 'i') {
            print_Catalog(catalog);
        }
        else if (input[0] == 'p') {
            char* company = (char*) malloc(sizeof(char) * strlen(input));
            sscanf(input, "p %[^\r\n]", company);
            print_Catalog_by_company(catalog, company);
        }
        else if (input[0] == 'r') {
            // remove todos os jogos duplicados
        }
        else if (input[0] == 'a') {
            // a 2010
            // fazo parse
            // retorna todos os jogos lançados no ano
        }
        else if (input[0] == 'f') {
            // implementar função que libera todos games dentro de catalogo. 
            // Lembrar de apontar ponteiros para NULL após dar free. 
            fclose(csv);
            return 0;
        }
        else if (input[0] == 'u') {
            // u 5
            // imprime o jogo na posição “int” do catálogo.
        }
        else if (input[0] == 'm' && input[1] == 'r') {
            // mr 3 6 
            // o usuário deve mover 6 casas para a direita o jogo que está na casa 3.
        }
        else if (input[0] == 'm' && input[1] == 'l') {
            // ml 3 6 
            // o usuário deve mover 6 casas para a esquerda o jogo que está na casa 3.
        }
    }

}
