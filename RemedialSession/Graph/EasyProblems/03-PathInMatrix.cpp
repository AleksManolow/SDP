#include<iostream>
#include <cstring>
#define N 4
bool isSafe(int i, int j, int matrix[][N])
{
    if (i >= 0 && i < N && j >= 0 && j < N)
        return true;
    return false;
}
bool isaPath(int matrix[][N], int i, int j, bool visited[][N])
{
    if (isSafe(i, j, matrix) && matrix[i][j] != 0 && !visited[i][j]) {

        visited[i][j] = true;
 
        if (matrix[i][j] == 2)
            return true;
 
        bool up = isaPath(matrix, i - 1, j, visited);
 
        if (up)
            return true;

        bool left = isaPath(matrix, i, j - 1, visited);
 
        if (left)
            return true;
 
        bool down = isaPath(matrix, i + 1, j, visited);
 
        if (down)
            return true;

        bool right = isaPath(matrix, i, j + 1, visited);

        if (right)
            return true;
    }
    return false;
    
}
void isPath(int matrix[N][N])
{
    bool visited[N][N];
    memset(visited, 0, sizeof(visited));
 
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1 && !visited[i][j])
            {
                if (isaPath(matrix, i, j, visited)) 
                {
                    flag = true;
                    break;
                }
            }
        }
    }
    if (flag)
        std::cout << "YES";
    else
        std::cout << "NO";
}
int main()
{
    int matrix[N][N] = { { 0, 3, 0, 1 },
                         { 3, 0, 3, 3 },
                         { 2, 3, 3, 3 },
                         { 0, 3, 3, 3 } };

    isPath(matrix);
    return 0;
}
 