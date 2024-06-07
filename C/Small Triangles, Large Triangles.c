#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float get_area(triangle t){
    float p = (t.a + t.b + t.c)/2.0;
    return sqrt(p*(p-t.a)*(p-t.b)*(p-t.c));
}

void sort_by_area(triangle* tr, int n) {

    int i,j;
    triangle temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (get_area(tr[j]) > get_area(tr[j + 1])) {
                temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
        }
    }
  }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}