#ifndef _PROJECT_HEADER_
#define _PROJECT_HEADER_

#include <stdio.h>

//edition,edition_id,country_noc,sport,event,result_id,athlete,athlete_id,pos,medal,isTeamSport,age
struct Data
{
    char    edition[255];
    int     edition_id;
    char    country_noc[50];
    char    sport[50];
    char    event[255];
    int     result_id;
    char    athlete[255];
    int     athlete_id;
    int     pos;
    char    medal[50];
    char    isTeamSport[50];
    int     age;
};

int getEditionID(const char* edition);

int readFile();









#endif //_PROJECT_HEADER_
