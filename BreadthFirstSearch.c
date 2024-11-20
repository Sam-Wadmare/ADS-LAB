#include<stdio.h>


void BFS(int arr[20][20],int sourcen,int visited[20],int n) {
    int queue[20],front=0,rear=0;
    queue[rear++]=sourcen;
    visited[sourcen]=1;

    while(front<rear) {
        int current=queue[front++];
        for(int i =1;i<n;i++) {
            if(arr[current][i] == 1 && !visited[i]) {
                queue[rear++]=1;
                visited[i]=1; //mark as visited
            }
        }
    }
}
int main() {
    int n,a[20][20],sourcen,visited[20],i,j;
    printf("Enter the size of matrix: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix : \n");
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the source node: ");
    scanf("%d",&sourcen);

    BFS(a,sourcen,visited,n);

    
    for(i=1;i<=n;i++) {
        if(visited[i]) {
            printf("node %d  is reachable\n",i);
        }
        else {
            printf("node %d is not reachable",i);
        }
        
    }


    return 0;
}