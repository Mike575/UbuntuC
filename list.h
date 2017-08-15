#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>/*feature of c99*/

struct bitNum_node
{
    int bit_at_where;/*从个位0开始，依次十位1,百位2等等*/
    int bit_is_what;
};

typedef struct bitNum_node Item;

typedef struct node
{
    Item item;
    struct node* next;
}Node;

typedef Node* List;

/*函数原型*/

/*操作：        初始化一个链表                                      */
/*前提条件：    plist指向一个链表                                   */
/*后置条件：    链表为空                                            */
void InitializeList(List* plist);

/*操作：        确定链表是否为空定义，plist指向一个已初始化的链表   */    
/*后置条件：    如果链表为空，返回true;否则返回false                */
bool ListIsEmpty(const List* plist);

/*操作：        确定链表是否已满，plist指向一个已初始化的链表       */
/*后置条件：    如果链表已满，返回true;否则返回false                */
bool ListIsFull(const List* plist);

/*操作：        确定链表中的项数，plist指向一个已初始化的链表       */
/*后置条件：    该函数返回链表中的项数                              */
unsigned int ListItemCount(const List* plist);

/*操作：        在链表的末尾添加项                                  */
/*前提条件：    item是一个待添加到链表的项，plist指向一个已初始化的链表*/
/*后置条件：    如果可以，该函数在链表末尾添加一个项，且返回true;否则false*/
bool AddItem(Item item,List* plist);

/*操作：        把函数作用于链表中的每一项                          */
/*              plist指向一个已初始化的链表                         */
/*              pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值*/
/*后置条件      pfun指向的函数作用于链表的每一项一次                */
void Traverse(const List* plist,void(*pfun)(Item item));             

/*操作：        释放已分配的内存                                    */
/*              plist指向一个已初始化的链表                         */
/*后置条件：    释放了为链表分配的所有内存，链表设置为空            */
void EmptyTheList(List* plist);

#endif

