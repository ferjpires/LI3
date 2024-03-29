#include "program/menu_mode.h"

#include <ncurses.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "queries/query_manager.h"
#include "data_manager/parser.h"
#include "data_manager/validater.h"
#include "entities/user.h"
#include "entities/flight.h"
#include "entities/reservation.h"
#include "entities/airport.h"
#include "catalogs/hotels_catalog.h"
#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "utils/utils.h"
#include "stats/metrics_catalog.h"
                                 
// =============== Auxiliar Functions ===============

// Get user input
int get_user_input(char *path, int i, int y, int x) {
    int ch = 0;

    while ((ch = getch()) != '\n') {
        if (i>=63 && (isprint(ch))) continue;
        if (ch == 27) {  // escape key
            return (-1);   // Break out of the loop if Escape is pressed
        }
        if (isprint(ch)) {
            //Print each character user writes
            path[i++] = ch;
            mvaddch(y, x+i, ch);
        } else if (ch == KEY_BACKSPACE || ch == 127) { 
            // If backspace erase last character
            if (i > 0) {
                mvprintw(y, i+x, " ");
                move(y, i+x);
                path[--i] = '\0';
            }
        }
        refresh();
    }
    path[i] = '\0';
    return i;
}

// Delete input
void delete_user_input(char *path, int i, int y, int x) {
    while (i>0) {
        mvprintw(y, i+x, " ");
        i--;
    }
    move(y, i+x+1);
    path[i]= '\0';
    refresh();
}

// Draw a box without borders
void box_draw (int box_starty, int box_startx, int box_height1, int box_width1) {
    int i=0;
    for (i = box_starty; i < box_starty + box_height1; ++i) {
        for (int j = box_startx; j < box_startx + box_width1; ++j) {
            mvaddch(i, j, ' ');
        }
    }
}

void clean_line(int y) {
    for (int i = 0; i < COLS; i++) {
        mvaddch(y, i, ' ');
    }
}

int center_print(char *text, int starty, int highlight) {
    if (text == NULL) return starty;

    int textLength = strlen(text);
    int startxCentered;

    if (highlight == 1) {
        attron(A_BOLD | A_STANDOUT);
    }

    
    if (textLength >= COLS) {
        
        int i, j;
        for (i = 0, j = 0; i < textLength; i++, j++) {
            if (j == COLS-1) {
                startxCentered = (COLS-j)/2;
                mvprintw(starty++, startxCentered, "%.*s", COLS-1, text + i - j);
                j = 0;
            }
        }

        center_print(text+i-j, starty, highlight);
    } else {
        startxCentered = (COLS-textLength)/2;
        mvprintw(starty, startxCentered, "%s", text);
    }

    if (highlight == 1) {
        attroff(A_BOLD | A_STANDOUT);
    }
    starty++;

    refresh();
    return starty;
}

void query_choice (int query) {

    int starty2= ((LINES-4)/2) - 7;

        starty2=center_print("Escolhe a opção que pretendes executar",starty2, 1);
        starty2+=1; 
        starty2=center_print("Clica [KEY UP] ou [KEY DOWN] para mudar de opção.", starty2, 1);
        starty2=center_print("Clica [ESC] para sair. Clica [ENTER] para executar a página pretendida", starty2, 1);
        starty2+=1; 
        switch (query) {
            case 1:
                starty2=center_print("Query 1 - Resumo de dados", starty2,1);
                starty2+=2;
                starty2=center_print("Listar o resumo de um utilizador, voo, ou reserva, consoante o identificador recebido por argumento.", starty2,0);
                starty2=center_print("Garantido que não existem identificadores repetidos entre as diferentes entidades.", starty2,0);
                refresh();
                break;
            case 2:
                starty2=center_print("Query 2 - Listar voos e reservas de utilizador", starty2,1);
                starty2+=2;
                starty2=center_print("Listar os voos ou reservas de um utilizador, se o segundo argumento for flights ou reservations,respetivamente, ordenados por data.", starty2,0);
                starty2=center_print("Caso não seja fornecido um segundo argumento, apresentar voos e reservas, juntamente com o tipo.", starty2,0);
                refresh();
                break;
            case 3:                                       
                starty2=center_print("Query 3 - Classificação média de um hotel.", starty2,1);
                starty2+=2;
                starty2=center_print("Apresentar a classificação média de um hotel, a partir do seu identificador.", starty2,0);
                refresh();
                break;
            case 4:
                starty2=center_print("Query 4 - Listar as reservas de um hotel num intervalo de tempo", starty2,1);
                starty2+=2;
                starty2=center_print("Listar as reservas de um hotel, ordenadas por data de início.", starty2,0);
                starty2=center_print("Caso duas reservas tenham a mesma data, deve ser usado o identificador da reserva como critério de desempate.", starty2,0);
                refresh();
                break;
            case 5:
                starty2=center_print("Query 5 - Voos com origem num aeropoto num intervalo de tempo", starty2,1);
                starty2+=2;
                starty2=center_print("Listar os voos com origem num dado aeroporto, entre duas datas, ordenados por data de partida estimada.", starty2,0);
                starty2=center_print("Caso dois voos tenham a mesma data, o identificador do voo deverá ser usado como critério de desempate.", starty2,0);
                refresh();
                break;
            case 6:
                starty2=center_print("Query 6 - Listar top N aeroportos por número de passageiros", starty2,1);
                starty2+=2;
                starty2=center_print("Listar o top N aeroportos com mais passageiros, para um dado ano. Deverão ser contabilizados os voos com a data estimada de partida nesse ano.", starty2,0);
                starty2=center_print("Caso dois aeroportos tenham o mesmo valor, deverá ser usado o nome do aeroporto como critério de desempate.", starty2,0);
                refresh();
                break;
            case 7:
                starty2=center_print("Query 7 - Listar o top N aeroportos com a maior mediana de atrasos", starty2,1);
                starty2+=2;
                starty2=center_print("Listar o top N aeroportos com a maior mediana de atrasos (diferença entre a data estimada e a data real de partida).", starty2,0);
                starty2=center_print("Caso dois aeroportos tenham a mesma mediana, o nome do aeroporto deverá ser usado como critério de desempate.", starty2,0);
                refresh();
                break;
            case 8:
                starty2=center_print("Query 8 - Receita total de um hotel num intervalo de tempo", starty2,1);
                starty2+=2;
                starty2=center_print("Apresentar a receita total de um hotel entre duas datas (inclusive), a partir do seu identificador.", starty2,0);
                starty2=center_print("As receitas de um hotel devem considerar apenas o preço por noite de todas as reservas com noites entre as duas datas.", starty2,0);
                refresh();
                break;
            case 9:
                starty2=center_print("Query 9 - Listar utilizadores por prefixo do nome", starty2,1);
                starty2+=2;
                starty2=center_print("Listar todos os utilizadores cujo nome começa com o prefixo passado por argumento, ordenados por nome.", starty2,0);
                starty2=center_print("Utilizadores inativos não deverão ser considerados pela pesquisa.", starty2,0);
                refresh();
                break;
            case 10:
                starty2=center_print("Query 10 - Apresentação de métricas gerais", starty2,1);
                starty2+=2;
                starty2=center_print("Métricas são número de novos utilizadores registados; número de voos; número de passageiros; número de passageiros únicos; e número de reservas.", starty2,0);
                refresh();
                break;
        }
}

void exec_asked(int query){
    clear();
    refresh();
    
    int starty3 = ((LINES-4)/2)-6;

    switch (query) {
        case 1:
            starty3 =center_print("Query 1 - Resumo de dados", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o identificador do utilizador, voo ou reserva correspondente.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 1{F} <Identificador>", starty3, 0);
            starty3 =center_print("Exemplo: 1F DGarcia429, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 2:
            starty3 =center_print("Query 2 - Listar voos ou reservas de utilizador", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o identificador do utilizador e tipo correspondente.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT: 2{F} <Identificador> <Tipo (flights ou reservations)>", starty3, 0);
            starty3 =center_print("Exemplo: 2F JéssiTavares910 flights, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 3:
            starty3 =center_print("Query 3 - Classificação média de um hotel.", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o identificador do hotel correspondente.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 3{F} <Identificador>", starty3, 0);
            starty3 =center_print("Exemplo: 3F HTL1001, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 4:
            starty3 =center_print("Query 4 - Listar as reservas de um hotel num intervalo de tempo", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o identificador do hotel correspondente.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 4{F} <Identificador>", starty3, 0);
            starty3 =center_print("Exemplo: 4F HTL1003, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 5:
            starty3 =center_print("Query 5 - Voos com origem num aeroporto num intervalo de tempo", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o identificador do aeroporto e datas correspondentes.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 5{F} <Identificador> <Data inicial> <Data final>", starty3, 0);
            starty3 =center_print("Exemplo: 5F LIS \"2021/01/01 00:00:00\" \"2022/12/31 23:59:59\", {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 6:
            starty3 =center_print("Query 6 - Listar top N aeroportos por número de passageiros", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o ano e número de aeroportos correspondentes.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 6{F} <Ano> <Número de aeroportos>", starty3, 0);
            starty3 =center_print("Exemplo: 6F 2021 10, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);

            refresh();
            break;

        case 7:
            starty3 =center_print("Query 7 - Listar o top N aeroportos com a maior mediana de atrasos", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o número de aeroportos correspondente.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 7{F} <Número de aeroportos>", starty3, 0);
            starty3 =center_print("Exemplo: 7F 20, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 8:
            starty3 =center_print("Query 8 - Receita total de um hotel num intervalo de tempo", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o identificador do hotel e datas correspondentes.", starty3, 0);
            starty3 =center_print("Caso não exista, será apresentada uma mensagem de erro.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 8{F} <Identificador> <Data inicial> <Data final>", starty3, 0);
            starty3 =center_print("Exemplo: 8F HTL1001 2023/05/02 2023/05/02, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 9:
            starty3 =center_print("Query 9 - Listar utilizadores por prefixo do nome", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, escreva o prefixo do nome correspondente.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 9{F} <Prefixo>", starty3, 0);
            starty3 =center_print("Exemplo: 9F Julia, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

        case 10:
            starty3 =center_print("Query 10 - Métricas gerais da aplicação", starty3, 1);
            starty3+=2;
            starty3 =center_print("Para executar esta query, pode não escrever nada e terá todas as métricas.", starty3, 0);
            starty3 =center_print("Ou pode escrever apenas o ano, ou ano e mês para obter para os intervalos desejados.", starty3, 0);
            starty3+=2;
            starty3 =center_print("INPUT : 10{F} [ano [mês]]", starty3, 0);
            starty3 =center_print("Exemplo: 10F 2023 10, {F} apenas mostra os resultados de forma estruturada, pode retirar", starty3, 0);
            refresh();
            break;

    }
}
int verify_input(int query, char* query_input) {
    // Val corresponde ao tipo de erro
    int val=0;
    
    // int de paragem
    int p=1;
    
    char arg1[4], arg2[20], arg3[20];

    char *aux = g_strdup (query_input);
    char *ptr = aux;
    char *token;

    for (int i=0; i<5 && p==1 && val==0 ; i++) {
        token = strsep(&ptr, " ");
        if (token==NULL || *token == '\0') p=0;
        switch (query){
            case 1:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "1")!=0 && g_strcmp0(token, "1F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==0) val=-1;
                    }
                    else if (p==1) val=-1;
                }
                break;
            case 2:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "2")!=0 && g_strcmp0(token, "2F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==0) val=-1;
                    }
                    else {
                        if (i==2) {
                            if (p==1 && (g_strcmp0(token, "reservations")!=0 && g_strcmp0(token, "flights")!=0)) {val=3;p=0;}
                        }
                        else if (p==1) val=-1;
                    }
                }
                break;
            case 3:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "3")!=0 && g_strcmp0(token, "3F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==0) val=-1;
                    }
                    else if (p==1) val=-1;
                }
                break;
            case 4:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "4")!=0 && g_strcmp0(token, "4F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==0) val=-1;
                    }
                    else if (p==1) val=-1;
                }
                break;
            case 5:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "5")!=0 && g_strcmp0(token, "5F")!=0)) val=1;
                }
                p=0;
                /* else {
                    if (i==1){
                        if (p==0) val=-1;
                        else if (is_airport_name_valid(token)==0) val=2;  
                    }
                    else {
                        if (i==2 || i==3) {
                            if (p==0) val=-1;
                            else if (is_valid_date_with_time(token)==0) val=i+1;
                        }
                        else if (p==1) val=-1;
                    }
                } */
                break;
            case 6:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "6")!=0 && g_strcmp0(token, "6F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==0) val=-1;
                        else if (g_strcmp0(token, "9999")>=0 || g_strcmp0(token, "1900")<=0) val=2;
                    }
                    else {
                        if (i==2) {
                            if (p==0) val=-1;
                        }
                        else if (p==1) val=-1;
                    }
                }
                break;
            case 7:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "7")!=0 && g_strcmp0(token, "7F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==0) val=-1;
                    }
                    else if (p==1) {val=-1;p=0;}
                }
                break;
            case 8:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "8")!=0 && g_strcmp0(token, "8F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==0) val=-1;
                    }
                    else {
                        if (i==2 || i==3) {
                            if (p==0) val=-1;
                            else if (is_valid_date(token)==0) val=i+1;
                        }
                        else if (p==1) val=-1;
                    }
                }
                break;
            case 9:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "9")!=0 && g_strcmp0(token, "9F")!=0)) val=1;
                }
                p=0;
                /* else {
                    if (i==1){
                        if (p==0) val=-1;
                    }
                    else if (p==1) val=-1;
                } */
                break;
            case 10:
                if (i==0) {
                    if (p==0) val=-1;
                    else if ((g_strcmp0(token, "10")!=0 && g_strcmp0(token, "10F")!=0)) val=1;
                }
                else {
                    if (i==1){
                        if (p==1 && (g_strcmp0(token, "9999")>=0 || g_strcmp0(token, "1900")<=0)) val=2;
                    }
                    else {
                        if (i==2) {
                            if (p==1 && (g_strcmp0(token, "12")>0 || g_strcmp0(token, "1")<0)) val=3;
                        }
                        else if (p==1) val=-1;
                    }
                }
                break;
        }

    }
    
    if (query==5) {
        sscanf(ptr, "%3s \"%19[^\"]\" \"%19[^\"]\"", arg1, arg2, arg3);

        if (is_airport_name_valid(arg1)==0) val=2; 
        else if (is_valid_date_with_time(arg2)==0) val=3;
        else if (is_valid_date_with_time(arg3)==0) val=4;
    }


    if (aux!=NULL) free (aux);
    return val;
} 

int print_result(int numPedidos) {
    clear();

    char nome[100];
    char linha[100];

    sprintf(nome, "Resultados/command%d_output.txt", numPedidos);
    FILE *f = fopen(nome, "r");
    if (f == NULL) {
        return 3;
    }

    int max_linhas, max_colunas;
    getmaxyx(stdscr, max_linhas, max_colunas);

    int margem = max_colunas / 10;
    
    int page=1;
    int linha_atual = 1;
    int linha_escrita;
    int max_escrita = (max_linhas-6);
    
    int fim=0;
    int p=1;
    
    int ch;
    while (fim==0) {

        linha_escrita=2;

        if (p==1) { 
            clear();
            center_print("RESULTADO", 1, 1);
            while (fgets(linha, sizeof(linha), f) != NULL) {
                if (linha_atual <= (max_escrita*page) && linha_atual>((max_escrita)*(page-1))) {
                    mvprintw(linha_escrita, margem, "%s", linha);
                    linha_escrita++;
                }
                linha_atual++;
                if (linha_atual > max_escrita*page) break;

            }
            center_print("[KEY UP] or [KEY DOWN] to navigate, [ESC] to exit", max_linhas - 2, 0);
            refresh();
        }
        p=1;

        ch=getch();

        switch (ch) {
            case KEY_UP:
                if (page > 1) {
                    page--;
                    linha_atual = 1;
                    rewind(f); // volta ao ínicio do arquivo
                }
                else p=0;
                break;
            case KEY_DOWN:
                if (linha_atual>max_escrita*page) {
                    page++;
                }
                else p=0;
                break;
            case 27:
                fim=1;
                break;
            default:
                p=0;
                break;    
        }
    }

    fclose(f);
    return 2;
}


void exec_menu_mode(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, METRICS_CATALOG metrics) {
    // Initialize ncurses

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    
    // Colors
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // black text on a white background (1)
    init_pair(2, COLOR_RED, COLOR_WHITE); // red text on a white background (2)
    init_pair(3, COLOR_RED, COLOR_BLACK); // red text on a black background (3)
    
    int screen=1;
    int numPedidos = 0;
    int parser_done = 0;
    int erro = 0;
    
    while (screen==1 && parser_done==0) {
        
        
        //====== Screen 1 ======
        int height1 = 3;
        int width1 = 64;
        int starty1 = (LINES - height1) / 2; 
        int startx1 = (COLS - width1) / 2;   


        // Buffer for the path
        char *path = malloc (64 * sizeof(char));
        if (path==NULL) {
            screen=-1;
            break;
        }
        int index1=0;

        FILE *users_csv=NULL;
        FILE *flights_csv=NULL;
        FILE *passengers_csv=NULL;
        FILE *reservations_csv=NULL;

        int p=1;
        
        while (p==1) {
            clear();
            
            attron(COLOR_PAIR(1));
            box_draw(starty1-5,startx1-5, height1+10, width1+8);
            attroff(COLOR_PAIR(1));

            box_draw(starty1,startx1, height1, width1);

            attron(COLOR_PAIR(1));
            mvprintw(starty1 - 2, startx1, "Indica o Path para o dataset: ");
            mvprintw(starty1 + height1 + 2, startx1, "(Exemplo: dataset/data_clean)");
            mvprintw(starty1 + height1 + 3, startx1, "Clica [ESC] para sair.");
            attroff(COLOR_PAIR(1));
            
            attron(COLOR_PAIR(2));
            if (erro==1) mvprintw(starty1 + height1 + 1, startx1, "Path errado. Escreve de novo!");
            attroff(COLOR_PAIR(2));
            erro=0;
            
            // Cursor vísivel
            curs_set(1);
            move(starty1+1, startx1+1);
            refresh();

            // Input do user
            index1=get_user_input(path, index1, starty1+1, startx1);

            if (index1==(-1)) {screen=-1; break;}

            // Opening all csv's

            // Opens users.csv
            users_csv = open_csv (path, "users.csv");
            if (users_csv == NULL) {
                path[0]='\0';
                index1=0;
                erro=1;
                refresh();
                continue;
            }

            // Opens flights.csv
            flights_csv = open_csv (path, "flights.csv");
            if (flights_csv == NULL) {
                path[0]='\0';
                index1=0;
                erro=1;
                refresh();
                if (users_csv!=NULL) fclose(users_csv);
                continue;
            }

            // Opens passengers.csv
            passengers_csv = open_csv (path, "passengers.csv");
            if (passengers_csv == NULL) {
                path[0]='\0';
                index1=0;
                erro=1;
                refresh();
                if (users_csv!=NULL) fclose(users_csv);
                if (flights_csv!=NULL) fclose(flights_csv);
                continue;
            }

            // Opens reservations.csv
            reservations_csv = open_csv (path, "reservations.csv");
            if (reservations_csv == NULL) {
                path[0]='\0';
                index1=0;
                erro=1;           
                refresh();
                if (users_csv!=NULL) fclose(users_csv);
                if (flights_csv!=NULL) fclose(flights_csv);
                if (passengers_csv!=NULL) fclose(passengers_csv);
                continue;
            }
            // p=0 para verificar se abriu tudo com sucesso
            p=0;

            //Cursor não vísivel
            curs_set(0);



            //====== Screen 2 ======
            screen++;


            int key;
            int query=1;
            
            while (screen >= 2) {
                clear ();
                refresh();

                if (screen==2) {
                    query_choice (query);
                    

                    key=getch();
                    switch (key) {
                        case KEY_UP:
                            if (query == 1) query = 10;
                            else query--;
                            break;
                        case KEY_DOWN:
                            if (query == 10) query = 1;
                            else query++;
                            break;
                        case '\n':
                            screen=3;
                            break;
                        case 27:
                            screen=1;
                            break;
                    }
                }

                else {
                // Screen anterior
                    if (screen==1) break;
                    //Screen posterior
                    else {

                        //====== Screen 3 ======
                        if (screen==3) {
                            
                            int p3=5;

                            int index3=0;
                            char *query_input= malloc (64 * sizeof(char));

                            if (query_input==NULL) {
                                screen=-1;
                                break;
                            }

                            refresh();
                            
                            while (p3!=0) {
                                clear();
                                refresh();

                                int starty3 = (LINES - 4)/2 +9; 
                                int startx3 = (COLS - 50) / 2;

                                exec_asked(query);

                                starty3 =center_print("|ESCREVA O SEU INPUT AQUI|", starty3, 0);
                                starty3 =center_print("V                        V", starty3, 0);
                                int inp=starty3+1;
                                attron(COLOR_PAIR(3));
                                    if (p3==-1) starty3 =center_print("Número de argumentos inválido.", starty3+2, 0);
                                    else if (p3==1) starty3 =center_print("Primeiro argumento inválido.", starty3+2, 0);
                                    else if (p3==2) starty3 =center_print("Segundo argumento inválido.", starty3+2, 0);
                                    else if (p3==3) starty3 =center_print("Terceiro argumento inválido.", starty3+2, 0);
                                    else if (p3==4) starty3 =center_print("Quarto argumento inválido.", starty3+2, 0);
                                    else if (erro==5) {starty3 =center_print("Erro ao abrir ficheiro de resultados.", starty3+2, 0);erro=0;}
                                attroff(COLOR_PAIR(3));
                                query_input[0]='\0';
                                index3=0;

                                //Cursor vísivel
                                curs_set(1);
                                move(inp, startx3+1);
                                refresh();

                                index3 = get_user_input(query_input, index3, inp, startx3);

                                if (index3==(-1)) {screen=2;p3=0;}
                                else {
                                    p3=0;
                                    p3=verify_input(query,query_input);
                                    if (p3==0) screen=4;
                                }
                            }

                            //Cursor não vísivel
                            curs_set(0);

                            clear();
                            refresh();

                            
                            //====== Screen 4 ======
                            if (screen==4) {

                                numPedidos++;

                                if (parser_done == 0) parser(users_catalog, flights_catalog, reservations_catalog, airports_catalog,hotels_catalog, users_csv, flights_csv, reservations_csv, passengers_csv, metrics);
                                parser_done=1;
                                process_line(query_input, numPedidos, users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, metrics);

                                screen = print_result(numPedidos);
                                if (screen==3) erro=5;
                                
                                screen=2;
                            }

                            free (query_input);
                        }

                    }
                }
            }
                        
        }
        clear ();
        free (path);
        if (users_csv!=NULL) fclose(users_csv);
        if (flights_csv!=NULL) fclose(flights_csv);
        if (passengers_csv!=NULL) fclose(passengers_csv);
        if (reservations_csv!=NULL) fclose(reservations_csv);
    }
    
    endwin();
}

