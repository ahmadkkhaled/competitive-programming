/// global

const int N = SIZE;
int a[N][N]; /// fill 0 or declare global

    /// fill
    a[i][j] = val /// i,j are 1 based
    /// end fill

    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            /**
             * sum at i,j = sum of previous (col wise) sub matrix + sum of upper (row wise) sub matrix - sum of joint sub matrix
             */
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
        }
    }

    /// a[i][j] = sum of all numbers within the rectangle 0,0 (upper left) and  i,j (lower right) including value[i][j]

    /// find subsum contained in x2,y2 (lower right) , x1,y1 (upper left)
    subsum = a[y2][x2] - a[y1 - 1][x2] - a[y2][x1 - 1] + a[y1 - 1][x1 - 1];