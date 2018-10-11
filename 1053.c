#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct N
    {
        long id;
        int vote;
        struct N* next;
    }recordes;
    long tmp;
    int m;
    long n;
    int i, j, flag;
    scanf("%ld %d",&n, &m);

    recordes* head = (recordes*)malloc(sizeof(recordes));
    recordes* p;
    head->next = NULL;
    for(i = 0; i < m; i++)
    {
        flag = 0;
        scanf("%ld", &tmp);
        for(p = head; p->next != NULL; p = p->next)
        {
            if(tmp == p->id)
            {
                p->vote++;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            p->id = tmp;
            p->vote = 1;
            p->next = (recordes*)malloc(sizeof(recordes));
            p->next->next = NULL;
        }
    }
    for(p = head; p->next != NULL; p = p->next)
    {
        flag = 0;
        if(p->vote > m/2)
        {
            printf("%ld\n",p->id);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("-1");
    }
    return 0;
}
