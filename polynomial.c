/* Purpose:Aplication of singly linked list
Problem statement: polynomial operation
1. Polynomial Addition
2. Polynomial subtraction
3. Polynomial Multiplication
Author: Pranav Vashisth*/
#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int pow;
    int coff;
    struct poly *next;
} node;
node *create(node *start, int n)
{
    node *temp = NULL, *newnode = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the Power: ");
        scanf("%d", &newnode->pow);
        printf("Enter the Coff: ");
        scanf("%d", &newnode->coff);
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return start;
}
node *poly_add(node *p, node *q);
node *poly_sub(node *p, node *q);
node *poly_multiply(node *p, node *q);
void display(node *start)
{
    node *temp = start;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coff, temp->pow);
        if (temp->next != NULL)
            printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *p = NULL, *q = NULL;
    int pn, qn;
    printf("No. of terms in p: ");
    scanf("%d", &pn);
    p = create(p, pn);
    printf("No. of terms in q: ");
    scanf("%d", &qn);
    q = create(q, qn);
    int choice;
    printf("Enter your choice:\n");
    printf("1. Polynomial Addition\n2. Polynomial Subtraction\n3. Polynomial Multiplication\n");
    scanf("%d", &choice);
    node *res;

    switch (choice)
    {
    case 1:
        // Call function for Polynomial Addition
        printf("Performing Polynomial Addition...\n");
        res = poly_add(p, q);
        display(res);
        break;
    case 2:
        // Call function for Polynomial Subtraction
        printf("Performing Polynomial Subtraction...\n");
        res = poly_sub(p, q);
        display(res);
        break;
    case 3:
        // Call function for Polynomial Multiplication
        printf("Performing Polynomial Multiplication...\n");
        res = poly_multiply(p, q);
        display(res);
        break;
    default:
        printf("Invalid choice! Please enter a valid option.\n");
    }
    return 0;
}
node *poly_add(node *p, node *q)
{
    node *a, *rear, *start = NULL;
    node *t1 = p, *t2 = q; // prevention of loss of original data
    while (t1 != NULL && t2 != NULL)
    {
        a = (node *)malloc(sizeof(node));
        if (t1->pow == t2->pow)
        {
            a->coff = t1->coff + t2->coff;
            a->pow = t1->pow;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->pow > t2->pow)
        {
            a->coff = t1->coff;
            a->pow = t1->pow;
            t1 = t1->next;
        }
        else
        {
            a->coff = t2->coff;
            a->pow = t2->pow;
            t2 = t2->next;
        }
        if (start == NULL)
        {
            start = a;
            rear = a;
        }
        else
        {
            rear->next = a;
            rear = a;
            a->next = NULL;
        }
    }
    if (t1 == NULL)
    {
        while (t2 != NULL)
        {
            a = (node *)malloc(sizeof(node));
            a->coff = t2->coff;
            a->pow = t2->pow;
            t2 = t2->next;
            if (start == NULL)
            {
                start = a;
                rear = a;
            }
            else
            {
                rear->next = a;
                rear = a;
                a->next = NULL;
            }
        }
    }
    if (t2 == NULL)
    {
        while (t1 != NULL)
        {
            a = (node *)malloc(sizeof(node));
            a->coff = t1->coff;
            a->pow = t1->pow;
            t1 = t1->next;
            if (start == NULL)
            {
                start = a;
                rear = a;
            }
            else
            {
                rear->next = a;
                rear = a;
                a->next = NULL;
            }
        }
    }
    return start;
}
node *poly_sub(node *p, node *q)
{
    node *a, *rear, *start = NULL;
    node *t1 = p, *t2 = q; // prevention of loss of original data
    while (t1 != NULL && t2 != NULL)
    {
        a = (node *)malloc(sizeof(node));
        if (t1->pow == t2->pow)
        {
            a->coff = t1->coff - t2->coff;
            a->pow = t1->pow;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->pow > t2->pow)
        {
            a->coff = t1->coff;
            a->pow = t1->pow;
            t1 = t1->next;
        }
        else
        {
            a->coff = t2->coff;
            a->pow = t2->pow;
            t2 = t2->next;
        }
        if (start == NULL)
        {
            start = a;
            rear = a;
        }
        else
        {
            rear->next = a;
            rear = a;
            a->next = NULL;
        }
    }
    if (t1 == NULL)
    {
        while (t2 != NULL)
        {
            a = (node *)malloc(sizeof(node));
            a->coff = t2->coff;
            a->pow = t2->pow;
            t2 = t2->next;
            if (start == NULL)
            {
                start = a;
                rear = a;
            }
            else
            {
                rear->next = a;
                rear = a;
                a->next = NULL;
            }
        }
    }
    if (t2 == NULL)
    {
        while (t1 != NULL)
        {
            a = (node *)malloc(sizeof(node));
            a->coff = t1->coff;
            a->pow = t1->pow;
            t1 = t1->next;
            if (start == NULL)
            {
                start = a;
                rear = a;
            }
            else
            {
                rear->next = a;
                rear = a;
                a->next = NULL;
            }
        }
    }
    return start;
}
node *poly_multiply(node *p, node *q)
{
    node *t1 = p, *t2 = q, *start = NULL, *temp, *newnode;
    while (t1 != NULL) {
        t2 = q;
        while (t2 != NULL) {
            newnode = (node *)malloc(sizeof(node));
            newnode->coff = t1->coff * t2->coff;
            newnode->pow = t1->pow + t2->pow;
            newnode->next = NULL;
            if (start == NULL) {
                start = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return start;
}