#include <stdio.h>
#define MAX 50
int hashTable[MAX];
int m;
void initHashTable()
{
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}
int hashFunction(int key)
{
    return key % m;
}
void insert(int key)
{
    int index = hashFunction(key);
    while (hashTable[index] != -1)
    {
        index = (index + 1) % m;
    }
    hashTable[index] = key;
}
void display()
{
    printf("\nHash Table:\n");
    printf("Address\tKey\n");
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] != -1)
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t---\n", i);
    }
}
int main()
{
    int n, key;
    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);
    initHashTable();
    printf("Enter number of employee records (N): ");
    scanf("%d", &n);
    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
