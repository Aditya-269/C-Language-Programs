int isSafe(int* positions, int i, int j) {
    int k;
    for(k = 0; k < i; k++) {
        if(positions[k] == j // vertical check
        || abs(k - i) == abs(positions[k] - j)) // diagonal check
          return 0;
    }
    return 1;
}

int recursion(int* positions, int N, int i) {
    int j, total = 0;

    if(i == N) {
        return 1;
    }

    for (j = 0; j < N; j++) {
        positions[i] = j;
        if (isSafe(positions, i, j)) {
            total += recursion(positions, N, i + 1);
        }
    }
    return total;
}
int totalNQueens(int n) {
int sum;
int* positions = (int*) malloc(n * sizeof(int));
sum = recursion(positions, n, 0);
free(positions);
return sum;
}
