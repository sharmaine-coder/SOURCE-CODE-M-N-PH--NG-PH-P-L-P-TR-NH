#include <stdio.h>
#include <math.h>

// ================= HÀM BỔ TRỢ & KIỂM TRA =================

int laSNT(int k) {
    int i;
    if (k < 2) return 0;
    for (i = 2; i < k; i++) {
        if (k % i == 0) return 0;
    }
    return 1;
}

int laChinhPhuong(int k) {
    int can;
    if (k < 0) return 0;
    can = sqrt(k);
    if (can * can == k) return 1;
    return 0;
}

void nhapmang(int a[], int *n) {
    int i;
    printf("Nhap so phan tu n: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void xuatmang(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// ================= CÂU 1 -> 7 =================

int tongchan(int a[], int n) {
    int s = 0, i;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            s = s + a[i];
        }
    }
    return s;
}

int demle(int a[], int n) {
    int d = 0, i;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            d++;
        }
    }
    return d;
}

void lietkeSNT(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (laSNT(a[i]) == 1) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

float tbcle(int a[], int n) {
    int s = 0, d = 0, i;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            s = s + a[i];
            d++;
        }
    }
    if (d == 0) return 0;
    return (float)s / d;
}

int kttontaiCP(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (laChinhPhuong(a[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

int kttoanchan(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            return 0;
        }
    }
    return 1;
}

int ktmangtang(int a[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// ================= CÂU 8 -> 24 =================

int chanlexenke(int a[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if ((a[i] + a[i + 1]) % 2 == 0) {
            return 0;
        }
    }
    return 1;
}

int tongSNT(int a[], int n) {
    int s = 0, i;
    for (i = 0; i < n; i++) {
        if (laSNT(a[i]) == 1) {
            s = s + a[i];
        }
    }
    return s;
}

int timmax(int a[], int n) {
    int max = a[0], i;
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timchanmax(int a[], int n) {
    int i, max = -1, cochan = 0;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (cochan == 0 || a[i] > max) {
                max = a[i];
                cochan = 1;
            }
        }
    }
    return max;
}

int timduongmin(int a[], int n) {
    int i, min = -1, coduong = 0;
    for (i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (coduong == 0 || a[i] < min) {
                min = a[i];
                coduong = 1;
            }
        }
    }
    return min;
}

void sapxepgiam(int a[], int n) {
    int i, j, tam;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }
}

int timvitriSNTdau(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (laSNT(a[i]) == 1) {
            return i;
        }
    }
    return -1;
}

void xuat_va_dem_lonhonx(int a[], int n, int x) {
    int i, d = 0;
    printf("Cac so lon hon %d la: ", x);
    for (i = 0; i < n; i++) {
        if (a[i] > x) {
            printf("%d ", a[i]);
            d++;
        }
    }
    printf("\nSo luong gia tri lon hon %d la: %d\n", x, d);
}

void themvitri(int a[], int *n, int y, int vt) {
    int i;
    for (i = *n; i > vt; i--) {
        a[i] = a[i - 1];
    }
    a[vt] = y;
    (*n)++;
}

void themcuoi(int a[], int *n, int y) {
    a[*n] = y;
    (*n)++;
}

void themdau(int a[], int *n, int y) {
    themvitri(a, n, y, 0);
}

void themsauchandau(int a[], int *n, int y) {
    int i;
    for (i = 0; i < *n; i++) {
        if (a[i] % 2 == 0) {
            themvitri(a, n, y, i + 1);
            return;
        }
    }
}

void xoavitri(int a[], int *n, int vt) {
    int i;
    for (i = vt; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

void xoadau(int a[], int *n) {
    xoavitri(a, n, 0);
}

void xoatatcax(int a[], int *n, int x) {
    int i;
    for (i = 0; i < *n; i++) {
        if (a[i] == x) {
            xoavitri(a, n, i);
            i--; 
        }
    }
}

void suaSNTthanh0(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (laSNT(a[i]) == 1) {
            a[i] = 0;
        }
    }
}

void tachmang(int a[], int n, int b[], int *nb, int c[], int *nc) {
    int i;
    *nb = 0;
    *nc = 0;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[*nb] = a[i];
            (*nb)++;
        } else {
            c[*nc] = a[i];
            (*nc)++;
        }
    }
}

void sapxepchantanglegiam(int a[], int n) {
    int i, j, tam;
    int trai = 0, phai = n - 1;
    int vtle = 0;

    while (trai < phai) {
        while (trai < phai && a[trai] % 2 == 0) trai++;
        while (trai < phai && a[phai] % 2 != 0) phai--;
        if (trai < phai) {
            tam = a[trai];
            a[trai] = a[phai];
            a[phai] = tam;
        }
    }

    while (vtle < n && a[vtle] % 2 == 0) {
        vtle++;
    }

    for (i = 0; i < vtle - 1; i++) {
        for (j = i + 1; j < vtle; j++) {
            if (a[i] > a[j]) {
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    for (i = vtle; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }
}

// ================= HÀM CHÍNH ĐẦY ĐỦ =================

int main() {
    int a[100], b[100], c[100];
    int n, nb, nc, x, y, vt;

    // Nhập mảng ban đầu
    nhapmang(a, &n);
    printf("Mang vua nhap: ");
    xuatmang(a, n);
    printf("\n");

    // ----- CÁC CÂU KHÔNG LÀM THAY ĐỔI MẢNG (1 đến 12, 14, 15, 16) -----
    
    printf("Cau 1: Tong cac so chan la: %d\n", tongchan(a, n));
    
    printf("Cau 2: So luong so le la: %d\n", demle(a, n));
    
    printf("Cau 3: Cac so nguyen to trong mang la: ");
    lietkeSNT(a, n);
    
    printf("Cau 4: Trung binh cong cac so le la: %.2f\n", tbcle(a, n));
    
    if (kttontaiCP(a, n) == 1) printf("Cau 5: Mang CO ton tai so chinh phuong.\n");
    else printf("Cau 5: Mang KHONG ton tai so chinh phuong.\n");
    
    if (kttoanchan(a, n) == 1) printf("Cau 6: Mang TOAN la so chan.\n");
    else printf("Cau 6: Mang KHONG phai toan so chan.\n");
    
    if (ktmangtang(a, n) == 1) printf("Cau 7: Mang TANG dan.\n");
    else printf("Cau 7: Mang KHONG tang dan.\n");
    
    if (chanlexenke(a, n) == 1) printf("Cau 8: Mang CO chan le xen ke.\n");
    else printf("Cau 8: Mang KHONG chan le xen ke.\n");
    
    printf("Cau 9: Tong cac so nguyen to la: %d\n", tongSNT(a, n));
    
    printf("Cau 10: So lon nhat mang la: %d\n", timmax(a, n));
    
    printf("Cau 11: So chan lon nhat mang la: %d\n", timchanmax(a, n));
    
    printf("Cau 12: So duong nho nhat mang la: %d\n", timduongmin(a, n));
    
    vt = timvitriSNTdau(a, n);
    if (vt != -1) printf("Cau 14: Vi tri SNT dau tien la chi so %d\n", vt);
    else printf("Cau 14: Khong co SNT trong mang.\n");
    
    printf("\nCau 15 & 16 - Nhap x de tim kiem: ");
    scanf("%d", &x);
    xuat_va_dem_lonhonx(a, n, x);


    // ----- CÁC CÂU LÀM THAY ĐỔI MẢNG (13, 17 đến 24) -----
    
    printf("\n--- BAT DAU THAY DOI MANG ---\n");
    
    printf("Cau 17 & 18 - Nhap y de them vao mang: ");
    scanf("%d", &y);
    themcuoi(a, &n, y);
    printf("Sau khi them %d vao CUOI mang: ", y); xuatmang(a, n);
    
    themdau(a, &n, y);
    printf("Sau khi them %d vao DAU mang: ", y); xuatmang(a, n);
    
    themsauchandau(a, &n, y);
    printf("Cau 19 - Sau khi them %d vao sau so chan dau tien: ", y); xuatmang(a, n);
    
    xoadau(a, &n);
    printf("Cau 20 - Sau khi xoa phan tu dau tien: "); xuatmang(a, n);
    
    printf("Cau 21 - Nhap gia tri can xoa tat ca: ");
    scanf("%d", &x);
    xoatatcax(a, &n, x);
    printf("Sau khi xoa tat ca %d: ", x); xuatmang(a, n);
    
    suaSNTthanh0(a, n);
    printf("Cau 22 - Sau khi sua tat ca SNT thanh 0: "); xuatmang(a, n);
    
    printf("\nCau 23 - Tach mang A:\n");
    tachmang(a, n, b, &nb, c, &nc);
    printf("Mang B (chan): "); xuatmang(b, nb);
    printf("Mang C (le): "); xuatmang(c, nc);
    
    printf("\nCau 13 - Sap xep mang GIAM dan: ");
    sapxepgiam(a, n);
    xuatmang(a, n);

    printf("Cau 24 - Sap xep chan truoc tang, le sau giam: ");
    sapxepchantanglegiam(a, n);
    xuatmang(a, n);

    return 0;
}