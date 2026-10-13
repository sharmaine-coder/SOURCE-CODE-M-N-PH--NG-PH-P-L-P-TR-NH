#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Hàm liệt kê các ước số của n
void lietKeUocSo(int n) {
    int i;
    printf("Cac uoc so cua %d la: ", n);
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Hàm tính tổng các số chẵn nhỏ hơn n
int tongChanNhoHon(int n) {
    int i;
    int sum = 0;
    for (i = 2; i < n; i += 2) {
        sum += i;
    }
    return sum;
}

// Hàm tính trung bình cộng các số lẻ nhỏ hơn n
float tbcLeNhoHon(int n) {
    int i;
    int sum = 0, count = 0;
    for (i = 1; i < n; i += 2) {
        sum += i;
        count++;
    }
    return count > 0 ? (float)sum / count : 0;
}

// Hàm đếm số lượng số nhỏ hơn n là bội số của 3 và 5
int demBoi3Va5(int n) {
    int i;
    int count = 0;
    for (i = 15; i < n; i += 15) { // Bội của 3 và 5 là bội của 15
        count++;
    }
    return count;
}

// Hàm kiểm tra n có phải là số nguyên tố không
bool kiemTraNguyenTo(int n) {
    int i;
    if (n < 2) return false;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra n có phải là số hoàn thiện không
bool kiemTraHoanThien(int n) {
    int i;
    int sum = 0;
    if (n <= 1) return false;
    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

// Hàm đếm số chữ số lẻ của n
int demChuSoLe(int n) {
    int count = 0;
    while (n > 0) {
        if ((n % 10) % 2 != 0) count++;
        n /= 10;
    }
    return count;
}

// Hàm liệt kê các chữ số chẵn của n
void lietKeChuSoChan(int n) {
    int digit;
    printf("Cac chu so chan cua n la: ");
    while (n > 0) {
        digit = n % 10;
        if (digit % 2 == 0) printf("%d ", digit);
        n /= 10;
    }
    printf("\n");
}

// Hàm kiểm tra n có toàn chữ số chẵn hay không
bool kiemTraToanChuSoChan(int n) {
    while (n > 0) {
        if ((n % 10) % 2 != 0) return false;
        n /= 10;
    }
    return true;
}

// Hàm kiểm tra các chữ số của n có tăng dần không (từ trái qua phải)
bool kiemTraTangDan(int n) {
    int lastDigit, currentDigit;
    lastDigit = n % 10;
    n /= 10;
    while (n > 0) {
        currentDigit = n % 10;
        if (currentDigit >= lastDigit) return false;
        lastDigit = currentDigit;
        n /= 10;
    }
    return true;
}

// Hàm tính tổng các chữ số chẵn của n
int tongChuSoChan(int n) {
    int sum = 0;
    int digit;
    while (n > 0) {
        digit = n % 10;
        if (digit % 2 == 0) sum += digit;
        n /= 10;
    }
    return sum;
}

// Hàm tìm chữ số lớn nhất của n
int timChuSoLonNhat(int n) {
    int max = 0;
    int digit;
    while (n > 0) {
        digit = n % 10;
        if (digit > max) max = digit;
        n /= 10;
    }
    return max;
}

// Hàm kiểm tra n có đối xứng hay không
bool kiemTraDoiXung(int n) {
    int reversed = 0, original = n;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    int n;
    
    // Nhập và kiểm tra điều kiện (0 < n < 1000 và n là số chẵn)
    do {
        printf("Nhap n (0 < n < 1000, chan): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000 || n % 2 != 0) {
            printf("Gia tri khong hop le, vui long nhap lai!\n");
        }
    } while (n <= 0 || n >= 1000 || n % 2 != 0);

    printf("\n--- KET QUA ---\n");
    lietKeUocSo(n);
    printf("Tong cac so chan nho hon %d la: %d\n", n, tongChanNhoHon(n));
    printf("Trung binh cong cac so le nho hon %d la: %.2f\n", n, tbcLeNhoHon(n));
    printf("So luong cac so nho hon %d la boi cua 3 va 5 la: %d\n", n, demBoi3Va5(n));
    printf("Kiem tra so nguyen to: %s\n", kiemTraNguyenTo(n) ? "Co" : "Khong");
    printf("Kiem tra so hoan thien: %s\n", kiemTraHoanThien(n) ? "Co" : "Khong");
    printf("So chu so le cua %d la: %d\n", n, demChuSoLe(n));
    lietKeChuSoChan(n);
    printf("Kiem tra toan chu so chan: %s\n", kiemTraToanChuSoChan(n) ? "Co" : "Khong");
    printf("Kiem tra tang dan: %s\n", kiemTraTangDan(n) ? "Co" : "Khong");
    printf("Tong cac chu so chan cua %d la: %d\n", n, tongChuSoChan(n));
    printf("Chu so lon nhat cua %d la: %d\n", n, timChuSoLonNhat(n));
    printf("Kiem tra doi xung: %s\n", kiemTraDoiXung(n) ? "Co" : "Khong");

    return 0;
}