#include <bits/stdc++.h>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3


int min_element(int arr[])
{
  int min_ind = 0;
  for (int i = 1; i < N; i++)
    if (arr[i] < arr[min_ind])
      min_ind = i;
  return min_ind;
}


int max_element(int arr[])
{
  int max_ind = 0;
  for (int i = 1; i < N; i++)
    if (arr[i] > arr[max_ind])
      max_ind = i;
  return max_ind;
}


int min_of_two(int x, int y) 
{ 
    int a=(x < y) ? x : y;
    return a;
}


void min_cash_flow_rec(int amount[])
{

 
  if (amount[max_element(amount)] == 0 && amount[min_element(amount)] == 0)
    return;

  int min = min_of_two(-amount[min_element(amount)], amount[max_element(amount)]);

  // Transfer the minimum amount
  amount[max_element(amount)] -= min;
  amount[min_element(amount)] += min;


  cout << "Person " << min_element(amount) << " pays " << min
       << " to "
       << "Person " << max_element(amount) << endl;

  // Recursively call the function for the updated amount array
  min_cash_flow_rec(amount);
}

// Function to find the minimum cash flow
void min_cash_flow(int graph[][N])
{


  int amount[N] = { 0 };


  for (int p = 0; p < N; p++)
    for (int i = 0; i < N; i++)
      amount[p] += (graph[i][p] - graph[p][i]);


  min_cash_flow_rec(amount);
}

int main()
{

  int graph[N][N] = {
    { 0, 1000, 2000 },
    { 0, 0, 5000 },
    { 0, 0, 0 },
  };


  min_cash_flow(graph);
  return 0;
}
