#include<bits/stdc++.h>

using namespace std ;

void maxHeap(vector<int> &v,int n,int i)
{
    int    large = i ;
    int    l = 2*i+1 ;
    int    r = 2*i+2 ;
    if(l<n&&v[large]<v[l])
        large = l ;
    if(r<n&&v[large]<v[r])
        large=r ;

    if(large!=i)
    {
        swap(v[large],v[i]) ;
        maxHeap(v,n,large) ;
    }
}
void heapsort(vector<int> &v,int n)
{
    for(int i = n/2-1; i>=0; i--)
        maxHeap(v,n,0);
    for(int i=n-1; i>=0; i--)
    {
        swap(v[i],v[0]);
        maxHeap(v,i,0);
    }

}

void bubbleSort(vector<int>&v,int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]) ;
        }
    }
}

void selectionSort(vector<int>&v,int n)
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        minIdx = i ;
        for(int j=i+1; j<n; j++)
        {
            if(v[midIdx]>v[j])
            {
                midIdx = j
            }
        }
        swap(v[minIdx],v[i]) ;
    }
}
void marge(vector<int>&v,int left,int mid, int right)
{
    int lenght1 = mid - left + 1 ;
    int length2 = right - mid ;

    vector<int> leftArray(lenght1),rightArray(lenght2) ;

    for(int i = 0 ; i < lenght1 ; i++)
    {
        leftArray[i] = v[i] ;
    }
    for(int i = 0 ; i < lenght2 ; i++)
    {
        rightArray[i] = v[mid+1+i] ;
    }
    int i = 0, j = 0, k = 0 ;
    while(i<lenght1 && j<lenght2)
    {
        if(leftArray[i]<rightArray[j])
        {
            v[k] = leftArray[i];
            k++;
            i++;
        }
        else
        {
            v[k] = rightArray[j];
            k++;
            j++;
        }
    }
    while(i<lenght1)
    {
        v[k]=leftArray[i];
        k++;
        i++;
    }
    while(j<lenght2)
    {
        v[k]=rightArray[j];
        k++;
        j++;
    }
}
void margeSort(vector<int>&v,int left,int right)
{
    if(left>=right) return ;
    int mid = (left+ (right - left))/2 ;
    margeSort(v,left,mid) ;
    margeSort(v,mid+1,right) ;
    marge(v,left,mid,right) ;
}
void ppartition(vector<int>&v,int low,int high){
    int pivot = v[high];
    int i = low-1 ;
    for(j=low;j<high;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]) ;
        }
        swap(v[i+1],v[high]);
        return i+1 ;
    }
}

void quickSort(vector<int>&v,int low,int high){
    if(low<high){
        int pi = ppartition(v,low,high) ;
        quickSort(v,low,pi-1);
        quickSort(v,pi+1,high);
    }
}

int main()
{
    int n;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0; i<n; i++) cin >> v[i] ;
    heapsort(v,n);
    for(int i = 0 ; i <n ; i++) cout << v[i] << " " ;
    return 0 ;
}

