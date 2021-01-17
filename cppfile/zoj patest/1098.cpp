#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 101;
bool isInsertionSort(vector<int> v1, vector<int> v2, int &index)
{
    int size = v1.size();
    for (int i = 0; i < size - 1; i++)
    {
        if (v2[i] <= v2[i + 1])
            continue;
        else
        {
            if (index == -1)
                index = i + 1;
            if (v2[i + 1] != v1[i + 1])
            {
                return false;
            }
        }
    }
    return true;
}
void insertionSortNextStep(vector<int> &v, int index)
{
    int t = v[index];
    int i;
    for (i = index; i > 0 && t < v[i - 1]; i--)
    {
        v[i] = v[i - 1];
    }
    v[i] = t;
}
void findHeapSortIndex(vector<int> v, int &index)
{
    vector<int> temp = v;
    sort(temp.begin(), temp.end());
    int n = v.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (temp[i] != v[i])
        {
            index = i;
            return;
        }
    }
}
void downAdjust(vector<int> &v, int low, int high)
{
    int i = low, j = 2 * i;
    while (j <= high)
    {
        if (j + 1 <= high && v[j + 1] > v[j])
            j++;
        if (v[i] < v[j])
        {
            swap(v[i], v[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
}
void upAdjust(vector<int> &v, int low, int high)
{
    int i = high, j = i / 2;
    ;
    while (j >= low)
    {
        if (v[i] > v[j])
        {
            swap(v[i], v[j]);
            i = j;
            j = i / 2;
        }
        else
            break;
    }
}
void insert(vector<int> &v, int x, int n)
{
    v[++n] = x;
    upAdjust(v, 1, n);
}
void createHeap(vector<int> &v, int n)
{
    for (int i = n / 2; i >= 1; i--)
        downAdjust(v, i, n);
}

void heapSortNextStep(vector<int> &v, int n, int index)
{
    for (int i = n; i > index - 1; i--)
    {
        swap(v[i], v[1]);
        downAdjust(v, 1, i - 1);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    vector<int> initialSequence;
    int t;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        initialSequence.push_back(t);
    }
    vector<int> partialSortedSequence;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        partialSortedSequence.push_back(t);
    }
    int index = -1;
    if (isInsertionSort(initialSequence, partialSortedSequence, index))
    {
        printf("Insertion Sort\n");
        insertionSortNextStep(partialSortedSequence, index);
        for (int i = 0; i < partialSortedSequence.size(); i++)
        {
            printf("%d", partialSortedSequence[i]);
            if (i != partialSortedSequence.size() - 1)
                printf(" ");
        }
    }
    else
    {
        initialSequence.insert(initialSequence.begin(), 0);
        partialSortedSequence.insert(partialSortedSequence.begin(), 0);
        findHeapSortIndex(partialSortedSequence, index);
        int n = initialSequence.size() - 1;
        createHeap(initialSequence, n);
        heapSortNextStep(initialSequence, n, index);
        printf("Heap Sort\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d", initialSequence[i]);
            if (i != n)
                printf(" ");
        }
    }
    return 0;
}