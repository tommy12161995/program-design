#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct data_struct;
typedef struct listnode ListNode;


typedef struct
{
    char name[10];
    int student_ID;
    int chinese;
    int english;
    int math;
    int science;
    int social_study;
    int sum;
} data_struct;
typedef struct listnode
{
    data_struct data;
    struct listnode *next;
} ListNode;


#endif // STRUCT_H_INCLUDED
