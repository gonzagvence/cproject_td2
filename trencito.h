#ifndef _TRENCITO_HH_
#define _TRENCITO_HH_

#include <stdio.h>
#include <stdlib.h>

struct node {
    char* name;
    int group;
    struct node* next;
};

struct trainDance {
    struct node* first;
    int count;
};

char* strDuplicate(char* src);

int strCompare(char* str1, char* str2);

char* strConcatenate(char* src1, char* src2);

struct trainDance* trainDanceNew(char* name1, int group1, char* name2, int group2);

struct node* trainDanceGetNode(struct trainDance* train, char* name1);

int trainDanceGroupCount(struct trainDance* train, int group);

char* trainDanceGetNames(struct trainDance* train, char* separator);

int trainDanceAddToDance(struct trainDance* train, char* name1, char* name2, char* nameNew, int groupNew);

int trainDanceImTired(struct trainDance* train, char* name);

void trainDanceGotToMosh(struct trainDance** train, struct trainDance** trainMosh, struct trainDance** trainRemains, int groupMosh);

void trainDanceDelete(struct trainDance* train);

void trainDancePrint(struct trainDance* train);

#endif
