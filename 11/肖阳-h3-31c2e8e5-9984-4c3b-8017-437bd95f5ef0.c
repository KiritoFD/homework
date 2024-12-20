void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int **ret=(int**)malloc(matrixSize*sizeof(int*));
    for(int i=0;i<matrixSize;i++){
        ret[i]=(int*)malloc(sizeof(int)*matrixSize);
        for(int j=0;j<matrixSize;j++){
            ret[i][j]=matrix[matrixSize-j-1][i];
        }
    }
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize;j++)
        matrix[i][j]=ret[i][j];
    }
}