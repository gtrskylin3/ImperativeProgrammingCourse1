#include <stdio.h>
#include <math.h>

int main() { 
    int n, m, p, k, l;
    scanf("%d", &n); // n - номер квартиры
    scanf("%d %d %d %d", &m, &p, &k, &l);
    // m - номер квартиры  50
    // p - подъезд x 2
    // k - этаж x 4
    // l - кол-во этажей 9
    //output P , K
    int etaj = l * (p - 1) + k;
    int kv_na_etaje =  m / etaj;
    if (m % etaj != 0){
        kv_na_etaje ++;
    }
    int kv_v_podezde = kv_na_etaje * l;
    int Res1 = n / kv_v_podezde;
    if (n % kv_v_podezde != 0){
        Res1 ++;
    }
    int kv_do_Res1 = (Res1 - 1) * kv_v_podezde;
    int Res2 = (n - kv_do_Res1) / kv_na_etaje;
    if ((n-kv_do_Res1) % kv_na_etaje != 0){
        Res2 ++;
    }
    printf("%d %d", Res1, Res2);
}


// 100 
// 50 2 4 9 

// 9 + 4 = 13 
// 50 / 13 = 4

// 9 * 4 = 36
// 100 / 36 = 3

// 3 7 

// 100 - 