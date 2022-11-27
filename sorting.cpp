#include<iostream>
using namespace std;
void shakerSort(int a[], int l, int r){
    int k = 0;
    while (l < r)
    {
        for (int i = l; i < r; i++){
            if(a[i] > a[i + 1]){
                swap(a[i],a[i + 1]);
                k = i;
            }
        }
        r = k;
        for (int i = r; i > l; i--)
        {
            if(a[i] < a[i - 1]){
                swap(a[i],a[i - 1]);
                k = i;
            }
        }
        l = k;
    }
}
int shakerSortCount(int a[], int l, int r){
    int comparisons = 0;
    int k = 0;
    while (++comparisons && l < r)
    {
        for (int i = l; ++comparisons && i < r; i++){
            if(++comparisons && a[i] > a[i + 1]){
                swap(a[i],a[i + 1]);
                k = i;
            }
        }
        r = k;
        for (int i = r; ++comparisons && i > l; i--)
        {
            if(++comparisons && a[i] < a[i - 1]){
                swap(a[i],a[i - 1]);
                k = i;
            }
        }
        l = k;
    }
    return comparisons;
}
void shellSort(int a[], int l, int r){
    int interval = 1, n = r - l + 1;
    while (interval < n/3){
        interval = interval*3 +1;   
    }
    while (interval > 0)
    {
        for (int i = interval; i < n; i++)
        {
            int valueToInsert = a[i];
            int inner = i;
            while (inner > interval - 1 && a[inner - interval] >= valueToInsert)
            {
                a[inner] = a[inner-interval];
                inner = inner - interval;
            }
            a[inner] = valueToInsert;
        }
        interval = (interval - 1)/3;     
    }
}
int shellSortCount(int a[], int l, int r){
    int interval = 1, n = r - l + 1,comparisons = 0;
    while (++comparisons && interval < n/3){
        interval = interval*3 +1;   
    }
    while (++comparisons && interval > 0)
    {
        for (int i = interval;++comparisons && i < n; i++)
        {
            int valueToInsert = a[i];
            int inner = i;
            while ((++comparisons && inner > interval - 1) && (++comparisons &&  a[inner - interval] >= valueToInsert))
            {
                a[inner] = a[inner-interval];
                inner = inner - interval;
            }
            a[inner] = valueToInsert;
        }
        interval = (interval - 1)/3;     
    }
    return comparisons; 
}
void flashSort(int a[],int l, int r){
    int n = r - l + 1;
    int max = 0,maxVal = a[0], min = 0,minVal = a[0];
    int m = int(0.45*n);
    int *L = new int[m];
    // find max && min
    for (int i = 0; i < m; i++)
    {
        L[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[min]){
            minVal = a[i];
            min = i;
        }
        if (a[i] > a[max]){
            maxVal = a[i];
            max = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int k = (m-1)*(a[i]-minVal)/(maxVal - minVal);
        L[k]++;
    }
    for (int i = 1; i < n; i++)
    {
        L[i] += L[i-1];
    }
    swap(a[max],a[0]);
    //permutation
    int move = 0, j = 0,k = m - 1;
    int flash;
    while (move < (n-1))
    {
        while (j > (L[k]-1))
        {
            j++;
            k = (m-1)*(a[j]-minVal)/(maxVal - minVal);
        }
        flash = a[j];
        if(k < 0) break;
        while (j != L[k])
        {
            k = (m-1)*(flash - minVal)/(maxVal - minVal);
            --L[k];
            swap(flash,a[L[k]]);
            ++move;
        }
    }
    //insertion 
    for (int i = 1; i < n; i++)
    {
        int hold = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > hold)
        {
            a[j + 1] = a[j--];
        }
        a[j+1] = hold;
    }
}
int flashSortCount(int a[],int l, int r){
    int comparisons = 0;
    int n = r - l + 1;
    int max = 0,maxVal = a[0], min = 0,minVal = a[0];
    int m = int(0.45*n);
    int *L = new int[m];
    // find max && min
    for (int i = 0;++comparisons && i < m; i++)
    {
        L[i] = 0;
    }
    for (int i = 1;++comparisons && i < n; i++)
    {
        if (++comparisons && a[i] < a[min]){
            minVal = a[i];
            min = i;
        }
        if (++comparisons && a[i] > a[max]){
            maxVal = a[i];
            max = i;
        }
    }
    for (int i = 0;++comparisons && i < n; i++)
    {
        int k = (m-1)*(a[i]-minVal)/(maxVal - minVal);
        L[k]++;
    }
    for (int i = 1;++comparisons && i < n; i++)
    {
        L[i] += L[i-1];
    }
    swap(a[max],a[0]);
    //permutation
    int move = 0, j = 0,k = m - 1;
    int flash;
    while (++comparisons && move < (n-1))
    {
        while (++comparisons && j > (L[k]-1))
        {
            j++;
            k = (m-1)*(a[j]-minVal)/(maxVal - minVal);
        }
        flash = a[j];
        if(++comparisons && k < 0) break;
        while (++comparisons && j != L[k])
        {
            k = (m-1)*(flash - minVal)/(maxVal - minVal);
            --L[k];
            swap(flash,a[L[k]]);
            ++move;
        }
    }
    //insertion 
    for (int i = 1;++comparisons && i < n; i++)
    {
        int hold = a[i];
        int j = i - 1;
        while ((++comparisons && j >= 0) && (++comparisons && a[j] > hold))
        {
            a[j + 1] = a[j--];
        }
        a[j+1] = hold;
    }
    return comparisons;
}
int main(){
    int a[]{13,14,1,5,16,773,4,1,3,13,83,414,1,51,46,91,6,1,61,234,2,4};
    int b[]{13,14,1,5,16,773,4,1,3,13,83,414,1,51,46,91,6,1,61,234,2,4};
    int c[]{13,14,1,5,16,773,4,1,3,13,83,414,1,51,46,91,6,1,61,234,2,4};
    int n = sizeof(a)/sizeof(int);
    cout << "\n shaker : " << shakerSortCount(a,0,n-1) << "\n";
    for(int x : a){
        cout << x << " ";
    }
    cout << "\n shell : " << shellSortCount(b,0,n-1) << "\n";
    // flashSort(a,0,n-1);
    for(int x : b){
        cout << x << " ";
    }
    cout << "\n flash : " << flashSortCount(c,0,n-1) << "\n";
    // flashSort(a,0,n-1);
    for(int x : c){
        cout << x << " ";
    }
    return 0;
}