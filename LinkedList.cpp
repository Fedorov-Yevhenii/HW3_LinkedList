/*
Створіть аналог зв'язаного списку (LinkedList) мови Java. Реалізуйте наступний функціонал:
Додавання елемента в кінець списку - метод add(item);
Вставка елемента в середину списку - метод insert(index, item);
Кількість елементів у списку - метод size();
Видалення елемента за індексом - метод remove(index);
Заміна існуючого елемента - метод set(index, item);
Отримання значення заданого елемента - метод get(index);
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

int add(int item);
int insert(int index, int item);
void print();
void sizePrint();
int size();
int remove(int index);
int set(int index, int item);
node* get(int index);
void printNode(node* temp);

int main(){

    int choose, index, item;

    do {
        printf("\n1. add(item)\n");
        printf("2. insert(index, item)\n");
        printf("3. size()\n");
        printf("4. remove(index)\n");
        printf("5. set(index, item)\n");
        printf("6. get(index)\n");
        printf("0. ВИХІД\n");
        printf("ВИБІР: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Значення item: ");
                scanf("%d", &item);
                add(item);
                print();
                break;
            case 2:
                printf("Значення index: ");
                scanf("%d", &index);
                printf("Значення item: ");
                scanf("%d", &item);
                insert(index, item);
                print();
                break;
            case 3:
                sizePrint();
                break;
            case 4:
                printf("Значення index: ");
                scanf("%d", &index);
                remove(index);
                print();
                break;
            case 5:
                printf("Значення index: ");
                scanf("%d", &index);
                printf("Значення item: ");
                scanf("%d", &item);
                set(index, item);
                print();
                break;
            case 6:
                printf("Значення index: ");
                scanf("%d", &index);
                printNode(get(index));
                break;
            default:
                break;
        }

    } while (choose!=0);

}

int add(int item){
    if (head == nullptr){
        struct node *lastNode = (struct node*) malloc(sizeof(struct node));
        lastNode->item = item;
        lastNode->next = head;
        head = lastNode;
        return 1;
    }
    struct node *lastNode = (struct node*) malloc(sizeof(struct node));
    lastNode->item = item;
    struct node *linkedlist = head;
    while(linkedlist->next != nullptr) linkedlist = linkedlist->next;
    linkedlist->next = lastNode;
}

void print(){
    struct node *p = head;
    while(p != nullptr) {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

int insert(int index, int item){
    int i = 0;
    struct node *list = head;
    while (i!=index){
        list = list->next;
        i++;
    }
    struct node *inserted = (struct node*) malloc(sizeof(struct node));
    inserted->item = item;
    inserted->next = list->next;
    list->next = inserted;
}

int remove(int index){

    int i = 0;
    struct node *list = head, *prev;
    do {
        prev = list;
        list = list->next;
        i++;
    } while (i!=index);
    prev->next = list->next;

}

void sizePrint(){
    printf("%d", size());
}

int size(){
    int size = 0;
    struct node *temp = head;
    while(temp != NULL) {
        temp=temp->next;
        size++;
    }
    return size;
}

node* get(int index){
    struct node *temp = head;
    int i = 0;
    while (i!=index){
        temp = temp->next;
        i++;
    }
    return temp;
}

int set(int index, int item){
    struct node *temp = head;
    int i = 0;
    while (i!=index){
        temp = temp->next;
        i++;
    }
    temp->item = item;
}

void printNode(node* temp){
    printf("%d", temp->item);
}