#include <bits/stdc++.h> 
#include<graphics.h>

using namespace std; 

//Gap between two line.....

int gap = 7; 

// Function for swapping the lines graphically 
void swap_colour(int i, int j, int x, int y, int size) 
{ 
	
	setcolor(GREEN); 
	line(i, size, i, size - x); 
    delay(5);
	setcolor(RED); 
	line(i, size, i, size - x); 
	setcolor(YELLOW); 
	line(i, size, i, size - y); 

	
	setcolor(GREEN); 
	line(j, size, j, size - y); 
	setcolor(RED); 
	line(j, size, j, size - y); 
    delay(5);
	setcolor(YELLOW); 
	line(j, size, j, size - x); 
} 

// Bubble sort function ............................


void bubbleSort(vector<int>&nums) 
{ 
	for (int i = 1; i < nums.size(); i++) { 
		for (int j = 0; j < nums.size() - i; j++) { 
			if (nums[j] > nums[j + 1]) { 
				swap(nums[j+1], nums[j]);
                
				swap_colour(gap * j + 1, gap * (j + 1) + 1, nums[j + 1], nums[j], nums.size()); 
			} 
		} 
	} 
} 


// Selection sort function.............................


void selectionSort(vector<int>&nums)
{
    for(int i=0; i< nums.size()-1; i++)
    {
        int min=i;
        for(int j=i+1; j<nums.size();j++)
        {
            if(nums[j]<nums[min])
            {
                min=j;
            }
        }
        swap(nums[min], nums[i]);

        swap_colour(gap * i + 1, gap * (min) + 1, nums[min], nums[i], nums.size()); 

    }
}


// Insertion sort function..............................


void insertionSort(vector<int>&nums)
{
    for(int i=0;i<nums.size();i++)
    {
        int j=i;
        while(j>0 && nums[j-1]>nums[j])
        {
            swap(nums[j-1], nums[j]);

            swap_colour(gap * (j-1) + 1, gap * j + 1, nums[j], nums[j-1], nums.size()); 

            j--;
        }
        
    }
}


// Merge Sort function..........................


void merge(vector<int>&nums, int low, int mid, int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(nums[left]<=nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        nums[i]=temp[i-low];
        swap_colour(gap * (i-1) + 1, gap * (i-low) + 1, nums[i], nums[i-low-1], nums.size()); 

    }

}

void mergeSort(vector<int>&nums, int low, int high)
{
    if(low>=high) return;
    int mid=low+(high-low)/2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}


// Quick sort function...................


int partition(vector<int>&nums, int low, int high)
{
    int pivot=nums[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(nums[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while(nums[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(nums[i],nums[j]);
            swap_colour(gap * i + 1, gap * (j + 1) + 1, nums[j + 1], nums[i], nums.size()); 
        }
    }
    swap(nums[low],nums[j]);
    swap_colour(gap * low + 1, gap * (j + 1) + 1, nums[j + 1], nums[low], nums.size()); 

    return j;
}

void quickSort(vector<int>&nums, int low, int high)
{
    if(low<high)
    {
        int pIndex=partition(nums, low, high);
        quickSort(nums, low, pIndex-1);
        quickSort(nums, pIndex+1, high);
    }
}

// Print array...........
void print(vector<int>&nums)
{
    for (int i = 0; i < nums.size(); i++) { 
        cout << nums[i] << " "; 
    } 
    cout << endl; 
}


// Main function...............
int main() 
{ 
    vector<int> nums; 
    int size=500;
    int comnd;
       
       
    // Select the sorting method you want to visualize

    cout<<"To Visualize The Sorting Algorithm Enter a Command Accordingly.\n\n"
    <<"1. For Bubble Sort Enter -----> 1\n"
    <<"2. For Selection Sort Enter --> 2\n"
    <<"3. For Insertion Sort Enter --> 3\n"
    <<"4. For Merge Sort Enter ------> 4\n"
    <<"5. For Quick Sort Enter ------> 5\n"<<endl;
    cout<<"Enter your command."<<endl;
    cin>>comnd;

    // setting up window size (gap*size) * (size)
    int wid1 = initwindow(gap * size + 10, size + 10);
    setcurrentwindow(wid1);

    // Initializing the array
    for (int i = 1; i <= size; i++)
        nums.push_back(i);

    // Find a seed and shuffle the array
    // to make it random.
    // Here  different type of array
    // can be taken to results
    // such as nearly sorted, already sorted,
    // reverse sorted to visualize the result
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(nums.begin(), nums.end(), default_random_engine(seed));

    // Initial plot of numbers in graph taking
    // the vector position as x-axis and its
    // corresponding value will be the height of line.
    for (int i = 1; i <= gap * size; i += gap)
    {
        line(i, size, i, (size - nums[i / gap]));
    }

    // Delay the code
    delay(1000);

    if(comnd==1)
    {
        bubbleSort(nums);
        cout<<endl<<"Array after bubble sort :"<<endl;
        print(nums);
    }
    else if(comnd==2)
    {
        selectionSort(nums);
        cout<<endl<<"Array after selection sort :"<<endl;
        print(nums);
    }
    else if(comnd==3)
    {
        insertionSort(nums);
        cout<<endl<<"Array after insertion sort :"<<endl;
        print(nums);
    }
    else if(comnd==4)
    {
        mergeSort(nums,0,size);
        cout<<endl<<"Array after merge sort :"<<endl;
        print(nums);
    }
    else if(comnd==5)
    {
        quickSort(nums,0,size);
        cout<<endl<<"Array after quick sort :"<<endl;
        print(nums);
    }
    else{
        cout<<"You Press the wrong key."<<endl;
    }
    
    // Wait for sometime .
    delay(5000);


    // Close the graph
    closegraph();

    return 0;
} 
