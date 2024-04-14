#include <bits/stdc++.h>
using namespace std;

class SortingAlgorithms{
protected:
    int size;
    int nums[1000];
public:
    SortingAlgorithms(int arr[],int n)
    {
        size=n;
        for(int i=0;i<n;i++)
        {
            nums[i]=arr[i];
        }
    }

    void SelectionSort()
    {
        for(int i=0;i<size-1;i++)
        {
            int index=i;
            for(int j=i;j<size;j++)
            {
                if(nums[index]>nums[j])
                {
                    index = j;
                }
            }
            swap(nums[index],nums[i]);
        }
    }

    void BubbleSort()
    {
        for(int i=size-1;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }

    void InsertionSort()
    {
        for(int i=1;i<size;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]>nums[j+1])
                {
                    int ele = nums[j+1];
                    nums[j+1]=nums[j];
                    nums[j]=ele;
                }
                else break;
            }
        }
    }
    
    void PrintArray()
    {
        for(int i=0;i<size;i++)
        {
            cout<<nums[i]<<" ";
        }
    }
};

class MergeSort: public SortingAlgorithms {
    public:

    MergeSort(int arr[],int size):SortingAlgorithms(arr,size){}

    void Merge(int low,int mid, int high)
    {
        int left[mid-low+1];
        int right[high-mid];
        for(int i=low;i<=mid;i++)
        {
            left[i-low]=nums[i];
        }
        for(int i=mid+1;i<=high;i++)
        {
            right[i-mid-1]=nums[i];
        }

        int i=low,j=mid+1,k=low;
        while(i<=mid && j<=high)
        {
            if(right[j-mid-1]<left[i-low])
            {
                nums[k]=right[j-mid-1];
                j++;
            }
            else
            {
                nums[k]=left[i-low];
                i++;
            }
            k++;
        }
        while(i<=mid)
        {
            nums[k]=left[i-low];
            i++;
        }
        while(j<=high)
        {
            nums[k]=right[j-mid-1];
            j++;
        }
    }
    void Sort(int low,int high)
    {
        if(low>=high) return;
        int mid=(low+high)/2;
        Sort(low,mid);
        Sort(mid+1,high);
        Merge(low,mid,high);
    }
};

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // SortingAlgorithms obj = SortingAlgorithms(arr,n);
    // obj.SelectionSort();
    // obj.BubbleSort();
    // obj.InsertionSort();
    // obj.PrintArray();
    MergeSort obj1 = MergeSort(arr,n);;
    obj1.Sort(0,n-1);
    return 0;
}