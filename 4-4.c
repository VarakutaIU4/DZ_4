#include <stdio.h>

void sort(int degrees[], int numbers[], int point){
    int i, tmp1, tmp2;
    for(i=1;i<=point;i++){
        while((i > 0) && (degrees[i-1] > degrees[i])){
            tmp1 = degrees[i-1];
            tmp2 = numbers[i-1];
            degrees[i-1] = degrees[i];
            numbers[i-1] = numbers[i];
            degrees[i] = tmp1;
            numbers[i] = tmp2;
            i = i - 1;
        }
    }
}


int main(){

    FILE *f;
    f = fopen("graph.dot", "w");

    if(f != NULL){
        fprintf(f, "Graph A{\n");
    }

    int i, j, point, rib, x, y;
    printf("Size of matrix:\n");
    scanf("%d", &point);
    int a[point][point];

    for(i=1;i<=point;i++){
    fprintf(f, "%d;\n", i);
    }

    printf("Input matrix:\n");
        for(i=1;i<=point;i++){
        for(j=1;j<=point;j++){
            scanf("%d", &a[i][j]);
            }
            }
                printf("Matrix: \n");
                for(i=1;i<=point;i++){
                for(j=1;j<=point;j++){
                    printf("%d\t", a[i][j]);
                }
                    printf("\n");
                }
                printf("\n");

    for(i=1;i<=point;i++){
    for(j=1;j<=point;j++){
        if(a[i][j] == 1){
            printf("%d -- ", i);
            printf("%d;\n", j);
            fprintf(f, "%d -- %d;\n", i, j);
        }
    }
    }

    if(f != NULL){
        fprintf(f, "}");
    }
    printf("File graph.dot created\n\n");
    fclose(f);


// Проверка связности графа
    rib = 0;
    for(i=1;i<=point;i++){
    for(j=1;j<=point;j++){
        if(a[i][j] == 1){
            rib++;
        }
    }
    }
    printf("Rib = %d\n", rib);

    x = 1;
    for(int i=1;i<=point;i++){
    y = 0;
    for(int j=1;j<=point;j++){
        if(a[i][j] == 1){
            y = 1;
        }
        if(a[j][i] == 1){
            y = 1;
        }
    }
        if(y == 0){
            x = 0;
        }
    }

    if(rib > (point - 1)*(point - 2)/2){
        printf("Graph is connected (by theorem)\n\n");
    } else if(x == 0){
    printf("Graph is not connected\n\n");
    } else {
    printf("Graph is connected\n\n");
    }

// Найти вершины с минимальной степенью вершины

    int degree = 0;
    int degrees[point];
    int numbers[point];

    for(j=1;j<=point;j++){
    for(i=1;i<=point;i++){
        if(a[i][j] == 1){
            degree++;
        }
        if(a[j][i] == 1){
            degree++;
        }
    }
    degrees[j-1] = degree;
    numbers[j-1] = j;
    printf("Point %d = %d\n", j, degrees[j-1]);
    degree = 0;
    }

    printf("\nUnsorted:\n");
    for(i=0;i<point;i++){
        printf("%d ", degrees[i]);
    }

    sort(degrees, numbers, point);

    printf("\n\nSorted:\n");
    for(i=0;i<point;i++){
        printf("%d ", degrees[i]);
    }

    printf("\n\nPoints with minimum degree:\n\n");
    for(i=0;i<point;i++){
        if(degrees[0] == degrees[point - 1]){
            printf("* All degrees are equaled to each other and degree = %d *\n", degrees[0]);
            break;
        } else if(degrees[0] == degrees[i]){
            printf("* Degree of Point %d = %d *\n", numbers[i], degrees[i]);
        }
    }


return 0;
}
