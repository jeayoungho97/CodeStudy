#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 1. 숫자의 합 (11720)
void problem_1() {
    int n, sum = 0;
    char s[101];
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) sum += s[i] - '0';
    printf("%d\n", sum);
}

// 2. 문자열 분석 (10820)
void problem_2() {
    char s[101];
    while (fgets(s, 101, stdin)) {
        int lower=0, upper=0, digit=0, space=0;
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) lower++;
            else if (isupper(s[i])) upper++;
            else if (isdigit(s[i])) digit++;
            else if (s[i]==' ') space++;
        }
        printf("%d %d %d %d\n", lower, upper, digit, space);
    }
}

// 3. 단어 공부 (1157)
void problem_3() {
    char s[1001];
    int alpha[26] = {0}, max = 0, idx = 0, cnt = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) alpha[toupper(s[i]) - 'A']++;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > max) { max = alpha[i]; idx = i; cnt = 1; }
        else if (alpha[i] == max) cnt++;
    }
    printf("%c\n", cnt>1 ? '?' : idx+'A');
}

// 4. 그룹 단어 체커 (1316)
void problem_4() {
    int n, ans=0;
    scanf("%d", &n);
    for (int t=0; t<n; t++) {
        char s[101]; int check[26]={0}, ok=1;
        scanf("%s", s);
        for (int i=0; s[i]; i++) {
            if (s[i] != s[i-1] && check[s[i]-'a']) { ok=0; break; }
            check[s[i]-'a']=1;
            while (s[i+1] && s[i+1]==s[i]) i++;
        }
        ans+=ok;
    }
    printf("%d\n", ans);
}

// 5. 아스키 코드 (11654)
void problem_5() {
    char c;
    scanf(" %c", &c);
    printf("%d\n", c);
}

// 6. 알파벳 찾기 (10809)
void problem_6() {
    char s[101];
    int pos[26];
    for (int i=0;i<26;i++) pos[i]=-1;
    scanf("%s", s);
    for (int i=0; s[i]; i++)
        if (pos[s[i]-'a']==-1) pos[s[i]-'a']=i;
    for (int i=0;i<26;i++) printf("%d ", pos[i]);
    printf("\n");
}

// 7. 크로아티아 알파벳 (2941)
void problem_7() {
    char s[101];
    int cnt=0;
    scanf("%s", s);
    for (int i=0; s[i]; i++,cnt++) {
        if (!strncmp(&s[i],"dz=",3)) i+=2;
        else if (!strncmp(&s[i],"c=",2)||!strncmp(&s[i],"c-",2)||!strncmp(&s[i],"d-",2)||!strncmp(&s[i],"lj",2)||!strncmp(&s[i],"nj",2)||!strncmp(&s[i],"s=",2)||!strncmp(&s[i],"z=",2)) i+=1;
    }
    printf("%d\n",cnt);
}

// 8. 덩치 (7568)
struct Person { int w, h; };
void problem_8() {
    int n;
    scanf("%d", &n);
    struct Person p[50];
    for(int i=0;i<n;i++) scanf("%d %d", &p[i].w, &p[i].h);
    for(int i=0;i<n;i++) {
        int rank=1;
        for(int j=0;j<n;j++) if(i!=j && p[j].w>p[i].w && p[j].h>p[i].h) rank++;
        printf("%d ",rank);
    }
    printf("\n");
}

// 9. 셀프 넘버 (4673)
int d(int n) { int r=n; while(n) {r+=n%10;n/=10;} return r; }
void problem_9() {
    int arr[10001]={0};
    for(int i=1;i<=10000;i++) arr[d(i)]=1;
    for(int i=1;i<=10000;i++) if(!arr[i]) printf("%d\n",i);
}

// 10. 한수 (1065)
void problem_10() {
    int n, cnt=0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        if(i<100) cnt++;
        else {
            int a=i/100,b=i/10%10,c=i%10;
            if(a-b==b-c) cnt++;
        }
    }
    printf("%d\n",cnt);
}

// 11. 색종이 (2563)
void problem_11() {
    int n, x, y, paper[101][101] = {0}, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        for (int r = x; r < x + 10; r++)
            for (int c = y; c < y + 10; c++)
                paper[r][c] = 1;
    }
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            cnt += paper[i][j];
    printf("%d\n", cnt);
}

// 12. 주사위 세개 (2480)
void problem_12() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c) printf("%d\n", 10000 + a * 1000);
    else if (a == b || a == c) printf("%d\n", 1000 + a * 100);
    else if (b == c) printf("%d\n", 1000 + b * 100);
    else {
        int max = a > b ? (a > c ? a : c) : (b > c ? b : c);
        printf("%d\n", max * 100);
    }
}

// 13. 직사각형에서 탈출 (1085)
void problem_13() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int min = x;
    if (min > y) min = y;
    if (min > w - x) min = w - x;
    if (min > h - y) min = h - y;
    printf("%d\n", min);
}

// 14. 직각삼각형 (4153)
void problem_14() {
    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
            printf("right\n");
        else
            printf("wrong\n");
    }
}

// 15. 좌표 정렬하기 (11650)
struct Point { int x, y; };
int cmp(const void *a, const void *b) {
    struct Point *p1 = (struct Point *)a, *p2 = (struct Point *)b;
    return p1->x != p2->x ? p1->x - p2->x : p1->y - p2->y;
}
void problem_15() {
    int n;
    scanf("%d", &n);
    struct Point p[100000];
    for (int i = 0; i < n; i++) scanf("%d %d", &p[i].x, &p[i].y);
    qsort(p, n, sizeof(p[0]), cmp);
    for (int i = 0; i < n; i++) printf("%d %d\n", p[i].x, p[i].y);
}

// 16. 좌표 정렬하기 2 (11651)
int cmp2(const void *a, const void *b) {
    struct Point *p1 = (struct Point *)a, *p2 = (struct Point *)b;
    return p1->y != p2->y ? p1->y - p2->y : p1->x - p2->x;
}
void problem_16() {
    int n;
    scanf("%d", &n);
    struct Point p[100000];
    for (int i = 0; i < n; i++) scanf("%d %d", &p[i].x, &p[i].y);
    qsort(p, n, sizeof(p[0]), cmp2);
    for (int i = 0; i < n; i++) printf("%d %d\n", p[i].x, p[i].y);
}

// 17. 스택 (10828)
void problem_17() {
    int stack[10000], top = -1, n, x;
    char cmd[6];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push")) {
            scanf("%d", &x);
            stack[++top] = x;
        } else if (!strcmp(cmd, "pop")) printf("%d\n", top == -1 ? -1 : stack[top--]);
        else if (!strcmp(cmd, "size")) printf("%d\n", top + 1);
        else if (!strcmp(cmd, "empty")) printf("%d\n", top == -1);
        else if (!strcmp(cmd, "top")) printf("%d\n", top == -1 ? -1 : stack[top]);
    }
}

// 18. 큐 (10845)
void problem_18() {
    int queue[10000], front = 0, rear = 0, n, x;
    char cmd[6];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push")) {
            scanf("%d", &x);
            queue[rear++] = x;
        } else if (!strcmp(cmd, "pop")) printf("%d\n", front == rear ? -1 : queue[front++]);
        else if (!strcmp(cmd, "size")) printf("%d\n", rear - front);
        else if (!strcmp(cmd, "empty")) printf("%d\n", front == rear);
        else if (!strcmp(cmd, "front")) printf("%d\n", front == rear ? -1 : queue[front]);
        else if (!strcmp(cmd, "back")) printf("%d\n", front == rear ? -1 : queue[rear-1]);
    }
}

// 19. 덱 (10866)
void problem_19() {
    int deque[20000], front = 10000, rear = 10000, n, x;
    char cmd[11];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push_front")) {
            scanf("%d", &x);
            deque[--front] = x;
        } else if (!strcmp(cmd, "push_back")) {
            scanf("%d", &x);
            deque[rear++] = x;
        } else if (!strcmp(cmd, "pop_front")) printf("%d\n", front == rear ? -1 : deque[front++]);
        else if (!strcmp(cmd, "pop_back")) printf("%d\n", front == rear ? -1 : deque[--rear]);
        else if (!strcmp(cmd, "size")) printf("%d\n", rear - front);
        else if (!strcmp(cmd, "empty")) printf("%d\n", front == rear);
        else if (!strcmp(cmd, "front")) printf("%d\n", front == rear ? -1 : deque[front]);
        else if (!strcmp(cmd, "back")) printf("%d\n", front == rear ? -1 : deque[rear-1]);
    }
}

// 20. DFS와 BFS (1260)
int graph[1001][1001], visited[1001], n;
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++)
        if (graph[v][i] && !visited[i]) dfs(i);
}
void bfs(int v) {
    int queue[10000], front=0, rear=0;
    memset(visited,0,sizeof(visited));
    visited[v]=1; queue[rear++]=v;
    while(front<rear) {
        int cur=queue[front++]; printf("%d ",cur);
        for(int i=1;i<=n;i++) if(graph[cur][i]&&!visited[i]) {visited[i]=1;queue[rear++]=i;}
    }
}
void problem_20() {
    int m, v, x, y;
    scanf("%d %d %d", &n, &m, &v);
    for (int i=0;i<m;i++) {scanf("%d %d",&x,&y);graph[x][y]=graph[y][x]=1;}
    dfs(v); printf("\n"); bfs(v);
}