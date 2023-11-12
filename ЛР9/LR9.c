#include <stdio.h>
#include <math.h>

struct point
{
    int x;
    int y;
};

typedef struct point point;

struct move_point
{
    point dot;
    int l;
};

typedef struct move_point mp;

struct square
{
    point center;
    int side;
};

typedef struct square square;

void print_mp(mp dp)
{
    printf("x: %d, y: %d, l: %d\n", dp.dot.x, dp.dot.y, dp.l);
}

int max(int a, int b)
{
    if (a >= b){
        return a;
    }
    return b;
}

int min(int a, int b)
{
    if (a <= b){
        return a;
    }
    return b;
}

int in_square(point dot, square s)
{
    if (dot.x >= s.center.x - s.side / 2 && dot.x <= s.center.x + s.side / 2 && dot.y >= s.center.y - s.side / 2 && dot.y <= s.center.y + s.side / 2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    mp nw;
    mp old;
    old.dot.x = 11;
    old.dot.y = 13;
    old.l = 10;
    square s;
    s.center.x = 10;
    s.center.y = -10;
    s.side = 10;
    for (int k = 0; k < 50; k++)
    {
       nw.dot.x = abs(k - 15) - min(old.dot.x / 3, (old.dot.y + old.l) % 10) - 20;
       nw.dot.y = -(old.dot.y + k) / 5 + abs(old.dot.x * old.l % 8);
       nw.l = max((old.dot.x + old.dot.y) % 15, (old.l + k) % 14);
       old = nw;
       print_mp(old);
       if (in_square(old.dot, s) == 1)
       {
           printf("Success\n");
           break;
       }
       if (k == 49)
       {
           printf("Fail\n");
       }
    }
}
