vector<int> heapSort(vector<int>& arr, int n) {
    // P1> CBT creation
	for (int i = 1; i < n; i++)
    {
        int ci = i;
        int pi = (ci - 1) / 2;
        while (ci > 0 && arr[pi] < arr[ci])
        {
            swap(arr[pi], arr[ci]);
            ci = pi;
            pi = (ci - 1) / 2;
        }
    }
    // P2> Down-heapify
    int m = n;
    for (int i = 0; i < n - 1; i++)
    {
        swap(arr[0], arr[--m]);
        int pi = 0;
        int lci = (2 * pi + 1), rci = (2 * pi + 2);
        while (lci < m)
        {
            int maxIdx = pi;
            if (arr[maxIdx] < arr[lci])
                maxIdx = lci;
            if (rci < m && arr[maxIdx] < arr[rci])
                maxIdx = rci;
            if (maxIdx == pi) break;
            swap(arr[maxIdx], arr[pi]);
            pi = maxIdx;
            lci = (2 * pi + 1), rci = (2 * pi + 2);
        }
    }
    return arr;
}
