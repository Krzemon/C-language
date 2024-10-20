#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct point {
    double x, y;
};

struct vert_AC {
    struct point A;
    struct point C;
};

struct rect {
    struct vert_AC vertices;
    double area;
    double perimeter;
};

double rect_per(struct vert_AC rect) {
    double length = abs(rect.C.x - rect.A.x);
    double width = abs(rect.C.y - rect.A.y);
    return 2 * (length + width);
}

double rect_area(struct vert_AC rect) {
    double length = abs(rect.C.x - rect.A.x);
    double width = abs(rect.C.y - rect.A.y);
    return length * width;
}

void fill_tab(struct rect *tab, int n) {
    for (int i = 0; i < n; i++) {
        tab[i].vertices.A.x = rand() % 100;
        tab[i].vertices.A.y = rand() % 100;
        tab[i].vertices.C.x = tab[i].vertices.A.x + (rand() % 100);
        tab[i].vertices.C.y = tab[i].vertices.A.y + (rand() % 100);
        tab[i].perimeter = rect_per(tab[i].vertices);
        tab[i].area = rect_area(tab[i].vertices);
    }
}

void print_tab(struct rect *tab, int n) {
    printf("Numer struktury Ax\tAy\tBx\tBy\tCx\tCy\tDx\tDy\tpole\tobwod\n");
    for (int i = 0; i < n; i++) {
        struct vert_AC vert = tab[i].vertices;
        double Bx = vert.C.x;
        double By = vert.A.y;
        double Dx = vert.A.x;
        double Dy = vert.C.y;
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", 
               i, vert.A.x, vert.A.y, Bx, By, vert.C.x, vert.C.y, Dx, Dy, tab[i].area, tab[i].perimeter);
    }
}

struct vert_AC find_rect(struct rect *tab, int n, double perimeter, double area) {
    for (int i = 0; i < n; i++) {
        if (tab[i].perimeter == perimeter && tab[i].area == area) {
            return tab[i].vertices;
        }
    }
    struct vert_AC not_found = {{FLT_MAX, FLT_MAX}, {FLT_MAX, FLT_MAX}};
    return not_found;
}

int compare(const void *a, const void *b) {
    struct rect *rectA = (struct rect *)a;
    struct rect *rectB = (struct rect *)b;
    if (rectA->perimeter != rectB->perimeter) {
        return (rectA->perimeter > rectB->perimeter) - (rectA->perimeter < rectB->perimeter);
    }
    return (rectA->area > rectB->area) - (rectA->area < rectB->area);
}

int main() {
    int n = 10;
    struct rect *tab_rect = malloc(n * sizeof(struct rect));
    fill_tab(tab_rect, n);
    print_tab(tab_rect, n);

    double search_perimeter = tab_rect[0].perimeter;
    double search_area = tab_rect[0].area;
    struct vert_AC result = find_rect(tab_rect, n, search_perimeter, search_area);
    printf("Wspolrzedne znalezionego prostokata: Ax: %.2f Ay: %.2f Cx: %.2f Cy: %.2f\n", 
           result.A.x, result.A.y, result.C.x, result.C.y);

    qsort(tab_rect, n, sizeof(struct rect), compare);
    printf("\nPosortowana tablica:\n");
    print_tab(tab_rect, n);

    free(tab_rect);
    return 0;
}
