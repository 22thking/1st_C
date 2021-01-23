#include <stdio.h>
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 남쪽, 동쪽, 북쪽, 서쪽 순서
int n, m;
int board1[10][10]; 
int board2[10][10]; 
int cctv_n = 0;
int cctv[10];
int arr[10];
int mn = 0;
int isused[10];

int min(int x, int y) {
    if (x < y)return x;
    return y;
}
int OOB(int a, int b) { 
    return a < 0 || a >= n || b < 0 || b >= m;
}
void upd(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board2[x][y] == 6) return;
        if (board2[x][y] != 0) continue; 
        board2[x][y] = 7;
    }
}
void dfs(int k) {
   
    if (k == cctv_n) {
        for (int j = 0; j < n; j++)
            for (int z = 0; z < m; z++)
                board2[j][z] = board1[j][z];
     
        for (int i = 0; i < cctv_n; i++) {
            int x = cctv[i] / 10;
            int y = cctv[i] % 10;
            if (board1[x][y] == 1) {
                upd(x, y, arr[i]);
            }
            else if (board1[x][y] == 2) {
                upd(x, y, arr[i]);
                upd(x, y, arr[i] + 2);
            }
            else if (board1[x][y] == 3) {
                upd(x, y, arr[i]);
                upd(x, y, arr[i] + 1);
            }
            else if (board1[x][y] == 4) {
                upd(x, y, arr[i]);
                upd(x, y, arr[i] + 1);
                upd(x, y, arr[i] + 2);
            }
            else {
                upd(x, y, arr[i]);
                upd(x, y, arr[i] + 1);
                upd(x, y, arr[i] + 2);
                upd(x, y, arr[i] + 3);
            }
        }
        int val = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                val += (board2[i][j] == 0);
        mn = min(mn, val);
        return;  
    }       
    for (int i = 0; i < 4; i++) {
        if (!isused[i]) {
            arr[k] = i;

            dfs(k + 1);

        }
    }
}
int main(void) {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d" ,&board1[i][j]);
            if (board1[i][j] != 0 && board1[i][j] != 6) {
                cctv[cctv_n] = i * 10 + j;
                cctv_n++; 
            }
            if (board1[i][j] == 0) mn++;
        }
    }
    dfs(0);
    printf("%d", mn);
}