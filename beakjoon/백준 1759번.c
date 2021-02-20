#include <stdio.h>

int n, m;
int a[16];
char arr[16];
int issued[16];
void DFS(int t, int k)
{
    if (t == m)
    {
        int aeiou = 0;
        int others = 0;
        for (int i = 0; i < m; i++) {
            if (arr[a[i]] == 97 || arr[a[i]] == 101 || arr[a[i]] == 105 || arr[a[i]] == 111 || arr[a[i]] == 117) {
                aeiou++;
            }  
            else others++;
        }
        if (aeiou < 1 || others < 2)
            return;
        for (int i = 0; i < m; i++)
            printf("%c", arr[a[i]]);
        printf("\n");
        return;
    }
    for (int i = k; i < n; i++)
    {
        if (issued[i] == 0)
        {
            issued[i] = 1;
            a[t] = i;
            DFS(t + 1, i + 1);
            issued[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);
    getchar();
    char tmp = '0';
    char ch = NULL;
    int i = 0;
    while (i<n) {
        ch = getchar();
        if (ch == '\n')
            break;
        if (ch == ' ')
            continue;
        arr[i] = ch;
        i++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
  
    DFS(0, 0);
    return 0;
}