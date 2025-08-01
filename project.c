#include "project.h"

#include <string.h>
#include <ctype.h>


#define OLYMPICS_GAMES "Olympics_Games.csv"

#define OLYMPIC_EVENT_CSV_FILENAME  "Olympic_Athlete_Event_Results.csv"

int isNumber(const char *str) {
    if (*str == '\0')  // Empty string is not a number
        return 0;

    while (*str) {
        if (!isdigit((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}

int getEditionID(const char* edition)
{
    int id = 0;
    FILE *fp = NULL;
    fp = fopen(OLYMPICS_GAMES, "r");

    if(fp == NULL ) {
        printf("Read %s file failed\n", OLYMPICS_GAMES);
    }
    else {
        //while( 1 != feof(fp)  ) {
        // int size = 30;
        // for(int i=0; i < size; i++) {
        //     char editionRead[50];
        //     int id2;
        //     if( fscanf(fp, "%[^,],%d,", editionRead, &id2) == 2 )
        //         printf("edition = %s, id=%d\n", editionRead, id2);

        //     if( 0 == strcmp(editionRead, edition) ) {
        //         printf("id = %d\n", id);
        //         id = id2;
        //     }
            
        // } 
        char row[512];  // Buffer to hold one row
        while (fgets(row, sizeof(row), fp)) {
            //printf("Read row: %s", row);  // `fgets` keeps the newline character

            if( strstr(row, edition) ) {
                char str[5];
                printf("row = %s\n", row);
                strncpy(str, row + strlen(edition)+1, 2);
                str[2] = '\0';
                if( isNumber(str) )
                    id = atoi(str);
            }
        }  
    }

    fclose(fp);
    fp = NULL;
    return id;
}

int readFile(int edition_id)
{
    FILE *fp = NULL;

    fp = fopen(OLYMPIC_EVENT_CSV_FILENAME, "r");
    if( fp == NULL ) {
        printf("Fail to open file - %s\n.", OLYMPIC_EVENT_CSV_FILENAME);
    }
    else {
        printf("Reading...\n");
        
        readFile(fp);
    }

 

    if( NULL == fp )
        return 0;

    int i;
    struct Data info[500];
    for(i = 0; i < 500 && feof(fp) != 1;) {
        fscanf(fp, "%s,%d,%s,%s,\"%s\",  %d,%s,%d,%d,%s,%s,%d",
            info[i].edition, 
            &info[i].edition_id,
            info[i].country_noc,
            info[i].sport,
            info[i].event,
            &info[i].result_id,
            info[i].athlete,
            &info[i].athlete_id,
            &info[i].pos,
            info[i].medal,
            info[i].isTeamSport,
            &info[i].age
        );

        printf("medal: %s\n", info[i].medal);

        // value in medal is '-' means no medal for this athlete. Just skip this record to check the next record. 
        if(0 != strcmp(info[i].medal, "-"))
            i++;
    }

    if(i == 500 && feof(fp)!= 1)
        printf("Error: need more memory.\n");

    fclose(fp);
    fp = NULL;
    return (i+1);
}