#include <stdio.h>
#define INF 9999

int n, cost[10][10];

void prims() {
    int visited[10]={0};
    int totalcost=0;
    visited[0] = 1;
    printf("Edges in MST: \n");
    int edge;
    for(edge=0;edge<n-1;edge++){
        int mincost=INF,u=-1,v=-1;
        for(int i=0;i<n;i++) {
            if(visited[i]) {
                for(int j=0;j<n;j++) {
                    if(!visited[j] && cost[i][j] < mincost) {
                        mincost = cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(u != -1 && v != -1) {
            printf("%d to %d : %d \n",u,v,mincost);
            totalcost+=mincost;
            visited[v]=1;
        }

    }
    printf("total min cost is : %d",totalcost);
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims();
    return 0;
}
